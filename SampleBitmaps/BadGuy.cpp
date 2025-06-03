#include "BadGuy.h"
BadGuy::~BadGuy()
{
	al_destroy_bitmap(image);
}
BadGuy::BadGuy()
{
	image = al_create_bitmap(64,64);   
	if(!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	x = 0;
	y = 0;


	//		new custom enemy sprite of a cursed book :D

	al_draw_filled_rectangle(12, 8, 50, 56, al_map_rgb(128, 0, 128)); //background book
	al_draw_line(20, 8, 20, 56, al_map_rgb(64, 0, 64), 3); //spine indent
	al_draw_line(12, 56, 50, 56, al_map_rgb(255, 255, 200), 4); //pageline
	al_draw_filled_rectangle(23, 15, 45, 46, al_map_rgb(25, 9, 68)); //cover square
	al_draw_filled_triangle(34, 25, 27, 40, 41, 40, al_map_rgb(255, 255, 0)); //triangle on cover

	boundx = al_get_bitmap_width(image)*.75;
	boundy = al_get_bitmap_height(image)*.90;
	live = false;

}
void BadGuy::DrawBadGuy()
{
	if(live)
	{
		al_draw_bitmap(image,x,y,0);
	}

}

//now takes said badguy object pointer & the number of them to check collisions
void BadGuy::StartBadGuy(int WIDTH, int HEIGHT, BadGuy* BadGuys, int numBadGuys)
{
	if (!live) {
		if (rand() % 500 == 0) {

			// while it hasn't been broken from, this creates the potential bad guy coords.
			// it then grabs each other bad guy in existence's coords & saves them, checking each one against the 
			// new potential coords. If there's no colission, it sets the coords to the new potential coords & alles gut.
			// if there is a coordinate overlap, we set colission to true & exit the for loop checker, essentially ignoring
			// the new coords & looping back around until it works. I had the most trouble getting this to work.
			while (true) {

				bool collision = false;

				int newX = rand() % (WIDTH - boundx);
				int newY = rand() % (HEIGHT - boundy);

				for (int i = 0; i < numBadGuys; i++) {
					int secondX = BadGuys[i].x;
					int secondY = BadGuys[i].y;

					if (abs(newX - secondX) < boundx && abs(newY - secondY) < boundy) {
						collision = true;
						break;
					}
				}

				if (!collision) {
					x = newX;
					y = newY;
					live = true;
					break;
				}
			}
		}
	}
}


