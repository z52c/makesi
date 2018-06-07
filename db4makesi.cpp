#include "db4makesi.h"
#include <QtDebug>

db4Makesi::db4Makesi(QObject *parent) : QObject(parent)
{
    db=new QSqlDatabase();
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        *db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        *db = QSqlDatabase::addDatabase("QSQLITE");
        db->setDatabaseName("daye.db");
        //db->setUserName("daye");
        //db->setPassword("dayenihao");
    }
    if (!db->open())
    {
        qDebug() << "Error: Failed to connect database." << db->lastError();
    }
    else
    {
       // _create_tables();
    }
}

void db4Makesi::_create_tables()
{
    QSqlQuery sql_query;
    QString create_sql = "create table singleChoice (id INTEGER PRIMARY KEY AUTOINCREMENT, title varchar(255), answerA varchar(255),answerB varchar(255),answerC varchar(255),answerD varchar(255),answer varchar(10))";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table singleChoice created!";
    }
    create_sql = "create table multipleChoice (id INTEGER PRIMARY KEY AUTOINCREMENT, title varchar(255), answerA varchar(255),answerB varchar(255),answerC varchar(255),answerD varchar(255),answer varchar(10))";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table multipleChoice created!";
    }
    create_sql = "create table tf (id INTEGER PRIMARY KEY AUTOINCREMENT, title varchar(255),answer varchar(20))";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table tf created!";
    }
}

bool db4Makesi::insertSingleChoice(QString inTitle, QString inAnswerA, QString inAnswerB, QString inAnswerC, QString inAnswerD, QString inAnswer)
{
    QSqlQuery sql_query;
    QString insert_sql=QString("INSERT INTO singleChoice VALUES(NULL,\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\')").arg(inTitle).arg(inAnswerA).arg(inAnswerB).arg(inAnswerC).arg(inAnswerD).arg(inAnswer);
    if(!sql_query.exec(insert_sql))
    {
        qDebug()<<insert_sql;
        qDebug() << sql_query.lastError();
        return false;
    }
    else{
        return true;
    }
}

bool db4Makesi::insertMultipleChoice(QString inTitle, QString inAnswerA, QString inAnswerB, QString inAnswerC, QString inAnswerD, QString inAnswer)
{
    QSqlQuery sql_query;
    QString insert_sql=QString("INSERT INTO multipleChoice VALUES(NULL,\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\')").arg(inTitle).arg(inAnswerA).arg(inAnswerB).arg(inAnswerC).arg(inAnswerD).arg(inAnswer);
    if(!sql_query.exec(insert_sql))
    {
        qDebug()<<insert_sql;
        qDebug() << sql_query.lastError();
        return false;
    }
    else{
        return true;
    }
}

bool db4Makesi::insertTF(QString inTitle, QString inAnswer)
{
    QSqlQuery sql_query;
    QString insert_sql=QString("INSERT INTO tf VALUES(NULL,\'%1\',\'%2\')").arg(inTitle).arg(inAnswer);
    if(!sql_query.exec(insert_sql))
    {
        qDebug()<<insert_sql;
        qDebug() << sql_query.lastError();
        return false;
    }
    else{
        return true;
    }
}


bool db4Makesi::isExistInSingleChoice(QString inTitle)
{
    QSqlQuery sql_query;
    QString select_sql = QString("select * from singleChoice where title = \'%1\'").arg(inTitle);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    else
    {
        //qDebug()<<sql_query.numRowsAffected();
        if(sql_query.numRowsAffected()>1)
        {
            //qDebug()<<sql_query.value(0).toString();
            return true;
        }else
        {
            return false;
        }
    }
}

bool db4Makesi::isExistInMultipleChoice(QString inTitle)
{
    QSqlQuery sql_query;
    QString select_sql = QString("select * from multipleChoice where title = \'%1\'").arg(inTitle);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    else
    {
        if(sql_query.numRowsAffected()>1)
        {
            return true;
        }else
        {
            return false;
        }
    }
}

bool db4Makesi::isExistInTF(QString inTitle)
{
    QSqlQuery sql_query;
    QString select_sql = QString("select * from tf where title = \'%1\'").arg(inTitle);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    else
    {
        if(sql_query.numRowsAffected()>1)
        {
            return true;
        }else
        {
            return false;
        }
    }
}
