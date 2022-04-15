#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

extern short redrawScreen;

/* draws an hourglass shape */
void update_shape(void);
void draw_pos1(u_int center);
void draw_pos2(u_int center);
void draw_pos3(u_int center);

#endif // _DRAW_SHAPES_H_
