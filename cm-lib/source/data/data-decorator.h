#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include <QScopedPointer>
#include <QJsonObject>
#include <QString>
#include <QJsonValue>

#include <cm-lib_global.h>

namespace cm {
  namespace data {
    class Entity;

    class CMLIBSHARED_EXPORT DataDecorator : public QObject
    {
      Q_OBJECT
      Q_PROPERTY(QString ui_label READ label CONSTANT)

    public:
      explicit DataDecorator(Entity *parent = nullptr,
                             const QString& key="SomeItemKey",
                             const QString& label="");

      virtual ~DataDecorator();

      const QString& label() const;
      const QString& key() const;

      Entity* parentEntity();

      virtual QJsonValue jsonValue() const = 0;
      virtual void update(const QJsonObject& jsonObject) = 0;

    private:
      class Implementation;
      QScopedPointer<Implementation> implementation;
    };
  }
}



#endif // DATADECORATOR_H
