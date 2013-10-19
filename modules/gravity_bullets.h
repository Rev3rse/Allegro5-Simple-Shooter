/* 
 * File:   gravity_bullets.h
 * Author: root
 *
 * Created on October 12, 2013, 12:40 AM
 */

#ifndef GRAVITY_BULLETS_H
#define	GRAVITY_BULLETS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../simple_shooter.h"
#include "../includes/bullet_types.h"
#define NUM_GRAVITY_BULLETS 1
#define GRAVITY_BULLET_SPEED 5
#define GRAVITY_BULLET_AREA 125
#define GRAVITY_BULLET_SIZE 10
    typedef struct {
        Location location;
        int speed, live;
        BULLET_TYPE type;
        //The ship's acceleration will by set to effect.
        Acceleration effect;

    } GravityBullets;


    extern GravityBullets gravity_bullets[NUM_GRAVITY_BULLETS];

    void init_gravity_bullets(void);
    void draw_gravity_bullets(void);
    void update_gravity_bullets(void);


#ifdef	__cplusplus
}
#endif

#endif	/* GRAVITY_BULLETS_H */

