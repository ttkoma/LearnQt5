#include "entity.h"

namespace cm {
namespace data {

class Entity::Implementation {
public:
  Implementation(Entity *_entity, const QString &key)
      : entity(_entity), key(key) {}

  Entity *entity{nullptr};
  QString key;

  std::map<QString, Entity *> childEntities;
  std::map<QString, DataDecorator *> dataDecorators;
  std::map<QString, EntityCollectionBase *> childCollections;
};

Entity::Entity(QObject *parent, const QString &key) : QObject(parent) {
  implementation.reset(new Implementation(this, key));
}

Entity::Entity(QObject *parent, const QString &key,
               const QJsonObject &jsonObject)
    : Entity(parent, key) {
  update(jsonObject);
}

Entity::~Entity() {}

const QString &Entity::key() const { return implementation->key; }

void Entity::update(const QJsonObject &jsonObject) {
  // Update dataDecorators
  for (std::pair<QString, DataDecorator *> dataDecoratorPair :
       implementation->dataDecorators) {
    dataDecoratorPair.second->update(jsonObject);
  };

  // Update childEntities
  for (std::pair<QString, Entity *> entityPair :
       implementation->childEntities) {
    entityPair.second->update(jsonObject.value(entityPair.first).toObject());
  };
}

QJsonObject Entity::toJson() const {
  QJsonObject returnValue;
  // Add dataDecorators
  for (std::pair<QString, DataDecorator *> dataDecoratorPair :
       implementation->dataDecorators) {
    returnValue.insert(dataDecoratorPair.first,
                       dataDecoratorPair.second->jsonValue());
  }
  // Add childEntities
  for (std::pair<QString, Entity *> childEntityPair :
       implementation->childEntities) {
    returnValue.insert(childEntityPair.first, childEntityPair.second->toJson());
  }

  return returnValue;
}

Entity *Entity::addEntity(Entity *childEntity, const QString &key) {
  if (implementation->childEntities.find(key) ==
      std::end(implementation->childEntities)) {
    implementation->childEntities[key] = childEntity;
    emit childEntitiesChanged();
  }
  return childEntity;
}

DataDecorator *Entity::addDataItem(DataDecorator *dataDecorator) {
  if (implementation->dataDecorators.find(dataDecorator->key()) ==
      std::end(implementation->dataDecorators)) {
    implementation->dataDecorators[dataDecorator->key()] = dataDecorator;
    emit dataDecoratorsChanged();
  }

  return dataDecorator;
}

EntityCollectionBase *
Entity::addChildCollection(EntityCollectionBase *entityCollection) {
  if (implementation->childCollections.find(entityCollection->getKey()) ==
      std::end(implementation->childCollections)) {
    implementation->childCollections[entityCollection->getKey()] =
        entityCollection;
    emit childCollectionsChanged(entityCollection->getKey());
  }
  return entityCollection;
}

} // namespace data
} // namespace cm
