#ifndef ENTITY_H
#define ENTITY_H

#include <map>

#include <QJsonObject>
#include <QObject>
#include <QScopedPointer>

#include <cm-lib_global.h>
#include <data/data-decorator.h>

namespace cm {
namespace data {
class CMLIBSHARED_EXPORT Entity : public QObject {
  Q_OBJECT
public:
  Entity(QObject *parent = nullptr, const QString &key = "SomeEntityKey");

  Entity(QObject *parent, const QString &key, const QJsonObject &jsonObject);
  virtual ~Entity();

public:
  const QString &key() const;
  void update(const QJsonObject &jsonObject);
  QJsonObject toJson() const;

signals:
  void childEntitiesChanged();
  void dataDecoratorsChanged();

protected:
  Entity *addEntity(Entity *childEntity, const QString &key);
  DataDecorator *addDataItem(DataDecorator *dataDecorator);

protected:
  class Implementation;
  QScopedPointer<Implementation> implementation;

public slots:
};

} // namespace data
} // namespace cm

#endif // ENTITY_H
