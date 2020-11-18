#include "user.h"

User::User()
{

}
void User::read(const QJsonObject &json)
{
   userName =json["userName"].toString();
   creationDate =json["creationDate"].toString();
   activeWindowProcessName = json["activeWindowProcessName"].toString();
   QJsonArray Array_Programs = json["programs"].toArray();
   ProgArrSize = Array_Programs.size();
   Programs = new Program[ProgArrSize];
   int el_num = 0;
   foreach(const QJsonValue & value, Array_Programs)
   {
       QJsonObject obj = value.toObject();
       Programs[el_num].read(obj);
       el_num++;
   }
}


