#ifndef _COMMANDER_H
#define	_COMMANDER_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"

#define CMD_ADDR_MAX 3
#define CMD_BUFFER_SIZE 32

#define CMD_SET_OPERATION "SET"
#define CMD_SET_OPERATION_COUNT 3

#define CMD_GET_OPERATION "GET"
#define CMD_GET_OPERATION_COUNT 2

#define CMD_SEPARATOR ","
#define CMD_LINE_ENCODE "\r\n"

#define CMD_OK_TEXT "AOK"
#define CMD_NOK_TEXT "NOK"

void CMD_Receive();
int CMD_SetData(uint8_t addr , uint8_t data);
int CMD_GetData(uint8_t addr , uint8_t *data);

#endif

