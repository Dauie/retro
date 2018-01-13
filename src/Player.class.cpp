
#include "../incl/Player.class.hpp"

Player::Player(void) :
        GameObj(), _lives(3), _alive(TRUE), _rep('>'),
        _posY(1), _posX(1), _dirX(0), _dirY(0) {

}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    _rep = rhs.getRep();
    _alive = rhs.isAlive();

    _dirX = rhs._dirX;
    _dirY = rhs._dirY;
    _posY = rhs._posY;
    _posX = rhs._posX;
    return (*this);
}

Player::Player(const Player &obj) {
    *this = obj;
}

Player::~Player(void) {

}

void            Player::update(int input) {

    switch(input) {
        case UP:
            this->moveUp();
            break;
        case DOWN:
            this->moveDown();
            break;
        case LEFT:
            this->moveLeft();
            break;
        case RIGHT:
            this->moveRight();
            break;
        case FIRE:
            this->fireBullet();
    }
}

void        Player::fireBullet() {

}
