#include "led.h"


void LCD_Interrupt(){
    LED_Toggle();
}

void LCD_SetFlashing(uint8_t bflash){
    if(bflash){
        TMR0_StartTimer();
    }
    else{
        TMR0_StopTimer();
        LED_SetHigh();
    }
}

void LCD_Init(){
    TMR0_SetInterruptHandler(&LCD_Interrupt);
}