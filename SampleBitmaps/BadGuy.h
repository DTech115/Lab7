//DT Nesimi

#ifndef BADGUYH
#define BADGUYH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

class BadGuy
{
public:
	BadGuy();
	~BadGuy();
	void DrawBadGuy();
	void StartBadGuy(int WIDTH, int HEIGHT, BadGuy* BadGuys, int numBadGuys); //now takes a pointer to a badguy object + the num of them for colission spawning
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}
	bool getLive() {return live;}
	void setLive(bool l){live=l;}

private:
	int x;
	int y;
	bool live;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP *image;
};

#endif