#include "enumerator-decorator.h"

#include <QVariant>

namespace cm {
namespace data {
class EnumeratorDecorator::Implementation {
public:
  Implementation(EnumeratorDecorator *_intDecorator, const int &_value,
                 const std::map<int, QString> &_descriptionMapper)
      : intDecorator(_intDecorator), value(_value),
        descriptionMapper(_descriptionMapper) {}

  EnumeratorDecorator *intDecorator;
  int value;
  std::map<int, QString> descriptionMapper;

};

EnumeratorDecorator::EnumeratorDecorator(
    Entity *parentEntity, const QString &key, const QString &label,
    const int &value, const std::map<int, QString> &descriptionMapper)
    : DataDecorator(parentEntity, key, label) {
  implementation.reset(new Implementation(this, value, descriptionMapper));
}

EnumeratorDecorator::~EnumeratorDecorator() {}

int EnumeratorDecorator::value() const { return implementation->value; }

QString EnumeratorDecorator::valueDescription() const {
  auto iterator = implementation->descriptionMapper.find(implementation->value);
  if (iterator != implementation->descriptionMapper.end()) {
    return implementation->descriptionMapper.at(
        implementation->value); // iterator->second;
  } else {
    return {};
  }
}

EnumeratorDecorator &EnumeratorDecorator::setValue(const int &value) {
  if (value != implementation->value) {
    // ...Validation here if required...
    implementation->value = value;
    emit valueChanged();
  }

  return *this;
}

QJsonValue EnumeratorDecorator::jsonValue() const {
  return QJsonValue::fromVariant(QVariant(implementation->value));
}

void EnumeratorDecorator::update(const QJsonObject &_jsonObject) {
  if (_jsonObject.contains(key())) {
    setValue(_jsonObject.value(key()).toInt());
  } else {
    setValue(0);
  }
}

} // namespace data
} // namespace cm
