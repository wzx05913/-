/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *labelUserName;
    QLabel *labelPassword;
    QLabel *labelRePassword;
    QLineEdit *txtUserName;
    QLineEdit *txtPassword;
    QLineEdit *txtRePassword;
    QLabel *labelUserType;
    QComboBox *cbxUserType;
    QLabel *labelCompanyName;
    QComboBox *cbxCompanyName;
    QPushButton *pushButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(400, 300);
        labelUserName = new QLabel(RegisterDialog);
        labelUserName->setObjectName("labelUserName");
        labelUserName->setGeometry(QRect(80, 30, 54, 16));
        labelPassword = new QLabel(RegisterDialog);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(80, 70, 54, 16));
        labelRePassword = new QLabel(RegisterDialog);
        labelRePassword->setObjectName("labelRePassword");
        labelRePassword->setGeometry(QRect(80, 110, 54, 16));
        txtUserName = new QLineEdit(RegisterDialog);
        txtUserName->setObjectName("txtUserName");
        txtUserName->setGeometry(QRect(150, 30, 113, 20));
        txtPassword = new QLineEdit(RegisterDialog);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(150, 70, 113, 20));
        txtRePassword = new QLineEdit(RegisterDialog);
        txtRePassword->setObjectName("txtRePassword");
        txtRePassword->setGeometry(QRect(150, 110, 113, 20));
        labelUserType = new QLabel(RegisterDialog);
        labelUserType->setObjectName("labelUserType");
        labelUserType->setGeometry(QRect(80, 150, 54, 16));
        cbxUserType = new QComboBox(RegisterDialog);
        cbxUserType->addItem(QString());
        cbxUserType->addItem(QString());
        cbxUserType->setObjectName("cbxUserType");
        cbxUserType->setGeometry(QRect(150, 150, 67, 22));
        labelCompanyName = new QLabel(RegisterDialog);
        labelCompanyName->setObjectName("labelCompanyName");
        labelCompanyName->setGeometry(QRect(80, 190, 54, 16));
        cbxCompanyName = new QComboBox(RegisterDialog);
        cbxCompanyName->setObjectName("cbxCompanyName");
        cbxCompanyName->setGeometry(QRect(150, 190, 67, 22));
        pushButton = new QPushButton(RegisterDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 230, 75, 24));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        labelUserName->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelRePassword->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        labelUserType->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", nullptr));
        cbxUserType->setItemText(0, QCoreApplication::translate("RegisterDialog", "\345\256\242\346\210\267", nullptr));
        cbxUserType->setItemText(1, QCoreApplication::translate("RegisterDialog", "\347\256\241\347\220\206\345\221\230", nullptr));

        labelCompanyName->setText(QCoreApplication::translate("RegisterDialog", "\350\210\252\345\217\270\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
