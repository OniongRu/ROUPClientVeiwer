#include "typeinfostructform.h"
#include "ui_typeinfostructform.h"
#include <QMessageBox>
TypeInfoStructForm::TypeInfoStructForm(QWidget *parent, const std::vector<QString> &Users, const std::vector<QString> &Programs, QTcpSocket *Client, Account *myaccount) :
    QWidget(parent),
    ui(new Ui::TypeInfoStructForm)
{
    ui->setupUi(this);
    this->Users = Users;
    this->Programs = Programs;
    this->Client=Client;
    login = myaccount->login;
    password = myaccount->password;
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
    QString msg = "NeedJson\n";
    QJsonObject root;
    root["name"] = login;
    root["password"] = password;
    int ZeroCondition=0;
    QJsonArray jsonUsers;
    for(int i=0;i<Users.size();i++)
    {
        if(ui->listUsers->item(i)->checkState())
        {
            ZeroCondition++;
            jsonUsers.append(ui->listUsers->item(i)->text());
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
    QJsonArray jsonPrograms;
    for(int i=0;i<Programs.size();i++)
    {
        if(ui->listPrograms->item(i)->checkState())
        {
            ZeroCondition++;
            jsonPrograms.append(ui->listPrograms->item(i)->text());
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
    root["users"] = jsonUsers;
    root["programs"] = jsonPrograms;
    root["from"] = ui->dateTimeEditStart->dateTime().toString("HH:mm:ss, dd.MM.yyyy");
    root["to"] = ui->dateTimeEditEnd->dateTime().toString("HH:mm:ss, dd.MM.yyyy");
    QString data = msg + QJsonDocument(root).toJson();

    int i = Client->write(qUtf8Printable(data));
    qDebug()<<i<<" "<<data;

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

void TypeInfoStructForm::on_checkBoxAllUsers_stateChanged(int arg1)
{
    if(arg1)
        for(int i=0;i<Users.size();i++)
            ui->listUsers->item(i)->setCheckState(Qt::Checked);
    else
        for(int i=0;i<Users.size();i++)
            ui->listUsers->item(i)->setCheckState(Qt::Unchecked);
}

void TypeInfoStructForm::on_checkBoxAllPrograms_stateChanged(int arg1)
{
    if(arg1)
        for(int i=0;i<Programs.size();i++)
            ui->listPrograms->item(i)->setCheckState(Qt::Checked);
    else
        for(int i=0;i<Programs.size();i++)
            ui->listPrograms->item(i)->setCheckState(Qt::Unchecked);
}
