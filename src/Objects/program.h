#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include "hourinfo.h"

#include <QtNetwork/QTcpSocket>
#include <QNetworkAccessManager>
class Program
{
public:
    QString programName;
    int ID;
    int HourSize;
    HourInfo *Hours;
    void read(const QJsonObject &json);
    Program();

    Program& operator=(const Program& right) {
            //проверка на самоприсваивание
            if (this == &right) {
                return *this;
            }
            programName = right.programName;
            ID = right.ID;
            HourSize = right.HourSize;
            Hours = new HourInfo[HourSize];
            for(int i=0;i<HourSize;i++)
                Hours[i] = right.Hours[i];
            return *this;
        }
};

#endif // PROGRAM_H
