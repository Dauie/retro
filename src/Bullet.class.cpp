//
// Created by Robert LUTT on 1/12/18.
//
#include "rush00.hpp"

Bullet::Bullet(void) : GameObj()
{
}

Bullet::Bullet(float dirX, float dirY, float posX, float posY, bool accel, bool wall)
{
	_rep = '-';
	_color = COLOR_YELLOW;
	_dirX = dirX;
	_dirY = dirY;
	_posX = posX;
	_posY = posY;
	_accel = accel;
	_alive = true;
	_wall= wall;
}

Bullet::Bullet(float dirX, float dirY, float posX, float posY, bool accel)
{
	_rep = '-';
	_color = COLOR_YELLOW;
	_dirX = dirX;
	_dirY = dirY;
	_posX = posX;
	_posY = posY;
	_accel = accel;
	_alive = true;
	_wall= true;
}



Bullet &Bullet::operator=(Bullet const &rhs)
{
    if (this != &rhs) {
		_rep = rhs._rep;
		_color = rhs._color;
		_dirX = rhs._dirX;
		_dirY = rhs._dirY;
		_posY = rhs._posY;
		_posX = rhs._posX;
		_accel = rhs._accel;
		_alive = rhs._alive;
		_wall = rhs._wall;
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
	if (_accel)
	{
		if (_dirX)
			_dirX += _dirX < 0 ? -.1 : .1;
		if (_dirY)
			_dirY += _dirY < 0 ? -.1 : .1;
	}
	_posX += _dirX;
	_posY += _dirY;
}
void        Bullet::update() {
	if (!_alive)
	{
		delete this;
		return;
	}
	move(0.0, 0.0);
}
