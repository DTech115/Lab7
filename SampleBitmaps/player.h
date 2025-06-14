//DT Nesimi
#ifndef PLAYERH
#define PLAYERH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "BadGuy.h"

class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight(int WIDTH);
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}

	void CollidePlayer(BadGuy BadGuys[], int cSize, int prevX, int prevY); //new collision checker that tkaes the badguys & compares coords
	
private:
	int x;
	int y;
	int speed;
	int dir; //dir variable added back
	int boundx;
	int boundy;
	ALLEGRO_BITMAP *image;
};
#endif

