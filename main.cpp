#include "git_version.h"
#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QSettings>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("http://github.com/Osse/qttemplate");
    QCoreApplication::setOrganizationName("Øystein Walle");
    QCoreApplication::setApplicationName("QtTemplate");
    QCoreApplication::setApplicationVersion(GIT_VERSION);
    QSettings::setDefaultFormat(QSettings::IniFormat);

    QCommandLineParser parser;
    parser.setApplicationDescription(QObject::tr("Descriptive string"));
    parser.addHelpOption();
    parser.addVersionOption();

    MainWindow w;
    w.show();

    return a.exec();
}
