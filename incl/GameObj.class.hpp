#ifndef GAMEOBJ_CLASS_HPP
#define GAMEOBJ_CLASS_HPP

#include <iostream>
#include <string>
#include <ncurses.h>

#define UP (int)'w'
#define DOWN (int)'s'
#define LEFT (int)'a'
#define RIGHT (int)'d'
#define FIRE (int)' '

class GameObj {

public:

    typedef void (GameObj::*Actions)(void);

    GameObj(void);
    GameObj &operator=(GameObj const &rhs);
    GameObj(const GameObj &obj);
    ~GameObj(void);

    int             getX(void) const;
    int             getY(void) const;
    char            getRep(void) const;
    int             getHp(void) const;
    int             getMaxHp(void) const;
    int             getMaxDmg(void) const;
    int             getSpeed(void) const;
    void            setX(int);
    void            setY(int);
    void            setYMax(int);
    void            setXMax(int);
    void            setHp(int);
    void            takeDamage(unsigned int amt);
    void            beRepaired(unsigned int amt);
    void            jumpTo(int x, int y);
    void            moveRight(void);
    void            moveUp(void);
    void            moveDown(void);
    void            moveLeft(void);
    void            drawSelf(void) const;


//    Actions                     _actions;

protected:

    char                        _rep;
    int                         _hp;
    unsigned int                _maxHp;
    unsigned int                _dmg;
    unsigned int                _maxDmg;
    unsigned int                _speed;
    int                         _x;
    int                         _y;
    int                         _xMax;
    int                         _yMax;

    static const std::string    **_options[];
};

#endif