#include "draw_shapes.h"    
#include "switches.h"
#include "buzzer.h"

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_GREEN;


void
draw_pos1(u_int center) {
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
draw_pos2(u_int center) {
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
draw_pos3(u_int center) {
  fillRectangle((center - 10), (center + 10), 17, 10, COLOR_GREEN);
  fillRectangle((center + 6), (center + 10), 8, 10, COLOR_GREEN); //left_col, row, w, h
  fillRectangle((center + 14), (center + 2), 4, 64, COLOR_GREEN);
  fillRectangle((center + 18), (center + 2), 4, 64, COLOR_GREEN);
  fillRectangle((center + 22), (center - 15), 8, 81, COLOR_GREEN);
  fillRectangle((center + 26), (center - 15), 26, 8, COLOR_GREEN);
  fillRectangle((center + 30), (center + 2), 20, 48, COLOR_GREEN);
  fillRectangle((center + 48), (center - 15), 8, 81, COLOR_GREEN);
  fillRectangle((center + 56), (center + 2), 8, 64, COLOR_GREEN);
  fillRectangle((center + 64), (center + 10), 8, 10, COLOR_GREEN);
  fillRectangle((center + 68), (center + 10), 17, 10, COLOR_GREEN);
}



void
update_shape(void)
{
  static unsigned char row = screenHeight / 2, col = screenWidth / 2;
  static char blue = 31, green = 0, red = 31;
  static unsigned char step = 0;
  if (switches & SW4) return;
  if (step <= 60) {
    int startCol = col - step;
    int endCol = col + step;
    int width = 1 + endCol - startCol;
    // a color in this BGR encoding is BBBB BGGG GGGR RRRR
    unsigned int color = (blue << 11) | (green << 5) | red;
    fillRectangle(startCol, row+step, width, 1, color);
    fillRectangle(startCol, row-step, width, 1, color);
    if (switch3_down){
      green = (green + 1) % 64;
      buzzer_set_period(1000);
    }
    if (switch2_down){
      blue = (blue + 2) % 32;
      buzzer_set_period(3000);
    }
    if (switch1_down) red = (red - 3) % 32;
    step ++;
  } else {
     clearScreen(COLOR_BLUE);
     step = 0;
  }
}

