#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "strlib.h"

int Split( const char *str, const char *delimiter, char *out[] ) {
    char    *tok;
    int     cnt = 0;

    tok = strtok( str, delimiter );
    while( tok != NULL) {
        out[cnt++] = tok;
        tok = strtok( NULL, delimiter );
    }
    return cnt;
}
int ParseLong( const char *str , long *ret , int base){
    char *end;
    *ret = strtol(str,&end,base);
    if(*end != '\0'){
        return 1;
    }
    return 0;
}
int ParseInt( const char *str , int *ret , int base){
    int val;
    if( ParseLong(str,&val,base) != 0 || val > INT_FAST16_MAX || val < INT_FAST16_MIN){
        return -1;
    }
    *ret = val;
    return 0;
}
int ParseByte( const char *str , char *ret , int base){
    int val;
    if( ParseLong(str,&val,base) != 0 || val > INT_FAST8_MAX || val < INT_FAST8_MIN){
        return -1;
    }
    *ret = val;
    return 0;
}
int ParseUInt( const char *str , int *ret , int base){
    int val;
    if( ParseLong(str,&val,base) != 0 || val > UINT_FAST16_MAX || val < 0){
        return -1;
    }
    *ret = val;
    return 0;
}
int ParseUByte( const char *str , char *ret , int base){
    int val;
    if( ParseLong(str,&val,base) != 0 || val > UINT_FAST8_MAX || val < 0){
        return -1;
    }
    *ret = val;
    return 0;
}