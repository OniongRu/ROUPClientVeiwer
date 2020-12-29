#include "statisticsform.h"
#include "ui_statisticsform.h"



StatisticsForm::StatisticsForm(QWidget *parent, UserManager *Data) :
    QWidget(parent),
    ui(new Ui::StatisticsForm)
{
    ui->setupUi(this);
    this->Data = Data;
    this->Data->initAvalibleProgram();
    this->Data->initTimeBorders();
    //Init compliterAvaliblePrograms
    initInfoPage();
    initCompliter();
    series = new QLineSeries();
}


void StatisticsForm::initInfoPage()
{
    QString DateInterval = Data->StartDate.toString("HH:mm:ss, dd.MM.yyyy");
    DateInterval+=" - " + Data->EndDate.toString("HH:mm:ss, dd.MM.yyyy");
    ui->label_timeInterval->setText(DateInterval);
    for(int i=0;i<Data->UserSize;i++)
        ui->listWidget_users->addItem(new QListWidgetItem(Data->Users[i].userName));
    for(int i=0;i<Data->AvalibleProgram.size();i++)
        ui->listWidget_programs->addItem(new QListWidgetItem(Data->AvalibleProgram[i]));
}

void StatisticsForm::initCompliter()
{
    QStringList keywordsProgram;
    for(int i=0;i<Data->AvalibleProgram.size();i++)
        keywordsProgram<<Data->AvalibleProgram[i];
    compliterAvaliblePrograms = new QCompleter(keywordsProgram, this);
    compliterAvaliblePrograms->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_programName->setCompleter(compliterAvaliblePrograms);
}

static int randomBetween(int low, int high, int seed)
{
    qsrand(seed); // Установка базового числа для отсчёта рандома в qrand
    return (qrand() % ((high + 1) - low) + low);
}

void StatisticsForm::initStatisticPage(QString programName)
{
    ui->label_programName->setText(programName);
    QDateTime maxT = QDateTime::fromString("23:59:59, 20.12.2000","HH:mm:ss, dd.MM.yyyy");
    QDateTime minT = QDateTime::fromString("23:59:59, 20.12.2100","HH:mm:ss, dd.MM.yyyy");
    int workTime = 0;
    int activeWindowTime = 0;
    double cpuUsage = 0;
    int ramUsage = 0;
    int threadAmount = 0;
    int numberElements = 0;
    double maxCpu = 0;
    QDateTime maxCpuTime = QDateTime::fromString("23:59:59, 20.12.2000","HH:mm:ss, dd.MM.yyyy");
    int maxRam = 0;
    QDateTime maxRamTime = QDateTime::fromString("23:59:59, 20.12.2000","HH:mm:ss, dd.MM.yyyy");
    for(int i=0;i < Data->UserSize;i++)
        for(int j=0;j < Data->Users[i].ProgramSize;j++)
            if(Data->Users[i].Programs[j].programName==programName)
            {
                for(int k=0; k < Data->Users[i].Programs[j].HourSize; k++)
                {
                    numberElements+=Data->Users[i].Programs[j].Hours[k].dataPackCount;
                    workTime += Data->Users[i].Programs[j].Hours[k].workTime;
                    activeWindowTime += Data->Users[i].Programs[j].Hours[k].activeWindowTime;
                    cpuUsage += Data->Users[i].Programs[j].Hours[k].cpuUsage*Data->Users[i].Programs[j].Hours[k].dataPackCount;
                    ramUsage += Data->Users[i].Programs[j].Hours[k].ramUsage*Data->Users[i].Programs[j].Hours[k].dataPackCount;
                    threadAmount += Data->Users[i].Programs[j].Hours[k].threadAmount;
                    if(maxT<Data->Users[i].Programs[j].Hours[k].creationDate)
                        maxT = Data->Users[i].Programs[j].Hours[k].creationDate;
                    if(minT>Data->Users[i].Programs[j].Hours[k].creationDate)
                        minT = Data->Users[i].Programs[j].Hours[k].creationDate;
                    if(maxCpu < Data->Users[i].Programs[j].Hours[k].cpuUsage)
                    {
                        maxCpu = Data->Users[i].Programs[j].Hours[k].cpuUsage;
                        maxCpuTime = Data->Users[i].Programs[j].Hours[k].creationDate;
                    }
                    if(maxRam < Data->Users[i].Programs[j].Hours[k].ramUsage)
                    {
                        maxRam = Data->Users[i].Programs[j].Hours[k].ramUsage;
                        maxRamTime = Data->Users[i].Programs[j].Hours[k].creationDate;
                    }
                }
                break;
            }
    cpuUsage = cpuUsage / numberElements;
    ramUsage = ramUsage / numberElements;
    threadAmount = threadAmount / numberElements;
    ui->label_from->setText(minT.toString("HH:mm:ss, dd.MM.yyyy"));
    ui->label_to->setText(maxT.toString("HH:mm:ss, dd.MM.yyyy"));
    ui->label_worktime->setText(QString::number(workTime));
    ui->label_activeWorkTime->setText(QString::number(activeWindowTime));
    ui->label_CPU->setText(QString::number(cpuUsage));
    ui->label_RAM->setText(QString::number(ramUsage));
    ui->label_thread->setText(QString::number(threadAmount));
    ui->label_maxCpu->setText(QString::number(maxCpu));
    ui->label_maxCpuDate->setText(maxCpuTime.toString("HH:mm:ss, dd.MM.yyyy"));
    ui->label_maxRam->setText(QString::number(maxRam));
    ui->label_maxRamDate->setText(maxRamTime.toString("HH:mm:ss, dd.MM.yyyy"));
    QChartView *chartView = new QChartView(this);
    ui->horizontalLayoutGraphic->addWidget(chartView);
    int seed = 0;
    seed = randomBetween(0, 100, seed);

    int k = 0;
    while (k <= 100)
    {
        *series << QPointF(sin((seed+ k)*0.1), k);
        ++k;
    }
    // Создаём график и добавляем в него синусоиду
    chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Graphic");
    // Добавим всплывающую подсказку для графика
    chart->setToolTip(QString("Количество отсчётов %2").arg(k));
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("x, м");
    axisX->setLabelFormat("%i");
    axisX->setTickCount(1);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("t, мс");
    axisY->setLabelFormat("%g");
    axisY->setTickCount(5);

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    //chartView->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    // Устанавливаем график в представление
    chartView->setChart(chart);
    chart->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

StatisticsForm::~StatisticsForm()
{
    delete ui;
}

void StatisticsForm::on_pushButton_showStatistic_clicked()
{

    QString programName = ui->lineEdit_programName->text();
    bool conditionProgramExist = false;
    for(int i = 0; i<Data->AvalibleProgram.size();i++)
    {
        if(Data->AvalibleProgram[i]==programName)
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
    initStatisticPage(programName);
}

void StatisticsForm::on_pushButton_save_clicked()
{

}

void StatisticsForm::on_pushButton_info_clicked()   //TODO переделать в connect()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void StatisticsForm::on_pushButton_backStatistic_clicked()  //TODO переделать в connect()
{
    ui->stackedWidget->setCurrentIndex(0);
}
