//
// Created by Robert LUTT on 1/13/18.
//

#include "rush00.hpp"

Particle::Particle(void) {
}


Particle::Particle(float posX, float posY) : GameObj(1) {
	_rep = '.';
	_color = COLOR_WHITE;
	_alive = true;
	_dirY = rand()%2 == 1 ? (float)(rand() % 5 + 1) * 0.5 : (float)(rand() % 5 + 1) * -0.5;
	_dirX = rand()%2 == 1 ? (float)(rand() % 5 + 1) * 0.5 : (float)(rand() % 5 + 1) * -0.5;
	_posX = posX;
	_posY = posY;
	_ttl = 24;
	for (int i = COLLIDABLE; i < TOTALOBJ; i++)
	{
		if (!Game::objs[i])
		{
			Game::objs[i] = this;
			break;
		}
	}
}


Particle::Particle(const Particle &obj) {
	_rep = obj._rep;
	_color = obj._color;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
}

Particle::~Particle(void) {
	for (int i = COLLIDABLE; i < TOTALOBJ; i++)
	{
		if (Game::objs[i] == this)
		{
			Game::objs[i] = nullptr;
			break;
		}
	}
}

Particle	&Particle::operator=(Particle const &obj)
{
	if (this != &obj)
	{
		this->_rep = obj._rep;
		this->_color = obj._color;
		this->_alive = obj._alive;
		this->_dirX = obj._dirX;
		this->_dirY = obj._dirY;
		this->_posX = obj._posX;
		this->_posY = obj._posY;
	}
	return (*this);
}

int		Particle::getTtl() const {
	return (_ttl);
}

void	Particle::setTtl(int ttl) {
	_ttl = ttl;
}

void	Particle::move(float x, float y) {
	(void)x;
	(void)y;

	_posX += _dirX * .1;
	_posY += _dirY * .1;
}

void	Particle::update(void) {
	if (!_alive) {
		delete this;
		return;
	}
	_ttl -= 1;
	this->move(0.0, 0.0);
	if (_ttl == 0)
		_alive = false;
}
