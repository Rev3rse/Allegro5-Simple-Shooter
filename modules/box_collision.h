/* 
 * File:   box_collision.h
 * Author: root
 *
 * Created on October 7, 2013, 2:40 PM
 */

#ifndef BOX_COLLISION_H
#define	BOX_COLLISION_H

#ifdef	__cplusplus
extern "C" {
#endif

        
    /*This function detects collision between bullets and enemy ships. Called within the main loop.*/
    void collision_detector(void);
 int detect_inside_area (float, float, float, float, float, float, float, float);


#ifdef	__cplusplus
}
#endif

#endif	/* BOX_COLLISION_H */

