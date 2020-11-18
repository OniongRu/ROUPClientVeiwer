#include "testjson.h"
#include <QJsonObject>
#include <QJsonArray>
TestJson::TestJson()
{

}

void TestJson::Show()
{
   qDebug()<<name<<" "<<age<<"\n";
}

void TestJson::read(const QJsonObject &json)
{
    name = json["name"].toString();
    age = json["age"].toString().toInt();
    QJsonArray ar_data = json["data"].toArray();
    int i=0;
    foreach(const QJsonValue & value, ar_data)
    {
        QJsonObject obj = value.toObject();
        data[i][0] = obj["data0"].toString().toInt();
        data[i][1] = obj["data1"].toString().toInt();
        i++;
    }
}
