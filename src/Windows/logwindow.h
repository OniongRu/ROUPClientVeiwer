#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QJsonObject>
#include <QThread>
#include <iostream>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QCloseEvent>

namespace Ui {
class LogWindow;
}

class LogWindow : public QMainWindow
{
    Q_OBJECT

public:
    //LogWindow(QTcpSocket * Client, MyAccount * CurrentAccount);
    explicit LogWindow(QWidget *parent = nullptr, QTcpSocket *Client = NULL);
    ~LogWindow();

    void LogAccept();

signals:
    void SigLog();

private slots:
    void on_BReg_clicked();

    void on_BLog_clicked();

    void on_BNext_clicked();

private:
    Ui::LogWindow *ui;
    QTcpSocket *Client;
    bool TypeClose;
    void closeEvent (QCloseEvent *event);
};

#endif // LOGWINDOW_H
