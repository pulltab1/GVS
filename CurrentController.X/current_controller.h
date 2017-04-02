#ifndef _CURRENTCONTROLLER_H
#define	_CURRENTCONTROLLER_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"

#define CC_MAX_ANGLE 180
#define CC_ANGLE_INCREMENT (CC_MAX_ANGLE/1000)
#define CC_MAX_COUNT 1000

#define CC_EXEC_BIT 0x01
#define CC_START_BIT 0x02
#define CC_DIRECTION_BIT 0x04
#define CC_MODE_BIT 0x08
#define CC_NOTIFY_BIT 0x80

#define CC_STATE_ADDR 0x00
#define CC_DA_ADDR_LOW 0x01
#define CC_DA_ADDR_HIGH 0x02

typedef struct{
    uint8_t Buffer;     //��ԊǗ����W�X�^��ێ�
    uint16_t Current;   //DA�l���W�X�^�̒l
    uint8_t bStart;     //�d���o�͊J�n�t���O
    uint8_t bDirection; //�d�������w��t���O
    uint8_t bMode;      //GVS�o�̓t���O
    uint8_t bNotify;    //��ԏo��
}CC_REGISTER;

void CC_CheckRegister();


#endif

