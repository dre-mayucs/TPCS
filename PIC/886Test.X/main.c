// PIC16F886 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ  20000000
#define true 1
#define false 0
#define SENS 150

int ADC(const int Set0, const int Set1)
{
    ADCON0 = Set0;
    ADCON1 = Set1;
    
     //AD変換ON
     ADON = 1;
     
    //アクィジション時間　40us
    __delay_us(40);
        
    //AD変換開始
    GO_nDONE = 1;
        
    //変換完了待ち
    while(GO_nDONE);
    return (ADRESH<<8) + ADRESL;
}

void main(void)
{
    TRISA = 0b00001111; //A0-A3 Input
    TRISB = 0b00000000; //all I/O
    TRISC = 0b00000000; //all I/O
    
    ANSEL = 0b00001111;//AN0-AN3 analog input
    
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    
    
    while(true) {
        //ADCON0レジスタ
        //bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
        //---- ---- CHS3 CHS2 CHS1 CHS0 DONE ADCON
        
        int AN_0 = ADC(0b00000001, 0b10000000);
        int AN_1 = ADC(0b00000101, 0b10000000);
        int AN_2 = ADC(0b00001001, 0b10000000);
        int AN_3 = ADC(0b00001101, 0b10000000);
        
        PORTC = 0b00000000;
        
        if(AN_0 > SENS){
            PORTC += 0b00010000;
        }
        
        if(AN_1 > SENS){
            PORTC += 0b00100000;
        }
        
        if(AN_2 > SENS){
            PORTC += 0b01000000;
        }
        
        if(AN_3 > SENS){
            PORTC += 0b10000000;
        }
    }
    __delay_ms(1);
    return;
}
