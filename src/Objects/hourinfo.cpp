#include "hourinfo.h"
#include <QDebug>
HourInfo::HourInfo()
{

}

void HourInfo::read(const QJsonObject &json)
{
    QString DateForm = "MMM dd, yyyy, h:m:s AP";
    QLocale mylocale(QLocale::English);
    QString DateStr =json["creationDate"].toString(); //"Nov 18, 2020, 8:54:32 PM"
    creationDate = mylocale.toDateTime(DateStr,DateForm);
    //qDebug()<<DateStr<<" "<<creationDate.toString(DateForm);
    workTime = json["workTime"].toString().toInt();
    activeWindowTime = json["activeWindowTime"].toString().toInt();
    threadAmount = json["threadAmount"].toString().toInt();
    cpuUsage = json["cpuUsage"].toString().toDouble();
    ramUsage = json["ramUsage"].toString().toInt();
}

//https://ravesli.com/urok-3-data-i-vremya-v-qt5/#toc-0
