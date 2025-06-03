#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "weapon.h"


weapon::~weapon()
{
	al_destroy_bitmap(image);
}
weapon::weapon()
{
	speed = 10;
	live = false;
	dir = 0;
	image = al_create_bitmap(64,64);   
	if(!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//			custom weapon sprite from prev labs added :D

	al_draw_filled_circle(32, 32, 14, al_map_rgb(255, 255, 255)); // white back circle

	al_draw_filled_circle(32, 32 - 6, 8, al_map_rgb(255, 0, 0));
	al_draw_filled_triangle(32 - 16, 32 + 2, 32 - 10, 32 - 12, 32, 32 - 8, al_map_rgb(255, 0, 0));
	al_draw_line(32 - 10, 32 - 10, 32, 32 - 10, al_map_rgb(255, 0, 0), 2);
	al_draw_filled_circle(32, 32 - 8, 2, al_map_rgb(255, 255, 255)); //white eye
	al_draw_filled_circle(32 - 6, 32 + 6, 2, al_map_rgb(255, 0, 0)); //red eye

	x = 0;
	y = 0;


	speed = 7;
	boundx = al_get_bitmap_width(image)/3;
	boundy = al_get_bitmap_height(image)/3;
	live=false;
	angle=0;

}
void weapon::Drawweapon()
{

	if(live){
		al_draw_scaled_rotated_bitmap(image,32,32,x,y,.5,.5,angle,0);
		angle+=.1;
	}
}

// takes direction as an arg in order to set the class's dir properly. doubles as a setter
void weapon::Fireweapon( player &Player, int direction)
{
	if(!live)
	{
		x = Player.getX() + Player.getBoundX()/2;
		y = Player.getY() + Player.getBoundY()/2;
		live = true;
		dir = direction;
	}
}

//now takes height in order to properly move & remove the weapon in motion
void weapon::Updateweapon(int WIDTH, int HEIGHT)
{
	if(live)
	{
		if (dir == 0) {
			y -= speed;
			if (y < 0)
				live = false;
		}
		else if (dir == 1) {
			y += speed;
			if (y > HEIGHT)
				live = false;
		}
		else if (dir == 2) {
			x -= speed;
			if (x < 0) {
				live = false;
			}
		}
		else if (dir == 3) {
			x += speed;
			if (x > WIDTH) {
				live = false;
			}
		}
	}
}
void weapon::Collideweapon(BadGuy BadGuys[], int cSize)
{
	if(live)
	{
		for(int j =0; j < cSize; j++)
		{
			if(BadGuys[j].getLive())
			{
				if(x > (BadGuys[j].getX() - BadGuys[j].getBoundX()) &&
					x < (BadGuys[j].getX() + BadGuys[j].getBoundX()) &&
					y > (BadGuys[j].getY() - BadGuys[j].getBoundY()) &&
					y < (BadGuys[j].getY() + BadGuys[j].getBoundY()))
				{
					live = false;
					BadGuys[j].setLive(false);
				}
			}
		}
	}

}

