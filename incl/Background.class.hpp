#ifndef BACKGROUND_CLASS_HPP
#define BACKGROUND_CLASS_HPP

#include "rush00.hpp"

class	Background {

private:

	int *_xpoints;
	int *_ypoints;
	int _curModCycle;
	int _size;
	
public:

	Background(void);
	Background(const Background &obj);
	virtual ~Background(void);
	
	void	update(void);
	void	draw(void);

	Background	&operator=(Background const &obj);
};

#endif
