#include "player.h"
#include <stdio.h>
#include "display.h"



static ALLEGRO_BITMAP *player_img = NULL;



void
destroy_player (void)
{
  al_destroy_bitmap (player.image);
  player.x = 0;
  player.y = 0;
  player.dx = 0;
  player.dy = 0;

}

ALLEGRO_BITMAP *
init_player (void)
{


  player.image = al_load_bitmap ("assets/png/player.png");
  player.x = SCREEN_W / 2 - 75;
  player.y = SCREEN_H - 100;
  return player.image;

}

void
draw_player (void)
{
  al_draw_bitmap (player.image, player.x, player.y, 0);
}
int
increase_dx (int amount)
{
  player.dx += amount;
}

increase_dy (int amount)
{
  player.dy += amount;
}

increase_x (int amount)
{
  player.x += amount;
}

increase_y (int amount)
{
  player.y = +amount;
}

int
set_dx (int amount)
{
  player.dx = amount;
}

int
set_dy (int amount)
{
  player.dy = amount;
}

int
get_x (void)
{
  return player.x;
}

int
get_y (void)
{
  return player.y;
}

int
set_x (int amount)
{
  player.x = amount;
}

int
set_y (int amount)
{
  player.y = amount;
}