#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include <ncurses.h>
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <time.h>

#include "GameObj.class.hpp"
#include "Player.class.hpp"
#include "Bullet.class.hpp"

#define ENEMYCOUNT 50
#define BULLETCOUNT (ENEMYCOUNT * 100)
#define TOTALOBJ (ENEMYCOUNT + BULLETCOUNT + 1)

class Game {

public:
    Game(void);
    Game &operator=(Game const &rhs);
    Game(const Game &obj);
    ~Game(void);
    void                    update(void);
    void                    render(void) const;
    unsigned int            getFps(void) const;
    clock_t                 getGameStart() const;

	static unsigned int    xMax;
	static unsigned int    yMax;
	static int             input;
	static GameObj         **objs;

private:
    clock_t         _gameStart;
    clock_t         _lastRender;
    unsigned int    _frames;
    unsigned int    _fps;
};

#endif



new player
new spawner(x, y)
new spawners(x, y)

