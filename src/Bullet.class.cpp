//
// Created by Robert LUTT on 1/12/18.
//
#include "rush00.hpp"

Bullet::Bullet(void) : GameObj() {

}

Bullet::Bullet( float dirY, float posX, float posY) : GameObj() {
	_rep = '-';
	_dirY = dirY;
	_posX = posX;
	_posY = posY;
}


Bullet &Bullet::operator=(Bullet const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
	_rep = rhs._rep;
	_dirX = rhs._dirX;
	_dirY = rhs._dirY;
	_posY = rhs._posY;
	_posX = rhs._posX;
    return (*this);
}

Bullet::Bullet(const Bullet &obj){
    *this = obj;
}

Bullet::~Bullet(void){
}

void        Bullet::checkPos(void) {
	if (this->getYPos() >= Game::yMax)
		this->_alive = false;
	else if (this->getYPos() <= 0)
		this->_alive = false;
	if (this->getXPos() >= Game::xMax)
		this->_alive = false;
	else if (this->getXPos() <= 0)
		this->_alive = false;
}

void		Bullet::move(float x, float y) {
	/*Satisfy compiler*/
	_dirY += y;
	_dirX += x;
	/*Slowly increase speed.*/
	_dirY += _dirY < 0 ? -.1 : .1;
	_posY += _dirY;
	checkPos();
}
void        Bullet::update() {

	move(0.0, 0.0);
}
