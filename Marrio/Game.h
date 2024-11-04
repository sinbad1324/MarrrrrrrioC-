//Incldes
#include <iostream>

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include "Gui.h"
#include "GameEvents.h"
#include "Workspace.h"
#ifndef _GAME_
#define _GAME_

class Game
{

private:
	sf::RenderWindow * window;
	Gui* ScreenGui;
	Workspace* workspace;
	//initalize
	void initWindow();
	void initScreenGui();
	void initWorkspace();
public:
	//Constructor & destructor
	Game();
	~Game();

	// updates
	void update();
	void updateEvent();
	// accessor
	bool const isOpen() const ;
	 sf::Vector2i getPosition();
	 sf::Vector2u getSize();
	 bool getPollEvent(sf::Event ev);
	 GameEvents gameEvent;
	//render
	void render();
};
#endif // !_GAME_

