/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *xorKeyLineEdit;
    QPushButton *startButton;
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QCheckBox *timerCheckBox;
    QSpinBox *timerSpinBox;
    QGroupBox *groupBox;
    QLineEdit *outputDirLineEdit;
    QCheckBox *overwriteCheckBox;
    QPushButton *selectFolderButton;
    QGroupBox *groupBox_2;
    QLineEdit *filesLineEdit;
    QPushButton *selectFilesButton;
    QCheckBox *deleteFilesCheckBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        xorKeyLineEdit = new QLineEdit(centralwidget);
        xorKeyLineEdit->setObjectName("xorKeyLineEdit");
        xorKeyLineEdit->setGeometry(QRect(20, 150, 201, 22));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(140, 270, 75, 24));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 190, 211, 23));
        progressBar->setValue(0);
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(30, 380, 161, 16));
        timerCheckBox = new QCheckBox(centralwidget);
        timerCheckBox->setObjectName("timerCheckBox");
        timerCheckBox->setGeometry(QRect(30, 230, 131, 20));
        timerSpinBox = new QSpinBox(centralwidget);
        timerSpinBox->setObjectName("timerSpinBox");
        timerSpinBox->setGeometry(QRect(190, 230, 131, 22));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(240, 10, 241, 161));
        outputDirLineEdit = new QLineEdit(groupBox);
        outputDirLineEdit->setObjectName("outputDirLineEdit");
        outputDirLineEdit->setGeometry(QRect(10, 20, 221, 41));
        outputDirLineEdit->setDragEnabled(false);
        overwriteCheckBox = new QCheckBox(groupBox);
        overwriteCheckBox->setObjectName("overwriteCheckBox");
        overwriteCheckBox->setGeometry(QRect(40, 130, 141, 20));
        selectFolderButton = new QPushButton(groupBox);
        selectFolderButton->setObjectName("selectFolderButton");
        selectFolderButton->setGeometry(QRect(40, 70, 151, 41));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 10, 201, 131));
        filesLineEdit = new QLineEdit(groupBox_2);
        filesLineEdit->setObjectName("filesLineEdit");
        filesLineEdit->setGeometry(QRect(10, 20, 181, 22));
        selectFilesButton = new QPushButton(groupBox_2);
        selectFilesButton->setObjectName("selectFilesButton");
        selectFilesButton->setGeometry(QRect(10, 60, 181, 24));
        deleteFilesCheckBox = new QCheckBox(groupBox_2);
        deleteFilesCheckBox->setObjectName("deleteFilesCheckBox");
        deleteFilesCheckBox->setGeometry(QRect(10, 100, 181, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        xorKeyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "XOR", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        statusLabel->setText(QString());
        timerCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \320\277\320\276 \321\202\320\260\320\271\320\274\320\265\321\200\321\203", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\262\321\213\320\262\320\276\320\264\320\260 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        outputDirLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
        overwriteCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213", nullptr));
        selectFolderButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\277\320\260\320\277\320\272\320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        filesLineEdit->setText(QString());
        filesLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\320\272\320\260 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        selectFilesButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213", nullptr));
        deleteFilesCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\277\320\276\321\201\320\273\320\265 \320\262\321\213\320\261\320\276\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
