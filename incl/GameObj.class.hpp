#ifndef GAMEOBJ_CLASS_HPP
#define GAMEOBJ_CLASS_HPP

#include <iostream>
#include <string>
#include <ncurses.h>

#define UP (int)'w'
#define DOWN (int)'s'
#define LEFT (int)'a'
#define RIGHT (int)'d'
#define FIRE (int)' '

class GameObj {

public:

	GameObj(void);
	GameObj(const GameObj &obj);
	~GameObj(void);

//setters and getters:
	
	float	getXDir(void) const;
	float	getYDir(void) const;
	float	getXPos(void) const;
	float	getYPos(void) const;
	
	void	setXDir(float);
	void	setYDir(float);
	void	setXPos(float);
	void	setYPos(float);

	bool	isAlive(void) const;
	void	LivingStatus(bool);

	char	getRep(void) const;
	void	setRep(char);

//other stuff:

	virtual void	update(void) = 0;
	void	move(void);
	virtual void	draw(void);

//overloads:
	
	GameObj	&operator=(GameObj const &rhs);

protected:

	char _rep;
	bool _alive;
	float _dirX;
	float _dirY;
	float _posX;
	float _posY;	

};

#endif
