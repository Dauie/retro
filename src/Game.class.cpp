

#include "rush00.hpp"

GameObj** Game::objs = new GameObj*[TOTALOBJ];

unsigned int Game::yMax = 0;
unsigned int Game::xMax = 0;
int Game::input = 0;

Game::Game(void) {
    initscr();
    timeout(0);
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, xMax, yMax);
    _gameStart = clock();
    _lastRender = 0;

    /*Make Game Entities*/
	for (int i = 0; i < TOTALOBJ; i++) {
		objs[i] = nullptr;
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
	delete[] Game::objs;
    endwin();
}

int				Game::setInput(int c) {
	input = c;
	return (1);
}

clock_t			Game::getGameStart() const { return (_gameStart); }


void			Game::update() {
	for (int i = 0; i < TOTALOBJ; i++) {
		if (objs[i]) {
			objs[i]->update();
		}
	}
}
void			Game::render() const {
    for (int i = 0; i < TOTALOBJ; i++) {
		if (objs[i]) {
        	objs[i]->draw();
		}
    }
}

void			Game::collision(void){
	for (int i = 0; i < TOTALOBJ; i++ ){
		if (!objs[i])
			continue;
		int pxi = roundf(objs[i]->getXPos());
		int pyi = roundf(objs[i]->getYPos());
		for (int j = 0; j < TOTALOBJ; j++){
			if (!objs[j])
				continue;
			int pxj = roundf(objs[j]->getXPos());
			int pyj = roundf(objs[j]->getYPos());

			//check to see if objects occupy same space
			if (pxi == pxj && pyi == pyj)
				objs[i]->livingStatus(false);
			objs[j]->livingStatus(false);
		}
		//check to see if objects are out of bounds
		if (i > 0 &&
			(pyi >= (int)Game::yMax || pyi <= 0 ||
					pxi >= (int)Game::xMax || pxi <= 0))
		{
			objs[i]->livingStatus(false);
		}
	}
}