#include "command-controller.h"

#include <QDebug>
#include <QList>

using namespace cm::framework;

namespace cm {
  namespace controllers {
    class CommandController::Implementation {
    public:
      Implementation(CommandController* _commandController)
        : commandController(_commandController)
      {
         Command* createClientView_SaveCommand =
             new Command(commandController, QChar( 0xf0c7 ), "Save");

         QObject::connect(createClientView_SaveCommand, &Command::executed,
                 commandController, &CommandController::onCreateClientViewExecuted);

         createClientView_Commands.append(createClientView_SaveCommand);
      }

      CommandController* commandController;
      QList<Command*> createClientView_Commands;
    };

    CommandController::CommandController(QObject *parent) : QObject(parent)
    {
      implementation.reset(new Implementation(this));
    }

    CommandController::~CommandController()
    {

    }

    QQmlListProperty<Command> CommandController::ui_createClientViewContextCommands()
    {
      return QQmlListProperty<Command>(this, implementation->createClientView_Commands);
    }

    void CommandController::onCreateClientViewExecuted()
    {
      qDebug() << "onCreateClientViewExecuted";
    }
  }
}


