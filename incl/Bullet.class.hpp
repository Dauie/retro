//
// Created by Robert LUTT on 1/12/18.
//

#ifndef BULLET_CLASS_HPP
#define BULLET_CLASS_HPP

#include "GameObj.class.hpp"

class   Bullet : public GameObj {

public:
    Bullet(void);
    Bullet(float x, float y);
    Bullet &operator=(Bullet const &rhs);
    Bullet(const Bullet &obj);
    ~Bullet(void);

	void        checkPos(void);

private:
};


#endif //CPP_BULLET_CLASS_HPP
