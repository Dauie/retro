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

class Game {

public:
    Game(void);
    Game &operator=(Game const &rhs);
    Game(const Game &obj);
    ~Game(void);
    void                    update(void);
    void                    render(void) const;
    unsigned int            getYMax(void) const;
    unsigned int            getXMax(void) const;
    int                     setInput(int);
    int                     getInput(void) const;
    unsigned int            getFps(void) const;
    clock_t                 getGameStart() const;

private:
    clock_t         _gameStart;
    clock_t         _lastRender;
    unsigned int    _frames;
    unsigned int    _fps;
    unsigned int    _xMax;
    unsigned int    _yMax;
    int             _input;
    GameObj         **_objs;
};

#endif
