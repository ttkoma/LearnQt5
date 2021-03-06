#include "data-decorator.h"

namespace cm {
namespace data {
class DataDecorator::Implementation {
public:
  Implementation(Entity *_parentEntity, const QString &_key,
                 const QString &_label)
      : parentEntity(_parentEntity), key(_key), label(_label) {}

  Entity *parentEntity{nullptr};

  QString key;
  QString label;
};

DataDecorator::DataDecorator(Entity *parent, const QString &key,
                             const QString &label)
    : QObject((QObject *)parent)
//: QObject ( static_cast<QObject*>( parent ))
// :QObject( qobject_cast<QObject>(parent))
{
  implementation.reset(new Implementation(parent, key, label));
}

DataDecorator::~DataDecorator() {}

const QString &DataDecorator::label() const { return implementation->label; }

const QString &DataDecorator::key() const { return implementation->key; }

Entity *DataDecorator::parentEntity() { return implementation->parentEntity; }
} // namespace data
} // namespace cm
