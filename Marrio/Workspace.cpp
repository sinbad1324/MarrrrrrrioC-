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
	Objects.emplace_back(std::make_unique<object>(name, parent, Objects.size() + 1));
	return Objects.back();
}

void Workspace::update()
{
	for (int i = 0; i < Objects.size(); i++)
	{
		Objects[i].update();
	}
}

void Workspace::render(sf::RenderTarget*target)
{
	for (int i = 0; i < Objects.size(); i++)
	{
		Objects[i].render(target);
	}
}
