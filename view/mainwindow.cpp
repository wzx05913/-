#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建一个controlleruser用于管理注册、登录、登出
    controlleruser=new ControllerUser();

    // 创建用户空闲计时器
    idleTimer=new QTimer(this);//以MainWindow为父对象，父对象被销毁时自动delete
    idleTimer->setInterval(timeoutMs);
    idleTimer->setSingleShot(true);
    connect(idleTimer,&QTimer::timeout,controlleruser,&ControllerUser::LogoutUser);

    //登录、登出信号与登录状态显示槽函数连接
    connect(controlleruser,&ControllerUser::userLoggedIn,this,&MainWindow::updateUserStatus);
    connect(controlleruser,&ControllerUser::userLoggedOut,this,&MainWindow::clearUserStatus);

    // 安装全局事件过滤器，捕获鼠标和键盘操作
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete controlleruser;
    delete idleTimer;
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
    LoginDialog logindialog(this,controlleruser);
    if(logindialog.exec()==QDialog::Accepted){
        idleTimer->start();// 登录成功，启动空闲计时器
    }
}
void MainWindow::updateUserStatus(const QString& type,const QString& name){
    ui->labelUser->setText(type+": "+name);
}
void MainWindow::clearUserStatus(){
    ui->labelUser->setText("未登录");
}
