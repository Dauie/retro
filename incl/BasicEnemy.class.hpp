#ifndef BASICENEMY_CLASS_HPP
#define BASICENEMY_CLASS_HPP

#include "GameObj.class.hpp"

class	BasicEnemy : public GameObj {

public:

	BasicEnemy(void);
	BasicEnemy(const BasicEnemy &obj);
	BasicEnemy(float dirX, float dirY, float posX, float posY);
	virtual ~BasicEnemy(void);
	
	void	update(void);
	
//overloads:

	BasicEnemy	&operator=(BasicEnemy const *obj);
	
}

#endif
