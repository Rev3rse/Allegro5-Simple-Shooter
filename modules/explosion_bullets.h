/* 
 * File:   exploision_bullets.h
 * Author: root
 *
 * Created on October 12, 2013, 8:47 AM
 */

#ifndef EXPLOISION_BULLETS_H
#define	EXPLOISION_BULLETS_H

#ifdef	__cplusplus
extern "C" {
#endif
#define EXPLOSION_BULLET_SPEED 2.2
#define EXPLOSION_BULLET_RADIUS 35
#define NUM_EXPLOSION_BULLETS 1
#define EXPLOSION_BULLET_W 9
#define EXPLOSION_BULLET_H 33
#define EXPLOSION_H 162
#define EXPLOSION_W 168
#define EXPLOSION_BULLET_REGEN_TIME 10.0
#include "../simple_shooter.h"
#include "../includes/bullet_types.h"
    typedef struct {
        Location location;
        Acceleration acceleration;
        int radius;
        int live;
        int explode;
        BULLET_TYPE type;

    } ExplosionBullet;
    
    extern ExplosionBullet explosion_bullets[NUM_EXPLOSION_BULLETS];
    void init_explosion_bullets(void);
    void update_explosion_bullets(void);
    void draw_explosion_bullets(void);
    void fire_explosion_bullet(void);
    void explosion_timer(void);
    void regen_explosion_bullet(void);

#ifdef	__cplusplus
}
#endif

#endif	/* EXPLOSION_BULLETS_H */

