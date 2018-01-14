
#ifndef BULLET_CLASS_HPP
#define BULLET_CLASS_HPP

#include "rush00.hpp"

class  Bullet : public GameObj {

public:
    Bullet(void);
    Bullet(float dirY, float posX, float posY);
    Bullet &operator=(Bullet const &rhs);
    Bullet(const Bullet &obj);
    ~Bullet(void);

	void        checkPos(void);
	void		move(float x, float y);
	void		update(void);

private:
};


#endif //CPP_BULLET_CLASS_HPP
