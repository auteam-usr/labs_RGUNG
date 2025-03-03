/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *tasksListWidget;
    QPushButton *addTaskButton;
    QPushButton *detailsTaskButton;
    QPushButton *deleteTaskButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(573, 288);
        MainWindow->setMouseTracking(false);
        MainWindow->setTabletTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:white"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tasksListWidget = new QListWidget(centralwidget);
        tasksListWidget->setObjectName("tasksListWidget");
        tasksListWidget->setStyleSheet(QString::fromUtf8("background-color:OldLace"));

        verticalLayout->addWidget(tasksListWidget);

        addTaskButton = new QPushButton(centralwidget);
        addTaskButton->setObjectName("addTaskButton");

        verticalLayout->addWidget(addTaskButton);

        detailsTaskButton = new QPushButton(centralwidget);
        detailsTaskButton->setObjectName("detailsTaskButton");

        verticalLayout->addWidget(detailsTaskButton);

        deleteTaskButton = new QPushButton(centralwidget);
        deleteTaskButton->setObjectName("deleteTaskButton");

        verticalLayout->addWidget(deleteTaskButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 573, 22));
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
        addTaskButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        detailsTaskButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\276\321\201\321\202\320\270 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        deleteTaskButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
