#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QColorSpace>
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
#include <QStandardPaths>
#include <QImageWriter>
#include <QProcess>
#include <QResizeEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->imageLabel->setBackgroundRole(QPalette::Base);
    ui->imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->imageLabel->setScaledContents(true);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    setWindowTitle("Classifier Photo");
    //ui->scrollArea->setWidget(ui->imageLabel);
    //ui->scrollArea->setWidget(ui->imageLabel);
    //ui->scrollArea->setVisible(false);
    //setCentralWidget(ui->scrollArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(const QImage &newImage)
{
    int width = ui->scrollArea->width();
    int height = ui->scrollArea->height();
    image = newImage.scaled(width, height);
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);
    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
//! [4]
    ui->scrollArea->setVisible(true);

    //ui->imageLabel->adjustSize();


}

void MainWindow::on_pushButton_2_clicked()
{
    QFileDialog dialog(this, tr("Open Directory"));
    static bool firstDialog = true;
    QString path;
    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        path = picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last();
        dialog.setDirectory(path);
    }
    path = dialog.getExistingDirectory(this, "Open Directory", path);
    if(!path.isEmpty())
    {
        ui->photodirLineEdit->setText(path);
        photoDir = path;
    }

}


static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    dialog.setAcceptMode(acceptMode);
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void MainWindow::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().constFirst())) {}
}


bool MainWindow::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
//! [2]

    setImage(newImage);

    setWindowFilePath(fileName);
    recognizePath = fileName;
    scaleImage(1.0);
    return true;
}

//! [23]
void MainWindow::scaleImage(double factor)
//! [23] //! [24]
{
    scaleFactor *= factor;
    ui->imageLabel->resize(scaleFactor * ui->imageLabel->pixmap(Qt::ReturnByValue).size());

    adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);
}
//! [24]

//! [25]
void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
//! [25] //! [26]
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}
//! [26]

void MainWindow::on_pushButton_4_clicked()
{
    QProcess process(this);
    QStringList arguments;
    QString newPhotoPath = recognizePath + ".jpg";
    arguments <<  "./deploy.py" << recognizePath << newPhotoPath;
    process.start("/usr/bin/python", arguments);
    process.waitForFinished();
    process.waitForReadyRead();
    QString msg = process.readAllStandardOutput();
    if(!msg.isEmpty())
    {
        QString msg2 = msg;
       msg2.chop(msg2.size()-msg2.lastIndexOf("}"));
       msg2 = msg2.right(msg2.size() - msg2.indexOf("{")-1);
       qDebug() << msg2;
        if(!msg2.isEmpty())
        {
            ui->textEdit->setText(msg2);
        }
    }

    QString error = process.readAllStandardError();
    if(!error.isEmpty())
    {
        qDebug() << error;
    }
    process.close();

    QImageReader reader(newPhotoPath);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        return;
    }
//! [2]

    setImage(newImage);
}

void MainWindow::on_pushButton_5_clicked()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().constFirst())) {}
    ui->photodirLineEdit_2->setText(recognizePath);
}

bool MainWindow::setFileDir(const QString &fileName)
{
    ui->photodirLineEdit_2->setText(fileName);
    recognizePath = fileName;
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this, tr("Open Directory"));
    static bool firstDialog = true;
    QString path;
    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        path = picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last();
        dialog.setDirectory(path);
    }
    path = dialog.getExistingDirectory(this, "Open Directory", path);
    if(!path.isEmpty())
    {
        ui->lineEdit->setText(path);
        classifierDir = path;
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    QString keyword = ui->lineEdit_2->text();
    if(keyword.isEmpty())
        QMessageBox::warning(this, "tips", "keyword must value");
    double probabilityNum = ui->doubleSpinBox->value();
    QString srcdir = ui->photodirLineEdit->text();
    if(srcdir.isEmpty())
        QMessageBox::warning(this, "tips", "srcdir must value");
    QString dstdir = ui->lineEdit->text();
    if(dstdir.isEmpty())
        QMessageBox::warning(this, "tips", "dstdir must value");
    qDebug() << keyword << probabilityNum << srcdir << dstdir;


    QProcess process(this);
    QStringList arguments;
    arguments <<  "./deploy01.py" << keyword << QString::number( probabilityNum) << srcdir << dstdir;
    process.start("/usr/bin/python", arguments);
    ui->textEdit->setText("Classifier Photo start");
    process.waitForFinished();
    process.waitForReadyRead();
    QString msg = process.readAllStandardOutput();
    if(!msg.isEmpty())
    {
       qDebug() << msg;
    }

    QString error = process.readAllStandardError();
    if(!error.isEmpty())
    {
        qDebug() << error;
    }
    process.close();
    ui->textEdit->setText("done");
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->imageLabel->resize(ui->scrollArea->size());
    QMainWindow::resizeEvent(event);
}
