#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void Write(QString FileName)
{
    QFile mFile(FileName);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<< "could not open file for writing";
        return;
    }

    QTextStream out(&mFile);
    out<< "Hello";
    mFile.flush();
    mFile.close();
}

void Read(QString FileName)
{
    QFile mFile(FileName);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<< "could not open file for reading";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() <<mText;
    mFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString MyFileName = "C:/myfile.txt";
    Write(MyFileName);
    Read(MyFileName);

    return a.exec();
}
