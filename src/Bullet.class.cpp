//
// Created by Robert LUTT on 1/12/18.
//
#include "rush00.hpp"

Bullet::Bullet(void) : GameObj()
{
}

Bullet::Bullet(float dirX, float dirY, float posX, float posY)
{
	_rep = '-';
	_dirX = dirX;
	_dirY = dirY;
	_posX = posX;
	_posY = posY;
}


Bullet &Bullet::operator=(Bullet const &rhs)
{
    if (this != &rhs)
    {
	_rep = rhs._rep;
	_dirX = rhs._dirX;
	_dirY = rhs._dirY;
	_posY = rhs._posY;
	_posX = rhs._posX;
    }
    return (*this);
}

Bullet::Bullet(const Bullet &obj)
{
    *this = obj;
}

Bullet::~Bullet(void)
{
}



void		Bullet::move(float x, float y)
{
	(void)x;
	(void)y;
	_dirX += _dirX < 0 ? -.1 : .1;
	_dirY += _dirY < 0 ? -.1 : .1;
	_posX += _dirX;
	_posY += _dirY;
}
void        Bullet::update() {

	move(0.0, 0.0);
}
