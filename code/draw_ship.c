#include "draw_ship.h"
#include "state_machines.h"
#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"

char move_left;
char move_right;
char shoot;
char honk;
char drawing_enemies = 1;

static char x = 60;
static char y = 120;
static char old_x = 0;
static char velocity = 2;
static char gun_x = 0;
static char gun_y = 0;
static char redraw_screen = 0;
static int enemy_counter = 0;
static int gun_counter = 0;
static int dance_counter = 0;

void draw_enemies(void) {
   if (drawing_enemies) {
    enemy_counter++;
    if (enemy_counter == 1) {
      draw_ship(30, 20, COLOR_GREEN);
      buzzer_set_period(1000);
    }
    else if (enemy_counter == 10) {
      buzzer_set_period(0);
    }
    else if (enemy_counter == 15) {
      draw_ship(50, 20, COLOR_GREEN);
      buzzer_set_period(2000);
    }
    else if (enemy_counter == 25) {
      buzzer_set_period(0);
    }
    else if (enemy_counter == 30) {
      draw_ship(70, 20, COLOR_GREEN);
      buzzer_set_period(3000);
    }
    else if (enemy_counter == 40) {
      buzzer_set_period(0);
    }
    else if (enemy_counter == 45) {
      draw_ship(90, 20, COLOR_GREEN);
      buzzer_set_period(4000);
    }
    else if (enemy_counter == 60) {
      draw_ship(30, 20, COLOR_BLUE);
      draw_ship(30, 40, COLOR_GREEN);
      buzzer_set_period(4000);
    }
    else if (enemy_counter == 75) {
      draw_ship(50, 20, COLOR_BLUE);
      draw_ship(50, 40, COLOR_GREEN);
      buzzer_set_period(3000);
    }
    else if (enemy_counter == 90) {
      draw_ship(70, 20, COLOR_BLUE);
      draw_ship(70, 40, COLOR_GREEN);
      buzzer_set_period(2000);
    }
    else if (enemy_counter == 105) {
      buzzer_set_period(4000);
      draw_ship(90, 20, COLOR_BLUE);
      draw_ship(90, 40, COLOR_GREEN);
      drawing_enemies = 0;
    }
  }
}

void gun(void) {
  if (shoot){
    if (gun_x == 0) {
      gun_x = x;
      gun_y = y - 10;
    }
    gun_counter ++;
    if (gun_counter == 1) {
      drawRectOutline(gun_x, gun_y, 2, 2, COLOR_WHITE);
    }
    else if (gun_counter == 10) {
      drawRectOutline(gun_x, gun_y, 2, 2, COLOR_BLUE);
      drawRectOutline(gun_x, gun_y - 10, 2, 2, COLOR_WHITE);
    }
    else if (gun_counter == 20) {
      drawRectOutline(gun_x, gun_y - 10, 2, 2, COLOR_BLUE);
      drawRectOutline(gun_x, gun_y - 20, 2, 2, COLOR_WHITE);
    }    
    else if (gun_counter == 30) {
      drawRectOutline(gun_x, gun_y - 20, 2, 2, COLOR_BLUE);
      drawRectOutline(gun_x, gun_y - 30, 2, 2, COLOR_WHITE);
    }
    else if (gun_counter == 40) {
      drawRectOutline(gun_x, gun_y - 30, 2, 2, COLOR_BLUE);
      drawRectOutline(gun_x, gun_y - 40, 2, 2, COLOR_WHITE);
    }
    else if (gun_counter == 50) {
      drawRectOutline(gun_x, gun_y - 40, 2, 2, COLOR_BLUE);
      drawRectOutline(gun_x, gun_y - 50, 2, 2, COLOR_WHITE);
    }
    else if (gun_counter == 60) {
      drawRectOutline(gun_x, gun_y - 50, 2, 2, COLOR_BLUE);
      drawRectOutline(gun_x, gun_y - 60, 2, 2, COLOR_WHITE);
    }    
    else if (gun_counter == 70) {
      drawRectOutline(gun_x, gun_y - 60, 2, 2, COLOR_BLUE);
      draw_circle(gun_x, gun_y - 60, 10, COLOR_RED);
    }
    else if (gun_counter == 80) {
      draw_circle(gun_x, gun_y - 60, 20, COLOR_RED);
    }
    else if (gun_counter == 85) {
      draw_circle(gun_x, gun_y - 60, 40, COLOR_RED);
    }
    else if (gun_counter == 90) {
      draw_circle(gun_x, gun_y - 60, 80, COLOR_RED);
    }
    else if (gun_counter == 95) {
      clearScreen(COLOR_RED);
      game = 0;
      animation = 1;
    }
  }
}

void dance(void){
    dance_counter++;
    if (dance_counter == 1) {
      clearScreen(COLOR_BLUE);
      draw_pos1(30, COLOR_GREEN);
      buzzer_set_period(1000);
      char message[] = "steal";
      drawString5x7(55, 100, message, COLOR_RED, COLOR_BLUE); 
    }
    else if (dance_counter > 15 && dance_counter < 17) {
      buzzer_set_period(0);
      draw_pos1(30, COLOR_BLUE);
    }
    else if (dance_counter > 17 && dance_counter < 32) {
      draw_pos2(30, COLOR_GREEN);
      buzzer_set_period(2000);
      char message[] = "from";
      drawString5x7(55, 110, message, COLOR_RED, COLOR_BLUE);
    }
    else if (dance_counter > 32 && dance_counter < 34) {
      draw_pos2(30, COLOR_BLUE);
      buzzer_set_period(0);
    }
    else if (dance_counter > 34 && dance_counter < 50) {
      draw_pos3(30, COLOR_GREEN);
      buzzer_set_period(3000);
      char message[] = "walmart";
      drawString5x7(55, 120, message, COLOR_RED, COLOR_BLUE); 
    }
    else if (dance_counter > 50) {
      clearScreen(COLOR_BLUE);
      dance_counter = 0;
      buzzer_set_period(0);
    }
}

void ship(void){
  //state();
  if (game) {
    if (move_left) {
      if (x - velocity > 10) {
	old_x = x;
	x -= velocity;
	redraw_screen = 1;
      }
    }
    else if (move_right) {
      if (x + velocity < 115) {
	old_x = x;
	x += velocity;
	redraw_screen = 1;
      }
    }
    if (honk) {
      buzzer_set_period(2000);
    }
    else {
      buzzer_set_period(0);
    }
    if (redraw_screen) {
      draw_player(old_x, y, COLOR_BLUE);
      draw_player(x, y, COLOR_RED);
      redraw_screen = 0;
    }
    draw_enemies();
    gun();
  }
  if (animation) {
    drawing_enemies = 0;
    dance();
    if (honk) {
      clearScreen(COLOR_BLUE);
      animation = 0;
      game = 1;
      shoot = 0;
      gun_counter = 0;
      dance_counter = 0;
      enemy_counter = 0;
      gun_x = 0;
      gun_y = 0;
      drawing_enemies = 1;
    }
  }
}
