/* 
 * File:   player.h
 * Author: root
 *
 * Created on October 7, 2013, 3:40 PM
 */


#ifndef PLAYER_HEADER
#define	PLAYER_HEADER

#ifdef	__cplusplus
extern "C" {
#endif

#include <allegro.h>
#include <allegro5/allegro_image.h>
#include "../simple_shooter.h"

#define PLAYER_W 99
#define PLAYER_H 75
#define PLAYER_SPEED 9
    
    typedef struct {
        int x, y, dx, dy;
        ALLEGRO_BITMAP *image;
    } Player;
    Player player;
    
    ALLEGRO_BITMAP * init_player(void);
    void destroy_player(void);
    void draw_player(void);
    int increase_dx(int);
    int increase_dy(int);
    int increase_x(int);
    int increase_y(int);
    int set_dx(int);
    int set_dy(int);
    int set_x(int);
    int set_y(int);
    void player_shoot(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PLAYER_HEADER */

