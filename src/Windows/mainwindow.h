#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>

#include "logwindow.h"
#include "Objects/account.h"
#include "Forms/dataform.h"
#include "Forms/chooseform.h"
#include "Objects/usermanager.h"
#include "Forms/typeinfostructform.h"
#include "Forms/tableform.h"
#include <QProgressDialog>
//#include "Tests/testentiretydata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSokConnected();
    void onSokReadyRead();
    void onSokDisconnected();
    void onSokErrorConnect(QAbstractSocket::SocketError socketError);

    void on_AddTab_clicked();

    void on_tabWidget_tabCloseRequested(int index);



    void on_tabWidget_tabBarDoubleClicked(int index);

private:
    Ui::MainWindow *ui;
    QTcpSocket *Client = nullptr;
    LogWindow *Log;
    //UserManager *Data;
    std::vector<QString>Users;
    std::vector<QString>Programs;
    Account *myaccount;

    void LogSuccessful();

    bool LogInStatus = false;

    //TestEntiretyData *UnitTest = nullptr;
    //QProgressDialog d;
    //MyAccount *CurrentAccount;
};

#endif // MAINWINDOW_H
