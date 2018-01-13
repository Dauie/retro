//
// Created by Robert LUTT on 1/11/18.
//

#include "../incl/Game.class.hpp"

GameObj Game::objs = new GameObj*[TOTALOBJ];

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
	for (int i = 0; i < TOTALOBJ; i++) {
		Game::objs[i] = nullptr;
	}
	new Player;
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
	for (int i = 0; i < TOTALOBJ; i++) {
		delete Game::objs[i];
		Game::objs[i] = nullptr;
	}
	delete Game::objs;
    endwin();
}

clock_t			Game::getGameStart() const { return (_gameStart); }


void			Game::update() {
	for (int i = 0; i < TOTALOBJ; i++) {
		Game::objs[i]->update();
	}
}

void			Game::render() const {
    for (int i = 0; i < TOTALOBJ; i++) {
        Game::objs[i]->draw();
    }
}