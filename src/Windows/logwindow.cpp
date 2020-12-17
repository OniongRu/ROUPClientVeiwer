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

    QString m = "Initialize observer\n";

    //Here json needed: name: "name", password: "16 bytes"
    QJsonObject root;
    root["name"] = ui->EditLogin->text();
    login = "";
    //Password to be encrypted here
    root["password"] = "nYTQ4q/9v8UcKK64U2cz9g==";
    //password = ui->EditPassword->text(); //TODO add password's encryption
    password = "nYTQ4q/9v8UcKK64U2cz9g==";
    qDebug() << qUtf8Printable(m);
    QString data = m + QJsonDocument(root).toJson();
    Client->write(qUtf8Printable(data));
}

void LogWindow::accountInfo(Account *myaccount)
{
    myaccount->login = login;
    myaccount->password = password;
}
