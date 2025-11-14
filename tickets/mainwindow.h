#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
private slots:
    void on_btnLogin_clicked();
    void logout();
private:
    Ui::MainWindow *ui;
    QTimer *idleTimer;
    const int timeoutMs = 60 * 60 * 1000;
};
#endif // MAINWINDOW_H
