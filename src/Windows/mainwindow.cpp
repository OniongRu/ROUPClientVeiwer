#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentWidget(new DataForm());
    Log = new LogWindow();
    connect(Log, &LogWindow::SigLog, this, &MainWindow::Test);
    Client = new QTcpSocket();
    connect(Client, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(Client, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(Client, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    this->setEnabled(0);
    Log->setWindowFlags(Qt::WindowStaysOnTopHint);
    Log->show();
    //FIXME delete 4 tests
    Users.push_back("Goose");
    Users.push_back("Sportorg");
    Users.push_back("JoJo");
    Programs.push_back("Discord");
    Programs.push_back("Wakanim");
    Programs.push_back("DarkSouls");
}




void MainWindow::onSokConnected()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    QString m = "flag1";
    out << quint16(0) << m;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    Client->write(arrBlock);
}

void MainWindow::onSokReadyRead()
{
    QJsonObject obj;
    QString data = Client->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if(doc.isObject())
     {
         obj = doc.object();
     }
    UserManager *Data = new UserManager();
    Data->read(obj);

    qDebug()<<data;
    QWidget *container = ui->tabWidget->currentWidget();
    QWidget *old_content = dynamic_cast<QWidget*>(container->children()[0]);
    delete old_content;
    QWidget *new_content = new TableForm(container,Data);
    container->layout()->addWidget(new_content);
    new_content->show();
}

void MainWindow::onSokDisconnected()
{
    //отображение ошибки в любом window и требование переподключиться к серверу ил ret 0
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddTab_clicked()
{
    QWidget *container = new QWidget;
    //QPalette Pal(palette()); Pal.setColor(QPalette::Background, Qt::green); container->setAutoFillBackground(true); container->setPalette(Pal);
    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(new TypeInfoStructForm(container,Users,Programs,Client));
    container->setLayout(hlayout);
    ui->tabWidget->addTab(container, QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    //DataForm *content = new DataForm(container);

    //content->show();
    /*ui->tabWidget->addTab(new DataForm(), QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);*/
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::Test()
{
    this->setEnabled(1);
    int Hport = 5020;
    const QString addr = "127.0.0.1";
    Client->connectToHost(addr,Hport);
}

void MainWindow::on_pushButton_clicked()
{

    QWidget *container = ui->tabWidget->currentWidget();
    QWidget *old_content = dynamic_cast<QWidget*>(container->children()[0]);
    delete old_content;
    QWidget *new_content = new ChooseForm(container);
    container->layout()->addWidget(new_content);
    new_content->show();

}
