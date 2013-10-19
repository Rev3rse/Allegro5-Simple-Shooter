/* 
 * File:   main.c
 * Author: root
 *
 * Created on October 6, 2013, 7:20 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "modules/box_collision.h"
#include "modules/player.h"
#include "simple_shooter.h"
#include "modules/display.c"
#include "modules/bullets.h"
#include "modules/enemies.h"
#include "modules/box_collision.h"
#include "modules/gravity_bullets.h"
#include "modules/explosion_bullets.h"
#include "modules/enemy_bullets.h"

/*
 * 
 */

enum KEY_ENUM
{
  KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

//Include externals
int level;
int spawn_enemies_flag;

int
main (int argc, char** argv)
{

  /*Initialize game components.*/
  ALLEGRO_TIMER *timer = NULL;
  ALLEGRO_TIMER *second_timer = NULL; //A timer to tick every second.
  ALLEGRO_TIMER *explosion_bullet_regen_timer = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  bool key[4] = {false, false, false, false};
  bool redraw = true;
  level = 1;
  spawn_enemies_flag = 1;


  //Initialize core
  if (!al_init ())
    {
      fprintf (stderr, "Failed to initialize Allegro5.\n");
      return (EXIT_FAILURE);
    }

  //Initialize keyboard component
  if (!al_install_keyboard ())
    {
      fprintf (stderr, "Failed to install keyboard.\n");
      return (EXIT_FAILURE);
    }

  //Initialize FPS timer(used to regularate FPS)
  timer = al_create_timer (1.0 / FPS);
  if (!timer)
    {
      fprintf (stderr, "Failed to initialize timer.\n");
      return (EXIT_FAILURE);
    }
  //Initialize second(as in time) timer(for secondly events)
  second_timer = al_create_timer (1.0);
  if (!second_timer)
    {
      fprintf (stderr, "Failed to initialize second timer.\n");
      al_destroy_timer (timer);
      return (EXIT_FAILURE);
    }

  explosion_bullet_regen_timer = al_create_timer (EXPLOSION_BULLET_REGEN_TIME);
  if (!explosion_bullet_regen_timer)
    {
      al_destroy_timer (timer);
      al_destroy_timer (second_timer);

      fprintf (stderr, "Failed to initialize timer. \n");
      return (EXIT_FAILURE);
    }
  //Initialize display
  ALLEGRO_DISPLAY *display = init_display ();

  if (!display)
    {
      fprintf (stderr, "Failed to initialize display.\n");
      al_destroy_timer (timer);
      al_destroy_timer (second_timer);
      al_destroy_timer (explosion_bullet_regen_timer);
      return (EXIT_FAILURE);
    }

  //Initialize event queue(to listen for events - such as keyboard, timer, etc.)
  event_queue = al_create_event_queue ();
  if (!event_queue)
    {
      fprintf (stderr, "Failed to initialize event queue\n");
      al_destroy_timer (timer);
      al_destroy_timer (second_timer);
      al_destroy_timer (explosion_bullet_regen_timer);
      al_destroy_display (display);
      return (EXIT_FAILURE);
    }

  //Initialize image addon(to load image files)
  if (!al_init_image_addon ())
    {
      fprintf (stderr, "Failed to initialize image addon\n");
      al_destroy_timer (timer);
      al_destroy_timer (second_timer);
      al_destroy_timer (explosion_bullet_regen_timer);
      al_destroy_display (display);
      al_destroy_event_queue (event_queue);

      return (EXIT_FAILURE);

    }

  //Initialize player and load his image.
  ALLEGRO_BITMAP *player_img = init_player ();
  if (!player_img)
    {
      al_destroy_timer (timer);
      al_destroy_timer (second_timer);
      al_destroy_timer (explosion_bullet_regen_timer);
      al_destroy_display (display);
      fprintf (stderr, "Failed to load player's graphics.\n");
      return (EXIT_FAILURE);
    }
  //Initialize player objects.
  init_bullets ();
  init_gravity_bullets ();
  init_explosion_bullets ();
  //Initialize enemy objects.
  init_enemies ();
  init_enemy_bullets ();

  /*Register events*/
  al_register_event_source (event_queue, al_get_display_event_source (display));
  al_register_event_source (event_queue, al_get_timer_event_source (timer));
  al_register_event_source (event_queue, al_get_timer_event_source (second_timer));
  al_register_event_source (event_queue, al_get_timer_event_source (explosion_bullet_regen_timer));
  al_register_event_source (event_queue, al_get_keyboard_event_source ());


  al_start_timer (timer);
  al_start_timer (second_timer);
  al_start_timer (explosion_bullet_regen_timer);

  ALLEGRO_BITMAP *background_image = al_load_bitmap ("/root/NB_PROJECTS/Simple Shooter/assets/png/Background/starBackground.png");

  /*Game loop.*/
  while (1)
    {
      ALLEGRO_EVENT ev;
      al_wait_for_event (event_queue, &ev);

      //Leave loop upon clicking X.
      if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
          break;
        }
      //A timer called to regen explosion bullets
      if (ev.timer.source == explosion_bullet_regen_timer)
        {
          regen_explosion_bullet ();
        }
      //A timer called every second.
      if (ev.timer.source == second_timer)
        {
          
          explosion_timer ();
        }
      //Frames
      if (ev.timer.source == timer)
        {
          redraw = true;
          update_bullets ();
          update_gravity_bullets ();
          update_explosion_bullets ();
          update_enemies ();
          update_enemy_bullets();


          //collision detector
          collision_detector ();



          /*Spawn enemies depending on level*/
          if (spawn_enemies_flag == 1)
            {
              spawn_enemies_flag = 0;

              //Span enemies depending on level.
              switch (level)
                {
                case 1:
                  spawn_enemies (5);
                  break;
                case 2:
                  spawn_enemies (7);
                  break;
                }
            }

          /*Update level on finish*/
          if (enemies_live () == 0)
            {
              level++;
              spawn_enemies_flag = 1;

            }

          //Movement key listeners: 
          if (key[KEY_LEFT] && get_x () > 0)
            {
              increase_x (-PLAYER_SPEED);
            }
          if (key[KEY_RIGHT] && get_x () < SCREEN_W - PLAYER_W)
            {
              increase_x (PLAYER_SPEED);
            }


        }
        //Key listeners
      else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {

          switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_RIGHT:
              key[KEY_RIGHT] = true;
              break;
            case ALLEGRO_KEY_LEFT:
              key[KEY_LEFT] = true;
              break;
            case ALLEGRO_KEY_UP:
              fire_bullet ();
              break;
            case ALLEGRO_KEY_Z:
              fire_gravity_bullet ();
              break;
            case ALLEGRO_KEY_X:
              fire_explosion_bullet ();
              break;
            }
        }
      else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
          switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_RIGHT:
              key[KEY_RIGHT] = false;
              break;
            case ALLEGRO_KEY_LEFT:
              key[KEY_LEFT] = false;
              break;
            }
        }

      /*Drawings goes here (triggered by redraw = true from the timer).*/
      if (redraw && al_is_event_queue_empty (event_queue))
        {
          redraw = false;
          al_clear_to_color (al_map_rgb (0, 0, 0));

          /*Redraw visual components to the display.*/
          al_draw_scaled_bitmap (background_image, 0, 0, 254, 256, 0, 0, SCREEN_W, SCREEN_H, 0); //Draw background
          draw_player ();
          draw_bullets ();
          draw_gravity_bullets ();
          draw_explosion_bullets ();
          draw_enemies ();
          draw_enemy_bullets ();



          al_flip_display ();
        }

    }

  al_destroy_display (display);
  destroy_player ();
  al_destroy_event_queue (event_queue);
  al_destroy_timer (timer);
  al_destroy_timer (second_timer);
  al_destroy_timer (explosion_bullet_regen_timer);

  return (EXIT_SUCCESS);
}

