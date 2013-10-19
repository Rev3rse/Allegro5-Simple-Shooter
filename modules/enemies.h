/* 
 * File:   enemy.h
 * Author: root
 *
 * Created on October 10, 2013, 3:32 AM
 */

#ifndef ENEMIES_H
#define	ENEMIES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../simple_shooter.h"
#include <allegro.h>
#include <allegro5/allegro_image.h>
#include "bullets.h"
#include "gravity_bullets.h"

#define NUM_ENEMIES 15
#define ENEMY_H 50
#define ENEMY_W 98
#define ENEMY_Y_THRESHOLD 150
#define ENEMY_HP 2
    typedef struct {
        Location location;
        Acceleration acceleration;
        int health_pts, current_health_pts, live, follow_player;
        ALLEGRO_BITMAP *image;
        GravityBullets *puller;

    } Enemy;

    extern Enemy enemies[NUM_ENEMIES];

    void init_enemies(void);
    void draw_enemies(void);
    void update_enemies(void);
    void spawn_enemies(int);
    void enemy_hit(int index, BULLET_TYPE type);
    int enemies_live(void);
    void enemy_pull_towards(int index, GravityBullets *puller);


#ifdef	__cplusplus
}
#endif

#endif	/* ENEMIES_H */

