#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setImage(const QImage &newImage);
private:
    void open();
    bool loadFile(const QString &fileName);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    bool setFileDir(const QString &fileName);

    //void changeEvent(QEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    QImage image;
    QString photoDir;
    QString classifierDir;
    QString recognizePath;
    double scaleFactor = 1;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
