
#include "rush00.hpp"

Player::Player(void) : GameObj() {
	_lives = 3;
	_alive = true;
	_rep = '>';
	_posY = 1;
	_posX = 1;
	_dirX = 0;
	_dirY = 0;
}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    _rep = rhs.getRep();
    _alive = rhs.isAlive();

    _dirX = rhs._dirX;
    _dirY = rhs._dirY;
    _posY = rhs._posY;
    _posX = rhs._posX;
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
		_lives--;
		_alive = true;
	}
	if (!_lives)
	{
		delete this;
	}
	
    switch(Game::input) {
        case UP:
            this->setXDir(-1.5);
            break;
        case DOWN:
            this->setXDir(1.5);
            break;
        case LEFT:
            this->setYDir(-1.5);
            break;
        case RIGHT:
            this->setYDir(1.5);
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

void        Player::fireBullet() {
	new Bullet(0.0, 1.0, _posX, _posY + 1.0);
}
