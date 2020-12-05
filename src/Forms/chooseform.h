#ifndef CHOOSEFORM_H
#define CHOOSEFORM_H

#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
class ChooseForm;
}

class ChooseForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseForm(QWidget *parent = nullptr);
    ~ChooseForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    int i;
    Ui::ChooseForm *ui;
};

#endif // CHOOSEFORM_H
