#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include "user.h"
namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();
signals:
    void SigTable();

private slots:

//определим слоты для обработки сигналов сокета
    void onSokConnected();

    void onSokReadyRead();

    void on_ToMenu_clicked();
    void on_TakeInfo_clicked();

private:
    Ui::TableWindow *ui;
    QTcpSocket *Client;
};

#endif // TABLEWINDOW_H
