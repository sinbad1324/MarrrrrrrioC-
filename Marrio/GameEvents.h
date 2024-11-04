#pragma once
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>

class GameEvents
{
public:
	using listner = std::function<void(sf::Event)>;
	void Event(listner func);

	void LuncheEvent(sf::Event args);

private:
	std::vector<listner>Events;

};

