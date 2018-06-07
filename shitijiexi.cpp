#include "shitijiexi.h"
#include "daye.h"
shitijiexi::shitijiexi(QObject *parent) : QObject(parent)
{

}

void shitijiexi::doJob(QString inFileName, db4Makesi *inDB)
{
    fileName=inFileName;
    db=inDB;
    file=new QFile(fileName);
    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug()<<QString("%1打开失败").arg(fileName);
        return;
    }
    doBefore();
    for(int i=0;i<20;i++)
    {
        getSingleChoice();
    }

    for(int i=0;i<10;i++)
    {
        getMultipleChoice();
    }

    for(int i=0;i<20;i++)
    {
        getTF();
    }
    file->close();
    file=NULL;
}

void shitijiexi::doBefore()
{
    while(!file->atEnd())
    {
        line=file->readLine();
        if(line.contains("<span class=\"choiceTitle\">"))
        {
            return;
        }
    }
}

void shitijiexi::getSingleChoice()
{
    while(!file->atEnd())
    {
        line=file->readLine();
        if(line.contains("<span class=\"choiceTitle\">"))
        {
            break;
        }
    }
    QString tmpTitle=getTitleOrChoice(line);
    //qDebug()<<QString("title:%1").arg(tmpTitle);
    QString tmpAnswerA=getTitleOrChoice(file->readLine());
    QString tmpAnswerB=getTitleOrChoice(file->readLine());
    QString tmpAnswerC=getTitleOrChoice(file->readLine());
    QString tmpAnswerD=getTitleOrChoice(file->readLine());
    QString tmpAnswer=getAnswer();
    if(!db->isExistInSingleChoice(tmpTitle))
    {
        db->insertSingleChoice(tmpTitle,tmpAnswerA,tmpAnswerB,tmpAnswerC,tmpAnswerD,tmpAnswer);
    }
}

void shitijiexi::getMultipleChoice()
{
    while(!file->atEnd())
    {
        line=file->readLine();
        if(line.contains("<span class=\"choiceTitle\">"))
        {
            break;
        }
    }
    QString tmpTitle=getTitleOrChoice(line);
    QString tmpAnswerA=getTitleOrChoice(file->readLine());
    QString tmpAnswerB=getTitleOrChoice(file->readLine());
    QString tmpAnswerC=getTitleOrChoice(file->readLine());
    QString tmpAnswerD=getTitleOrChoice(file->readLine());
    QString tmpAnswerE="";
    line=file->readLine();
    if(line.contains("choiceTitle"))
    {
        tmpAnswerE=getTitleOrChoice(line);
    }
    QString tmpAnswer=getAnswer();
    if(!db->isExistInMultipleChoice(tmpTitle))
    {
        db->insertMultipleChoice(tmpTitle,tmpAnswerA,tmpAnswerB,tmpAnswerC,tmpAnswerD,tmpAnswerE,tmpAnswer);
    }
}

void shitijiexi::getTF()
{
    while(!file->atEnd())
    {
        line=file->readLine();
        if(line.contains("<span class=\"choiceTitle\">"))
        {
            break;
        }
    }
    QString tmpTitle=getTitleOrChoice(line);
    QString tmpAnswer=getAnswer();
    if(!db->isExistInTF(tmpTitle))
    {
        db->insertTF(tmpTitle,tmpAnswer);
    }
}

QString shitijiexi::getAnswer()
{
    QString rtn;
    char tmp[20];
    while(!file->atEnd())
    {
        line=file->readLine();
        if(line.contains("<span style=\"color:green;font-weight: bold;\">"))
        {
            getStringBetweenAandB(line.toStdString().c_str(),"<span style=\"color:green;font-weight: bold;\">","</span>",tmp);
            rtn=tmp;
            return rtn;
        }
    }
}

QString shitijiexi::getTitleOrChoice(QString in)
{
    QString rtn;
    char tmp[1000];
    if(!getStringBetweenAandB(in.toStdString().c_str(),"class=\"choiceTitle\">","</span>",tmp))
    {
        rtn=tmp;
        rtn=removeNumberIntitle(rtn);
        return rtn;
    }
    else{
        qDebug()<<QString("提取选项或者标题失败 ：%1").arg(in);
        return QString("");
    }
}

QString shitijiexi::removeNumberIntitle(QString in)
{
    in.replace("10、","");
    in.replace("11、","");
    in.replace("12、","");
    in.replace("13、","");
    in.replace("14、","");
    in.replace("15、","");
    in.replace("16、","");
    in.replace("17、","");
    in.replace("18、","");
    in.replace("19、","");
    in.replace("20、","");
    in.replace("1、","");
    in.replace("2、","");
    in.replace("3、","");
    in.replace("4、","");
    in.replace("5、","");
    in.replace("6、","");
    in.replace("7、","");
    in.replace("8、","");
    in.replace("9、","");
    //qDebug()<<in;
    return in;
}
