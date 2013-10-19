#include "enemy_bullets.h"
#include "enemies.h"
EnemyBullet enemy_bullets[NUM_ENEMY_BULLETS];

void
init_enemy_bullets (void)
{

  int i;

  for (i = 0; i < NUM_ENEMY_BULLETS; i++)
    {
      enemy_bullets[i].live = 0;
      enemy_bullets[i].type = FLARE;


    }
  Location location = {100, 150};
  fire_enemy_bullet (location);
}

void
update_enemy_bullets (void)
{
  int i;

  for (i = 0; i < NUM_ENEMY_BULLETS; i++)
    {
      if (enemy_bullets[i].live == 1)
        {
          enemy_bullets[i].location.y += ENEMY_BULLET_SPEED;
        }
    }

}

void
draw_enemy_bullets (void)
{

  int i;

  for (i = 0; i < NUM_ENEMY_BULLETS; i++)
    {
      if (enemy_bullets[i].live == 1)
        {

          al_draw_filled_circle (enemy_bullets[i].location.x, enemy_bullets[i].location.y, ENEMY_BULLET_SIZE, al_map_rgb (50, 255, 50));
        }
    }
}

void
fire_enemy_bullet (Location location)
{

  int i;

  for (i = 0; i < NUM_ENEMY_BULLETS; i++)
    {
      if (enemy_bullets[i].live == 0)
        {
          enemy_bullets[i].location = location;
          enemy_bullets[i].live = 1;
          break;
        }
    }
}