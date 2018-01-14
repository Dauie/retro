#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "rush00.hpp"
#include <ctime>
#include <cmath>
#include "GameObj.class.hpp"



class Game {

public:
    Game(void);
    Game &operator=(Game const &rhs);
    Game(const Game &obj);
    ~Game(void);
    void                    update(void);
    void                    render(void) const;
    unsigned int            getFps(void) const;
    clock_t                 getGameStart() const;
	clock_t					getProcStart() const;
	void					setProcStart(clock_t start);
	void					collision();
	int						setInput(int c);

	static unsigned int    xMax;
	static unsigned int    yMax;
	static int             input;
	static GameObj         **objs;

private:
    clock_t         _gameStart;
	clock_t			_procStart;
    clock_t         _lastRender;
    unsigned int    _frames;
    unsigned int    _fps;
};

#endif
