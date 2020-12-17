#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "user.h"
#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtNetwork/QTcpSocket>
#include <QNetworkAccessManager>
#include <QDateTime>
#include <vector>

class UserManager
{
public:
    UserManager();
    int UserSize=0;
    User *Users;
    std::vector<QString> AvalibleProgram;
    QDateTime StartDate=QDateTime::currentDateTime();
    QDateTime EndDate=QDateTime::currentDateTime();
    void read(const QJsonObject &json);
    void initAvalibleProgram();
    void initTimeBorders();


    UserManager& operator=(const UserManager& right) {
            //проверка на самоприсваивание
            if (this == &right) {
                return *this;
            }
            UserSize = right.UserSize;
            Users = new User[UserSize];
            for(int i=0;i<UserSize;i++)
                Users[i] = right.Users[i];
            return *this;
        }
};

#endif // USERMANAGER_H
