#include "state_machines.h"
#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "draw_ship.h"

unsigned int game = 0;
unsigned int animation = 0;

static int dance_counter = 0;
static int game_counter = 0;
static int enemy_counter = 0;

void run_game(void) {
  ship();
}

void dance(void){
    dance_counter++;
    if (dance_counter == 1) {
      clearScreen(COLOR_BLUE);
      draw_pos1(30, COLOR_GREEN);
      buzzer_set_period(1000);
      char message[] = "look at him go!";
      drawString5x7(25, 100, message, COLOR_RED, COLOR_BLUE); 
    }
    else if (dance_counter > 15 && dance_counter < 17) {
      buzzer_set_period(0);
      draw_pos1(30, COLOR_BLUE);
    }
    else if (dance_counter > 17 && dance_counter < 32) {
      draw_pos3(30, COLOR_GREEN);
      buzzer_set_period(2000);
      char message[] = "he's on a mission";
      drawString5x7(25, 100, message, COLOR_RED, COLOR_BLUE);
    }
    else if (dance_counter > 32 && dance_counter < 34) {
      draw_pos3(30, COLOR_BLUE);
      buzzer_set_period(0);
    }
    else if (dance_counter > 34 && dance_counter < 50) {
      draw_pos4(30);
      buzzer_set_period(3000);
      char message[] = "to destroy capitalism";
      drawString5x7(5, 100, message, COLOR_RED, COLOR_BLUE); 
    }
    else if (dance_counter > 50) {
      clearScreen(COLOR_BLUE);
      dance_counter = 0;
      buzzer_set_period(0);
    }
}


