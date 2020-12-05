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
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();
signals:
    void SigLog();

private slots:

    void on_BReg_clicked();

private:
    Ui::LogWindow *ui;
    bool TypeClose;
    void closeEvent (QCloseEvent *event);
};

#endif // LOGWINDOW_H
