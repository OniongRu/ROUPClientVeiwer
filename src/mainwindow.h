#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablewindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void SigMain();

private slots:
    void on_TableEx_clicked();

    void on_LogOut_clicked();

private:
    Ui::MainWindow *ui;
    TableWindow *WinTable;
};
#endif // MAINWINDOW_H
