#include <delays.h>
#include <xc.h>
#include "Serial.h"
//#include "wifiTCP.h"
//#include "funcionaPLS.h"
//#include "PicConfig.h"

// CONFIG         
#pragma config USBDIV = 2
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HSPLL_HS //HS / INTOSCCLK// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)         
//#pragma config FOSC = INTOSC_HS
#pragma config WDT = OFF       // Watchdog Timer Enable bit (WDT disabled)         
// #pragma config PBADEN = OFF       // Power-up Timer Enable bit (PWRT enabled)         
#pragma config MCLRE = ON      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)         
// #pragma config BOREN = ON      // Brown-out Detect Enable bit (BOD disabled)         
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)       
// #pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)         
#pragma config PWRT = ON        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config PBADEN = OFF

#define _XTAL_FREQ 48000000 // Internal oscillator  
//#define BAUDRATE 115200
//unsigned char RxData[25];

//END CONFIG
//bit flagRead = 0;
//unsigned const char endInstr[] = "\r\n";
//unsigned const char sendCmd[] = "AT+CIPSEND=0,4\r\n";
//unsigned char RxData[1];
void init_timer(){
 SCS1 = 0;
 SCS0 = 0; 
 IOFS = 1;
 IRCF2 = 1;
 IRCF1 = 1;
 IRCF0 = 1;
 INTCONbits.GIE = 1;
 INTCONbits.PEIE = 1;
 INTCONbits.TMR0IF = 0;
 INTCONbits.TMR0IE = 0;
 T0CONbits.T08BIT = 0;
 T0CONbits.T0CS = 0;
 T0CONbits.PSA = 1;
 T0CONbits.T0PS2 = 1;
 T0CONbits.T0PS1 = 1;
 T0CONbits.T0PS0 = 1;
 TMR0H=0xFF;
 TMR0L=0x30;
 T0CONbits.TMR0ON = 1;
}

//



//void pwmControle(){
////    
////
////     pwm[0] = (unsigned char)i; 
////
////     if((unsigned char)i > (unsigned char)165)
////         i = 0;
//     pwmExecute((unsigned char*) pwm);
//}
long unsigned i = 0, j = 0;
bit FlagTXSend = 0;

void main(void) {

/////////////////////////        SerialWrite("AT+UART=9600,8,1,0,0\r\n");
    initUART();
    
    SerialWrite("bbb\r\n");
    delaySeg(1);
    SerialWrite("AAAAA\r\n");
    delaySeg(1);
    
    while(1){
     SerialWrite("A\r\n");
     delaySeg(2);
        
    }
    return;
}