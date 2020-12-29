#ifndef TYPEINFOSTRUCTFORM_H
#define TYPEINFOSTRUCTFORM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <Objects/account.h>
#include <QJsonArray>
namespace Ui {
class TypeInfoStructForm;
}

class TypeInfoStructForm : public QWidget
{
    Q_OBJECT

public:
    explicit TypeInfoStructForm(QWidget *parent = nullptr, const std::vector<QString> &Users = {}, const std::vector<QString> &Programs = {}, QTcpSocket *Client=NULL, Account *myaccount=nullptr, QString *typeData=nullptr);
    ~TypeInfoStructForm();
    void meme(std::vector<QString>&m);

private slots:
    void on_buttonSendJson_clicked();

    void on_checkBoxAllUsers_stateChanged(int arg1);

    void on_checkBoxAllPrograms_stateChanged(int arg1);

private:
    Ui::TypeInfoStructForm *ui;
    std::vector<QString> Users;
    std::vector<QString> Programs;
    QTcpSocket *Client;
    QString login;
    QString password;
    QString *typeData;
    void InitUsers();
    void InitProgrmas();
    void InitTypes();

};

#endif // TYPEINFOSTRUCTFORM_H
