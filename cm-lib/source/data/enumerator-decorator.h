#ifndef ENUMERATORDECORATOR_H
#define ENUMERATORDECORATOR_H

#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <cm-lib_global.h>
#include <data/data-decorator.h>

namespace cm {
namespace data {
class CMLIBSHARED_EXPORT EnumeratorDecorator : public DataDecorator {
  Q_OBJECT

  Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
  Q_PROPERTY(
      QString ui_valueDescription READ valueDescription NOTIFY valueChanged)

public:
  explicit EnumeratorDecorator(Entity *parentEntity,
                               const QString &key = "SomeItemKey",
                               const QString &label = "", const int &value = 0,
                               const std::map<int, QString> &descriptionMapper =
                                   std::map<int, QString>());
  ~EnumeratorDecorator() override;

  int value() const;
  QString valueDescription() const;
  EnumeratorDecorator &setValue(const int &value);

  QJsonValue jsonValue() const override;
  void update(const QJsonObject &_jsonObject) override;

signals:
  void valueChanged();

private:
  class Implementation;
  QScopedPointer<Implementation> implementation;
};
} // namespace data
} // namespace cm

#endif // ENUMERATORDECORATOR_H
