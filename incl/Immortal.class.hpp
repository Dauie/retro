#ifndef IMMORTAL_CLASS_HPP
#define IMMORTAL_CLASS_HPP

#include "rush00.hpp"

class	Immortal : public GameObj
{

private:

	int _lives;
	
public:

	static bool active;
	
	Immortal(void);
	Immortal(const Immortal &obj);
	Immortal(float dirX, float dirY, float posX, float posY);
	virtual	~Immortal(void);

	void	bullet_hell(void);
	void	update(void);
	void	draw(void);
	
	Immortal	&operator=(Immortal const &obj);
};

#endif
