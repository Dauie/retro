
#include "BasicEnemy.class.hpp"

//this is unfinished!

BasicEnemy::BasicEnemy(void)
{
	_rep = 'E';
	_alive = true;
	_dirX = -1;
	_dirY = 0;
	_posX = 0;
	_posY = 0;
}

BasicEnemy::BasicEnemy(const BasicEnemy &obj)
{
	_rep = obj._rep;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
}

BasicEnemy::~BasicEnemy(void)
{
}

void	update(void)
{
	if (!this->isAlive())
	{
		removeEnemy();
		return ;
	}
	this->move();
	this->draw();
}

BasicEnemy	&BasicEnemy::operator=(BasicEnemy const *obj)
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
