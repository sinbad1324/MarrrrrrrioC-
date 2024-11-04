#pragma once
#ifndef _WORKSPACE_
#define _WORKSPACE_
#include <vector>
#include "object.h"
#include "MyClass.hpp"

#include <memory>

Game game;

class Workspace :MyClass::GlobalObject 
{
private:
	std::vector<std::unique_ptr<MyClass::GlobalObject>> Objects ;
public:
	//Variables
	Game* game;
	Workspace(Game* game);

	object& addObject(std::string name , MyClass::GlobalObject *parent);

	void update();
	void render(sf::RenderTarget* target);

};
#endif // !_WORKSPACE_

