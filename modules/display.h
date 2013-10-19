/* 
 * File:   display.h
 * Author: root
 *
 * Created on October 7, 2013, 5:37 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <allegro.h>

     ALLEGRO_DISPLAY *init_display(void);
     ALLEGRO_DISPLAY *get_display(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

