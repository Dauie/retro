//
// Created by Robert LUTT on 1/13/18.
//

#ifndef PARTICLE_CLASS_HPP

#include "rush00.hpp"

class		Particle : GameObj {

public:

	Particle(void);
	Particle(float posX, float posY);
	Particle(const Particle &obj);
	virtual ~Particle(void);

	int		getTtl() const;
	void	setTtl(int);
	void	update(void);
	void	move(float, float);

	Particle	&operator=(Particle const &obj);

private:
	int		_ttl;

};

#define PARTICLE_CLASS_HPP

#endif //RETRO_PARTICLE_CLASS_HPP
