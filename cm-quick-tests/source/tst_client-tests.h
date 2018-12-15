//#include <QtTest>
//#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

#include <controllers/master-controller.h>

class ClientTests : public QObject
{
  Q_OBJECT
public:
  ClientTests() {
    qmlRegisterType<cm::controllers::MasterController>("Cm", 1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("Cm", 1, 0, "NavigationController");
  }

public slots:
  void qmlEngineAvailable(QQmlEngine *engine)
  {
    cm::controllers::MasterController *masterController = new cm::controllers::MasterController(this);
    engine->rootContext()->setContextProperty("masterController", masterController);

  }

  void cleanupTestCase() {}
  void applicationAvailable() {}
};
