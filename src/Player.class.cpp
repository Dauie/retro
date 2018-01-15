
#include "rush00.hpp"

Player::Player(void) : GameObj() {
	_lives = 3;
	_alive = true;
	_rep = '>';
	_color = COLOR_CYAN;
	_posY = Game::yMax / 5;
	_posX = Game::xMax / 2;
	_dirX = 0;
	_dirY = 0;
	_wall = false;
}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    _rep = rhs._rep;
	_color = rhs._color;
    _alive = rhs._alive;
    _dirX = rhs._dirX;
    _dirY = rhs._dirY;
    _posY = rhs._posY;
    _posX = rhs._posX;
    _wall = rhs._wall;
    return (*this);
}

Player::Player(const Player &obj) {
    *this = obj;
}

Player::~Player(void) {

}

void            Player::move(float dirX, float dirY) {
	_posX += dirX;
	if (_posX < 0)
		_posX = Game::xMax -1;
	else if (_posX > Game::xMax)
		_posX = 0;
	_posY += dirY;
	if (_posY < 0)
		_posY = 0;
	else if (_posY > Game::yMax)
		_posY = Game::yMax;
}
void            Player::update() {

	if (!_alive)
	{
		attron(COLOR_PAIR(8));
		for (int i = 0; i < (int)Game::xMax; i++) {
			for (int j = 0; j < (int)Game::yMax; j++){
				mvprintw(i, j, "%c", '|');
			}
		}
		refresh();
		usleep(30000);

		attroff(COLOR_PAIR(8));
		std::system("afplay ./sounds/lifereduce.mp3 &");
		_lives--;
		_alive = true;
	}
	if (_lives <=0)
	{
		std::system("afplay ./sounds/explosion.mp3 &");
		for (int i = 0; i < 16; i++) {
			new Particle(_posX, _posY);
		}
		delete this;
        return;
	}
	
    switch(Game::input) {
        case UP:
            this->setXDir(-1.0);
            break;
        case DOWN:
            this->setXDir(1.0);
            break;
        case LEFT:
            this->setYDir(-1.0);
            break;
        case RIGHT:
            this->setYDir(1.0);
            break;
        case FIRE:
            this->fireBullet();
    }
	this->move(this->_dirX, this->_dirY);
	if (_dirX == 0 && _dirY == 0)
		return;
	_dirX += _dirX < 0.0 ? 0.5 : 0.0;
	_dirY += _dirY < 0.0 ? 0.5 : 0.0;
	_dirX -= _dirX > 0.0 ? 0.5 : 0.0;
	_dirY -= _dirY > 0.0 ? 0.5 : 0.0;
}


int     Player::getLives() const {
    return _lives;
}

void        Player::fireBullet() {
	std::system("afplay ./sounds/gunFirePlayer.mp3 &");
	float d = 0;
	if (Game::score > 2000)
		d = (float)(rand() % 100 - 50) / 3000;
	new Bullet(d, 1.0, _posX, _posY + 1.0, true);
}
