#include "draw_shapes.h"    
#include "switches.h"
#include "buzzer.h"

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_GREEN;


void
draw_pos1(u_int center, u_int color) {
  fillRectangle((center + 6), (center + 10), 8, 40, color); //left_col, row, w, h
  fillRectangle((center + 14), (center + 2), 4, 64, color);
  fillRectangle((center + 18), (center + 2), 4, 64, color);
  fillRectangle((center + 22), (center - 15), 8, 81, color);
  fillRectangle((center + 26), (center - 15), 26, 8, color);
  fillRectangle((center + 30), (center + 2), 20, 48, color);
  fillRectangle((center + 48), (center - 15), 8, 81, color);
  fillRectangle((center + 56), (center + 2), 8, 64, color);
  fillRectangle((center + 64), (center + 10), 8, 40, color);
}

void
draw_pos2(u_int center, u_int color) {
  fillRectangle((center + 6), (center + 10), 8, 25, color); //left_col, row, w, h
  fillRectangle((center + 14), (center + 2), 4, 64, color);
  fillRectangle((center + 18), (center + 2), 4, 64, color);
  fillRectangle((center + 22), (center - 15), 8, 81, color);
  fillRectangle((center + 26), (center - 15), 26, 8, color);
  fillRectangle((center + 30), (center + 2), 20, 48, color);
  fillRectangle((center + 48), (center - 15), 8, 81, color);
  fillRectangle((center + 56), (center + 2), 8, 64, color);
  fillRectangle((center + 64), (center + 10), 8, 25, color);
}

void
draw_pos3(u_int center, u_int color) {
  fillRectangle((center - 10), (center + 10), 17, 10, color);
  fillRectangle((center + 6), (center + 10), 8, 10, color); //left_col, row, w, h
  fillRectangle((center + 14), (center + 2), 4, 64, color);
  fillRectangle((center + 18), (center + 2), 4, 64, color);
  fillRectangle((center + 22), (center - 15), 8, 81, color);
  fillRectangle((center + 26), (center - 15), 26, 8, color);
  fillRectangle((center + 30), (center + 2), 20, 48, color);
  fillRectangle((center + 48), (center - 15), 8, 81, color);
  fillRectangle((center + 56), (center + 2), 8, 64, color);
  fillRectangle((center + 64), (center + 10), 8, 10, color);
  fillRectangle((center + 68), (center + 10), 17, 10, color);
}

void
draw_ship(u_int x, u_int y, u_int color){
  fillRectangle((x - 1), (y - 1), 7, 3, color);//center
  fillRectangle((x - 2), (y - 4), 2, 12, color);//left wing
  fillRectangle((x + 2), (y + 2), 2, 4, color);//pilot 
  fillRectangle((x + 6), (y - 4), 2, 12, color);//right wing
  //left_col, row, w, h
}

void
draw_player(u_int x, u_int y, u_int color) {
  fillRectangle(x, y-1, 2, 11, color);//l start
  fillRectangle(x+2, y-1, 2, 11, color);//right start
  fillRectangle(x-2, y + 2, 2, 2, color);//top eye left
  fillRectangle(x + 4, y + 2, 2, 2, color);//top eye right
  fillRectangle(x - 2, y + 6, 2, 2, color);//bottom eye left
  fillRectangle(x + 4, y + 6, 2, 2, color);//bottom eye right
  fillRectangle(x - 4, y + 2, 2, 6, color);//left outer eye
  fillRectangle(x + 6, y + 2, 2, 6, color);//right outer eye
  fillRectangle(x-6, y + 4, 2, 4, color);
  fillRectangle(x + 8, y + 4, 2, 4, color);
  fillRectangle(x - 6, y + 8, 2, 8, color); //left ear
  fillRectangle(x + 8, y + 8, 2, 8, color); // right ear
  fillRectangle(x - 1, y + 12, 2, 2, color); // dust 1
  fillRectangle(x + 4, y + 14, 2, 2, color);
  fillRectangle(x - 1, y + 16, 2, 2, color);
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
draw_circle(int x, int y, int r, u_int color)
{
  int x_coord = x;
  int y_coord = y;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

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

