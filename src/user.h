#ifndef USER_H
#define USER_H
#include <QString>
#include <QMainWindow>
#include "tablewindow.h"
#include <QJsonObject>
#include <QJsonArray>
#include "program.h"
#include <vector>
class User
{
public:
    User();
    int ProgArrSize;
    QString userName;
    QString creationDate;
    QString activeWindowProcessName;
    Program *Programs;
    void read(const QJsonObject &json);
};

#endif // USER_H
