#include "explosion_bullets.h"
#include "player.h"
#include "enemies.h"
#include "box_collision.h"
#include <allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>


static ALLEGRO_BITMAP *shared_image;
static ALLEGRO_BITMAP *shared_explode_image;
static int explode = 0;
static int second_ellapsed = 0;
static int regen_bullet = 1;
ExplosionBullet explosion_bullets[NUM_EXPLOSION_BULLETS];

void
init_explosion_bullets (void)
{
  int i;
  shared_image = al_load_bitmap ("assets/png/laserRed.png");
  shared_explode_image = al_load_bitmap ("assets/png/laserRedShot.png");
  for (i = 0; i < NUM_EXPLOSION_BULLETS; i++)
    {
      explosion_bullets[i].acceleration.y = -EXPLOSION_BULLET_SPEED;
      explosion_bullets[i].radius = EXPLOSION_BULLET_RADIUS;
      explosion_bullets[i].live = 0;
      explosion_bullets[i].type = EXPLOSION;
      explosion_bullets[i].explode = 0;

    }
}

void
fire_explosion_bullet (void)
{
  if (regen_bullet == 1)
    {
      int i;
      for (i = 0; i < NUM_EXPLOSION_BULLETS; i++)
        {
          if (explosion_bullets[i].live == 0)
            {
              explosion_bullets[i].live = 1;
              explosion_bullets[i].location.x = get_x () + PLAYER_W / 2.15; //Somehow the bullet isn't fired from the middle.
              explosion_bullets[i].location.y = get_y ();
              regen_bullet = 0;
              break;
            }
        }
    }
}

void
draw_explosion_bullets (void)
{
  int i;

  for (i = 0; i < NUM_EXPLOSION_BULLETS; i++)
    {
      if (explosion_bullets[i].live == 1)
        {
          al_draw_bitmap (shared_image, explosion_bullets[i].location.x, explosion_bullets[i].location.y, 0);

        }
      if (explosion_bullets[i].explode == 1)
        {

          al_draw_scaled_bitmap (shared_explode_image, 0, 0, 56, 54, explosion_bullets[i].location.x - EXPLOSION_W / 2, explosion_bullets[i].location.y - EXPLOSION_H / 2, EXPLOSION_W, EXPLOSION_H, 0);

        }
    }

}

void
update_explosion_bullets (void)
{
  int i;

  for (i = 0; i < NUM_EXPLOSION_BULLETS; i++)
    {
      if (explosion_bullets[i].live == 1)
        {
          if (explosion_bullets[i].location.y < 0)
            {
              explosion_bullets[i].live = 0;
            }
          explosion_bullets[i].location.y += explosion_bullets[i].acceleration.y;

        }
    }
}

void
explosion_bullet_hit (int index)
{
  explosion_bullets[index].live = 0;
  //Do explosion effect on the next frame
  explosion_bullets[index].explode = 1;

  //Do the actual damage(damaging all nearby enemy ships):

  int i;
  for (i = 0; i < NUM_ENEMIES; i++)
    {
      if (detect_inside_area (explosion_bullets[index].location.x + EXPLOSION_BULLET_W / 2, explosion_bullets[index].location.y + EXPLOSION_BULLET_H / 2, EXPLOSION_W, EXPLOSION_H, enemies[i].location.x, enemies[i].location.y, ENEMY_W, ENEMY_H))
        { //An enemy was found within explosion area.
          enemy_hit (i, EXPLOSION);
        }
    }
}

void
explosion_timer (void)
{

  if (second_ellapsed == 0)
    {
      second_ellapsed = 1;
    }
  else
    {
      second_ellapsed = 0;

      int i;

      for (i = 0; i < NUM_EXPLOSION_BULLETS; i++)
        {

          if (explosion_bullets[i].explode == 1)
            {
              explosion_bullets[i].explode = 0;
            }

        }

    }
}

void
regen_explosion_bullet (void)
{
  regen_bullet = 1;
}