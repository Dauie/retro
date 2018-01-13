//
// Created by Robert LUTT on 1/12/18.
//
#include "../incl/Bullet.class.hpp"

Bullet::Bullet(void) : GameObj() {
    _hp = 0;
    _direction = 1;
    _speed = 10;
    _rep = '-';
}

Bullet::Bullet(int direction) : GameObj() {
   _direction = direction;
}


Bullet &Bullet::operator=(Bullet const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    _rep = rhs.getRep();
    _maxHp = rhs.getMaxHp();
    _hp = rhs.getHp();
    _speed = rhs.getSpeed();
    _x = rhs.getX();
    _y = rhs.getY();
    _direction = rhs.getDirection();
    return (*this);
}

Bullet::Bullet(const Bullet &obj){
    *this = obj;
}

Bullet::~Bullet(void){

}

void        Bullet::setDirection(int direction) {
    _direction = direction;
}

int        Bullet::getDirection() const {
    return (_direction);
}

void        Bullet::updateSelf(int x, int y) {
    setXMax(x);
    setYMax(y);
    if (getHp() == 0)
        return;
    if (_direction == 1)
        this->moveRight();
    else
        this->moveLeft();
}