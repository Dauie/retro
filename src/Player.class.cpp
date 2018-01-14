
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
    _dirX += dirX;
    _dirY += dirY;

    _posX += _dirX;
    _posY += _dirY;
	_dirX += _dirX < 0.0 ? 0.5 : 0.0;
	_dirY += _dirY < 0.0 ? 0.5 : 0.0;
	_dirX -= _dirX > 0.0 ? 0.5 : 0.0;
	_dirY -= _dirY > 0.0 ? 0.5 : 0.0;
}

void            Player::update() {

    switch(Game::input) {
        case UP:
            this->move(-1.0, 0.0);
            break;
        case DOWN:
            this->move(1.0, 0.0);
            break;
        case LEFT:
            this->move(0.0, -1.0);
            break;
        case RIGHT:
            this->move(0.0, 1.0);
            break;
        case FIRE:
            this->fireBullet();
    }
}

void        Player::fireBullet() {
	new Bullet(1.0, _posX, _posY + 1.0);
}
