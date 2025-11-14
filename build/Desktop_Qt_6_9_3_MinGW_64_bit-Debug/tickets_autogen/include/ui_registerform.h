/********************************************************************************
** Form generated from reading UI file 'registerform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERFORM_H
#define UI_REGISTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterForm
{
public:
    QLabel *label_UserName;
    QLineEdit *txtUserName;
    QLabel *label_Password;
    QLineEdit *txtPassword;
    QLabel *label_RePassword;
    QLineEdit *txtRePassword;
    QLabel *label_UserType;
    QComboBox *cbx_UserType;
    QLabel *label_CompanyName;
    QComboBox *cbx_CompanyName;

    void setupUi(QWidget *RegisterForm)
    {
        if (RegisterForm->objectName().isEmpty())
            RegisterForm->setObjectName("RegisterForm");
        RegisterForm->resize(400, 300);
        label_UserName = new QLabel(RegisterForm);
        label_UserName->setObjectName("label_UserName");
        label_UserName->setGeometry(QRect(60, 50, 54, 16));
        txtUserName = new QLineEdit(RegisterForm);
        txtUserName->setObjectName("txtUserName");
        txtUserName->setGeometry(QRect(130, 50, 113, 20));
        label_Password = new QLabel(RegisterForm);
        label_Password->setObjectName("label_Password");
        label_Password->setGeometry(QRect(60, 90, 54, 16));
        txtPassword = new QLineEdit(RegisterForm);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(130, 90, 113, 20));
        label_RePassword = new QLabel(RegisterForm);
        label_RePassword->setObjectName("label_RePassword");
        label_RePassword->setGeometry(QRect(60, 130, 54, 16));
        txtRePassword = new QLineEdit(RegisterForm);
        txtRePassword->setObjectName("txtRePassword");
        txtRePassword->setGeometry(QRect(130, 130, 113, 20));
        label_UserType = new QLabel(RegisterForm);
        label_UserType->setObjectName("label_UserType");
        label_UserType->setGeometry(QRect(60, 170, 54, 16));
        cbx_UserType = new QComboBox(RegisterForm);
        cbx_UserType->addItem(QString());
        cbx_UserType->addItem(QString());
        cbx_UserType->setObjectName("cbx_UserType");
        cbx_UserType->setGeometry(QRect(130, 170, 67, 22));
        label_CompanyName = new QLabel(RegisterForm);
        label_CompanyName->setObjectName("label_CompanyName");
        label_CompanyName->setGeometry(QRect(60, 210, 54, 16));
        cbx_CompanyName = new QComboBox(RegisterForm);
        cbx_CompanyName->setObjectName("cbx_CompanyName");
        cbx_CompanyName->setGeometry(QRect(130, 210, 67, 22));

        retranslateUi(RegisterForm);

        QMetaObject::connectSlotsByName(RegisterForm);
    } // setupUi

    void retranslateUi(QWidget *RegisterForm)
    {
        RegisterForm->setWindowTitle(QCoreApplication::translate("RegisterForm", "Form", nullptr));
        label_UserName->setText(QCoreApplication::translate("RegisterForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_Password->setText(QCoreApplication::translate("RegisterForm", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_RePassword->setText(QCoreApplication::translate("RegisterForm", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        label_UserType->setText(QCoreApplication::translate("RegisterForm", "\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", nullptr));
        cbx_UserType->setItemText(0, QCoreApplication::translate("RegisterForm", "\345\256\242\346\210\267", nullptr));
        cbx_UserType->setItemText(1, QCoreApplication::translate("RegisterForm", "\347\256\241\347\220\206\345\221\230", nullptr));

        label_CompanyName->setText(QCoreApplication::translate("RegisterForm", "\350\210\252\345\217\270\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterForm: public Ui_RegisterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERFORM_H
