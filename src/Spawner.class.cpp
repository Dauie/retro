
#include "rush00.hpp"

Spawner::Spawner(void)
{
}

Spawner::Spawner(const Spawner &obj)
{
	_rep = obj._rep;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
	_cyclesPerSpawn = obj._cyclesPerSpawn;
	_curModCycle = obj._curModCycle;
}

Spawner::Spawner(float posX, float posY, int cyclesPerSpawn)
{
	_rep = 'S';
	_alive = true;
	_dirX = 0;
	_dirY = 0;
	_posX = posX;
	_posY = posY;
	_cyclesPerSpawn = cyclesPerSpawn;
	_curModCycle = 0;
}

Spawner::~Spawner(void)
{
}

void	Spawner::update(void)
{
	if (!this->isAlive())
	{
		delete this;
	}

	if (_curModCycle % _cyclesPerSpawn == 0)
	{
		BasicEnemy *e = new BasicEnemy(-1, 0, _posX - 1, _posY);
		(void)e;
	}
	_curModCycle++;

	this->move(0.0, 0.0);
	this->draw();
}

Spawner	&Spawner::operator=(Spawner const &obj)
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
