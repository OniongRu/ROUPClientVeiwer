#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    ui->BoxEnter->hide();
    TypeClose = false;
}


LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::closeEvent(QCloseEvent *event)
{
    if(TypeClose==false)
        qApp->quit();
}

void LogWindow::on_BReg_clicked()
{
    TypeClose = true;
    this->close();
    emit SigLog();
}
