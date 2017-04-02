#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "command.h"
#include "strlib.h"

static uint8_t CMD_Reg[CMD_ADDR_MAX];
static char CMD_Buf[CMD_BUFFER_SIZE];
static char CMD_Ptr;

int CMD_Execute(const char *cmd){
    uint8_t addr;
    uint8_t val;
    uint8_t cnt;
    char *buf[3];
    
    cnt = Split(cmd,CMD_SEPARATOR,buf);
    
    if(cnt > 1){
        if(ParseUByte(buf[1],&addr,16) != 0 || addr >= CMD_ADDR_MAX){
            printf("%s%s",CMD_NOK_TEXT,CMD_LINE_ENCODE);
            return -1;
        }
    }
    
    if(cnt == CMD_SET_OPERATION_COUNT && strcmp(buf[0],CMD_SET_OPERATION) == 0){
       if(ParseUByte(buf[2],&val,16) != 0){
            printf("%s%s",CMD_NOK_TEXT,CMD_LINE_ENCODE);
            return -1;
        }
        CMD_Reg[addr] = val;
        printf("%s%s",CMD_OK_TEXT,CMD_LINE_ENCODE);
        return 1;
    }
    
    if(cnt == CMD_GET_OPERATION_COUNT && strcmp(buf[0],CMD_GET_OPERATION) == 0){
        printf("%d%s",CMD_Reg[addr],CMD_LINE_ENCODE);
        return 2;
    }
    
    printf("%s%s",CMD_NOK_TEXT,CMD_LINE_ENCODE);
    return -1;
}

void CMD_Receive(){
    if(EUSART_DataReady){
        do{
            CMD_Buf[CMD_Ptr] = toupper(EUSART_Read());
            CMD_Buf[CMD_Ptr+1] = '\0';
            if(CMD_Ptr > 0 && CMD_Buf[CMD_Ptr - 1] == '\r' && CMD_Buf[CMD_Ptr] == '\n'){
                CMD_Buf[CMD_Ptr - 1] = '\0';
                CMD_Execute(CMD_Buf);
                CMD_Ptr = 0;
                break;
            }
            CMD_Ptr++;
        }while(EUSART_DataReady);
    }
}

int CMD_SetData(uint8_t addr , char data){
    if( addr < CMD_ADDR_MAX ){
        CMD_Reg[addr] = data;
        return 0;
    }
    return -1;
}

int CMD_GetData(uint8_t addr , char *data){
    if( addr < CMD_ADDR_MAX ){
        (*data) = CMD_Reg[addr];
        return 0;
    }
    return -1;
}
