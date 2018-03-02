#include <QCoreApplication>
#include <QDebug>
#include "version.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Version version;
    auto line = version.getVersion();
    qDebug() << "line:" << line;
    return a.exec();
}
