/* 
 * File   PicConfig.h
 * Author test
 *
 * Created on 31 de Julho de 2015, 1418
 */

#ifndef PICCONFIG_H
#define	PICCONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <xc.h>
#include "Serial.h"
#include "wifiTCP.h"
    bit A0 = 0, A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0, A6 = 0, A7 = 0;
    bit B0 = 0, B1 = 0, B2 = 0, B3 = 0, B4 = 0, B5 = 0, B6 = 0, B7 = 0;
    bit TA0 = 0, TA1 = 0;
    unsigned int PortaSend = 0;
//    void ADCInit()
//    {
//        INTCONbits.GIE = 0;
//        CMCON = 0b00000010;
//        VRCON = 0b10101110; //2,083V
//        TRISA               = 7; // 1100 - 0 saídas e 1 entradas
//        __delay_ms(10);
//        
//    }
    
//    unsigned char ADCRead(){
//        for(unsigned char i = 0; i < 16; ++i)
//        {
//            VRCON = 128+32+i;
////            WifiTCPSend(&i,1);
//            __delay_ms(1);
//            if(CMCONbits.C2OUT)
//                return i+48;
//        }
//        return 15+48;
//    }
    
     void SetPWMDutyCycle (unsigned int DutyCycle){
        CCPR1L = DutyCycle>>2;
        CCP1CON &= 0xCF;
        CCP1CON |= (0x30&(DutyCycle<<4));
    }
    
    void InitPWM(void) {
          TRISBbits.TRISB3 = 0;
          CCP1CON = 0x0C;
          PR2 = 255;
          T2CON = 0x01;
          
          SetPWMDutyCycle(0);
          
          T2CON |= 0x06;        
    }
    
    void PicConfig(unsigned char *stringConfig, unsigned lenStr)
    {
        unsigned char OkSend[] = "OK\r\n", zero[] = "0\r\n", one[] = "1\r\n", charSend[] = "0\r\n";
        
//        WifiTCPSend(stringConfig,lenStr);
//        if(strstr(stringConfig,"RA0C")){
//            if(stringConfig[4] == zero[0])
//                TRISAbits.TRISA0 = 0;
//            else
//                TRISAbits.TRISA0 = 1;
//            WifiTCPSend(OkSend,4);
//        }
//        if(strstr(stringConfig,"RA1C")){
//            if(stringConfig[4] == zero[0])
//                TRISAbits.TRISA1 = 0;
//            else
//                TRISAbits.TRISA1 = 0;
//            WifiTCPSend(OkSend,4);
//        }
        if(strstr(stringConfig,"AN1R")){
//            charSend[0] = ADCRead();
            WifiTCPSend(charSend,3);
        }
        
        if(strstr(stringConfig,"PWM")){
            unsigned int PWMValue = (stringConfig[3]-48)*100 + (stringConfig[4]-48)*10 + stringConfig[5]-48;
//            PWMValue = scaleChange(1024, 0, 999, 0, PWMValue);
            SetPWMDutyCycle (PWMValue/4+140);
            WifiTCPSend(OkSend,4);
        }
//        if(strstr(stringConfig,"RA2R")){
////            TA0 = 1;
////            TRISA = 8;
////            charSend[0] = ;
//            if(RA2)
//                WifiTCPSend(one,3);
//            else
//                WifiTCPSend(zero,3);
////            RA0;
////            SerialWrite("OK\r\n");
//        }
//        if(strstr(stringConfig,"RA3R")){
////            TA1 = 1;
////            TRISA = (TA0 + 2*TA1);
//            if(RA3)
//                WifiTCPSend(one,3);
//            else
//                WifiTCPSend(zero,3);
////            RA0;
////            SerialWrite("OK\r\n");
//        }
//        bit Controle = 0;
        if(strstr(stringConfig,"RA0W")){
            if(stringConfig[4] == zero[0])
                A0 = 0;
            else
                A0 = 1;
            
            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
            WifiTCPSend(OkSend,4);
        }
        if(strstr(stringConfig,"RA1W")){
            if(stringConfig[4] == zero[0])
                A1 = 0;
            else
                A1 = 1;
            
            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
            WifiTCPSend(OkSend,4);
        }
        if(strstr(stringConfig,"RA2W")){
            if(stringConfig[4] == zero[0])
                A2 = 0;
            else
                A2 = 1;
            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
            WifiTCPSend(OkSend,4);
        }
        if(strstr(stringConfig,"RA3W")){
            if(stringConfig[4] == zero[0])
                A3 = 0;
            else
                A3 = 1;
            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
            WifiTCPSend(OkSend,4);
        }
//        if(strstr(stringConfig,"RA4W")){
//            if(stringConfig[4] == zero[0])
//                A4 = 0;
//            else
//                A4 = 1;
//            
//            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
//            WifiTCPSend(OkSend,4);
//        }
//        if(strstr(stringConfig,"RA5W")){
//            if(stringConfig[4] == zero[0])
//                A5 = 0;
//            else
//                A5 = 1;
//            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
//            WifiTCPSend(OkSend,4);
//        }
//        if(strstr(stringConfig,"RA6W")){
//            if(stringConfig[4] == zero[0])
//                A6 = 0;
//            else
//                A6 = 1;
//            
//            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
//            WifiTCPSend(OkSend,4);
//        }
        if(strstr(stringConfig,"RA7W")){
            if(stringConfig[4] == zero[0])
                A7 = 0;
            else
                A7 = 1;
            PORTA = (A0 + 2*A1 + 4*A2 + 8*A3 + 16*A4 + 32*A5 + 64*A6 + 128*A7);
            WifiTCPSend(OkSend,4);
        }
        //Output portB
        if(strstr(stringConfig,"RB0W")){
            if(stringConfig[4] == zero[0])
                B0 = 0;
            else
                B0 = 1;
            
            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
            WifiTCPSend(OkSend,4);
        }
//        if(strstr(stringConfig,"RB1W")){
//            if(stringConfig[4] == zero[0])
//                B1 = 0;
//            else
//                B1 = 1;
//            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
//            WifiTCPSend(OkSend,4);
//        }
//        if(strstr(stringConfig,"RB2W")){
//            if(stringConfig[4] == zero[0])
//                B2 = 0;
//            else
//                B2 = 1;
//            
//            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
//            WifiTCPSend(OkSend,4);
//        }
//        if(strstr(stringConfig,"RB3W")){
//            if(stringConfig[4] == zero[0])
//                B3 = 0;
//            else
//                B3 = 1;
//            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
//            WifiTCPSend(OkSend,4);
//        }
        if(strstr(stringConfig,"RB4W")){
            if(stringConfig[4] == zero[0])
                B4 = 0;
            else
                B4 = 1;
            
            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
            WifiTCPSend(OkSend,4);
        }
        if(strstr(stringConfig,"RB5W")){
            if(stringConfig[4] == zero[0])
                B5 = 0;
            else
                B5 = 1;
            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
            WifiTCPSend(OkSend,4);
        }
//        if(strstr(stringConfig,"RB6W")){
//            if(stringConfig[4] == zero[0])
//                B6 = 0;
//            else
//                B6 = 1;
//            
//            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
//            WifiTCPSend(OkSend,4);
//        }
//        if(strstr(stringConfig,"RB7W")){
//            if(stringConfig[4] == zero[0])
//                B7 = 0;
//            else
//                B7 = 1;
//            PORTB = (B0 + 2*B1 + 4*B2 + 8*B3 + 16*B4 + 32*B5 + 64*B6 + 128*B7);
//            WifiTCPSend(OkSend,4);
//        }
    }
   


//    bit PicConfigRead(unsigned char *stringConfig, unsigned lenStr)
//    {
        
//        else if(strstr(StringConfig,"RA1R"))
//            return RA1;
//        else if(strstr(StringConfig,"RA2R"))
//            return RA2;
//        else if(strstr(StringConfig,"RA3R"))
//            return RA3;
//        else if(strstr(StringConfig,"RA4R"))
//            return RA4;
//        else if(strstr(StringConfig,"RA5R"))
//            return RA5;
//        else if(strstr(StringConfig,"RA6R"))
//            return RA6;
//        else if(strstr(StringConfig,"RA7R"))
//            return RA7;  
//    }
    
//    bit PicConfigWrite(unsigned char *stringConfig, unsigned lenStr)
//    {
//        WifiTCPSend(stringConfig,lenStr);
//        if(strstr(stringConfig,"RA0W")){
//            RA0 = 0;
//            SerialWrite("OK\r\n");
//        }
//        else if(strstr(stringConfig,"RA0W1")){
//            RA0 = 1;
//            SerialWrite("OK\r\n");
//        }
//        else if(strstr(StringConfig,"RA0W1"))
//            RA0 = 1;
//        else if(strstr(StringConfig,"RA1W0"))
//            RA1 = 0;
//        else if(strstr(StringConfig,"RA1W1"))
//            RA1 = 1;
//        else if(strstr(StringConfig,"RA2W0"))
//            RA2 = 0;
//        else if(strstr(StringConfig,"RA2W1"))
//            RA2 = 1;
//        else if(strstr(StringConfig,"RA3W0"))
//            RA3 = 0;
//        else if(strstr(StringConfig,"RA3W1"))
//            RA3 = 1;
//        else if(strstr(StringConfig,"RA4W0"))
//            RA4 = 0;
//        else if(strstr(StringConfig,"RA4W1"))
//            RA4 = 1;
//        else if(strstr(StringConfig,"RA5W0"))
//            RA5 = 0;
//        else if(strstr(StringConfig,"RA5W1"))
//            RA5 = 1;
//        else if(strstr(StringConfig,"RA6W0"))
//            RA6 = 0;
//        else if(strstr(StringConfig,"RA6W1"))
//            RA6 = 1;
//        else if(strstr(StringConfig,"RA7W0"))
//            RA7 = 0;
//        else if(strstr(StringConfig,"RA7W1"))
//            RA7 = 1;
//    }

#ifdef	__cplusplus
}
#endif

#endif	/* PICCONFIG_H */
