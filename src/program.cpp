#include "program.h"

Program::Program()
{

}
void Program::read(const QJsonObject &json)
{
    name = json["name"].toString();
    ID = json["ID"].toInt();
    threadAmount = json["threadAmount"].toInt();
    cpuUsage = json["cpuUsage"].toDouble();
    ramUsage = json["ramUsage"].toInt();
}

/*
    QString name;
    int ID;
    int threadAmount;
    double cpuUsage;
    int ramUsage;
  */
