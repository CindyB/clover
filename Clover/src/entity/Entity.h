#ifndef ENTITY_H_
#define ENTITY_H_

#include "..\core\BaseEntity.h"
#include "..\physic\Vector2D.h"

class Entity : public BaseEntity
{

public :
	Entity();
	Entity(std::vector<BaseComponent*> components);

	virtual ~Entity();
};

#endif // !ENTITY_H_