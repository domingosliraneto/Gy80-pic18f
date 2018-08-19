/* 
 * File:   Serial.h
 * Author: test
 *
 * Created on 29 de Julho de 2015, 15:36
 */

#ifndef SERIAL_H
#define	SERIAL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <usart.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
//#define _XTAL_FREQ 8000000 // Internal oscillator  
//#define BAUDRATE 115200

#define _XTAL_FREQ 48000000 // Internal oscillator  
//#define BAUDRATE 9600;
#define BAUDRATE 115200
    
unsigned char SerialReceivedData;
unsigned char SerialReceivedString[50];
unsigned SerialLen = 50;

void delaySeg(unsigned waitTime)
    {
    for(unsigned j = 0; j < waitTime; ++j)
        for(unsigned i = 0; i <= 113; ++i)  
            __delay_ms(10);
    }

void initUART(void)
{
    TRISCbits.TRISC7 = 1;
    TRISCbits.TRISC6 = 0;
    SPBRG =  (unsigned char) (_XTAL_FREQ/(16*BAUDRATE) - 1);   
    SPBRGH =  (unsigned char) (_XTAL_FREQ/(16*BAUDRATE) - 1);   
    CSRC = 0;
    TX9  = 0;
    TXEN = 1;
    SYNC = 0;
    SENDB = 0;
    BRGH = 1;
    TRMT = 0;
    TX9D = 0;
    
    SPEN = 1;
    RX9  = 0;
    SREN = 0;
    CREN = 1;
    ADDEN = 0;
    FERR = 0;
    OERR = 0;
    RX9D = 0;
    TXIE = 0;
    RCIE = 1;    
}

void SerialPrint(unsigned char byte)
{
    while(!TXIF);
    TXREG = byte;
    RCIF = 0;
    OERR = 0;
}

void SerialWrite(const char* frase)
{
    unsigned char indice = 0;
    unsigned char tamanho = strlen(frase);

    while(indice < tamanho){
//        __delay_us(10);
//        DelayMs(2);
        if(frase[indice] != '\0')
        {
            SerialPrint(frase[indice]);
//            __delay_ms(1);
            ++indice;
        }
        else
            break;
    }
    SerialLen = indice;
}

char SerialRead(void)
{
    if(OERR)
    {
        CREN = 0;
        CREN = 1;
    }
    while(!RCIF);
    SerialReceivedData = RCREG;
    RCIF = 0;
    return RCREG;
}

void SerialReadString()
{
    unsigned i = 0;
    while(1)
    {
        SerialReceivedString[i] = SerialRead();
        if( ('\n' == SerialReceivedString[i]) || ('\r' == SerialReceivedString[i]) || (' ' == SerialReceivedString[i]))
        {
            SerialReceivedString[i+1] = '\0';
            break;
        }
        ++i;
    }
    SerialLen = i+1;
}

bit ContainString(const char* containedString)
{
    unsigned char sizeString = strlen(SerialReceivedString),i, j, sizeStringToCompare = strlen(containedString);
    unsigned char * hasString = strstr(SerialReceivedString, containedString);
    if(hasString)
        return 1;

    return 0;
}

bit waitToken(char value)
{
//        while(1){
    if(!RCIF)
        return 0;
    
    if((SerialRead() == value)){
        RCREG = value+1;
        return 1;
    }
    else
        return 0;
//                break;
//        }
}

void waitUntil(const unsigned char stringToCompare[])
{
    
    while(!ContainString(stringToCompare))
        SerialReadString();
}

void SerialReadUntilToken(const char charToCompare)
{
    unsigned i = 0;
    while(1)
    {
        SerialReceivedString[i] = SerialRead();
        if( charToCompare == SerialReceivedString[i])
        {
            SerialReceivedString[i] = '\0';
            break;
        }
        ++i;
    }
    SerialLen = i;
}

void SerialReceiveNChar(const int NumberOfCharToReceive)
{
    SerialReceivedString[NumberOfCharToReceive] = '\0';
    for(unsigned i = 0; i < NumberOfCharToReceive; ++i)
    {
        SerialReceivedString[i] = SerialRead();
    }
}

#ifdef	__cplusplus
}
#endif

#endif	/* SERIAL_H */

