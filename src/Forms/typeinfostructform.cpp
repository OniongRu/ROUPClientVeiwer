#include "typeinfostructform.h"
#include "ui_typeinfostructform.h"
#include <QMessageBox>
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


    QString msg = trUtf8("<StartMsg>NeedJson, Users: ");
    int ZeroCondition=0;
    for(int i=0;i<Users.size();i++)
    {
        if(ui->listUsers->item(i)->checkState())
        {
            ZeroCondition++;
            msg+=ui->listUsers->item(i)->text().toUtf8()+" ";
        }
    }
    if(ZeroCondition==0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка данных");
        msgBox.setText("Не выбран ни один Пользователь");
        msgBox.exec();
        return;
    }
    ZeroCondition=0;
    msg+=" Programs: ";
    for(int i=0;i<Programs.size();i++)
    {
        if(ui->listPrograms->item(i)->checkState())
        {
            ZeroCondition++;
            msg+=ui->listPrograms->item(i)->text().toUtf8()+" ";
        }
    }
    if(ZeroCondition==0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка данных");
        msgBox.setText("Не выбрана ни одна Программа");
        msgBox.exec();
        return;
    }
    msg+=" Start: " + ui->dateTimeEditStart->dateTime().toString("HH:mm:ss, dd.MM.yyyy");
    msg+=" End: " + ui->dateTimeEditEnd->dateTime().toString("HH:mm:ss, dd.MM.yyyy");
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    //out << quint16(m.size())  << qUtf8Printable(m);
    out<< qUtf8Printable(msg);
    qDebug()<<qUtf8Printable(msg);
    //out.device()->seek(0);
    //out << quint16(arrBlock.size() - sizeof(quint16));
    //int i = Client->write(arrBlock, arrBlock.size());
    int i = Client->write(arrBlock);
    Client->flush();
    qDebug()<<i;
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
