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
    Users.clear();
    Programs.clear();
    delete ui;
}

void TypeInfoStructForm::on_buttonSendJson_clicked()
{

    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    QString m = trUtf8("NeedJson");
    out << quint16(0) << qUtf8Printable(m);
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    Client->write(arrBlock);
}

void TypeInfoStructForm::InitUsers()
{
    for(int i=0;i<Users.size();i++)
    {
        ui->listUsers->addItem(new QListWidgetItem(Users[i]));
        ui->listUsers->item(i)->setCheckState(Qt::Unchecked);
    }
}
void TypeInfoStructForm::InitProgrmas()
{
    for(int i=0;i<Programs.size();i++)
    {
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
