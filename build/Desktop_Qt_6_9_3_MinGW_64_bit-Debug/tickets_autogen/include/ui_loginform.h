/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *labelUserName;
    QLabel *labelPassword;
    QLineEdit *txtUserName;
    QLineEdit *txtPassword;
    QPushButton *btnLogin;
    QPushButton *btnRegister;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(400, 300);
        labelUserName = new QLabel(LoginForm);
        labelUserName->setObjectName("labelUserName");
        labelUserName->setGeometry(QRect(90, 70, 54, 16));
        labelPassword = new QLabel(LoginForm);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(90, 100, 54, 16));
        txtUserName = new QLineEdit(LoginForm);
        txtUserName->setObjectName("txtUserName");
        txtUserName->setGeometry(QRect(150, 70, 113, 20));
        txtPassword = new QLineEdit(LoginForm);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(150, 100, 113, 20));
        btnLogin = new QPushButton(LoginForm);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(90, 170, 75, 24));
        btnRegister = new QPushButton(LoginForm);
        btnRegister->setObjectName("btnRegister");
        btnRegister->setGeometry(QRect(180, 170, 75, 24));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Form", nullptr));
        labelUserName->setText(QCoreApplication::translate("LoginForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginForm", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginForm", "\347\231\273\345\275\225", nullptr));
        btnRegister->setText(QCoreApplication::translate("LoginForm", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
