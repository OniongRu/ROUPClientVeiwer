#ifndef TABLEFORM_H
#define TABLEFORM_H

#include <QWidget>
#include "Objects/usermanager.h"
namespace Ui {
class TableForm;
}

class TableForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableForm(QWidget *parent = nullptr, UserManager *Data=nullptr);
    ~TableForm();

private:
    Ui::TableForm *ui;
    UserManager *Data;
    void CreateTable();
};

#endif // TABLEFORM_H
