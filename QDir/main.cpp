#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir mDir;

    /*
    foreach (QFileInfo mItm, mDir.drives()) {
        qDebug()<<mItm.absoluteFilePath();
    }
    */

    QString mPath = "C:/aaa";
    if(!mDir.exists(mPath)) {
        mDir.mkpath("C:/aaa");
        qDebug()<<"created";
    }
    else
    {
        qDebug() << "already exists";
    }

    return a.exec();
}
