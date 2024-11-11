#include "Workspace.h"
#include "Game.h"

Workspace::Workspace(Game* game)
{
	this->game = game;
	sf::Vector2u Wsize = game->getSize();
	this->setSize(sf::Vector2f((float)Wsize.x, (float)Wsize.y));
}

object& Workspace::addObject(std::string name, MyClass::GlobalObject* parent)
{
	object *myOBJ = new object(name, parent, Objects.size()+1);
	Objects.push_back(myOBJ);
	return *myOBJ;
}

void Workspace::update()
{
	for (int i = 0; i < Objects.size(); i++)
		Objects[i]->update();
	
}

void Workspace::render(sf::RenderTarget*target)
{
	for (int i = 0; i < Objects.size(); i++)
		Objects[i]->render(target);
	

	
}
