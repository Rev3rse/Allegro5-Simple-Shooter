#include "enemies.h"
#include "gravity_bullets.h"
#include <stdlib.h>
static Location enemy_random_location ();
static Acceleration enemy_random_acceleration ();

static Acceleration
enemy_random_acceleration ()
{

  Acceleration acceleration = {1.5, 0.5};

  //50% of enemy ships will go accelerate to the other side(heading towards up)

  if (random_in_range (0, 2)) acceleration.y *= -1;

  return acceleration;
}

void
init_enemies (void)
{
  int i;
  ALLEGRO_BITMAP *shared_enemy_ship_image = al_load_bitmap ("assets/png/enemyShip.png");
  for (i = 0; i < NUM_ENEMIES; i++)
    {
      enemies[i].health_pts = ENEMY_HP;
      enemies[i].location = enemy_random_location ();
      enemies[i].live = 0;
      enemies[i].follow_player = random_in_range (0, 2); //50% will follow the player
      enemies[i].acceleration = enemy_random_acceleration ();
      enemies[i].image = shared_enemy_ship_image;
      enemies[i].puller = NULL;

    }
}

void
draw_enemies (void)
{

  int i;

  for (i = 0; i < NUM_ENEMIES; i++)
    {
      if (enemies[i].live == 1)
        {
          al_draw_bitmap (enemies[i].image, enemies[i].location.x, enemies[i].location.y, 0);
        }
    }

}

void
spawn_enemy (void)
{
  int i;
  for (i = 0; i < NUM_ENEMIES; i++)
    {
      if (enemies[i].live == 0)
        {
          enemies[i].live = 1;
          enemies[i].location = enemy_random_location ();
          enemies[i].health_pts = ENEMY_HP + level;

          break;
        }
    }
}

void
spawn_enemies (int num)
{

  int i;

  for (i = 0; i < num; i++)
    {
      spawn_enemy ();
    }
}

void
update_enemies (void)
{

  int i;

  for (i = 0; i < NUM_ENEMIES; i++)
    {
      if (enemies[i].live == 1)
        {
          enemies[i].location.x += enemies[i].acceleration.x;
          enemies[i].location.y += enemies[i].acceleration.y;

          if (enemies[i].puller != NULL) //i.e., this enemy ship is being pulled
            {
              if (enemies[i].puller->live == 0) //The puller is dead; stop following him!
                {
                  enemies[i].acceleration = enemy_random_acceleration ();
                  

                }
            }
          
          //Unstuck enemies
          if(enemies[i].acceleration.x == 0 || enemies[i].acceleration.y == 0)
            {
              enemies[i].acceleration = enemy_random_acceleration ();
            }
          
          //Enemy ship x-axis alignment to the player ship:
          if (enemies[i].follow_player == 1)
            {
              if (enemies[i].location.x > get_x ())
                {
                  if (enemies[i].acceleration.x > 0)
                    enemies[i].acceleration.x *= -1; //Reverse acceleration.
                }
              else if (enemies[i].location.x < get_x ())
                {
                  if (enemies[i].acceleration.x < 0)
                    {
                      enemies[i].acceleration.x *= -1;
                    }
                }
              else if (enemies[i].location.x == get_x ())
                {
                  enemies[i].acceleration.x = 0;
                }
            }

          //Enemy ships can't leave the display
          if (enemies[i].location.x > SCREEN_W - ENEMY_W)
            {
              if (enemies[i].acceleration.x > 0)
                enemies[i].acceleration.x *= -1; //Reverse X acceleration
            }
          if (enemies[i].location.x < 0)
            {
              if (enemies[i].acceleration.x < 0)
                {
                  enemies[i].acceleration.x *= -1; //Reverse X acceleration
                }
            }
          //Enemy ships can't go too high or too close to the player ship
          if (enemies[i].location.y < 0 || enemies[i].location.y > ENEMY_Y_THRESHOLD)
            {
              enemies[i].acceleration.y *= -1; //Reverse Y acceleration.

            }

        }
      //Cleanup dead enemies
      if (enemies[i].health_pts <= 0)
        {
          enemies[i].live = 0;
        }
    }
}

static Location
enemy_random_location (void)
{
  Location location;
  location.x = get_random_location ().x;
  location.y = random_in_range (25, 100);

  return location;


}

void
enemy_hit (int index, BULLET_TYPE type)
{

  if (type == FLARE)
    {
      enemies[index].health_pts--;


    }
  if (type == EXPLOSION)
    {
      enemies[index].health_pts -= 3;
    }

}

int
enemies_live (void)
{
  int i;
  int num_alive = 0;
  for (i = 0; i < NUM_ENEMIES; i++)
    {
      if (enemies[i].live == 1)
        {
          num_alive++;
        }
    }

  return num_alive;
}

void
enemy_pull_towards (int index, GravityBullets *puller)
{

  enemies[index].puller = puller;
  
  /*Pull the enemy towards the gravity bullet by setting the acceleration to the direction of bullet(both X and Y)*/
  if ((*puller).location.x > enemies[index].location.x)
    {
      enemies[index].acceleration.x = (*puller).effect.x;
    }
  if ((*puller).location.x < enemies[index].location.x)
    {
      enemies[index].acceleration.x = -(*puller).effect.x;
    }
  if ((*puller).location.y > enemies[index].location.y)
    {
      enemies[index].acceleration.y = (*puller).effect.y;
    }
  if ((*puller).location.y < enemies[index].location.y)
    {
      enemies[index].acceleration.y = -(*puller).effect.y;

    }
}