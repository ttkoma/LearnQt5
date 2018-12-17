#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qtqmlversion.h>
#include <QQmlContext>

#include <cm-lib_global.h>
#include <controllers/master-controller.h>
#include <controllers/navigation-controller.h>
#include <controllers/command-controller.h>
#include <framework/command.h>

#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
  qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0, "NavigationController");
  qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");

  qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");

  cm::controllers::MasterController masterController;

  QQmlApplicationEngine engine;
  engine.addImportPath("qrc:/");
  engine.rootContext()->setContextProperty(QStringLiteral("masterController"), &masterController);
  engine.rootContext()->setContextProperty("QtQmlVersion", QTQML_VERSION_STR);

  engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
