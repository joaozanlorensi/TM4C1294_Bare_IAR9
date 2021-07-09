#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "driverlib/systick.h"
#include "driverleds.h" // Projects/drivers

// MEF com apenas 2 estados e 1 evento temporal que alterna entre eles
// Seleção por estado

typedef enum {COUNT_0, COUNT_1, COUNT_2, COUNT_3, COUNT_4, COUNT_5, COUNT_6, COUNT_7} state_t;

volatile uint8_t Evento = 0;

void SysTick_Handler(void){
  Evento = 1;
} // SysTick_Handler

void main(void){
  static state_t Estado = COUNT_0; // estado inicial da MEF
  
  LEDInit(LED1);
  LEDInit(LED2);
  LEDInit(LED3);

  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  SysTickIntEnable();
  SysTickEnable();

  while(1){
    if(Evento){
      Evento = 0;
      switch(Estado){
        case COUNT_0:
          LEDOff(LED3);
          LEDOff(LED2);
          LEDOff(LED1);
          Estado = COUNT_1;
          break;
        case COUNT_1:
          LEDOff(LED3);
          LEDOff(LED2);
          LEDOn(LED1);
          Estado = COUNT_2;
          break;
        case COUNT_2:
          LEDOff(LED3);
          LEDOn(LED2);
          LEDOn(LED1);
          Estado = COUNT_3;
          break;
        case COUNT_3:
          LEDOff(LED3);
          LEDOn(LED2);
          LEDOff(LED1);
          Estado = COUNT_4;
          break;
        case COUNT_4:
          LEDOn(LED3);
          LEDOn(LED2);
          LEDOff(LED1);
          Estado = COUNT_5;
          break;
        case COUNT_5:
          LEDOn(LED3);
          LEDOn(LED2);
          LEDOn(LED1);
          Estado = COUNT_6;
          break;
        case COUNT_6:
          LEDOn(LED3);
          LEDOff(LED2);
          LEDOn(LED1);
          Estado = COUNT_7;
          break;
        case COUNT_7:
          LEDOn(LED3);
          LEDOff(LED2);
          LEDOff(LED1);
          Estado = COUNT_0;
          break;
      } // switch
    } // if
  } // while
} // main
