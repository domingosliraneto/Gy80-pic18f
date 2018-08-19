/* 
 * File:   TesteFunc.h
 * Author: unp
 *
 * Created on 16 de Fevereiro de 2016, 18:06
 */

#ifndef TESTEFUNC_H
#define	TESTEFUNC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Serial.h"
//unsigned const char endInstr[] = "\r\n";
//unsigned const char sendCmd[] = "AT+CIPSEND=0,9\r\n";
//unsigned char RxData[1];
void conecta(){
    initUART();
    //delaySeg(1);
        SerialWrite("AT+RST\r\n");
        delaySeg(2);
        SerialWrite("ATE0\r\n");
        delaySeg(2);
       
       SerialWrite("AT+CWMODE=1\r\n");
        delaySeg(2);
        
       SerialWrite("AT+CWJAP=\"BatCaverna\",\"23dfd1b64b\"\r\n");
        delaySeg(8);
        
        SerialWrite("AT+CIPMUX=1\r\n");
        delaySeg(2);
       
        SerialWrite("AT+CIPSERVER=1,4000\r\n");
        delaySeg(2);
}
//void TestTrans(){
//    waitToken('_');
//    SerialReadUntilToken('_');
//    delaySeg(1);
//    SerialWrite((char *)sendCmd);
//    delaySeg(1);
//    SerialWrite((char *)SerialReceivedString);
//    delaySeg(1);
//}


#ifdef	__cplusplus
}
#endif

#endif	/* TESTEFUNC_H */

