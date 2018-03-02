#ifndef VERSION_H
#define VERSION_H

#include <QFile>
#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QDir>

class Version : public QObject
{
    Q_OBJECT
public:
    Version();
    ~Version();

    void mount(const QString &devPath, const QString &mountpath);
    QString getVersion();
};

#endif // VERSION_H
