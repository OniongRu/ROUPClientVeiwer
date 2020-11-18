#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WinTable = new TableWindow();
    connect(WinTable, &TableWindow::SigTable, this, &TableWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TableEx_clicked()
{
    this->close();
    WinTable->show();
}

void MainWindow::on_LogOut_clicked()
{
    this->close();
    emit SigMain();
}
