#include "usermanager.h"

UserManager::UserManager()
{

}

void UserManager::read(const QJsonObject &json)
{
    QJsonArray Array_Users = json["Users"].toArray();
    UserSize = Array_Users.size();
    Users = new User[UserSize];
    int el_num = 0;
    foreach(const QJsonValue & value, Array_Users)
    {
        QJsonObject obj = value.toObject();
        Users[el_num].read(obj);
        el_num++;
    }
}

