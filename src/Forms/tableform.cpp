#include "tableform.h"
#include "ui_tableform.h"

TableForm::TableForm(QWidget *parent,UserManager *Data) :
    QWidget(parent),
    ui(new Ui::TableForm)
{
    ui->setupUi(this);
    this->Data = Data;
    CreateTable();
}

TableForm::~TableForm()
{
    delete ui;
}

void TableForm::CreateTable()
{
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
    ui->tableWidget->setRowCount(RowSize);
    ui->tableWidget->setColumnCount(5);
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
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("ProgramID"));
            ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem(QString::number(Data->Users[i].Programs[j].ID)));
            RowCurrent++;
            ui->tableWidget->setItem(RowCurrent,1,new QTableWidgetItem("Hours"));
            for(int k=0;k<Data->Users[i].Programs[j].HourSize;k++)
            {
                ui->tableWidget->setItem(RowCurrent,2,new QTableWidgetItem("creationDate"));
                ui->tableWidget->setItem(RowCurrent,3,new QTableWidgetItem(Data->Users[i].Programs[j].Hours[k].creationDate));
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
                RowCurrent++;
            }
        }
    }
}
/*
    QString creationDate; //FIXME change type
    int workTime;
    int activeWindowTime;
    int threadAmount;
    double cpuUsage;
    int ramUsage;

 */
