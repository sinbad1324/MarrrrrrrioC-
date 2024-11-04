#include <iostream>
#include "Game.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int main()
{
    srand(static_cast< unsigned int>(time(0)));


    Game game;

    while (game.isOpen())
    {
        game.update();
        game.render();
}
    return 0;
}

