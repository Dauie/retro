
#include "../incl/Player.class.hpp"

Player::Player(void) :
        GameObj(), _lives(3), _alive(TRUE), _rep('>'),
        _posY(1), _posX(1), _dirX(0), _dirY(0) {

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

void            Player::move(float x, float y) {
    _dirX += x;
    _dirY += y;

    _posX += _dirX;
    _posY += _dirY;
	_dirX += _dirX < 0.0 ? 0.5 : 0.0;
	_dirY += _dirY < 0.0 ? 0.5 : 0.0;
	_dirX -= _dirX > 0.0 ? 0.5 : 0.0;
	_dirY -= _dirY > 0.0 ? 0.5 : 0.0;
}

void            Player::update(int input, GameObj **objs, int len) {

    switch(input) {
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
            this->fireBullet(objs);
    }
}

void        Player::fireBullet(GameObj **objs) {
	for (int i = 0; i < TOTALOBJ; i++) {
		if (objs[i] == NULL) {
			objs[i] = new Bullet;
		}
	}
}
