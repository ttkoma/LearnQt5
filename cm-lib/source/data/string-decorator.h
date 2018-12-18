#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include <QObject>
#include <QScopedPointer>
#include <QString>
#include <QJsonValue>
#include <QJsonObject>

#include <data/data-decorator.h>
#include <cm-lib_global.h>

namespace cm {
  namespace data {
    class CMLIBSHARED_EXPORT StringDecorator : public DataDecorator
    {
      Q_OBJECT

      Q_PROPERTY(QString ui_value READ value  WRITE setValue  NOTIFY valueChanged)

    public:
      explicit StringDecorator(Entity* parentEntity,
                               const QString& key = "SomeItemKey",
                               const QString& label="", const QString& value="");
      ~StringDecorator() override;

      const QString& value() const;
      StringDecorator& setValue(const QString& value);

      QJsonValue jsonValue() const override;
      void update(const QJsonObject& _jsonObject) override;

    signals:
      void valueChanged();

    private:
      class Implementation;
      QScopedPointer<Implementation> implementation;

    };
  }
}


#endif // STRINGDECORATOR_H
