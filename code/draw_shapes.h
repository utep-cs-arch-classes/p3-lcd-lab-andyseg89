#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

extern short redrawScreen;

/* draws an hourglass shape */
void draw_pos1(u_int center, u_int color);
void draw_pos2(u_int center, u_int color);
void draw_pos3(u_int center, u_int color);
void draw_ship(u_int x, u_int y, u_int color);
void draw_player(u_int x, u_int y, u_int color);
void draw_circle(int x, int y, int r, u_int color);
void drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color);
void drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR);

#endif // _DRAW_SHAPES_H_
