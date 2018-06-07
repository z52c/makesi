#ifndef DB4MAKESI_H
#define DB4MAKESI_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class db4Makesi : public QObject
{
    Q_OBJECT
public:
    explicit db4Makesi(QObject *parent = nullptr);
    bool insertSingleChoice(QString inTitle,QString inAnswerA,QString inAnswerB,QString inAnswerC,QString inAnswerD,QString inAnswer);
    bool insertMultipleChoice(QString inTitle,QString inAnswerA,QString inAnswerB,QString inAnswerC,QString inAnswerD,QString inAnswer);
    bool insertTF(QString inTitle,QString inAnswer);
    bool isExistInSingleChoice(QString inTitle);
    bool isExistInMultipleChoice(QString inTitle);
    bool isExistInTF(QString inTitle);

    void _create_tables();
signals:

public slots:

private:
    QSqlDatabase *db;


};

#endif // DB4MAKESI_H
