#ifndef HOURINFO_H
#define HOURINFO_H
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QtNetwork/QTcpSocket>
#include <QNetworkAccessManager>
class HourInfo
{
public:
    HourInfo();
    //TODO add methods
    QDateTime creationDate; //FIXME change type
    int workTime;
    int activeWindowTime;
    int threadAmount;
    double cpuUsage;
    int ramUsage;
    void read(const QJsonObject &json);

    HourInfo& operator=(const HourInfo& right) {
            //проверка на самоприсваивание
            if (this == &right) {
                return *this;
            }
            creationDate = right.creationDate;
            workTime = right.workTime;
            activeWindowTime = right.activeWindowTime;
            threadAmount = right.threadAmount;
            cpuUsage = right.cpuUsage;
            ramUsage = right.ramUsage;
            return *this;
        }
};

#endif // HOURINFO_H
