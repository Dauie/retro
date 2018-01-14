#ifndef STRONGENEMY_CLASS_HPP
#define STRONGENEMY_CLASS_HPP

#include "rush00.hpp"

class	StrongEnemy : public GameObj
{
private:

	int _curModCycle;
	int _cyclesPerDirChange;
	int _cyclesPerShot;
	
public:

	StrongEnemy(void);
	StrongEnemy(const StrongEnemy &obj);
	StrongEnemy(float dirX, float dirY, float posX, float posY);
	virtual	~StrongEnemy(void);

	void update(void);
	
//overloads:

	StrongEnemy	&operator=(StrongEnemy const &obj);
	
};

#endif
