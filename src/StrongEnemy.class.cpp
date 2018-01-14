
#include "rush00.hpp"

StrongEnemy::StrongEnemy(void)
{
	_rep = 'X';
	_alive = true;
}

StrongEnemy::StrongEnemy(const StrongEnemy &obj)
{
	_rep = obj._rep;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;

	_curModCycle = obj._curModCycle;
	_cyclesPerDirChange = obj._cyclesPerDirChange;
	_cyclesPerShot = obj._cyclesPerShot;
}

StrongEnemy::StrongEnemy(float dirX, float dirY, float posX, float posY)
{
	_rep = 'X';
	_alive = true;
	_dirX = dirX;
	_dirY = dirY;
	_posX = posX;
	_posY = posY;

	_curModCycle = 0;
	_cyclesPerDirChange = 20;
	_cyclesPerShot = 40;
}

StrongEnemy::~StrongEnemy(void)
{
}

void	StrongEnemy::update(void)
{
	
	if (!_alive)
	{
		delete this;
		return;
	}

	if (_curModCycle % _cyclesPerDirChange == 0)
	{
		if (_posX / (float)Game::xMax > 0.5)
		{
			_dirX = (float)((rand() % 1000) - 800) / 1000;
		}
		else
		{
			_dirX = (float)((rand() % 1000) - 200) / 1000;
		}

		if (_posY / (float)Game::yMax > 0.5)
		{
			_dirY = (float)((rand() % 1000) - 800) / 1000;
		}
		else
		{
			_dirY = (float)((rand() % 1000) - 200) / 1000;
		}
	}

	if (_curModCycle % _cyclesPerShot == 0)
	{
		new Bullet(0.0, _dirY >= 0 ? -_dirY: _dirY, _posX, _posY - 1.0);
	}
	
	_curModCycle++;
	
	this->move(0.0, 0.0);
	this->draw();
}

StrongEnemy	&StrongEnemy::operator=(StrongEnemy const &obj)
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
