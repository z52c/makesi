#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "db4makesi.h"
#include "shitijiexi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(); //解析并存入数据库

    void on_pushButton_2_clicked();//创建数据库

private:
    Ui::MainWindow *ui;
    db4Makesi *mDB;
    shitijiexi *stjx;
};

#endif // MAINWINDOW_H
