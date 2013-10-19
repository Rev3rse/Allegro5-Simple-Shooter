/* 
 * File:   simple_shooter.h
 * Author: root
 *
 * Created on October 7, 2013, 5:03 PM
 */

#ifndef SIMPLE_SHOOTER_H
#define	SIMPLE_SHOOTER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FPS 60
#define SCREEN_W 640
#define SCREEN_H 480

#include <stdlib.h>

    typedef struct {
        float x, y;
    } Location;
    typedef struct {
        float x, y;
    } Acceleration;
    /*Game's modify-able globals.*/
    //===============================
    
    extern int level; // Current level.
    extern int spawn_enemies_flag;//If set to 1 a new pair of enemies will be spawned depending on _level_.
    
    //===============================

    static inline int random_in_range(unsigned int min, unsigned int max) {
        int base_random = rand(); /* in [0, RAND_MAX] */
        if (RAND_MAX == base_random) return random_in_range(min, max);
        /* now guaranteed to be in [0, RAND_MAX) */
        int range = max - min,
                remainder = RAND_MAX % range,
                bucket = RAND_MAX / range;
        /* There are range buckets, plus one smaller interval
           within remainder of RAND_MAX */
        if (base_random < RAND_MAX - remainder) {
            return min + base_random / bucket;
        } else {
            return random_in_range(min, max);
        }
    }

    static inline Location get_random_location(void) {
        Location location;

        location.x = random_in_range(50, SCREEN_W - 50); //get a random X coordinate that is a bit within screen width. 
        location.y = random_in_range(50, SCREEN_H - 50); // Get a random Y coordinate that is a bit within screen height. 

        return location;
    }


#ifdef	__cplusplus
}
#endif

#endif	/* SIMPLE_SHOOTER_H */

