#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class LogWindow;
}

class LogWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

private slots:
    void on_BReg_clicked();

    void on_BLog_clicked();

    void on_BNext_clicked();

private:
    Ui::LogWindow *ui;
    MainWindow *WinMain;
};

#endif // LOGWINDOW_H
