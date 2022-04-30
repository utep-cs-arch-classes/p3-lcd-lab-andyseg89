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
static char redraw_screen = 0;
static int enemy_counter = 0;

void draw_enemies(void) {
   if (drawing_enemies) {
    enemy_counter++;
    if (enemy_counter == 2) {
      draw_ship(30, 20, COLOR_GREEN);
      buzzer_set_period(1000);
    }
    else if (enemy_counter == 10) {
      buzzer_set_period(0);
    }
    else if (enemy_counter > 20 && enemy_counter < 22) {
      draw_ship(50, 20, COLOR_GREEN);
      buzzer_set_period(2000);
    }
    else if (enemy_counter == 35) {
      buzzer_set_period(0);
    }
    else if (enemy_counter > 35 && enemy_counter < 37) {
      draw_ship(70, 20, COLOR_GREEN);
      buzzer_set_period(3000);
    }
    else if (enemy_counter == 45) {
      buzzer_set_period(0);
    }
    else if (enemy_counter > 55 && enemy_counter < 57) {
      draw_ship(90, 20, COLOR_GREEN);
      buzzer_set_period(2000);
    }
    else if (enemy_counter > 70 && enemy_counter < 72) {
      draw_ship(30, 20, COLOR_BLUE);
      draw_ship(30, 40, COLOR_GREEN);
      buzzer_set_period(3000);
    }
    else if (enemy_counter > 85 && enemy_counter < 87) {
      draw_ship(50, 20, COLOR_BLUE);
      draw_ship(50, 40, COLOR_GREEN);
      buzzer_set_period(4000);
    }
    else if (enemy_counter > 104 && enemy_counter < 106) {
      draw_ship(70, 20, COLOR_BLUE);
      draw_ship(70, 40, COLOR_GREEN);
      buzzer_set_period(2000);
    }
    else if (enemy_counter > 120 && enemy_counter < 122) {
      buzzer_set_period(5000);
      draw_ship(90, 20, COLOR_BLUE);
      draw_ship(90, 40, COLOR_GREEN);
      drawing_enemies = 0;
    }
  }
}

void ship(void){
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
    buzzer_set_period(1000);
  }
  else {
    buzzer_set_period(0);
  }
  if (shoot) {
    buzzer_set_period(3000);
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
}

void gun(void) {
  if (shoot){
    shoot = 0;
  }
}
