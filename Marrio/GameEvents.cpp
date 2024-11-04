#include "GameEvents.h"


void GameEvents::Event(listner func)
{
    this->Events.push_back(func);  // Ajouter un écouteur à la liste
}

void GameEvents::LuncheEvent(sf::Event args)
{
    for (const auto& func : this->Events)
    {
        func(args);  // Appeler chaque fonction avec l'argument
    }
}
