#include <QApplication>
#include <QQmlApplicationEngine>
#include "wControl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;

    a.setOrganizationName("Wyder");
    a.setOrganizationDomain("Test");
    a.setApplicationName("TestGraph");
    a.setApplicationVersion("1.0.0");

    qmlRegisterType<WControl>("WControl", 1, 0, "WControl");

    const QUrl url("qrc:/path/main.qml");
    engine.load(url);
    return a.exec();
}
