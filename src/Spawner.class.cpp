
#include "rush00.hpp"

Spawner::Spawner(void)
{
}

Spawner::Spawner(const Spawner &obj)
{
	_rep = obj._rep;
	_reverse = obj._reverse;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
	_cyclesPerSpawn = obj._cyclesPerSpawn;
	_curModCycle = obj._curModCycle;
	_angle = obj._angle;
	_wall = obj._wall;
}

Spawner::Spawner(float posX, float posY, int cyclesPerSpawn, int sync, float reverse)
{
	_reverse = reverse;
	_rep = 'S';
	_alive = true;
	_dirX = 0;
	_dirY = 0;
	_posX = posX;
	_posY = posY;
	_cyclesPerSpawn = cyclesPerSpawn;
	_curModCycle = sync + 1;
	_angle = 0;
	_wall = true;
}

Spawner::~Spawner(void)
{
}

void	Spawner::update(void)
{
	if (!this->isAlive())
	{
		;
		//do nothing, it can't die!
	}

	if (_curModCycle % (_cyclesPerSpawn * 20) == 0)
	{
//		new Immortal(0, -0.5, _posX, _posY);
		_cyclesPerSpawn = (int)((float)_cyclesPerSpawn * 0.8) + 1;
	}
	else if (_curModCycle % (_cyclesPerSpawn * 5) == 0)
	{
		new StrongEnemy(0, -2, _posX, _posY - 5);
	}
	else if (_curModCycle % _cyclesPerSpawn == 0)
	{
		new BasicEnemy(fabs(sinf(_angle * M_PI / 8)) * _reverse, -0.5, _posX, _posY - 5);
		_angle++;
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
		this->_wall = obj._wall;
	}
	return (*this);
}
