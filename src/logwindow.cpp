#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    ui->BoxEnter->hide();
    WinMain = new MainWindow();
    connect(WinMain, &MainWindow::SigMain, this, &MainWindow::show);
}

LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::on_BReg_clicked()
{
    ui->BoxWay->hide();
    ui->BNext->setText("Sign Up");
    ui->BoxEnter->show();
}

void LogWindow::on_BLog_clicked()
{
    ui->BoxWay->hide();
    ui->BoxEnter->setTitle("Вход в систему");
    ui->BoxEnter->show();
}

void LogWindow::on_BNext_clicked()
{
    this->close();      // Закрываем окно
    WinMain->show();
}
