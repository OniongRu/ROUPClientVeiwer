#ifndef USER_H
#define USER_H
#include <QString>
#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>
#include "program.h"

#include <QtNetwork/QTcpSocket>
#include <QNetworkAccessManager>
class User
{
public:
    User();
    QString userName;
    int ID;
    int ProgramSize;
    Program *Programs;
    void read(const QJsonObject &json);

    User& operator=(const User& right) {
            //проверка на самоприсваивание
            if (this == &right) {
                return *this;
            }
            ID = right.ID;
            userName = right.userName;
            ProgramSize = right.ProgramSize;
            Programs = new Program[ProgramSize];
            for(int i=0;i<ProgramSize;i++)
                Programs[i] = right.Programs[i];
            return *this;
        }
};

#endif // USER_H
