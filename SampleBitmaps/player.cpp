#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

player::~player()
{
	al_destroy_bitmap(image);
}
player::player(int HEIGHT)
{

	image = al_create_bitmap(64,64);   
	if(!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//			custom sprite added from prev labs :D

	int px = 32;
	int py = 32;

	//spline stuffs
	float dress_points[8] = {
		px - 18, py + 17,
		px - 12, py + 21,
		px + 8, py + 21,
		px + 17, py + 17
	};

	al_draw_filled_rectangle(px + 6, py - 4, px - 6, py + 10, al_map_rgb(255, 0, 0)); // body
	al_draw_filled_circle(px, py - 10, 10, al_map_rgb(50, 50, 100)); //hair

	al_draw_filled_triangle(px + 5, py + 24, px, py + 32, px, py + 24, al_map_rgb(255, 255, 255)); //left leg
	al_draw_filled_triangle(px - 4, py + 24, px, py + 30, px, py + 24, al_map_rgb(130, 130, 130)); //right leg

	al_draw_filled_triangle(px, py, px + 20, py + 20, px - 20, py + 20, al_map_rgb(255, 0, 0)); //dress
	al_draw_filled_ellipse(px, py + 20, 16, 4, al_map_rgb(255, 0, 0)); // rounded dress bottom
	al_draw_spline(dress_points, al_map_rgb(255, 255, 255), 1); // dress thread
	al_draw_line(px + 6, py + 6, px - 5, py + 6, al_map_rgb(255, 255, 255), 2);//waist ribbon

	al_draw_filled_triangle(px + 6, py - 4, px + 21, py, px + 18, py + 12, al_map_rgb(255, 255, 255)); //left arm
	al_draw_filled_triangle(px - 6, py - 4, px - 21, py, px - 18, py + 12, al_map_rgb(255, 255, 255)); //right arm
	al_draw_line(px + 20, py, px + 16, py + 10, al_map_rgb(255, 0, 0), 2); //left arm thread
	al_draw_line(px - 20, py, px - 16, py + 10, al_map_rgb(255, 0, 0), 2); //right arm thread

	al_draw_filled_triangle(px, py - 18, px + 16, py - 24, px + 12, py - 8, al_map_rgb(255, 0, 0)); //left ribbon
	al_draw_filled_triangle(px, py - 18, px - 16, py - 24, px - 12, py - 8, al_map_rgb(255, 0, 0)); //right ribbon
	al_draw_line(px + 16, py - 24, px + 12, py - 8, al_map_rgb(255, 255, 255), 2); //left ribbon frill
	al_draw_line(px - 16, py - 24, px - 12, py - 8, al_map_rgb(255, 255, 255), 2); //right ribbon frill
	al_draw_line(px + 2, py - 18, px - 2, py - 18, al_map_rgb(255, 0, 0), 3); //ribbon knot

	al_draw_line(px - 20, py + 20, px - 28, py - 30, al_map_rgb(139, 69, 19), 2); //gohei stick
	al_draw_filled_rectangle(px - 28, py - 30, px - 30, py - 25, al_map_rgb(255, 255, 255)); //gohei white pattern
	al_draw_filled_rectangle(px - 30, py - 25, px - 32, py - 20, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(px - 28, py - 20, px - 30, py - 15, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(px - 30, py - 15, px - 32, py - 10, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(px - 28, py - 10, px - 30, py - 5, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(px - 30, py - 5, px - 32, py, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(px - 28, py, px - 30, py + 5, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(px - 30, py + 5, px - 32, py + 10, al_map_rgb(255, 255, 255));

	

	x = 20;
	y = HEIGHT / 2;

	speed = 7;
	dir = 0; //direction is now initialized to face up
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);

}
void player::DrawPlayer()
{
	//depending on the direction, the yin yang will be displayed in the proper direction
	//main sprite will flip accordingly too
	if (dir == 0) {
		al_draw_filled_circle(x + 32, y - 10, 7, al_map_rgb(255, 255, 255)); // white back circle

		al_draw_filled_circle(x + 32, y - 13, 4, al_map_rgb(255, 0, 0));
		al_draw_filled_triangle(x + 24, y - 9, x + 27, y - 16, x + 32, y - 14, al_map_rgb(255, 0, 0));
		al_draw_line(x + 27, y - 15, x + 32, y - 15, al_map_rgb(255, 0, 0), 1);
		al_draw_filled_circle(x + 32, y - 14, 1, al_map_rgb(255, 255, 255)); //white eye
		al_draw_filled_circle(x + 29, y - 7, 1, al_map_rgb(255, 0, 0)); //red eye

		al_draw_bitmap(image, x, y, 0);
	}
	else if (dir == 1) {
		al_draw_filled_circle(x + 32, y + 74, 7, al_map_rgb(255, 255, 255)); // white back circle

		al_draw_filled_circle(x + 32, y + 71, 4, al_map_rgb(255, 0, 0));
		al_draw_filled_triangle(x + 24, y + 75, x + 27, y + 68, x + 32, y + 70, al_map_rgb(255, 0, 0));
		al_draw_line(x + 27, y + 69, x + 32, y + 69, al_map_rgb(255, 0, 0), 1);
		al_draw_filled_circle(x + 32, y + 70, 1, al_map_rgb(255, 255, 255)); //white eye
		al_draw_filled_circle(x + 29, y + 77, 1, al_map_rgb(255, 0, 0)); //red eye

		al_draw_bitmap(image, x, y, ALLEGRO_FLIP_HORIZONTAL);
	}
	else if (dir == 2) {
		al_draw_filled_circle(x - 10, y + 32, 7, al_map_rgb(255, 255, 255)); // white back circle

		al_draw_filled_circle(x - 13, y + 32, 4, al_map_rgb(255, 0, 0));
		al_draw_filled_triangle(x - 9, y + 24, x - 16, y + 27, x - 14, y + 32, al_map_rgb(255, 0, 0));
		al_draw_line(x - 15, y + 27, x - 17, y + 30, al_map_rgb(255, 0, 0), 1);
		al_draw_filled_circle(x - 14, y + 32, 1, al_map_rgb(255, 255, 255)); //white eye
		al_draw_filled_circle(x - 7, y + 29, 1, al_map_rgb(255, 0, 0)); //red eye

		al_draw_bitmap(image, x, y, ALLEGRO_FLIP_HORIZONTAL);
	}
	else {
		al_draw_filled_circle(x + 74, y + 32, 7, al_map_rgb(255, 255, 255)); // white back circle

		al_draw_filled_circle(x + 71, y + 32, 4, al_map_rgb(255, 0, 0));
		al_draw_filled_triangle(x + 75, y + 24, x + 68, y + 27, x + 70, y + 32, al_map_rgb(255, 0, 0));
		al_draw_line(x + 69, y + 27, x + 67, y + 30, al_map_rgb(255, 0, 0), 1);
		al_draw_filled_circle(x + 70, y + 32, 1, al_map_rgb(255, 255, 255)); //white eye
		al_draw_filled_circle(x + 77, y + 29, 1, al_map_rgb(255, 0, 0)); //red eye

		al_draw_bitmap(image, x, y, 0);
	}
}

//all of these now set the direction to the appropriate number
void player::MoveUp()
{
	dir = 0;
	y -= speed;
	if(y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	dir = 1;
	y += speed;
	if(y > HEIGHT-boundy)
		y = HEIGHT-boundy;
}
void player::MoveLeft()
{
	dir = 2;
	x -= speed;
	if(x < 0)
		x = 0;
}
void player::MoveRight(int WIDTH)
{
	dir = 3;
	x += speed;
	if(x > WIDTH-boundx)
		x = WIDTH-boundx;
}

//assuming a given bad guy is alive, check if the coords overlap & move back one pixel-ish if so
void player::CollidePlayer(BadGuy BadGuys[], int cSize, int prevX, int prevY) {
	
	for (int j = 0; j < cSize; j++)
	{
		if (BadGuys[j].getLive())
		{
			if (x > (BadGuys[j].getX() - BadGuys[j].getBoundX()) &&
				x < (BadGuys[j].getX() + BadGuys[j].getBoundX()) &&
				y >(BadGuys[j].getY() - BadGuys[j].getBoundY()) &&
				y < (BadGuys[j].getY() + BadGuys[j].getBoundY()))
			{
				x = prevX;
				y = prevY;
			}
		}
	}
}