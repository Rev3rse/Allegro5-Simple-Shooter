#include "bullets.h"
#include "player.h"
#include <allegro.h>
#include <allegro5/allegro_primitives.h>


/*Gets bullet default X location(based on player's current location)*/
static int bullet_get_location_x (void);

void
init_bullets (void)
{
  int i;

  for (i = 0; i < NUM_BULLETS; i++)
    {
      bullets[i].live = 0;
      //As the bullets move toward y = 0, the bullet's speed has to be negative.
      bullets[i].speed = -BULLET_SPEED;
      bullets[i].location.x = get_x () + PLAYER_W / 2;
      bullets[i].location.y = get_y ();
      bullets[i].type = FLARE;



    }
}

void
draw_bullets (void)
{
  int i;
  for (i = 0; i < NUM_BULLETS; i++)
    {
      if (bullets[i].live == 1)
        {
          al_draw_filled_circle (bullets[i].location.x, bullets[i].location.y, BULLET_SIZE, al_map_rgb (255, 0, 0));
        }
    }
}

void
fire_bullet (void)
{
  int i;
  /*Find a dead bullet and recycle it.*/
  for (i = 0; i < NUM_BULLETS; i++)
    {
      if (bullets[i].live == 0)
        {
          bullets[i].live = 1;
          bullets[i].location.x = bullet_get_location_x ();
          bullets[i].location.y = get_y ();
          break;
        }
    }
}

void
update_bullets (void)
{
  int i = 0;

  for (i = 0; i < NUM_BULLETS; i++)
    {
      if (bullets[i].live == 1)
        {
          if (bullets[i].location.y < 0) //i.e., out of screen
            {
              bullets[i].live = 0; //Flag it for recycle.

            }
          else // Within screen
            {
              //Move it forward.
              bullets[i].location.y += bullets[i].speed;


            }


        }

    }
}

static int
bullet_get_location_x (void)
{
  return get_x () + PLAYER_W / 2;
}

void
bullet_hit (int index)
{
  bullets[index].live = 0;


}