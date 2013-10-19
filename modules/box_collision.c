#include "box_collision.h"
#include "bullets.h"
#include "enemies.h"
#include "gravity_bullets.h"
#include "explosion_bullets.h"


static int detect_collision (int, int, int, int, int, int, int, int);

Bullet bullets[NUM_BULLETS];
Enemy enemies[NUM_ENEMIES];

static int
detect_collision (int a_x, int a_y, int a_h, int a_w, int b_x, int b_y, int b_h, int b_w)
{

  if (a_x >= b_x + b_w ||
      a_y >= b_y + b_h ||
      b_x >= a_x + a_w ||
      b_y >= a_y + a_h)
    {

      return 0; //No collision
    }

  return 1; //Collision detected.
}

int
detect_inside_area (float area_center_x, float area_center_y, float area_w, float area_h, float target_x, float target_y, float target_w, float target_h)
{

  if (area_center_x + area_w > target_x + target_w / 2 &&
      area_center_x - area_w < target_x + target_w / 2 &&
      area_center_y + area_h > target_y + target_h / 2 &&
      area_center_y - area_h < target_y + target_h / 2)
    {
      return 1; //inside area
    }
  return 0; //outside area.


}

void
collision_detector (void)
{
  int i;

  //Check collision for normal bullets(AKA FLARE bullets) : 
  for (i = 0; i < NUM_BULLETS; i++)
    {
      if (bullets[i].live == 1)
        {
          int j;
          for (j = 0; j < NUM_ENEMIES; j++)
            {
              if (enemies[j].live == 1)
                {

                  if (detect_collision (bullets[i].location.x, bullets[i].location.y, BULLET_SIZE, BULLET_SIZE, enemies[j].location.x, enemies[j].location.y, ENEMY_H * 0.9, ENEMY_W * 0.9))//Multiply by 0.9 to make the boundary smaller, for more accurate detection.
                    { //Collision detected - the bullet did hit an enemy ship.


                      bullet_hit (i);
                      enemy_hit (j, bullets[i].type);
                      break;

                    }

                }
            }
        }
    }
  //Check collision for gravity bullets (AKA GRAVITY) :
  for (i = 0; i < NUM_GRAVITY_BULLETS; i++)
    {
      if (gravity_bullets[i].live == 1)
        {
          int j;
          for (j = 0; j < NUM_ENEMIES; j++)
            {
              if (enemies[j].live == 1)
                {

                  /*Checking collision for gravity bullet doesn't mean that the bullet hits an enemy directly.
                   The gravity bullet has a field that pulls enemies closer, so the collision area of the gravity bullet is NOT the
                   actual bullet size - it's a much bigger size that represents the area of the gravity bullet.*/
                  if (detect_inside_area (gravity_bullets[i].location.x + GRAVITY_BULLET_SIZE / 2, gravity_bullets[i].location.y + GRAVITY_BULLET_SIZE / 2, GRAVITY_BULLET_AREA, GRAVITY_BULLET_AREA, enemies[j].location.x, enemies[j].location.y, ENEMY_W, ENEMY_H))
                    {//The enemy is within the bullet's range.

                      enemy_pull_towards (j, &gravity_bullets[i]);
                    }

                }
            }
        }
    }

  //Check collisions for explosion bullets (AKA EXPLOSION) :
  for (i = 0; i < NUM_EXPLOSION_BULLETS; i++)
    {
      if (explosion_bullets[i].live == 1)
        {
          int j;
          for (j = 0; j < NUM_ENEMIES; j++)
            {
              if (enemies[j].live == 1)
                if (detect_collision (explosion_bullets[i].location.x, explosion_bullets[i].location.y, EXPLOSION_BULLET_H, EXPLOSION_BULLET_W, enemies[j].location.x, enemies[j].location.y, ENEMY_H, ENEMY_W))
                  {
                    explosion_bullet_hit(i);
                    break;
                  }
            }
        }
    }


}

