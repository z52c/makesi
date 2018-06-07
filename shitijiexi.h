#ifndef SHITIJIEXI_H
#define SHITIJIEXI_H

#include <QObject>
#include "db4makesi.h"
#include <QFile>
#include <QtDebug>

class shitijiexi : public QObject
{
    Q_OBJECT
public:
    explicit shitijiexi(QObject *parent = nullptr);
    void doJob(QString inFileName,db4Makesi *inDB);
signals:

public slots:

private:
    QString fileName;
    db4Makesi *db;
    QFile *file;
    QString line;

    void doBefore();
    void getSingleChoice();
    void getMultipleChoice();
    void getTF();
    QString getAnswer();

    QString getTitleOrChoice(QString in);
    QString removeNumberIntitle(QString in);
};

#endif // SHITIJIEXI_H
