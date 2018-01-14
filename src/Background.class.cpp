
#include "rush00.hpp"

Background::Background(void)
{
	_size = (int)Game::yMax;
	_xpoints = new int[_size];
	_ypoints = new int[_size];		
	for (int i = 0; i < _size; i++)
	{
		_xpoints[i] = rand() % _size;
		_ypoints[i] = rand() % _size;
	}
	_curModCycle = 0;
}

Background::Background(const Background &obj)
{
	*this = obj;
}

Background::~Background(void)
{
	delete[] _xpoints;
	delete[] _ypoints;
}

void	Background::update(void)
{
	_curModCycle++;
}

void	Background::draw(void)
{
	init_pair(50, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(50));
	for (int i = 0; i < _size; i++)
	{
		mvprintw(_xpoints[i],
			 _size - (_ypoints[i] + _curModCycle) % _size,
			 "%s",
			 "~");
	}
	attroff(COLOR_PAIR(50));
}

Background	&Background::operator=(Background const &obj)
{
	if (this != &obj)
	{
		this->_curModCycle = obj._curModCycle;
	}
	return (*this);
}
