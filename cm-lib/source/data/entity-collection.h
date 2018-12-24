#ifndef ENTITYCOLLECTION_H
#define ENTITYCOLLECTION_H

#include <vector>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QList>
#include <QObject>
#include <QString>

#include <cm-lib_global.h>

namespace cm {
namespace data {

class Entity;

class CMLIBSHARED_EXPORT EntityCollectionObject : public QObject {
  Q_OBJECT
public:
  explicit EntityCollectionObject(QObject *parent = nullptr)
      : QObject(parent){};
  virtual ~EntityCollectionObject(){};

signals:
  void collectionChanged();
};

class EntityCollectionBase : public EntityCollectionObject {
public:
  EntityCollectionBase(QObject *parent = nullptr,
                       const QString &key = "SomeCollectionKey")
      : EntityCollectionObject(parent), m_key(key) {}

  virtual ~EntityCollectionBase(){};

  QString getKey() const { return m_key; }

  virtual void clear() = 0;
  virtual void update(const QJsonArray &json) = 0;
  virtual std::vector<Entity *> baseEntities() = 0;

  template <class T> QList<T *> &derivedEntities();

  template <class T> T *addEntity(T *);

private:
  QString m_key;
};

template <typename T> class EntityCollection : public EntityCollectionBase {
public:
  EntityCollection(QObject *parent = nullptr,
                   const QString &key = "SomeCollectionKey")
      : EntityCollectionBase(parent, key) {}

  ~EntityCollection();

  void clear() override {
    for (auto entity : m_collection) {
      entity.deleteLater();
    }
    m_collection.clear();
  }

  void update(const QJsonArray &jsonArray) override {
    clear();
    for (QJsonValue jsonValue : jsonArray) {
      addEntity(new T(this, jsonValue.toObject()));
    }
  }

  std::vector<Entity *> baseEntities() override {
    std::vector<Entity *> returnValue;

    for (T *entity : m_collection) {
      returnValue.push_back(entity);
    }
    return returnValue;
  }

  QList<T *> &derivedEntities() { return m_collection; }

  T *addEntity(T *entity) {
    if (!m_collection.contains(entity)) {
      m_collection.append(entity);
      emit EntityCollectionObject::collectionChanged();
    }
    return entity;
  }

private:
  QList<T *> m_collection;
};

template <class T> QList<T *> &EntityCollectionBase::derivedEntities() {
  return dynamic_cast<const EntityCollection<T> &>(*this).derivedEntities();
}

template <class T> T *EntityCollectionBase::addEntity(T *entity) {
  return dynamic_cast<const EntityCollection<T> &>(*this).addEntity(entity);
}

} // namespace data
} // namespace cm

#endif // ENTITYCOLLECTION_H
