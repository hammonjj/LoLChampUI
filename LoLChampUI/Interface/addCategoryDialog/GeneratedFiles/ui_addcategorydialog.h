/********************************************************************************
** Form generated from reading UI file 'addcategorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCATEGORYDIALOG_H
#define UI_ADDCATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addCategoryDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *edit_categoryText;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_accept;
    QPushButton *btn_cancel;

    void setupUi(QDialog *addCategoryDialog)
    {
        if (addCategoryDialog->objectName().isEmpty())
            addCategoryDialog->setObjectName(QStringLiteral("addCategoryDialog"));
        addCategoryDialog->resize(235, 107);
        addCategoryDialog->setMinimumSize(QSize(235, 105));
        addCategoryDialog->setMaximumSize(QSize(235, 107));
        widget = new QWidget(addCategoryDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 211, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 10, 188, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(widget1);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        edit_categoryText = new QLineEdit(widget1);
        edit_categoryText->setObjectName(QStringLiteral("edit_categoryText"));

        horizontalLayout->addWidget(edit_categoryText);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_accept = new QPushButton(widget);
        btn_accept->setObjectName(QStringLiteral("btn_accept"));

        horizontalLayout_2->addWidget(btn_accept);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        horizontalLayout_2->addWidget(btn_cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(addCategoryDialog);

        QMetaObject::connectSlotsByName(addCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *addCategoryDialog)
    {
        addCategoryDialog->setWindowTitle(QApplication::translate("addCategoryDialog", "Add New Category", 0));
        groupBox->setTitle(QString());
        label_name->setText(QApplication::translate("addCategoryDialog", "Name", 0));
        btn_accept->setText(QApplication::translate("addCategoryDialog", "Accept", 0));
        btn_cancel->setText(QApplication::translate("addCategoryDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class addCategoryDialog: public Ui_addCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCATEGORYDIALOG_H
