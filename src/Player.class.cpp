
#include "../incl/Player.class.hpp"

Player::Player(void) : GameObj() {
    _lives = 3;
    _rep = '>';
    _x = 1;
    _y = 1;
}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    _rep = rhs.getRep();
    _maxHp = rhs.getMaxHp();
    _hp = rhs.getHp();
    _speed = rhs.getSpeed();
    _x = rhs.getX();
    _y = rhs.getY();
    return (*this);
}

Player::Player(const Player &obj) {
    *this = obj;
}

Player::~Player(void) {

}

void            Player::updateSelf(int input, Bullet *bullets, int count, int yMax, int xMax) {

    this->setYMax(yMax);
    this->setXMax(xMax);

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
            this->fireBullet(bullets, count );
    }
}

void        Player::fireBullet(Bullet *bullets, int len) {
    for (int i = 0; i < len; i++) {
        if (bullets[i].getHp() == 0) {
            bullets[i].setHp(bullets[i].getMaxHp());
            bullets[i].setDirection(1);
            bullets[i].jumpTo(this->_y, this->_x + 1);
            break;
        }
    }
}
