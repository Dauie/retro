#ifndef SPAWNER_CLASS_HPP
#define SPAWNER_CLASS_HPP

#include "GameObj.class.hpp"

class	Spawner : pubic GameObj {

private:

	int _curModCycle;
	int _cyclesPerSpawn;
	Spawner(void);
	
public:

	Spawner(const Spawner &obj);
	Spawner(float posX, float posY, int cyclesPerSpawn);
	virtual ~Spawner(void);

	void	update(void);

//overloads:

	Spawner	&operator=(Spawner const *obj);
}

#endif
