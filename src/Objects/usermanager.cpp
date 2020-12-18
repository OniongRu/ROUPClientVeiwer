#include "usermanager.h"

UserManager::UserManager()
{

}

void UserManager::read(const QJsonObject &json)
{
    QJsonArray Array_Users = json["users"].toArray();
    UserSize = Array_Users.size();
    Users = new User[UserSize];
    int el_num = 0;
    foreach(const QJsonValue & value, Array_Users)
    {
        QJsonObject obj = value.toObject();
        Users[el_num].read(obj);
        el_num++;
    }
}

 void UserManager::initAvalibleProgram()
 {
     if(UserSize==0)
         return;
     for(int i=0;i<UserSize;i++)
     {
         for(int j=0;j<Users[i].ProgramSize;j++)
            {
             if(AvalibleProgram.size()==0)
                AvalibleProgram.push_back(Users[i].Programs[j].programName);
             else
             {
                 bool ConditionExclusiveName=true;
                 for(int k=0;k<AvalibleProgram.size();k++)
                 {
                     if(AvalibleProgram[k]==Users[i].Programs[j].programName)
                     {
                         ConditionExclusiveName=false;
                         break;
                     }
                 }
                 if(ConditionExclusiveName) AvalibleProgram.push_back(Users[i].Programs[j].programName);
             }
            }
     }
 }
void UserManager::initTimeBorders()
{
    StartDate = QDateTime::fromString("23:59:59, 20.12.2100","HH:mm:ss, dd.MM.yyyy");
    EndDate = QDateTime::fromString("23:59:59, 20.12.2000","HH:mm:ss, dd.MM.yyyy");
    qDebug()<<StartDate.toString("HH:mm:ss, dd.MM.yyyy");
    if(UserSize==0)
        return;
    for(int i=0;i<UserSize;i++)
    {
        for(int j=0;j<Users[i].ProgramSize;j++)
        {
           for(int k=0;k<Users[i].Programs[j].HourSize;k++)
           {
               if(Users[i].Programs[j].Hours[k].creationDate>EndDate)
                   EndDate = Users[i].Programs[j].Hours[k].creationDate;
               if(Users[i].Programs[j].Hours[k].creationDate<StartDate)
                   StartDate = Users[i].Programs[j].Hours[k].creationDate;
           }
        }
    }

}
