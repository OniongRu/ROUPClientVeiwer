#include "tablewindow.h"
#include "ui_tablewindow.h"
#include <QThread>
#include <iostream>
#include <QJsonDocument>
#include <testjson.h>

TableWindow::TableWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    Client = new QTcpSocket();
    connect(Client, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(Client, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
}

TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::on_ToMenu_clicked()
{
    this->close();
    emit SigTable();
}

void TableWindow::on_TakeInfo_clicked()
{
    int Hport = 5020;
    const QString addr = "127.0.0.1";
    Client->connectToHost(addr,Hport);

}

void TableWindow::onSokConnected()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    QString m = "hahahaha whats story 0_o";
    out << quint16(0) << m;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    Client->write(arrBlock);
}

void TableWindow::onSokReadyRead()
{
    QJsonObject obj;
    QString data = Client->readAll();
    qDebug()<<data;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if(doc.isObject())
    {
        obj = doc.object();
    }
    User UserTab;
    UserTab.read(obj);
    ui->tableWidget->setRowCount(6+UserTab.ProgArrSize);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("UserName"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(UserTab.userName));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("CreationDate"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(UserTab.creationDate));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("ActiveWindowProcessName"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem(UserTab.activeWindowProcessName));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("Programs"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem("name"));
    ui->tableWidget->setItem(3,2,new QTableWidgetItem("ID"));
    ui->tableWidget->setItem(3,3,new QTableWidgetItem("threadAmount"));
    ui->tableWidget->setItem(3,4,new QTableWidgetItem("cpuUsage"));
    ui->tableWidget->setItem(3,5,new QTableWidgetItem("ramUsage"));
    for(int i=0;i<4;i++)
    {
        ui->tableWidget->item(i,0)->setBackground(QColor(255, 239, 85));
        ui->tableWidget->item(i,1)->setBackground(QColor(215, 235, 255));
    }
    int row = 4;
    for(int i=0;i<UserTab.ProgArrSize;i++)
    {
        ui->tableWidget->setItem(row+i,1,new QTableWidgetItem(UserTab.Programs[i].name));
        ui->tableWidget->setItem(row+i,2,new QTableWidgetItem(QString::number(UserTab.Programs[i].ID)));
        ui->tableWidget->setItem(row+i,3,new QTableWidgetItem(QString::number(UserTab.Programs[i].threadAmount)));
        ui->tableWidget->setItem(row+i,4,new QTableWidgetItem(QString::number(UserTab.Programs[i].cpuUsage)));
        ui->tableWidget->setItem(row+i,5,new QTableWidgetItem(QString::number(UserTab.Programs[i].ramUsage)));
    }
    row = 4;
    ui->tableWidget->item(3,1)->setBackground(QColor(255, 206, 88));
    ui->tableWidget->item(3,2)->setBackground(QColor(122, 189, 255));
    ui->tableWidget->item(3,3)->setBackground(QColor(255, 206, 88));
    ui->tableWidget->item(3,4)->setBackground(QColor(122, 189, 255));
    ui->tableWidget->item(3,5)->setBackground(QColor(255, 206, 88));
    for(int i=0;i<UserTab.ProgArrSize;i++)
    {
        ui->tableWidget->item(i+row,1)->setBackground(QColor(255, 225, 154));
        ui->tableWidget->item(i+row,2)->setBackground(QColor(215, 235, 255));
        ui->tableWidget->item(i+row,3)->setBackground(QColor(255, 225, 154));
        ui->tableWidget->item(i+row,4)->setBackground(QColor(215, 235, 255));
        ui->tableWidget->item(i+row,5)->setBackground(QColor(255, 225, 154));
    }
}

 //ui->tableWidget->item(i,j)->setBackground(QColor(255, 164, 0));
















