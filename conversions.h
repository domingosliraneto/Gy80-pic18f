/* 
 * File:   conversions.h
 * Author: test
 *
 * Created on 29 de Julho de 2015, 18:38
 */

#ifndef CONVERSIONS_H
#define	CONVERSIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

char *intToString(int Number)
{

    if(Number < 10)
    {
        char Ret[1];
        Ret[0] = Number+48;
        return Ret;
    }else if (Number < 100)  
    {
        char Ret[2];
        int temp = (Number / 10);
        Ret[0] = temp + 48;
        int temp2 = (Number - temp*10);
        Ret[1] = temp2+48;
        return Ret;
    }
}

int stringToInt(const char CharNumber[])
{
    unsigned tamChar = strlen(CharNumber);
    unsigned number = 0;
    unsigned pow = 1;
    for(unsigned i = tamChar-1; i >= 0; --i)
    {
        number += (CharNumber[i] - 48)*pow;
        pow *= 10;
    }
    return number;
}

int scaleChange(int Xmax, int Xmin, int Ymax, int Ymin, int Y){
    return ((Y - Ymin)/(Ymax - Ymin)) * (Xmax - Xmin) + Xmin;
}

#ifdef	__cplusplus
}
#endif

#endif	/* CONVERSIONS_H */

