#include "mcp4922.h"

void MCP4922_Write(uint16_t val){
    SS_SetLow();
    SPI1_Exchange8bit(0x30 | ((val&0xff00) >>8 ));
    SPI1_Exchange8bit(val&0x00ff);
    SS_SetHigh();
}