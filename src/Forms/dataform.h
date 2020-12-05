#ifndef DATAFORM_H
#define DATAFORM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>

#include "chooseform.h"
//#include "ObjectManager/usermanager.h"

namespace Ui {
class DataForm;
}

class DataForm : public QWidget
{
    Q_OBJECT

public:
    explicit DataForm(QWidget *parent = nullptr);
    ~DataForm();
signals:
    void SigData();
private slots:
    void on_ShowInformation_clicked();

private:
    Ui::DataForm *ui;
    ChooseForm * Form;
};

#endif // DATAFORM_H
