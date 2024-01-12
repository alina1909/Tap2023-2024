#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   // qDebug() << "hello world!";

    QString mStr = "hello world";
    qDebug() << mStr;

    return a.exec();
}
