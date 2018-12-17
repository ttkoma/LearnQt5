#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <QtQml/QQmlListProperty>

#include <cm-lib_global.h>
#include <framework/command.h>

namespace cm {
  namespace controllers {
    class CMLIBSHARED_EXPORT CommandController : public QObject
    {
      Q_OBJECT
      Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands
                 READ createClientViewContextCommands CONSTANT)

    public:
      explicit CommandController(QObject *parent = nullptr);
      ~CommandController();

      QQmlListProperty<framework::Command>
      createClientViewContextCommands();

    public slots:
      void onCreateClientViewExecuted();

    private:
      class Implementation;
      QScopedPointer<Implementation> implementation;

    };
  }
}



#endif // COMMANDCONTROLLER_H
