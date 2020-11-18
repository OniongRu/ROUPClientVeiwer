#ifndef TESTJSON_H
#define TESTJSON_H
#include <QString>
#include <QMainWindow>
#include "tablewindow.h"
class TestJson
{
public:
    QString name;
    int age;
    int data[2][2];
    TestJson();
    void Show();
    void read(const QJsonObject &json);
};

#endif // TESTJSON_H
