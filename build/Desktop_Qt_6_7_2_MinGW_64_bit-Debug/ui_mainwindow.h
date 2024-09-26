/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnChoose;
    QLabel *lblImage;
    QTextEdit *teAscii;
    QPushButton *btnConvert;
    QPushButton *btnInverse;
    QPushButton *btnChoose_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1361, 820);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #ccd4e0;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnChoose = new QPushButton(centralwidget);
        btnChoose->setObjectName("btnChoose");
        btnChoose->setGeometry(QRect(210, 70, 301, 71));
        btnChoose->setStyleSheet(QString::fromUtf8("background-color: #9dacc2; \n"
"color: rgb(0, 0, 0);"));
        lblImage = new QLabel(centralwidget);
        lblImage->setObjectName("lblImage");
        lblImage->setGeometry(QRect(70, 170, 591, 501));
        lblImage->setStyleSheet(QString::fromUtf8("background-color: #9dacc2;\n"
"border: 5px dotted black;\n"
"\n"
""));
        teAscii = new QTextEdit(centralwidget);
        teAscii->setObjectName("teAscii");
        teAscii->setGeometry(QRect(690, 170, 581, 501));
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier")});
        font.setPointSize(9);
        font.setBold(true);
        teAscii->setFont(font);
        teAscii->setStyleSheet(QString::fromUtf8("background-color: #9dacc2;\n"
"border: 5px dotted black;\n"
"\n"
""));
        btnConvert = new QPushButton(centralwidget);
        btnConvert->setObjectName("btnConvert");
        btnConvert->setGeometry(QRect(720, 80, 241, 61));
        btnConvert->setStyleSheet(QString::fromUtf8("background-color: #9dacc2; \n"
"color: rgb(0, 0, 0);"));
        btnInverse = new QPushButton(centralwidget);
        btnInverse->setObjectName("btnInverse");
        btnInverse->setGeometry(QRect(980, 80, 241, 61));
        btnInverse->setStyleSheet(QString::fromUtf8("background-color: #9dacc2; \n"
"color: rgb(0, 0, 0);"));
        btnChoose_2 = new QPushButton(centralwidget);
        btnChoose_2->setObjectName("btnChoose_2");
        btnChoose_2->setGeometry(QRect(140, 80, 0, 0));
        btnChoose_2->setStyleSheet(QString::fromUtf8("background-color: #9dacc2; \n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1361, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnChoose->setText(QCoreApplication::translate("MainWindow", "Choose an image", nullptr));
        lblImage->setText(QString());
        btnConvert->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        btnInverse->setText(QCoreApplication::translate("MainWindow", "Inverse", nullptr));
        btnChoose_2->setText(QCoreApplication::translate("MainWindow", "Choose an image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
