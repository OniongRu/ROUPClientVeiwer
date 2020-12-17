#include "graphicform.h"
#include "ui_graphicform.h"

GraphicForm::GraphicForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicForm)
{
    ui->setupUi(this);
}

GraphicForm::~GraphicForm()
{
    delete ui;
}
