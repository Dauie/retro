#include "../incl/GameObj.class.hpp"

const std::string _options[] = {"100", "200", "300"};

GameObj::GameObj(void) : _hp(100), _maxHp(100), _speed(1), _x(0), _y(0) {
     //_actions = {&GameObj::moveDown, &GameObj::moveUp, &GameObj::moveLeft, &GameObj::moveRight};
    getmaxyx(stdscr, _xMax, _yMax);
};

GameObj &GameObj::operator=(GameObj const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    //_actions = rhs._actions;
    _maxHp = rhs._maxHp;
    _hp = rhs._hp;
    _speed = rhs._speed;
    _x = rhs._x;
    _y = rhs._y;
    return (*this);
}

GameObj::GameObj(const GameObj &obj) {
    *this = obj;
}

GameObj::~GameObj(void) { }

int             GameObj::getX(void) const { return _x; };

int             GameObj::getY(void) const { return _y; };

void            GameObj::setY(int y) { _y = y; };

void            GameObj::setX(int x) { _x = x; };

void            GameObj::setYMax(int y) { _yMax = y; }

void            GameObj::setXMax(int x) { _xMax = x; }

void            GameObj::setHp(int hp) { _hp = hp; }

void            GameObj::takeDamage(unsigned int amt) {
    if (_hp - (int)amt < 0) {
        _hp = 0;
        return;
    }
    _hp -= amt;
};


void            GameObj::beRepaired(unsigned int amt) {
    if (_hp + (int)amt >= (int)_maxHp) {
        _hp = _maxHp;
        return;
    }
    _hp += amt;
}

void            GameObj::jumpTo(int x, int y) {
    this->setX(x);
    this->setY(y);
}

void            GameObj::moveRight(void) {
    if (this->_y + (int)this->_speed != _yMax)
        this->setY(this->_y + this->_speed);
}

void            GameObj::moveUp(void) {
    if (this->_x - (int)this->_speed != 0)
        this->setX(this->_x - this->_speed);
}

void            GameObj:: moveDown(void) {
    if (this->_x + (int)this->_speed != _xMax)
        this->setX(this->_x + this->_speed);
}

void            GameObj::moveLeft(void) {
    if (this->_y - (int)this->_speed != 0)
        this->setY(this->_y - this->_speed);
}

char            GameObj::getRep(void) const { return (_rep); }

int             GameObj::getHp(void) const { return (_hp); }

int             GameObj::getMaxHp(void) const { return (_maxHp); }

int             GameObj::getMaxDmg(void) const { return (_maxDmg); }

int             GameObj::getSpeed(void) const { return (_speed); }

void            GameObj::drawSelf(void) const {
    if (_hp > 0 && _x && _y)
        mvprintw(_x, _y, "%c", _rep);
}

