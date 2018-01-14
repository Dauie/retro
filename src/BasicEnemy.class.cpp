
#include "rush00.hpp"

BasicEnemy::BasicEnemy(void)
{
}

BasicEnemy::BasicEnemy(const BasicEnemy &obj)
{
	_rep = obj._rep;
	_color = obj._color;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
}

BasicEnemy::BasicEnemy(float dirX, float dirY, float posX, float posY)
{
	_rep = 'E';
	_color  = COLOR_RED;
	_alive = true;
	_dirX = dirX;
	_dirY = dirY;
	_posX = posX;
	_posY = posY;
}

BasicEnemy::~BasicEnemy(void)
{
	for (int i = 0; i < 10; i++) {
		new Particle(_posX, _posY);
	}
}

void	BasicEnemy::update(void)
{
	if (!_alive)
	{
		delete this;
		return;
	}
	this->move(0.0, 0.0);
	this->draw();
}

BasicEnemy	&BasicEnemy::operator=(BasicEnemy const &obj)
{
	if (this != &obj)
	{
		this->_rep = obj._rep;
		this->_alive = obj._alive;
		this->_dirX = obj._dirX;
		this->_dirY = obj._dirY;
		this->_posX = obj._posX;
		this->_posY = obj._posY;
	}
	return (*this);
}
