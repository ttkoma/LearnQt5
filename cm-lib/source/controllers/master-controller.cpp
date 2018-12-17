#include <QDebug>

#include "master-controller.h"

namespace cm {
  namespace controllers {

    class MasterController::Implementation {
    public:
      Implementation (MasterController* _masterController)
        : masterController(_masterController)
      {
        navigationController = new NavigationController(masterController);
        commandController = new CommandController(masterController);
      }

      MasterController* masterController { nullptr};
      NavigationController* navigationController { nullptr };
      CommandController* commandController {nullptr};

      QString welcomeMessage = QStringLiteral("Welcome to Client Management app!");
    };

    MasterController::MasterController(QObject *parent) : QObject(parent)
    {
      implementation.reset(new Implementation(this));
    }

    MasterController::~MasterController() {

    }

    NavigationController*MasterController::navigationController()
    {
      return implementation->navigationController;
    }

    CommandController*MasterController::commandController()
    {
      return implementation->commandController;
    }

    const QString& MasterController::welcomeMessage() const
    {
      return implementation->welcomeMessage;
    }
  }
}
