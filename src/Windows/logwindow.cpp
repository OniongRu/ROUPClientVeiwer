#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent, QTcpSocket *Client) :
    QMainWindow(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    ui->BoxEnter->hide();
    TypeClose = false;
    this->setEnabled(0);
    int Hport = 5020;
    const QString addr = "127.0.0.1";
    this->Client=Client;
    Client->connectToHost(addr,Hport);
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

void LogWindow::LogAccept()
{
    TypeClose = true;
    this->close();
    emit SigLog();
}

void LogWindow::on_BReg_clicked()
{

   /* TypeClose = true;
    this->close();
    emit SigLog();*/
}

void LogWindow::on_BLog_clicked()
{
    ui->BoxWay->hide();
    ui->BoxEnter->show();
}

void LogWindow::on_BNext_clicked()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    QString m = "flag2";
    out << quint16(0) << qUtf8Printable(m);
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    Client->write(arrBlock);
}
