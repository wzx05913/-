/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *labelUserName;
    QLabel *labelPassword;
    QLineEdit *txtUserName;
    QLineEdit *txtPassword;
    QPushButton *btnLogin;
    QPushButton *btnRegister;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(400, 300);
        labelUserName = new QLabel(LoginDialog);
        labelUserName->setObjectName("labelUserName");
        labelUserName->setGeometry(QRect(80, 60, 54, 16));
        labelPassword = new QLabel(LoginDialog);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(80, 100, 54, 16));
        txtUserName = new QLineEdit(LoginDialog);
        txtUserName->setObjectName("txtUserName");
        txtUserName->setGeometry(QRect(160, 60, 113, 20));
        txtPassword = new QLineEdit(LoginDialog);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(160, 100, 113, 20));
        btnLogin = new QPushButton(LoginDialog);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(80, 150, 75, 24));
        btnRegister = new QPushButton(LoginDialog);
        btnRegister->setObjectName("btnRegister");
        btnRegister->setGeometry(QRect(170, 150, 75, 24));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        labelUserName->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        btnRegister->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
