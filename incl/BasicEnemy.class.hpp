#ifndef BASICENEMY_CLASS_HPP
#define BASICENEMY_CLASS_HPP

#include "GameObj.class.hpp"

//this is unfinished!

class	BasicEnemy : public GameObj {

public:

	BasicEnemy(void);
	BasicEnemy(const BasicEnemy &obj);
	virtual ~BasicEnemy(void);
	
	void	update(void);
	
//overloads:

	BasicEnemy	&operator=(BasicEnemy const *obj);
	
}

#endif
