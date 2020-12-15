#include "program.h"

Program::Program()
{

}
void Program::read(const QJsonObject &json)
{
    programName =json["name"].toString();
    ID = json["ID"].toString().toInt();
    QJsonArray Array_Hours = json["HourWork"].toArray();
    HourSize = Array_Hours.size();
    Hours = new HourInfo[HourSize];
    int el_num = 0;
    foreach(const QJsonValue & value, Array_Hours)
    {
        QJsonObject obj = value.toObject();
        Hours[el_num].read(obj);
        el_num++;
    }
}

