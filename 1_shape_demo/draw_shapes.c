#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

void
draw_monito(u_int center) {
  fillRectangle((center + 6), (center + 10), 8, 40, COLOR_GREEN); //left_col, row, w, h
  fillRectangle((center + 14), (center + 2), 4, 64, COLOR_GREEN);
  fillRectangle((center + 18), (center + 2), 4, 64, COLOR_GREEN);
  fillRectangle((center + 22), (center - 15), 8, 81, COLOR_GREEN);
  fillRectangle((center + 26), (center - 15), 26, 8, COLOR_GREEN);
  fillRectangle((center + 30), (center + 2), 20, 48, COLOR_GREEN);
  fillRectangle((center + 48), (center - 15), 8, 81, COLOR_GREEN);
  fillRectangle((center + 56), (center + 2), 8, 64, COLOR_GREEN);
  fillRectangle((center + 64), (center + 10), 8, 40, COLOR_GREEN);
}

void
draw_monito2(u_int center) {
  fillRectangle((center + 6), (center + 10), 8, 25, COLOR_GREEN); //left_col, row, w, h
  fillRectangle((center + 14), (center + 2), 4, 64, COLOR_GREEN);
  fillRectangle((center + 18), (center + 2), 4, 64, COLOR_GREEN);
  fillRectangle((center + 22), (center - 15), 8, 81, COLOR_GREEN);
  fillRectangle((center + 26), (center - 15), 26, 8, COLOR_GREEN);
  fillRectangle((center + 30), (center + 2), 20, 48, COLOR_GREEN);
  fillRectangle((center + 48), (center - 15), 8, 81, COLOR_GREEN);
  fillRectangle((center + 56), (center + 2), 8, 64, COLOR_GREEN);
  fillRectangle((center + 64), (center + 10), 8, 25, COLOR_GREEN);
}

void
draw_rectangle(void)
{
  int height = 10;
  int width  = 60;
  int row = 20, col = screenWidth / 2;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 16, green = 0, red = 31;
  u_int color = (blue << 11) | (green << 5) | red;

  fillRectangle(left_col, row, width, height, color);
}

void
border(void) {
  drawRectOutline(0, 0, 125, 158, COLOR_LIME_GREEN);
  drawRectOutline(10, 10, 100, 140, COLOR_YELLOW);
}


void
draw_triangle(void)
{
  int height = 40;
  int row = 80, col = screenWidth / 2;

  int step = 0;

  int blue = 31, green = 0, red = 31;

  u_int color = (blue << 11) | (green << 5) | red;

  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < height; step++) {
    // left side of triangle
    u_char start_col = col - (step / 2);
    // right side of triangle
    u_char end_col   = col + (step / 2);
    u_char width     = end_col - start_col;
    fillRectangle(col - (step / 2), row+step, width, 1, color);
  }
}


void
drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void
drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color)
{
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void
draw_circle(void)
{
  int x_coord = screenWidth / 2;
  int y_coord = 60;
  int r = 20;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  u_int color = COLOR_SIENNA;

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
  

