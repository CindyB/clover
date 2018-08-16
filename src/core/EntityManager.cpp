#include "EntityManager.h"
#include "..\physic\PositionComponent.h"

EntityManager EntityManager::m_EntityManager;

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
	for (std::map<UUID*, BaseEntity*>::iterator it = m_Entities.begin(); it != m_Entities.end(); ++it)
	{
		delete it->first;
		delete it->second;
	}
}

Entity* EntityManager::CreateEntity(std::list<BaseComponent*> components)
{
	Entity* entity = new Entity(components);
	m_Entities.insert(std::pair<UUID*,Entity*>(entity->GetUuid(), entity));
	return entity;
}

std::list<BaseEntity*> EntityManager::GetEntities()
{
	std::list<BaseEntity*> entities;
	for (std::map<UUID*, BaseEntity*>::iterator it = m_Entities.begin(); it != m_Entities.end(); ++it)
	{
		entities.push_back(it->second);
	}

	return entities;
}