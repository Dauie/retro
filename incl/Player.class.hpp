//
// Created by Robert LUTT on 1/12/18.
//

#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "Game.class.hpp"
#include "GameObj.class.hpp"
#include "Bullet.class.hpp"

class Player : public GameObj {

public:
    Player(void);
    Player &operator=(Player const &rhs);
    Player(const Player &obj);
    ~Player(void);

    void fireBullet(GameObjs **objs);
    void update(int input, GameObjs **objs);

private:
    unsigned int    _lives;
};

#endif //CPP_PLAYER_CLASS_HPP
