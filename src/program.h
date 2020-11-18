#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
class Program
{
public:
    QString name;
    int ID;
    int threadAmount;
    double cpuUsage;
    int ramUsage;
    void read(const QJsonObject &json);
    Program();
};

#endif // PROGRAM_H
