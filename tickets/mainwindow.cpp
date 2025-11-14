#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logindialog.h"
#include "user.h"
extern User *curUser;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建用户空闲计时器
    idleTimer=new QTimer(this);
    idleTimer->setInterval(timeoutMs);
    idleTimer->setSingleShot(true);
    connect(idleTimer,&QTimer::timeout,this,&MainWindow::logout);

    // 安装全局事件过滤器，捕获鼠标和键盘操作
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseMove||event->type()==QEvent::KeyPress||event->type()==QEvent::MouseButtonPress){
        idleTimer->start(); // 用户有操作，重置计时器
    }
    return QMainWindow::eventFilter(watched,event);
}
void MainWindow::on_btnLogin_clicked()
{
    LoginDialog logindialog;
    if(logindialog.exec()==QDialog::Accepted){
        idleTimer->start();// 登录成功，启动空闲计时器
    }
}
void MainWindow::logout()
{
    curUser=nullptr;
}

