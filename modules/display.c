#include "display.h"
#include "../simple_shooter.h"


static ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_DISPLAY *
init_display (void)
{
  display = al_create_display (SCREEN_W, SCREEN_H);

  return display;

}

ALLEGRO_DISPLAY *
get_display (void)
{
  return display;
}