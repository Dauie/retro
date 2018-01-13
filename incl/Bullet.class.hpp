//
// Created by Robert LUTT on 1/12/18.
//

#ifndef BULLET_CLASS_HPP
#define BULLET_CLASS_HPP

#include "GameObj.class.hpp"

class   Bullet : public GameObj {

public:
    Bullet(void);
    Bullet(int);
    Bullet &operator=(Bullet const &rhs);
    Bullet(const Bullet &obj);
    ~Bullet(void);
    void    setDirection(int);
    int     getDirection(void) const;
    void    updateSelf(int x, int y);

private:
    /*Greater than 0 right, less than 0 left*/
    int _direction;
};


#endif //CPP_BULLET_CLASS_HPP
