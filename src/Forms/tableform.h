#ifndef TABLEFORM_H
#define TABLEFORM_H

#include <QWidget>
#include <QCompleter>
#include <QMessageBox>
#include <algorithm>
#include <QTextDocument>
#include <QPrinter>
#include <QTextTableCell>
#include "Objects/usermanager.h"
#include "Objects/account.h"
namespace Ui {
class TableForm;
}

class TableForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableForm(QWidget *parent = nullptr, UserManager *Data=nullptr);
    ~TableForm();

private slots:
    void on_pushButtonUserSearch_clicked();

    void on_pushButtonProgramSearch_clicked();

    void on_pushButtonUseFilter_clicked();

    void on_pushButtonShowAll_clicked();

    void on_checkBoxUsers_stateChanged(int arg1);

    void on_checkBoxPrograms_stateChanged(int arg1);

    void on_pushButtonSavePDF_clicked();

private:
    Ui::TableForm *ui;
    UserManager *Data;
    QCompleter *compliterAvalibleUsers;
    QCompleter *compliterAvaliblePrograms;
    void CreateTable();
    void InitFilter();
    void InitCompliter();
    void PrintCellsDecs(int row, int offsetRow,int string, int offsetString, int colorIndex);
};

#endif // TABLEFORM_H
