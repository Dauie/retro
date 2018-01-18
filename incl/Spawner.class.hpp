#ifndef SPAWNER_CLASS_HPP
#define SPAWNER_CLASS_HPP

#include "rush00.hpp"

class	Spawner : public GameObj {

private:

	int _curModCycle;
	int _cyclesPerSpawn;
	float	_angle;
	float _reverse;
	
	Spawner(void);
	
public:

	Spawner(const Spawner &obj);
	Spawner(float posX, float posY, int cyclesPerSpawn, int sync, float reverse);
	virtual ~Spawner(void);

	void	update(void);

//overloads:
	Spawner	&operator=(Spawner const &obj);
};

#endif
