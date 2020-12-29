#include "tableform.h"
#include "ui_tableform.h"

TableForm::TableForm(QWidget *parent,UserManager *Data) :
    QWidget(parent),
    ui(new Ui::TableForm)
{
    ui->setupUi(this);
    this->Data = Data;
    CreateTable();
    this->Data->initAvalibleProgram();
    this->Data->initTimeBorders();
    InitFilter();
    InitCompliter();
}

TableForm::~TableForm()
{
    delete ui;
}

void TableForm::CreateTable()
{
    QColor* orangeColor =new QColor(245,133,86,150);

    int RowSize=0;
    for(int i=0;i<Data->UserSize;i++)
    {
        RowSize+=2;
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {
            RowSize+=2;
            RowSize+=Data->Users[i].Programs[j].HourSize*6;
        }
    }
    ui->label_filter->setStyleSheet("background-color: rgb(255, 99, 99); border: 1px solid black");
    ui->label_filter->setText("Filters inactive");
    ui->tableWidget->setRowCount(RowSize);
    ui->tableWidget->setColumnCount(4);
    int RowCurrent=0;
    for(int i=0;i<Data->UserSize;i++)
    {
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserName"));
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(Data->Users[i].userName));

        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserID"));
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(QString::number(Data->Users[i].ID)));
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("Programs"));
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {

            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramName"));            
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(Data->Users[i].Programs[j].programName));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramID"));
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].ID)));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("Hours"));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            for(int k=0;k<Data->Users[i].Programs[j].HourSize;k++)
            {


                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("creationDate"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(Data->Users[i].Programs[j].Hours[k].creationDate.toString("HH:mm:ss, dd.MM.yyyy")));

                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("workTime"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].workTime)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("activeWindowTime"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].activeWindowTime)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("threadAmount"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].threadAmount)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("cpuUsage"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].cpuUsage)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("ramUsage"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].ramUsage)));
                PrintCellsDecs(RowCurrent,6,2,2,k%2);
                RowCurrent++;


            }
        }
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    delete orangeColor;
}


void TableForm::InitFilter()
{

            for(int i=0;i<Data->UserSize;i++)
            {
                ui->listWidgetUsers->addItem(new QListWidgetItem(Data->Users[i].userName));
                ui->listWidgetUsers->item(i)->setCheckState(Qt::Unchecked);
            }
            for(int i=0;i<Data->AvalibleProgram.size();i++)
            {
                ui->listWidgetProgram->addItem(new QListWidgetItem(Data->AvalibleProgram[i]));
                ui->listWidgetProgram->item(i)->setCheckState(Qt::Unchecked);
            }
            ui->dateTimeEditStart->setMaximumDateTime(Data->EndDate);
            ui->dateTimeEditStart->setMinimumDateTime(Data->StartDate);
            ui->dateTimeEditEnd->setMaximumDateTime(Data->EndDate);
            ui->dateTimeEditEnd->setMinimumDateTime(Data->StartDate);
            ui->dateTimeEditStart->setDateTime(Data->StartDate);
            ui->dateTimeEditEnd->setDateTime(Data->EndDate);
}

void TableForm::InitCompliter()
{
    QStringList keywordsUser;
    QStringList keywordsProgram;
    for(int i=0;i<Data->UserSize;i++)
        keywordsUser<<Data->Users[i].userName;
    for(int i=0;i<Data->AvalibleProgram.size();i++)
        keywordsProgram<<Data->AvalibleProgram[i];
    compliterAvalibleUsers = new QCompleter(keywordsUser, this);
    compliterAvaliblePrograms = new QCompleter(keywordsProgram, this);
    compliterAvalibleUsers->setCaseSensitivity(Qt::CaseInsensitive);
    compliterAvaliblePrograms->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEditUserSearch->setCompleter(compliterAvalibleUsers);
    ui->lineEditProgramSearch->setCompleter(compliterAvaliblePrograms);

}
//https://www.youtube.com/watch?v=u6PeXMNI5iY&ab_channel=%D0%9B%D0%B5%D0%B2%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B5%D0%B5%D0%B2%D1%81%D0%BA%D0%B8%D0%B9

void TableForm::on_pushButtonUserSearch_clicked()
{
    QColor* orangeColor =new QColor(245,133,86,150);

    QString desiredUser = ui->lineEditUserSearch->text();
    int desiredUserID=0;
    bool conditionUserExist = false;
    for(int i = 0; i<Data->UserSize;i++)
    {
        if(Data->Users[i].userName==desiredUser)
        {
            conditionUserExist = true;
            desiredUserID = i;
            break;
        }
    }
    if(!conditionUserExist)
    {
        QMessageBox::warning(this, "Wrong name","Данного пользователя несуществует.\n Введите другое имя.");
        return;
    }
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(1);
    int RowSize=2;
    for(int i=0;i<Data->Users[desiredUserID].ProgramSize;i++)
    {
        RowSize+=2;
        RowSize+=Data->Users[desiredUserID].Programs[i].HourSize*6;
    }
    ui->tableWidget->setRowCount(RowSize);
    ui->tableWidget->setColumnCount(4);
    int RowCurrent=0;
    ui->label_filter->setStyleSheet("background-color: rgb(66, 255, 145); border: 1px solid black");
    ui->label_filter->setText("Filters active");
    ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserName"));
    ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(Data->Users[desiredUserID].userName));
    RowCurrent++;
    ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserID"));
    ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].ID)));
    RowCurrent++;
    ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("Programs"));
    for(int j=0;j<Data->Users[desiredUserID].ProgramSize;j++)
    {

        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramName"));
        ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(Data->Users[desiredUserID].Programs[j].programName));
        ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
        ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
        ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
        ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramID"));
        ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].Programs[j].ID)));
        ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
        ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
        ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
        ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("Hours"));
        ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
        for(int k=0;k<Data->Users[desiredUserID].Programs[j].HourSize;k++)
        {
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("creationDate"));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(Data->Users[desiredUserID].Programs[j].Hours[k].creationDate.toString("HH:mm:ss, dd.MM.yyyy")));
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("workTime"));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].Programs[j].Hours[k].workTime)));
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("activeWindowTime"));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].Programs[j].Hours[k].activeWindowTime)));
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("threadAmount"));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].Programs[j].Hours[k].threadAmount)));
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("cpuUsage"));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].Programs[j].Hours[k].cpuUsage)));
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("ramUsage"));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[desiredUserID].Programs[j].Hours[k].ramUsage)));
            PrintCellsDecs(RowCurrent,6,2,2,k%2);
            RowCurrent++;
        }
    }

    delete orangeColor;
}

void TableForm::on_pushButtonProgramSearch_clicked()
{    
    QColor* orangeColor =new QColor(245,133,86,150);

    QString desiredProgram = ui->lineEditProgramSearch->text();
    bool conditionProgramExist = false;
    for(int i = 0; i<Data->AvalibleProgram.size();i++)
    {
        if(Data->AvalibleProgram[i]==desiredProgram)
        {
            conditionProgramExist = true;
            break;
        }
    }
    if(!conditionProgramExist)
    {
        QMessageBox::warning(this, "Wrong program","Данной программы нет у пользоватей.\n Введите другое название.");
        return;
    }
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(1);
    ui->label_filter->setStyleSheet("background-color: rgb(66, 255, 145); border: 1px solid black");
    ui->label_filter->setText("Filters active");
    int RowSize=0;
    for(int i=0;i<Data->UserSize;i++)
    {
        RowSize+=2;
        int conditionUserHasProgram=false;
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {
            if(Data->Users[i].Programs[j].programName==desiredProgram)
            {
                RowSize+=2;
                RowSize+=Data->Users[i].Programs[j].HourSize*6;
                conditionUserHasProgram = true;
            }
        }
        if(!conditionUserHasProgram)
            RowSize-=2;
    }


    ui->tableWidget->setRowCount(RowSize);
    ui->tableWidget->setColumnCount(4);
    int RowCurrent=0;
    for(int i=0;i<Data->UserSize;i++)
    {
        int conditionUserHasProgram=false;
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
            if(Data->Users[i].Programs[j].programName==desiredProgram)
                conditionUserHasProgram = true;
        if(!conditionUserHasProgram)
            continue;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserName"));
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(Data->Users[i].userName));
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserID"));
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(QString::number(Data->Users[i].ID)));
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("Programs"));
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {
            if(Data->Users[i].Programs[j].programName!=desiredProgram)
                continue;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramName"));
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(Data->Users[i].Programs[j].programName));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramID"));
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].ID)));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("Hours"));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            for(int k=0;k<Data->Users[i].Programs[j].HourSize;k++)
            {
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("creationDate"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(Data->Users[i].Programs[j].Hours[k].creationDate.toString("HH:mm:ss, dd.MM.yyyy")));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("workTime"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].workTime)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("activeWindowTime"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].activeWindowTime)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("threadAmount"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].threadAmount)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("cpuUsage"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].cpuUsage)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("ramUsage"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].ramUsage)));
                PrintCellsDecs(RowCurrent,6,2,2,k%2);
                RowCurrent++;
            }
        }
    }


    delete orangeColor;
}


void TableForm::on_pushButtonUseFilter_clicked()
{

    QColor* orangeColor =new QColor(245,133,86,150);

    std::vector <QString> desiredUsers;
    std::vector <QString> desiredPrograms;
    bool ZeroCondition = false;
    for(int i=0;i<Data->UserSize;i++)
    {
        if(ui->listWidgetUsers->item(i)->checkState())
        {
            desiredUsers.push_back(ui->listWidgetUsers->item(i)->text());
            ZeroCondition=true;
        }
    }
    if(!ZeroCondition)
    {
        QMessageBox::warning(this, "Wrong users","Выберите хотя бы одного пользователя");
        return;
    }
    ZeroCondition = false;
    for(int i=0;i<Data->AvalibleProgram.size();i++)
    {
        if(ui->listWidgetProgram->item(i)->checkState())
        {
            desiredPrograms.push_back(ui->listWidgetProgram->item(i)->text());
            ZeroCondition=true;
        }
    }
    if(!ZeroCondition)
    {
        QMessageBox::warning(this, "Wrong programs","Выберите хотя бы одну программу");
        return;
    }
    QDateTime timeStart = ui->dateTimeEditStart->dateTime();
    QDateTime timeEnd = ui->dateTimeEditEnd->dateTime();
    if(timeStart>timeEnd)
    {
        QMessageBox::warning(this, "Wrong dates","Дата начала < Дата конца");
        return;
    }
    int RowSize=0;
    for(int i=0;i<Data->UserSize;i++)
    {
        if(std::find(desiredUsers.begin(), desiredUsers.end(), Data->Users[i].userName) == desiredUsers.end())
            continue;
        bool conditionProgramsExist = false;
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {
            if(std::find(desiredPrograms.begin(),desiredPrograms.end(),Data->Users[i].Programs[j].programName) == desiredPrograms.end() )
                continue;

            bool conditionHoursExist = false;
            for(int k=0; k<Data->Users[i].Programs[j].HourSize;k++)
                if((Data->Users[i].Programs[j].Hours[k].creationDate>=timeStart)&&(Data->Users[i].Programs[j].Hours[k].creationDate<=timeEnd))
                {
                    RowSize+=6;
                    conditionHoursExist = true;
                }
            if(conditionHoursExist)
            {
                RowSize+=2;
                conditionProgramsExist = true;
            }
        }
        if(conditionProgramsExist)
            RowSize+=2;
    }
    if(RowSize==0)
    {
        QMessageBox::warning(this, "Wrong data","Нет результата для данного фильтра");
        return;
    }
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(1);
    ui->label_filter->setStyleSheet("background-color: rgb(66, 255, 145); border: 1px solid black");
    ui->label_filter->setText("Filters active");
    ui->tableWidget->setRowCount(RowSize);
    ui->tableWidget->setColumnCount(4);
    int RowCurrent=0;
    for(int i=0;i<Data->UserSize;i++)
    {
        if(std::find(desiredUsers.begin(), desiredUsers.end(), Data->Users[i].userName) == desiredUsers.end())
            continue;
        bool conditionExistPrograms = false;
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {
            if(std::find(desiredPrograms.begin(),desiredPrograms.end(),Data->Users[i].Programs[j].programName)==desiredPrograms.end())
            {
                qDebug()<<Data->Users[i].Programs[j].programName<<" bad";
                continue;
            }
            bool conditionExitsHours = false;
            for(int k=0;k<Data->Users[i].Programs[j].HourSize;k++)
            {
                if((Data->Users[i].Programs[j].Hours[k].creationDate<timeStart)||(Data->Users[i].Programs[j].Hours[k].creationDate>timeEnd))
                    continue;
                conditionExitsHours=true;
                break;
            }
            if(!conditionExitsHours)
            {
                qDebug()<<Data->Users[i].Programs[j].programName<<" bad hours";
                continue;
            }
            conditionExistPrograms=true;
            break;
        }
        if(!conditionExistPrograms)
            continue;

        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserName"));
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(Data->Users[i].userName));
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("UserID"));
        ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem(QString::number(Data->Users[i].ID)));
        RowCurrent++;
        ui->tableWidget->setItem(RowCurrent,0,new QTableWidgetItem("Programs"));
        for(int j=0;j<Data->Users[i].ProgramSize;j++)
        {
            if(std::find(desiredPrograms.begin(),desiredPrograms.end(),Data->Users[i].Programs[j].programName)==desiredPrograms.end())
                continue;
            bool conditionExitsHours = false;
            for(int k=0;k<Data->Users[i].Programs[j].HourSize;k++)
            {
                if((Data->Users[i].Programs[j].Hours[k].creationDate<timeStart)||(Data->Users[i].Programs[j].Hours[k].creationDate>timeEnd))
                    continue;
                conditionExitsHours=true;
                break;
            }
            if(!conditionExitsHours)
                continue;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramName"));
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(Data->Users[i].Programs[j].programName));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramID"));
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].ID)));
            ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(""));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,2)->setBackground(*orangeColor);
            ui->tableWidget->item(RowCurrent,3)->setBackground(*orangeColor);
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("Hours"));
            ui->tableWidget->item(RowCurrent,1)->setBackground(*orangeColor);
            for(int k=0;k<Data->Users[i].Programs[j].HourSize;k++)
            {
                if((Data->Users[i].Programs[j].Hours[k].creationDate<timeStart)||(Data->Users[i].Programs[j].Hours[k].creationDate>timeEnd))
                    continue;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("creationDate"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(Data->Users[i].Programs[j].Hours[k].creationDate.toString("HH:mm:ss, dd.MM.yyyy")));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("workTime"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].workTime)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("activeWindowTime"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].activeWindowTime)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("threadAmount"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].threadAmount)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("cpuUsage"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].cpuUsage)));
                RowCurrent++;
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("ramUsage"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].Hours[k].ramUsage)));
                PrintCellsDecs(RowCurrent,6,2,2,k%2);
                RowCurrent++;
            }
        }
    }

    delete orangeColor;
}

void TableForm::on_pushButtonShowAll_clicked()
{
    ui->lineEditUserSearch->clear();
    ui->lineEditProgramSearch->clear();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(1);
    CreateTable();
}

void TableForm::on_checkBoxUsers_stateChanged(int arg1)
{
    if(arg1)
        for(int i=0;i<Data->UserSize;i++)
            ui->listWidgetUsers->item(i)->setCheckState(Qt::Checked);
    else
        for(int i=0;i<Data->UserSize;i++)
            ui->listWidgetUsers->item(i)->setCheckState(Qt::Unchecked);
}

void TableForm::on_checkBoxPrograms_stateChanged(int arg1)
{
    if(arg1)
        for(int i=0;i<Data->AvalibleProgram.size();i++)
            ui->listWidgetProgram->item(i)->setCheckState(Qt::Checked);
    else
        for(int i=0;i<Data->AvalibleProgram.size();i++)
            ui->listWidgetProgram->item(i)->setCheckState(Qt::Unchecked);
}


void TableForm::PrintCellsDecs(int row, int offsetRow,int string, int offsetString, int colorIndex){
    QColor** colors= new QColor*[2];
    colors[0]= new QColor(86,245,160,150);
    colors[1]= new QColor(86,180,245,150);


    int minRow=row-offsetRow;
    int maxString=string+offsetString;
    for(;row>minRow;row--){
        for(int bufferString=string ;bufferString<maxString;bufferString++)
        {
            ui->tableWidget->item(row, bufferString)->setBackground(*colors[colorIndex]);
        }
    }
    delete colors[0];
    delete colors[1];
    delete [] colors;
}

void TableForm::on_pushButtonSavePDF_clicked()
{
    const int columns = ui->tableWidget->columnCount();
    const int rows = ui->tableWidget->rowCount();
    QTextDocument doc;
    QTextCursor cursor(&doc);
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setCellPadding(0);
    tableFormat.setCellSpacing(0);
    tableFormat.setBorder(1);
    tableFormat.setBorderBrush(QBrush(Qt::SolidPattern));
    tableFormat.clearColumnWidthConstraints();
    QTextTable *textTable = cursor.insertTable(rows + 1, columns, tableFormat);
    QTextCharFormat tableHeaderFormat;
    tableHeaderFormat.setBackground(QColor("#DADADA"));
    for (int i = 0; i < columns; i++) {
        QTextTableCell cell = textTable->cellAt(0, i);
        cell.setFormat(tableHeaderFormat);
        QTextCursor cellCursor = cell.firstCursorPosition();
        if(ui->tableWidget->horizontalHeaderItem(i) == 0)
            cellCursor.insertText("");
        else
            cellCursor.insertText(ui->tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString());
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (!item || item->text().isEmpty()) {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(""));
            }

            QTextTableCell cell = textTable->cellAt(i, j);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(ui->tableWidget->item(i, j)->text());
        }
    }
    cursor.movePosition(QTextCursor::End);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    QString FileName = "TableSave"+QDateTime::currentDateTime().toString("HH_mm_ss_dd_MM_yyyy.pdf");
    printer.setOutputFileName(FileName);
    doc.setDocumentMargin(0);
    doc.setTextWidth(12);
    doc.print(&printer);
}
