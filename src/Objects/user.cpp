#include "user.h"

User::User()
{

}
void User::read(const QJsonObject &json)
{
   userName =json["name"].toString();
   ID = json["ID"].toString().toInt();
   qDebug() << ID << endl;
   QJsonArray Array_Programs = json["programs"].toArray();
   ProgramSize = Array_Programs.size();
   Programs = new Program[ProgramSize];
   int el_num = 0;
   foreach(const QJsonValue & value, Array_Programs)
   {
       QJsonObject obj = value.toObject();
       Programs[el_num].read(obj);
       el_num++;
   }
}
