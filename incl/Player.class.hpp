

#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "rush00.hpp"

class Player : public GameObj {

public:
    Player(void);
    Player &operator=(Player const &rhs);
    Player(const Player &obj);
    ~Player(void);

    void fireBullet(void);
    void update(void);
	void move(float dirX, float dirY);
	int  getLives() const;
	
private:
    unsigned int    _lives;
};

#endif //CPP_PLAYER_CLASS_HPP
