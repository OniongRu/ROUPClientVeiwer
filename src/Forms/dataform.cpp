#include "dataform.h"
#include "ui_dataform.h"

DataForm::DataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataForm)
{
    ui->setupUi(this);
}

DataForm::~DataForm()
{
    delete ui;
}

void DataForm::on_ShowInformation_clicked()
{
    this->close();
}
