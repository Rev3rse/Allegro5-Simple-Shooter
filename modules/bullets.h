/* 
 * File:   bullets.h
 * Author: root
 *
 * Created on October 7, 2013, 6:34 PM
 */

#ifndef BULLETS_H
#define	BULLETS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../simple_shooter.h"
#include "../includes/bullet_types.h"
#define NUM_BULLETS 10
#define BULLET_SPEED 12
#define BULLET_SIZE 2


    typedef struct {
        Location location;
        int speed;
        int live;
        BULLET_TYPE type;

    } Bullet;

    extern Bullet bullets[NUM_BULLETS];

    void init_bullets(void);
    void fire_bullet(void);
    void update_bullets(void);
    void draw_bullets(void);
    void bullet_hit(int index);

#ifdef	__cplusplus
}
#endif

#endif	/* BULLETS_H */

