#include "int-decorator.h"

#include <QVariant>

namespace cm {
namespace data {
class IntDecorator::Implementation {
public:
  Implementation(IntDecorator *_intDecorator, const int &_value)
      : intDecorator(_intDecorator), value(_value) {}

  IntDecorator *intDecorator;
  int value;
};

IntDecorator::IntDecorator(Entity *parentEntity, const QString &key,
                           const QString &label, const int &value)
    : DataDecorator(parentEntity, key, label) {
  implementation.reset(new Implementation(this, value));
}

IntDecorator::~IntDecorator() {}

int IntDecorator::value() const { return implementation->value; }

IntDecorator &IntDecorator::setValue(const int &value) {
  if (value != implementation->value) {
    // ...Validation here if required...
    implementation->value = value;
    emit valueChanged();
  }

  return *this;
}

QJsonValue IntDecorator::jsonValue() const {
  return QJsonValue::fromVariant(QVariant(implementation->value));
}

void IntDecorator::update(const QJsonObject &_jsonObject) {
  if (_jsonObject.contains(key())) {
    setValue(_jsonObject.value(key()).toInt());
  } else {
    setValue(0);
  }
}

} // namespace data
} // namespace cm
