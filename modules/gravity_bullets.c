#include <allegro5/allegro_primitives.h>

#include "gravity_bullets.h"
#include "../includes/bullet_types.h"
#include "allegro.h"
#include "allegro5/allegro_image.h"
#include "player.h"

GravityBullets gravity_bullets[NUM_GRAVITY_BULLETS];


void
init_gravity_bullets (void)
{

  int i;

  for (i = 0; i < NUM_GRAVITY_BULLETS; i++)
    {
      gravity_bullets[i].live = 0;
      gravity_bullets[i].speed = -GRAVITY_BULLET_SPEED;
      gravity_bullets[i].type = GRAVITY;

      //Bullet's effect on pulled objects' acceleration.
      gravity_bullets[i].effect.x = 2.5;
      gravity_bullets[i].effect.y = 2.5;

    }
}

void
draw_gravity_bullets (void)
{

  int i;

  for (i = 0; i < NUM_GRAVITY_BULLETS; i++)
    {
      if (gravity_bullets[i].live == 1)
        {
          al_draw_filled_circle (gravity_bullets[i].location.x, gravity_bullets[i].location.y, GRAVITY_BULLET_SIZE, al_map_rgb (139, 0, 204));
        }
    }
}

void
fire_gravity_bullet (void)
{
  int i;

  for (i = 0; i < NUM_GRAVITY_BULLETS; i++)
    {
      if (gravity_bullets[i].live == 0)
        {
          gravity_bullets[i].live = 1;
          gravity_bullets[i].location.y = get_y ();
          gravity_bullets[i].location.x = get_x () + PLAYER_W / 2;
          break;
        }
    }
}

void
update_gravity_bullets (void)
{
  int i;

  for (i = 0; i < NUM_GRAVITY_BULLETS; i++)
    {
      if (gravity_bullets[i].live == 1)
        {
          gravity_bullets[i].location.y += gravity_bullets[i].speed;

        }
      //Delete out of screen bullets
      if (gravity_bullets[i].live == 1 && gravity_bullets[i].location.y < 0)
        {
          gravity_bullets[i].live = 0;
        }
    }
}