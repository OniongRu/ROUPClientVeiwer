#ifndef STATISTICSFORM_H
#define STATISTICSFORM_H

#include <QWidget>
#include <QCompleter>
#include <QMessageBox>
#include <QChart>
#include <QtCharts>
#include <QChartView>
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <Objects/usermanager.h>
namespace Ui {
class StatisticsForm;
}

class StatisticsForm : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsForm(QWidget *parent = nullptr, UserManager *Data=nullptr);
    ~StatisticsForm();

private slots:
    void on_pushButton_showStatistic_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_info_clicked();

    void on_pushButton_backStatistic_clicked();

private:
    Ui::StatisticsForm *ui;
    UserManager *Data;
    QCompleter *compliterAvaliblePrograms;
    QLineSeries *series;
    QChart *chart;
    void initInfoPage();
    void initCompliter();
    void initStatisticPage(QString programName);
};

#endif // STATISTICSFORM_H
