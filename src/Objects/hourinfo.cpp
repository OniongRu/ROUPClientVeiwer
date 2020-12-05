#include "hourinfo.h"

HourInfo::HourInfo()
{

}

void HourInfo::read(const QJsonObject &json)
{
    creationDate =json["creationDate"].toString();
    workTime = json["workTime"].toString().toInt();
    activeWindowTime = json["activeWindowTime"].toString().toInt();
    threadAmount = json["threadAmount"].toString().toInt();
    cpuUsage = json["cpuUsage"].toString().toDouble();
    ramUsage = json["ramUsage"].toString().toInt();
}
