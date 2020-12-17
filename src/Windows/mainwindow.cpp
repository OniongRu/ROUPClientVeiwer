#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSignalBlocker>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentWidget(new DataForm());

    this->setEnabled(0);

    Client = new QTcpSocket();
    connect(Client, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(Client, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(Client, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(Client, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSokErrorConnect(QAbstractSocket::SocketError)));
    //qt.15 ->errorOccurred(QAbstractSocket::SocketError socketError) -> при подключении

    Log = new LogWindow(nullptr, Client);
    connect(Log, &LogWindow::SigLog, this, &MainWindow::LogSuccessful);
    Log->setWindowFlags(Qt::WindowStaysOnTopHint);
    Log->show();
    //UnitTest = new TestEntiretyData();


}


void MainWindow::onSokErrorConnect(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"Error";
    if(socketError==QAbstractSocket::ConnectionRefusedError)
    {
        if(!LogInStatus)
            {
                Log->setEnabled(0);
                Log->hide();
            }
            this->setEnabled(0);
            qDebug()<<"Error";
            QMessageBox MsgNoConnection;
            MsgNoConnection.setText("Can't connect to server\nRetry connect?");
            MsgNoConnection.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
            MsgNoConnection.setIcon(QMessageBox::Critical);
            MsgNoConnection.setDefaultButton(QMessageBox::No);
            int res = MsgNoConnection.exec();
            if (res == QMessageBox::Ok)
            {
                int Hport = 5020;
                const QString addr = "127.0.0.1";
                Client->connectToHost(addr,Hport);
            }
            else
            {
                qApp->quit();
            }
            if(!LogInStatus)
                Log->show();
    }

}

void MainWindow::onSokConnected()
{
    qDebug()<<"Connect";
    if(!LogInStatus)
        Log->setEnabled(1);
    else
        this->setEnabled(1);
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    QString m = "flag1";
    out << quint16(0) << qUtf8Printable(m);
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    Client->write(arrBlock);
}

void MainWindow::onSokReadyRead()
{
    qDebug()<<"ReadJson\n";
    QJsonObject obj;
    QString data = Client->readAll();
    qDebug()<<data;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if(doc.isObject())
    {
        obj = doc.object();
    }
    int OpType = obj["OpType"].toString().toInt();
    if(OpType==0)
    {
        int Accept = obj["accept"].toInt();
        if(Accept==0)
        {
             Log->statusBar()->showMessage("Wrong log data");
        }
        else if(Accept==1)
        {
            QJsonArray Array_Users = obj["users"].toArray();
            QJsonArray Array_Programs = obj["programs"].toArray();
            foreach(const QJsonValue & value, Array_Users)
                Users.push_back(value.toString());
            foreach(const QJsonValue & value, Array_Programs)
                Programs.push_back(value.toString());
            Log->accountInfo(myaccount);
            Log->LogAccept();
        }
    }
    if(OpType==1)
    {
        qDebug()<<"ReadBigJson\n";
        UserManager *Data = new UserManager();
        Data->read(obj);
        QWidget *container = ui->tabWidget->currentWidget();
        QWidget *old_content = dynamic_cast<QWidget*>(container->children()[0]);
        delete old_content;
        QWidget *new_content = new TableForm(container, Data);
        container->layout()->addWidget(new_content);
        new_content->show();
    }

}

void MainWindow::onSokDisconnected()
{
     qDebug()<<"Disconnect";

    //отображение ошибки в любом window и требование переподключиться к серверу ил ret 0
    if(!LogInStatus)
    {
        Log->setEnabled(0);
        Log->hide();
    }

    this->setEnabled(0);
    QMessageBox MsgDisconnect;
    MsgDisconnect.setText("Disconnect from server\nRetry connect?");
    MsgDisconnect.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
    MsgDisconnect.setIcon(QMessageBox::Critical);
    MsgDisconnect.setDefaultButton(QMessageBox::No);
    int res = MsgDisconnect.exec();
    if (res == QMessageBox::Ok)
    {
        int Hport = 5020;
        const QString addr = "127.0.0.1";
        Client->connectToHost(addr,Hport);
    }
    else
    {
        qApp->quit();
    }
    if(!LogInStatus)
        Log->show();
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
    hlayout->addWidget(new TypeInfoStructForm(container, Users, Programs, Client));
    container->setLayout(hlayout);
    ui->tabWidget->addTab(container, QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::LogSuccessful()
{
    this->setEnabled(1);
    LogInStatus=true;
    QWidget *container = new QWidget;
    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(new TypeInfoStructForm(container,Users, Programs, Client, myaccount));
    container->setLayout(hlayout);
    ui->tabWidget->addTab(container, QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

void MainWindow::on_tabWidget_tabBarDoubleClicked(int index)
{
    //TODO change name by DoubleClick
}
