#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char red_val[] = {0, LED_RED}, green_val[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
}

int led_set(int red_state, int green_state){
  // Only allow booleans
  if(red_state < 0 || red_state > 1 || green_state < 0 || red_state > 1)
    return 0;

  char ledFlags = 0;
  ledFlags |= red_state ? LED_RED : 0;
  ledFlags |= green_state ? LED_GREEN : 0;

  P1OUT &= (0xff - LEDS) | ledFlags;
  P1OUT |= ledFlags;
}

void led_update(){
  if(led_changed){
    char ledFlags = red_val[red_on] | green_val[green_on];

    P1OUT &= (0xff^LEDS) |ledFlags;
    P1OUT |=ledFlags;
    led_changed = 0;
  }
  
}

