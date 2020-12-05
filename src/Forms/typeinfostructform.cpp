#include "typeinfostructform.h"
#include "ui_typeinfostructform.h"

TypeInfoStructForm::TypeInfoStructForm(QWidget *parent, const std::vector<QString> &Users, const std::vector<QString> &Programs, QTcpSocket *Client) :
    QWidget(parent),
    ui(new Ui::TypeInfoStructForm)
{
    ui->setupUi(this);
    this->Users = Users;
    this->Programs = Programs;
    this->Client=Client;
    InitUsers();
    InitProgrmas();
    InitTypes();
}

TypeInfoStructForm::~TypeInfoStructForm()
{
    //ui->listUsers->clear();
    //ui->listPrograms->clear();
    Users.clear();
    Programs.clear();
    delete ui;
}

void TypeInfoStructForm::on_buttonSendJson_clicked()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    QString m = "faza2";
    out << quint16(0) << m;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    Client->write(arrBlock);
}

void TypeInfoStructForm::InitUsers()
{
    //QListWidgetItem *item = new QListWidgetItem[Users.size()];
    /*int i=0;
    for (auto const &element: Users)
    {
        item[i].setText(element);
        item->setCheckState(Qt::Unchecked);
        i++;
        item[i].setCheckState(Qt::Unchecked);
        ui->listUsers->addItem(&item[i]);
    }*/
    for(int i=0;i<3;i++)
    {
        /*item[i].setText(Users[i]);
        item->setCheckState(Qt::Unchecked);
        item[i].setCheckState(Qt::Unchecked);*/
        ui->listUsers->addItem(new QListWidgetItem(Users[i]));
        ui->listUsers->item(i)->setCheckState(Qt::Unchecked);
    }
}
void TypeInfoStructForm::InitProgrmas()
{
    //QListWidgetItem *item = new QListWidgetItem[Programs.size()];
    /*int i=0;
    for (auto const &element: Programs)
    {
        item[i].setText(element);
        item->setCheckState(Qt::Unchecked);
        i++;
        item[i].setCheckState(Qt::Unchecked);
        ui->listPrograms->addItem(&item[i]);
    }*/
    for(int i=0;i<3;i++)
    {
        /*item[i].setText(Programs[i]);
        item->setCheckState(Qt::Unchecked);
        item[i].setCheckState(Qt::Unchecked);
        ui->listPrograms->addItem(&item[i]);*/
        ui->listPrograms->addItem(new QListWidgetItem(Programs[i]));
        ui->listPrograms->item(i)->setCheckState(Qt::Unchecked);
    }
}
void TypeInfoStructForm::InitTypes()
{
    ui->comboType->addItem("Table");
    ui->comboType->addItem("Graphic");
    ui->comboType->addItem("Diagram");
}
