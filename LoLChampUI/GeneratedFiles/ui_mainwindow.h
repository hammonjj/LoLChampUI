/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListView *list_primary;
    QListView *list_secondary;
    QPushButton *btn_addPrimary;
    QPushButton *btn_removePrimary;
    QPushButton *btn_addSecondary;
    QPushButton *btn_removeSecondary;
    QRadioButton *rad_byChampion;
    QRadioButton *rad_byCategory;
    QPushButton *btn_apply;
    QPushButton *btn_restore;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(262, 561);
        MainWindow->setMinimumSize(QSize(262, 561));
        MainWindow->setMaximumSize(QSize(262, 561));
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        list_primary = new QListView(centralWidget);
        list_primary->setObjectName(QStringLiteral("list_primary"));
        list_primary->setGeometry(QRect(20, 40, 181, 221));
        list_secondary = new QListView(centralWidget);
        list_secondary->setObjectName(QStringLiteral("list_secondary"));
        list_secondary->setGeometry(QRect(20, 280, 181, 221));
        btn_addPrimary = new QPushButton(centralWidget);
        btn_addPrimary->setObjectName(QStringLiteral("btn_addPrimary"));
        btn_addPrimary->setGeometry(QRect(210, 40, 21, 23));
        btn_addPrimary->setCheckable(false);
        btn_removePrimary = new QPushButton(centralWidget);
        btn_removePrimary->setObjectName(QStringLiteral("btn_removePrimary"));
        btn_removePrimary->setGeometry(QRect(210, 70, 21, 23));
        btn_addSecondary = new QPushButton(centralWidget);
        btn_addSecondary->setObjectName(QStringLiteral("btn_addSecondary"));
        btn_addSecondary->setGeometry(QRect(210, 280, 21, 23));
        btn_removeSecondary = new QPushButton(centralWidget);
        btn_removeSecondary->setObjectName(QStringLiteral("btn_removeSecondary"));
        btn_removeSecondary->setGeometry(QRect(210, 310, 21, 23));
        rad_byChampion = new QRadioButton(centralWidget);
        rad_byChampion->setObjectName(QStringLiteral("rad_byChampion"));
        rad_byChampion->setGeometry(QRect(25, 10, 82, 17));
        rad_byChampion->setChecked(true);
        rad_byCategory = new QRadioButton(centralWidget);
        rad_byCategory->setObjectName(QStringLiteral("rad_byCategory"));
        rad_byCategory->setGeometry(QRect(120, 10, 82, 17));
        btn_apply = new QPushButton(centralWidget);
        btn_apply->setObjectName(QStringLiteral("btn_apply"));
        btn_apply->setGeometry(QRect(30, 510, 75, 23));
        btn_restore = new QPushButton(centralWidget);
        btn_restore->setObjectName(QStringLiteral("btn_restore"));
        btn_restore->setGeometry(QRect(115, 510, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 262, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LOL Champ Manager", 0));
        btn_addPrimary->setText(QApplication::translate("MainWindow", "+", 0));
        btn_removePrimary->setText(QApplication::translate("MainWindow", "-", 0));
        btn_addSecondary->setText(QApplication::translate("MainWindow", "+", 0));
        btn_removeSecondary->setText(QApplication::translate("MainWindow", "-", 0));
        rad_byChampion->setText(QApplication::translate("MainWindow", "By Champion", 0));
        rad_byCategory->setText(QApplication::translate("MainWindow", "By Category", 0));
        btn_apply->setText(QApplication::translate("MainWindow", "Apply", 0));
        btn_restore->setText(QApplication::translate("MainWindow", "Restore", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
