#include "datetime-decorator.h"

#include <QVariant>

namespace cm {
namespace data {
class DateTimeDecorator::Implementation {
public:
  Implementation(DateTimeDecorator *_dateTimeDecorator, const QDateTime &_value)
      : dateTimeDecorator(_dateTimeDecorator), value(_value) {}

  DateTimeDecorator *dateTimeDecorator;
  QDateTime value;
};

DateTimeDecorator::DateTimeDecorator(Entity *parentEntity, const QString &key,
                                     const QString &label,
                                     const QDateTime &value)
    : DataDecorator(parentEntity, key, label) {
  implementation.reset(new Implementation(this, value));
}

DateTimeDecorator::~DateTimeDecorator() {}

QDateTime DateTimeDecorator::value() const { return implementation->value; }

QString DateTimeDecorator::toIso8601String() const {
  return implementation->value.toString(Qt::ISODate);
}

QString DateTimeDecorator::toPrettyString() const {
  return implementation->value.toString("ddd d MMMM yyyy @ HH:mm:ss");
}

QString DateTimeDecorator::toPrettyDateString() const {
  return implementation->value.toString("d MMMM yyyy");
}

QString DateTimeDecorator::toPrettyTimeString() const {
  return implementation->value.toString("HH:mm");
}

DateTimeDecorator &DateTimeDecorator::setValue(const QDateTime &value) {
  if (value != implementation->value) {
    // ...Validation here if required...
    implementation->value = value;
    emit valueChanged();
  }

  return *this;
}

QJsonValue DateTimeDecorator::jsonValue() const {
  return QJsonValue::fromVariant(QVariant(implementation->value));
}

void DateTimeDecorator::update(const QJsonObject &_jsonObject) {
  if (_jsonObject.contains(key())) {
    setValue(_jsonObject.value(key()).toVariant().toDateTime());
  } else {
    setValue(QDateTime());
  }
}

} // namespace data
} // namespace cm
