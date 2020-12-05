#include "chooseform.h"
#include "ui_chooseform.h"

ChooseForm::ChooseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseForm)
{
    ui->setupUi(this);
    i=0;
}

ChooseForm::~ChooseForm()
{
    delete ui;
}

void ChooseForm::on_pushButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText("item "+QString::number(i));
    item->setCheckState(Qt::Unchecked);
    i++;
    ui->listWidget->addItem(item);
}

void ChooseForm::on_pushButton_2_clicked()
{
    int size = ui->listWidget->count();
    QListWidgetItem *item = new QListWidgetItem[size];
    for(int i=0;i<size;i++)
    {
        if(ui->listWidget->item(i)->checkState())
            item[i].setText("good "+QString::number(i));
        else
            item[i].setText("bad "+QString::number(i));
    }
    /*ui->listWidget->blockSignals(true);*/
    ui->listWidget->clear(); //FIXME
    for(int i=0;i<size;i++)
    {
        ui->listWidget->addItem(&item[i]);
    }
}

void ChooseForm::on_pushButton_3_clicked()
{
    int size = ui->listWidget->count();
    for(int i=0;i<size;i++)
        ui->listWidget->item(i)->setCheckState(Qt::Checked);
}
