#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "rush00.hpp"
#include <ctime>
#include <cmath>
#include "GameObj.class.hpp"
#include "Background.class.hpp"


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
	void					collision();
	int						setInput(int c);
    void                    drawBorder(void) const;
    void                    scoreboard(GameObj *p) const;
    void                    GameOver() const;

	static unsigned int    xMax;
	static unsigned int    yMax;
	static int             input;
	static GameObj         **objs;
	static int              score;

private:
	clock_t         _gameStart;
	clock_t         _lastRender;
	unsigned int    _frames;
	unsigned int    _fps;
	Background *_background;
};

#endif
