#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H

#include <QDateTime>
#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <cm-lib_global.h>
#include <data/data-decorator.h>

namespace cm {
namespace data {
class CMLIBSHARED_EXPORT DateTimeDecorator : public DataDecorator {
  Q_OBJECT

  Q_PROPERTY(QDateTime ui_value READ value WRITE setValue NOTIFY valueChanged)
  Q_PROPERTY(QString ui_iso8601String READ toIso8601String NOTIFY valueChanged)
  Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)
  Q_PROPERTY(
      QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged)
  Q_PROPERTY(
      QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged)

public:
  explicit DateTimeDecorator(Entity *parentEntity,
                             const QString &key = "SomeItemKey",
                             const QString &label = "",
                             const QDateTime &value = QDateTime());
  ~DateTimeDecorator() override;

  QDateTime value() const;
  QString toIso8601String() const;
  QString toPrettyString() const;
  QString toPrettyDateString() const;
  QString toPrettyTimeString() const;

  DateTimeDecorator &setValue(const QDateTime &value);

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

#endif // DATETIMEDECORATOR_H
