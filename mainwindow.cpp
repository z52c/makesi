#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDB=new db4Makesi();
    stjx=new shitijiexi();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName;
    for(int i=0;i<=202;i++)
    {
        fileName=QString("%1.html").arg(QString::number(i));
        qDebug()<<QString("处理文件%1").arg(fileName);
        stjx->doJob(fileName,mDB);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    mDB->_create_tables();
}
