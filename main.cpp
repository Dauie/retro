#include "rush00.hpp"

#define DELAY 42000 / 2

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)


int main(void) {
    Game    main;
    static int     frames = 0;
    static clock_t     start = clock();
    clock_t     f_time = 0;
    clock_t     last_sec = 0;

    while (true) {
        f_time = clock();
        /*Get user input*/
        frames++;
        if ((last_sec / CLOCKS_PER_SEC) != (start / CLOCKS_PER_SEC))
        {
            //display fps
            frames = 0;
            last_sec = f_time;
            //timer = (clock() - start) / CLOCKS_PER_SEC
        }
        if (!main.setInput(getch()))
            break;
        /*Update game entities*/
        main.update();
        /*Clear the Screen*/
        erase();
		/*Check for collisions*/
		main.collision();
        /*Draw all game entities*/
        main.render();
        /*Display the new screen*/
        refresh();
        /*Sleep the game loop*/
        while ((clock()/CLOCKS_PER_FRAME) == (f_time / CLOCKS_PER_FRAME)) {}
    }
    return (0);
}