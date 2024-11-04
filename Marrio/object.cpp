#include "object.h"



object::object(std::string name, MyClass::GlobalObject* parent, int uniqueID)
{
	initObject();
	
	setName(name);
	setParent(parent);
	uniqueId = uniqueID;


}

void object::update()
{
	BUpdate();
}

void object::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
