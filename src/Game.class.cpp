//
// Created by Robert LUTT on 1/11/18.
//

#include "../incl/Game.class.hpp"

Game::Game(void) : _xMax(0), _yMax(0) {
    initscr();
    timeout(0);
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, _xMax, _yMax);
    _gameStart = clock();
    _lastRender = 0;

    /*Make Game Entities*/

};


Game &Game::operator=(Game const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    return (*this);
}

Game::Game(const Game &obj) {
    *this = obj;
}

Game::~Game(void) {

    /*Delete Game Entities*/
    delete _enemies;
    delete _bullets;
    endwin();
}
int             Game::setInput(int c) {
    _input = c;
    return (1);
}

clock_t			Game::getGameStart() const { return (_gameStart); }

unsigned int	Game::getXMax() const { return (_xMax); }

unsigned int	Game::getYMax() const { return (_yMax); }

int				Game::getInput() const { return (_input); }

void			Game::update() {
	_player.updateSelf(_input, _bullets, BULLETCOUNT, _yMax, _xMax);
	for (int i = 0; i < BULLETCOUNT; i++) {
		_bullets[i].updateSelf(_xMax, _yMax);
	}
}

void			Game::render() const {
    _player.drawSelf();
    for (int i = 0; i < BULLETCOUNT; i++) {
        _bullets->drawSelf();
    }

}