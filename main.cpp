#include "rush00.hpp"

#define DELAY 30000

int main(void) {
    Game    main;

    while (true) {
        /*Get user input*/
        if (!main.setInput(getch()))
            break;
        /*Update game entities*/
        main.update();
        /*Clear the Screen*/
        clear();
		/*Check for collisions*/
		main.collision();
        /*Draw all game entities*/
        main.render();
        /*Display the new screen*/
        refresh();
        /*Sleep the game loop*/
        usleep(DELAY);
    }
    return (0);
}