/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *imageLabel;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *recognize_path;
    QLineEdit *photodirLineEdit_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *photodirLineEdit;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(764, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        scrollArea = new QScrollArea(horizontalWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 367, 578));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        imageLabel = new QLabel(scrollAreaWidgetContents);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(0, 0, 381, 571));
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit = new QTextEdit(horizontalWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        recognize_path = new QLabel(horizontalWidget);
        recognize_path->setObjectName(QString::fromUtf8("recognize_path"));

        horizontalLayout_7->addWidget(recognize_path);

        photodirLineEdit_2 = new QLineEdit(horizontalWidget);
        photodirLineEdit_2->setObjectName(QString::fromUtf8("photodirLineEdit_2"));

        horizontalLayout_7->addWidget(photodirLineEdit_2);

        pushButton_5 = new QPushButton(horizontalWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(horizontalWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_7->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_2 = new QLineEdit(horizontalWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        label_4 = new QLabel(horizontalWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        doubleSpinBox = new QDoubleSpinBox(horizontalWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1.000000000000000);
        doubleSpinBox->setSingleStep(0.010000000000000);
        doubleSpinBox->setValue(0.500000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        photodirLineEdit = new QLineEdit(horizontalWidget);
        photodirLineEdit->setObjectName(QString::fromUtf8("photodirLineEdit"));

        horizontalLayout_5->addWidget(photodirLineEdit);

        pushButton_2 = new QPushButton(horizontalWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit = new QLineEdit(horizontalWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        pushButton = new QPushButton(horizontalWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_3 = new QPushButton(horizontalWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        gridLayout->addWidget(horizontalWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imageLabel->setText(QString());
        recognize_path->setText(QCoreApplication::translate("MainWindow", "PhotoDIR:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "SetDir", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Recognize", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "KeyWord:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PhotoSrcDIR:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "SetDir", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PhotoDestDIR:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "SetDir", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Classifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
