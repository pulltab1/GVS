#ifndef _STRCNV_H
#define	_STRCNV_H

#include <xc.h>
#include "mcc_generated_files/mcc.h"

int Split(const char *str,const char *delimiter,char *out[]);
int ParseLong( const char *str , long *ret , int base);
int ParseInt( const char *str , int *ret , int base );
int ParseByte( const char *str , char *ret , int base );
int ParseUInt( const char *str , int *ret , int base );
int ParseUByte( const char *str , char *ret , int base );

#endif

