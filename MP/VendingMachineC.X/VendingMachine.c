 // CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

#include <xc.h>                //Incluimos los registros del Microcontrolador 18F4550
#include <stdio.h>             //Incluimos stdio para escribir cadenas  con formato en una variable
#include "lcd.h"  
//#define _XTAL_FREQ 8000000     //Cristal Externo de Alta Velocidad 8000000

#include<pic18f4550.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
//#include "Configuration_Header_File.h"
//#include "lcd.c"

float decimal= 4.47;
int entero=20;
char buffer_lcd[20];


void main(void) {

    unsigned char contador;   //Variable entera de 8 digitos tipo char
    TRISC=0x00;               //Configuramos el Puerto D como salida digital.
    lcd_init();               //Inicializamos la pantalla LCD.
    while(1)                  //Bucle Infinito 
    {
        lcd_clear();          //Limpiamos pantalla LCD
        lcd_gotoxy(1,1);      //Ubicamos el cursor en fila 1, columna 1
        lcd_putc("**IDE MPLAB X**");  //mostramos una cadena de caracteres en la pantalla LCD
        lcd_gotoxy(2,1);      //Ubicamos el cursor en fila2, columna 1
        lcd_putc("******XC8******");  //mostramos una cadena de caracteres en la pantalla LCD
        __delay_ms(1000);     //Retardo de 200 ms
        lcd_clear();          //Limpiamos pantalla LCD
        lcd_gotoxy(1,1);      //Ubicamos el cursor en fila 1, columna 1
        lcd_putc("   Jorge APC");   //mostramos una cadena de caracteres en la pantalla LCD
        lcd_gotoxy(2,1);      //Ubicamos el cursor en fila 2, columna 1
        lcd_putc("   PIC 18F4550"); //mostramos una cadena de caracteres en la pantalla LCD
        __delay_ms(2000);     //Retardo de 2s
        lcd_clear();          //Limpiamos pantalla LCD
        lcd_gotoxy(1,1);      //Ubicamos el cursor en fila 1, columna 1
        lcd_putc("***ELECTRONICA**"); //mostramos una cadena de caracteres en la pantalla LCD
        lcd_gotoxy(2,1);      //Ubicamos el cursor en fila 2, columna 1
        lcd_putc("***SUSCRIBETE***"); //mostramos una cadena de caracteres en la pantalla LCD
        
        for(contador=0;contador<15;contador++) //Mientras contador sea menor que 15, incrementamos su valor en una unidad. 
        {
            __delay_ms(500);  //Retardo de 500 ms
            lcd_shift_left(); //Desplazamos caracteres hacia la izquida
        }

        for(contador=0;contador<30;contador++)  //Mientras contador sea menor que 30, incrementamos su valor en una unidad. 
        {
            __delay_ms(500);  //Retardo de 500 ms
            lcd_shift_right();//Desplazamos caracteres hacia la derecha
        }
        
        lcd_clear();          //Limpiamos pantalla LCD
        lcd_gotoxy(1,1);      //Ubicamos cursor en fila 2, columna 1
        lcd_putc("*PIC - ARDUINO**"); //mostramos una cadena de caracteres en la pantalla LCD
        lcd_gotoxy(2,1);      //Ubicamos cursor en fila 2, columna 1
        lcd_write_char('J');  //mostramos caracter 
        __delay_ms(500);      //Retardo de 500 ms
        lcd_write_char('O');  //Mostramos caracter
        __delay_ms(500);      //Retardo de 500 ms
        lcd_write_char('R');  //mostramos caracter 
        __delay_ms(500);      //Retardo de 500 ms
        lcd_write_char('G');  //Mostramos caracter
        __delay_ms(500);      //Retardo de 500 ms
        lcd_write_char('E');  //Mostramos caracter
        __delay_ms(2000);     //Retardo de 2s
        lcd_clear();          //Limpiamos pantalla LCD
        sprintf(buffer_lcd,"Float: %03.2f", decimal);//Cargamos variable decimal en buffer_lcd.
        lcd_gotoxy(1,1);      //Ubicamos el cursor en fila 1, columna 1
        lcd_putc(buffer_lcd); //Mostramos el valor de buffer_lcd
        sprintf(buffer_lcd,"Int: %d",entero); //Cargamos variable decimal en buffer_lcd.
        lcd_gotoxy(2,1);      //Ubicamos el cursor en fila 1 columna 1
        lcd_putc(buffer_lcd); //Mostramos el valor de buffer_lcd
        __delay_ms(2000);     //Retardo de 2s   
    }
    return;
}