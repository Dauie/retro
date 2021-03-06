

#include "rush00.hpp"


GameObj** Game::objs = new GameObj*[TOTALOBJ];

unsigned int Game::yMax = 0;
unsigned int Game::xMax = 0;
int Game::input = 0;
int Game::score = 0;

static void	create_game_setup(void)
{
	new Player;

	new Spawner(0.9 * (float)Game::xMax, Game::yMax, 70, 0, -0.2);
	new Spawner(0.7 * (float)Game::xMax, Game::yMax, 70, 10, -0.2);
	new Spawner(0.5 * (float)Game::xMax, Game::yMax, 70, 20, 0.2);
	new Spawner(0.3 * (float)Game::xMax, Game::yMax, 70, 30, 0.2);
}

Game::Game(void) {
    initscr();
    timeout(0);
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, xMax, yMax);
    start_color();
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_color(COLOR_GREEN, 200, 200, 200);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_RED);
	std::srand(time(NULL));
	if(has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
    _gameStart = clock();
    _lastRender = 0;


    /*Make Game Entities*/
	for (int i = 0; i < TOTALOBJ; i++) {
		objs[i] = nullptr;
	}
	_background = new Background;

	create_game_setup();
};


Game &Game::operator=(Game const &rhs) {
    if (this != &rhs) {
        return (*this);
    }
    return (*this);
}

Game::Game(const Game &obj) {
    *this = obj;
}

Game::~Game(void) {

    /*Delete Game Entities*/
	delete[] Game::objs;
    endwin();
}

int				Game::setInput(int c) {
	input = c;
	return (1);
}

clock_t			Game::getGameStart() const { return (_gameStart); }


void			Game::update() {
	for (int i = 0; i < TOTALOBJ; i++) {
		if (objs[i]) {
			objs[i]->update();
		}
	}
	_background->update();
}
void			Game::render() const
{
	for (int i = 0; i < TOTALOBJ; i++) {
		if (objs[i]) {
			objs[i]->draw();
		}
	}
	_background->draw();
	Game::scoreboard((objs[0]));
	Game::drawBorder();
	if (objs[0]==nullptr)
		Game::GameOver();
}

void	Game::drawBorder(void) const{
	attron(COLOR_PAIR(3));
	for (int i = 1; i < (int)yMax - 1; i++) {
		mvaddch(0,i,ACS_HLINE);
		mvaddch(xMax - 1,i,ACS_HLINE); }
	for (int i = 1; i < (int)xMax - 1; i++) {
		mvaddch(i,0,ACS_VLINE);
		mvaddch(i,yMax - 1,ACS_VLINE); }
	mvaddch(0,0,ACS_ULCORNER);
	mvaddch(0,yMax - 1,ACS_URCORNER);
	mvaddch(xMax - 1,0,ACS_LLCORNER);
	mvaddch(xMax - 1,yMax - 1,ACS_LRCORNER);
	attroff(COLOR_PAIR(3));
}

//void Game::updateLeaderBoard(void) const{
//
//	std::stringstream logmsg;
//	char msg[] = "Please enter initials:\n";
//	char res[32];
//	std::string ret;
//
//	nodelay(stdscr, FALSE);
//	attron(COLOR_PAIR(5));
//	clear();
//	mvprintw(Game::yMax / 2, Game::xMax / 2,"%s", msg);
//	addstr(msg);
//	doupdate();
//	refresh();
//	sleep(1);
//	getstr(res);
//	logmsg << res << " " << Game::score;
//	ret = logmsg.str();
//	mvprintw(Game::yMax / 2, (Game::xMax / 2) - 2,"%s", res);
//	mvprintw(Game::yMax / 2, (Game::xMax / 2) - 4,"%d", Game::score);
//	refresh();
//	time_t time = std::time(0);
//	struct tm * now = localtime(&time);
//	std::string stime = std::to_string(now->tm_year + 1900) + "_"
//						+ std::to_string(now->tm_mon + 1) + "_" +
//						std::to_string(now->tm_mday) + "_" + std::to_string(now->tm_hour) +
//						":" + std::to_string(now->tm_min);
//	 ret = stime + "\n\tmessage: " + ret + "\n";
//
//	std::ofstream out;
//
//	out.open("LeaderBoard.log", std::ios::out | std::ios::app );
//	out << ret;
//	out.close();
//}

void Game::GameOver() const{


	attron(COLOR_PAIR(5));
	mvprintw((xMax/2)-5,(yMax/2)-5,"%s","GAME OVER");
	doupdate();
	refresh();
	sleep(5);
	while (getch() == ERR)
		;
//	Game::updateLeaderBoard();
	this->~Game();
	exit(0);
}

void	Game::scoreboard(GameObj *p) const{
	int w;
	int l=0;

	if (!(p==nullptr))
		l=((Player *)(p))->getLives();
	attron(COLOR_PAIR(3));
	for (int i = 1; i < (int)yMax - 1; i++) {
		mvaddch(2,i,ACS_HLINE); }
	w = (yMax / 8) - 1;
	mvprintw(1,1,"%*s:%-*d",w,"Lives",w,l);
	addch(ACS_VLINE);
	printw("%*s:%-*d",w,"Score",w,score);
	addch(ACS_VLINE);
	printw("%*s:%-*d",w,"FPS",w,60);
	addch(ACS_VLINE);
	printw("%*s:%-*f",w,"TIME",w,((float)((clock()-_gameStart)/1000000.0)));
	mvaddch(2,0,ACS_LTEE);
	mvaddch(2,yMax - 1,ACS_RTEE);
	mvaddch(0,2*w+2,ACS_TTEE);
	mvaddch(0,4*w+4,ACS_TTEE);
	mvaddch(0,6*w+6,ACS_TTEE);
	mvaddch(2,2*w+2,ACS_BTEE);
	mvaddch(2,4*w+4,ACS_BTEE);
	mvaddch(2,6*w+6,ACS_BTEE);
	attroff(COLOR_PAIR(3));
}

//collision:

static bool	isbetween(float n, float a, float b)
{
	float error = 0.01;

	if (n <= a + error && n >= b - error)
		return (true);
	if (n >= a - error && n <= b + error)
		return (true);
	return (false);
}

static bool	objects_will_collide(GameObj *o1, GameObj *o2)
{

	float col_radius = 1;

	
	float x1p = o1->getXPos();
	float x1d = o1->getXDir();
	float y1p = o1->getYPos();
	float y1d = o1->getYDir();
	float x2p = o2->getXPos();
	float x2d = o2->getXDir();
	float y2p = o2->getYPos();
	float y2d = o2->getYDir();


	if (fabs(x1p - x2p) + fabs(y1p - y2p) < col_radius * 2)
		return (true);
	
	if (fabs(x1d) <= 0.01 && fabs(y1d) <= 0.01)
		x1d = 0.1;
	if (fabs(x2d) <= 0.01 && fabs(y2d) <= 0.01)
		x2d = 0.1;

	float l1a, l1b, l1c, l2a, l2b, l2c;

	l1a = y1d;
	l1b = -x1d;
	l1c = l1a * x1p + l1b * y1p;

	l2a = y2d;
	l2b = -x2d;
	l2c = l2a * x2p + l2b * y2p;

	float det = l1a * l2b - l2a * l1b;


	
	if (det == 0)
		return (false);

	float ix = (l2b * l1c - l1b * l2c) / det;
	float iy = (l1a * l2c - l2a * l1c) / det;

	if (isbetween(ix, x1p, x1p + x1d) &&
	    isbetween(iy, y1p, y1p + y1d) &&
	    isbetween(ix, x2p, x2p + x2d) &&
	    isbetween(iy, y2p, y2p + y2d))
	{
		return (true);
	}
	return (false);
}

void			Game::collision(void)
{
	for (int i = 0; i < COLLIDABLE; i++)
	{
		if (!objs[i])
			continue;
		for (int j = 1; j < COLLIDABLE; j++)
		{
			if (!objs[j])
				continue;
			//check to see if objects occupy same space
			if ( i != j && objects_will_collide(objs[i], objs[j]))
			{	
				if ((i==0 && objs[i]->getWall() == false) && (objs[j]->getWall() == false))
				{
					objs[i]->livingStatus(false);
					objs[j]->livingStatus(false);
				}
				if ((objs[i]->getWall() == false) && (objs[j]->getWall() == true && i !=0))
				{
					objs[i]->livingStatus(false);
					objs[j]->livingStatus(false);
				}

				if (objs[i]->getWall()!=objs[j]->getWall())
						score++;
			}
		}
		//check to see if objects are out of bounds
		if (i > 0 &&
		    (objs[i]->getYPos() >= (int)Game::yMax ||
		     objs[i]->getYPos() <= 0 ||
		     objs[i]->getXPos() >= (int)Game::xMax ||
		     objs[i]->getXPos()<= 0))
		{
			objs[i]->livingStatus(false);
			objs[i]->hitWall(true);
		}
	}
}
