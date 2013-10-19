/* 
 * File:   enemy_bullets.h
 * Author: root
 *
 * Created on October 14, 2013, 3:09 AM
 */

#ifndef ENEMY_BULLETS_H
#define	ENEMY_BULLETS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../simple_shooter.h"
#include "../includes/bullet_types.h"
#define ENEMY_BULLET_SPEED 10
#define NUM_ENEMY_BULLETS 45
#define ENEMY_BULLET_SIZE 2

    typedef struct {
        Location location;
        BULLET_TYPE type;
        int live;
    } EnemyBullet;

    extern EnemyBullet enemy_bullets[NUM_ENEMY_BULLETS];

    void init_enemy_bullets(void);
    void update_enemy_bullets(void);
    void draw_enemy_bullets(void);
    void fire_enemy_bullet(Location location);

#ifdef	__cplusplus
}
#endif

#endif	/* ENEMY_BULLETS_H */

