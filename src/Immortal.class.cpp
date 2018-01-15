
#include "rush00.hpp"

bool	Immortal::active = false;

Immortal::Immortal(void)
{
}

Immortal::Immortal(const Immortal &obj)
{
	_lives = obj._lives;
	_rep = obj._rep;
	_color = obj._color;
	_alive = obj._alive;
	_dirX = obj._dirX;
	_dirY = obj._dirY;
	_posX = obj._posX;
	_posY = obj._posY;
	_wall = obj._wall;
}

Immortal::Immortal(float dirX, float dirY, float posX, float posY)
{
	_lives = 20;
	_rep = 'X';
	_color = COLOR_BLUE;
	_alive = true;
	_dirX = dirX;
	_dirY = dirY;
	_posX = posX;
	_posY = posY;
	_wall = false;
}

Immortal::~Immortal(void)
{
}

void	Immortal::bullet_hell(void)
{
	if (rand() % 100 > 90)
	{
		float x = (float)(rand() % 100 - 50) / 100;
		float y = (float)(rand() % 100 - 50) /	100;
		new Bullet(x, y, _posX, _posY, false, false);
	}
	if (rand() % 1000 > 995)
	{
		int lowgap = (int)((float(rand() % 90) / 100) * (float)Game::xMax);

		for (int i = 0; i < (int)Game::xMax; i++)
		{
			if (i <= lowgap || i >= lowgap + 10)
				new Bullet(0, -1, float(i), Game::yMax - 5, false, false);
		}
	}
}

void	Immortal::update(void)
{
        if (_dirX == 0 && _dirY == 0)
        {
		active = true;
                _posY = Game::yMax / 2;
                _posX = Game::xMax / 2;
        }
	else
	{
		if (_dirX > 0)
		{
			if (_posX > (float)Game::xMax / 2)
				_dirX = 0;
		}
		else
		{
			if (_posX < (float)Game::xMax / 2)
				_dirX = 0;
		}
		if (_dirY > 0)
		{
			if (_posY > (float)Game::yMax / 2)
				_dirY = 0;
		}
		else
		{
			if (_posY < (float)Game::yMax / 2)
		                 _dirY = 0;
		}
	}
	bullet_hell();
	if (!_alive)
	{
		_lives--;
		_alive = true;
	}
	if (!_lives)
	{
		active = false;
		delete this;
		return;
	}
	this->move(0, 0);
	this->draw();
}


void	Immortal::draw(void)
{
	int x = roundf(_posX);
	int y = roundf(_posY);
	attron(COLOR_PAIR(_color));
	mvprintw(x + 1,  y - 1, "%s", "/-\\");
	mvprintw(x, y - 1, "%s", " ? ");
	mvprintw(x - 1, y - 1, "%s", "\\-/");
	attroff(COLOR_PAIR(_color));
		
}


Immortal	&Immortal::operator=(Immortal const &obj)
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
		this->_wall = obj._wall;
	}
	return (*this);
}
