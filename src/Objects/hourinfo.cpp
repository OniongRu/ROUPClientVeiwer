#include "hourinfo.h"
#include <QDebug>
HourInfo::HourInfo()
{

}

void HourInfo::read(const QJsonObject &json)
{
    QString DateForm = "dd.MM.yyyy, HH:mm";
    QLocale mylocale(QLocale::English);
    QString DateStr =json["creationDate"].toString(); //"18.12.2020, 14:00"
    creationDate = mylocale.toDateTime(DateStr,DateForm);
    dataPackCount = json["dataPackCount"].toInt();
    //qDebug()<<DateStr<<" "<<creationDate.toString(DateForm);
    workTime = json["timeSum"].toInt();
    activeWindowTime = json["timeActSum"].toInt();
    QJsonObject resource = json["resource"].toObject();
    threadAmount = resource["threadAmount"].toInt();
    cpuUsage = resource["cpuUsage"].toDouble();
    ramUsage = resource["ramUsage"].toInt();
}

//https://ravesli.com/urok-3-data-i-vremya-v-qt5/#toc-0
