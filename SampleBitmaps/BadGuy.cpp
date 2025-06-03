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

	al_draw_filled_rectangle(12, 8, 50, 56, al_map_rgb(128, 0, 128)); //background book
	al_draw_line(20, 8, 20, 56, al_map_rgb(64, 0, 64), 3); //spine indent
	al_draw_line(12, 56, 50, 56, al_map_rgb(255, 255, 200), 4); //pageline
	al_draw_filled_rectangle(23, 15, 45, 46, al_map_rgb(25, 9, 68)); //cover square
	al_draw_filled_triangle(34, 25, 27, 40, 41, 40, al_map_rgb(255, 255, 0)); //triangle on cover

	boundx = al_get_bitmap_width(image)*.75;
	boundy = al_get_bitmap_height(image)*.75;
	live = false;

}
void BadGuy::DrawBadGuy()
{


	if(live)
	{
		al_draw_bitmap(image,x,y,0);
	}

}
void BadGuy::StartBadGuy(int WIDTH, int HEIGHT )
{

	if(!live)
	{
		if(rand() % 500 == 0)
		{
			live = true;
			do{
				x =  rand() % (WIDTH - boundx); 
			}while (x <100);
			do{
				y =  rand() % (HEIGHT - boundy);
			}while (y<100);

		}
	}
}

void BadGuy::CollideSelf(BadGuy BadGuys) {
	if (BadGuys.getLive())
	{
		if (x > (BadGuys.getX() - BadGuys.getBoundX()) &&
			x < (BadGuys.getX() + BadGuys.getBoundX()) &&
			y >(BadGuys.getY() - BadGuys.getBoundY()) &&
			y < (BadGuys.getY() + BadGuys.getBoundY()))
		{
			live = false;
		}
	}
}


