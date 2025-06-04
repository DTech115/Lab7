//DT Nesimi

#ifndef WEAPONH
#define WEAPONH
#include "BadGuy.h"
#include "player.h"
class weapon
{
public:
	weapon();
	~weapon();
	void Drawweapon();
	void Fireweapon(player &Player, int direction); //takes direction now to set later
	void Updateweapon(int WIDTH, int HEIGHT); // now takes the height for proper aim
	void Collideweapon(BadGuy BadGuys[], int cSize);
private:
	int x;
	int y;
	int boundx;
	int boundy;
	bool live;
	int speed;
	int dir; //also has direction again
	float angle;
	ALLEGRO_BITMAP *image;
};
#endif
