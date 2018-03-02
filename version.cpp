#include "version.h"

Version::Version() {}

Version::~Version() {}

void Version::mount(const QString &devPath, const QString &mountpath) {
    QDir tmp;
    bool exist = tmp.exists(mountpath);
    if (!exist) {
        tmp.mkdir(mountpath);
    }

    QProcess process;
    QString terminalArgs = QString("mount %1 %2").arg(devPath).arg(mountpath);
    process.start(terminalArgs);
    if (!process.waitForFinished())
        qDebug() << "Mount failed:" << process.errorString();
    else
        qDebug() << "Mount success!";
}

QString Version::getVersion() {
    mount("/dev/blockrom2","/tmp/initfs");

    QFile versionText("/tmp/initfs/startup/yocto_version.txt");
    if (!versionText.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "yocto_version is not open!";
    }
    QString version = versionText.readAll().trimmed();
    return version;
}

