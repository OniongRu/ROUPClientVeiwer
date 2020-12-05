#ifndef TYPEINFOSTRUCTFORM_H
#define TYPEINFOSTRUCTFORM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>


namespace Ui {
class TypeInfoStructForm;
}

class TypeInfoStructForm : public QWidget
{
    Q_OBJECT

public:
    explicit TypeInfoStructForm(QWidget *parent = nullptr, const std::vector<QString> &Users = {}, const std::vector<QString> &Programs = {}, QTcpSocket *Client=NULL);
    ~TypeInfoStructForm();
    void meme(std::vector<QString>&m);
private slots:
    void on_buttonSendJson_clicked();

private:
    Ui::TypeInfoStructForm *ui;
    std::vector<QString> Users;
    std::vector<QString> Programs;
    QTcpSocket *Client;
    void InitUsers();
    void InitProgrmas();
    void InitTypes();
};

#endif // TYPEINFOSTRUCTFORM_H
