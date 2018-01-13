
#include "GameObj.hpp"

GameObj::GameObj(void)
{
}

GameObj::GameObj(const GameObj &obj);
{
	_rep = obj._rep;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
}

GameObj::~GameObj(void)
{
}

//setters and getters:

float	GameObj::getXDir(void) const { return (_dirX); }
float	GameObj::getYDir(void) const { return (_dirY); }
float	GameObj::getXPos(void) const { return (_poxX); }
float	GameObj::getYPos(void) const { return (_posY); }

void	GameObj::setXDir(float f) { _dirX = f; }
void	GameObj::setYDir(float f) { _dirY = f; }
void	GameObj::setXPos(float f) { _posX = f; }
void	GameObj::setYPos(float f) { _posY = f; }

bool	GameObj::isAlive(void) const { return (_alive); }
void	GameObj::livingStatus(bool b) { _alive = b; }

char	GameObj::getRep(void) const { return (_rep); }
void	GameObj::setRep(char c) { _rep = c; }

//other stuff:

void	GameObj::move(void)
{
	_posX += _dirX;
	_posY += dirY;
}

void	GameObj::draw(void)
{
	int x = roundf(_posX);
	int y = roundf(_posY);

	mvprintw(x, y, "%c", _rep);
}

//overloads:

GameObj	&GameObj::operator=(GameObj const &obj)
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
