#include <stdio.h>
#include <math.h>

#include "current_controller.h"
#include "command.h"
#include "mcp4922.h"

static CC_REGISTER CC_Reg;
static double Angle;
static uint16_t Count;
static uint8_t Mode;

void CC_Interrupt(){
    uint16_t val = (uint16_t)( sin( ( Angle / 180.0 ) * M_PI ) * CC_Reg.Current * );
    
    MCP4922_Write(val);
    Angle += CC_ANGLE_INCREMENT;
    if(Angle > CC_MAX_ANGLE){
        Angle = 0;
    }
}

void CC_Init(){
    TMR1_SetInterruptHandler(&CC_Interrupt);
}

void CC_CheckRegister(){
    uint8_t buf;
    
    if(CMD_GetData(CC_STATE_ADDR,&CC_Reg.Buffer) == 0){
        if(CC_Reg.Buffer & CC_EXEC_BIT){

            CC_Reg.bStart      = CC_Reg.Buffer & CC_START_BIT;
            CC_Reg.bDirection  = CC_Reg.Buffer & CC_DIRECTION_BIT;
            CC_Reg.bMode       = CC_Reg.Buffer & CC_MODE_BIT;
            CC_Reg.bNotify     = CC_Reg.Buffer & CC_NOTIFY_BIT;
            
            if(CC_Reg.bStart){
                CMD_GetData(CC_DA_ADDR_LOW,&buf);
                CC_Reg.Current = buf;
                CMD_GetData(CC_DA_ADDR_HIGH,&buf);
                CC_Reg.Current |= ( buf & 0x0f ) << 8;
                Angle = 0;
                if(CC_Reg.bMode){
                    TMR1_StartTimer();
                }
                else{
                    TMR0_StopTimer();
                    MCP4922_Write(CC_Reg.Current);
                }
            }
            else{
                CC_Reg.Current = 0;
            }
            
            if(CC_Reg.bDirection){
                CDIR_SetHigh();
            }
            else{
                CDIR_SetLow();
            }
            
            if(CC_Reg.bNotify){
                printf("Notify:Reg[%xh],Current[%d]",CC_Reg.Buffer,CC_Reg.Current,CMD_LINE_ENCODE);
            }
            
            CMD_SetData(CC_STATE_ADDR,CC_Reg.Buffer & (~CC_EXEC_BIT));
        }
    }
}