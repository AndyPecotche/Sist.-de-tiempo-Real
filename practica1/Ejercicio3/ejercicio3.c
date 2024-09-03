// Utilice el entorno ISIS para abrir el diseño del circuito que se encuentra en la carpeta 
// “Samples\VSM  for  PICMICRO\VSM  for  PIC16\PIC ADC Example”. En este esquema se 
// observa  un  microcontrolador  PIC  16F877;  una  resistencia  variable  (que  simula  un 
// transductor) conectada a través del pin AN0; dos Latchs 74LS373 (multiplexados) cuyas 
// entradas comparten el puerto B y que son controlados a través de los pines RD6 y RD7 
// del puerto D; cuatro displays de 7 segmentos hexadecimales conectados a las salidas 
// de  los  latchs.  Configure  el  entorno  y  realice  un  programa  en  C  que  permita  capturar 
// valores analógicos realizando “polling” y muestre los valores digitales (en hexadecimal) 
// en los displays de 7 segmentos. Tenga en cuenta que : 
// 1. debe configurar el pin AN0 como entrada analógica y como tensión de referencia 
// el mismo del microcontrolador (VCC).  
// 2. los  latchs  (74LS373)  funcionan  de  forma  multiplexada  por  lo  que  requieren  la 
// activación/desactivación en el pin LE para que los datos de entrada queden en la 
// salida.  
// 3. que los displays muestran los valores en hexadecimal, por ejemplo si el valor a 
// mostrar es 1510 o 11112 mostrará la letra “F”. 
#include <htc.h>

void main(){
    //OPTION_REG = [-,-,T0CS,T0SE,PSA,PS2,PS1,PS0]
    //OPTION_REG = 0b00000000; //valor final de OPTION_REG

    //INTCON = [GIE,PEIE,T0IE,INTE,RBIE,T0IF,INTF,RBIF]
    //INTCON = 0b10100000;

    //PORTB = [RB7,RB6,RB5,RB4,RB3,RB2,RB1,RB0]
    //TRISB = [TRISB7,TRISB6,TRISB5,TRISB4,TRISB3,TRISB2,TRISB1,TRISB0]
    TRISB = 0b00000000; //registro PORTB(RB4) como salida

    //PORTA = [-,-,RA5,RA4,RA3,RA2,RA1,RA0]
    //TRISA = [-,-,TRISA5,TRISA4,TRISA3,TRISA2,TRISA1,TRISA0]
    TRISA = 0b00000001; //registro PORTA(RA0/AN0) como entrada

    //PORTD = [-,-,-,-,-,-,RD1,RD0]
    //TRISD = [-,-,-,-,-,-,TRISD1,TRISD0]
    TRISD = 0b00000000; //registro PORTD(RD6,RD7) como salida
    //RD6 --> LE de latch1 74LS373
    //RD7 --> LE de latch2 74LS373

//--------------------Configuracion de los pines analogicos ADCON1--------------------
    ADCON1 = 0b10001110; 
    /*
    ADCON1 = [ADFM,-,-,-,PCFG3,PCFG2,PCFG1,PCFG0]
    PCFGx = 0bxxxx1110 --> AN0 como entrada analogica, Vref+ = VDD, Vref- = VSS
    ADFM = 0b1xxxxxxx Bit de selección para establecer la forma en que se almacena el valor de la
        conversión A/D en los registros ADRESH:ADRESL :
        1: Justificar  a  derecha:  los  10  bits  del  valor  A/D  se  almacenan  en  los  10  menos 
        significativos (2 en ADRESH y 8 en ADRESL). Los 6 bits más significativos quedan en “0”.
        0: Justificar  a  izquierda:  los  10  bits  del  valor  A/D  se  almacenan  en  los  10  más 
        significativos (8 en ADRESH y 2 en ADRESL). Los 6 bits menos significativos quedan en 
        “0”. Si no interesa la precisión esta configuración es práctica para leer solo ADRESH 
        donde están los 8 bits más significativos 
    */

//--------------------Configuracion de los pines analogicos ADCON0--------------------
    ADCON0 = 0b01000001; 
    /* 
    ADCON0 = [ADCS1,ADCS0,CHS2,CHS1,CHS0,GO/DONE,-,ADON]
    ADCS1-ADCS0: Bits de selección del reloj para realizar la conversión (A/DClockSelection):
        0 FOSC/2 (1 ciclo del reloj de conversión cada 2 del reloj del sistema).
        1 FOSC/8 (1 ciclo del reloj de conversión cada 8 del reloj del sistema).
        2 FOSC/32 (1 ciclo del reloj de conversión cada 32 del reloj del sistema).
        3 FRC : reloj derivado del oscilador RC interno del modulo A/D (1 ciclo cada 4 del reloj del sistema?).
    CHS2-CHS0: Selector del canal A/D para convertir (ChannelSelection): 
        000 AN0
        001 AN1
        ...
        111 AN7
    GO/DONE: Bit de inicio de conversión A/D:
        1:  conversión A/D en progreso. Si se escribe un “1” en este bit comienza la conversión. 
        0: no hay conversión A/D en progreso. Este bit es puesto en “0” por hardware cuando 
           se completa la conversión. 
    ADON: Bit de control para activar el módulo de conversión A/D (A/D ON): 
        1: módulo A/D activado.
        0: módulo A/D desactivado.
    */

//--------------------Configuracion de los pines analogicos PIE1--------------------
    PIE1 = 0b00000000;
    /*
    PIE1 = [PSIE,ADIE,RCIE,TXIE,SSPIE,CCP1IE,TMR2IE,TMR1IE]
    ADIE: Habilita la interrupción del módulo A/D. 1: habilitada, 0: deshabilitada.
    Los demas no estan relacionado con el modulo A/D
    */

//--------------------Configuracion de los pines analogicos PIR1--------------------
    PIR1 = 0b00000000;
    /*
    PIR1 = [PSIF,ADIF,RCIF,TXIF,SSPIF,CCP1IF,TMR2IF,TMR1IF]
    ADIF: Flag de interrupción del módulo A/D. 1: conversión A/D completa, 0: conversion A/D en curso.
    Los demas no estan relacionado con el modulo A/D
    */

    while(1) {
        // Iniciar conversión A/D
        GO = 1;
        while(GO){}; // Esperar a que termine la conversión
        
        // Combinar el resultado de 10 bits
        unsigned int valor = (ADRESH << 8) | ADRESL;

        // Mostrar el resultado en los displays de 7 segmentos (multiplexado)
        // Mostrar el valor en el latch controlado por RD6 (displays menos significativos)
        RD6 = 1; // Habilitar latch 2
        PORTB = valor & 0xFF; // Enviar los bits menos significativos a PORTB
        RD6 = 0; // Deshabilitar latch 2
        
        // Mostrar el valor en el latch controlado por RD7 (displays más significativos)
        RD7 = 1; // Habilitar latch 1
        PORTB = (valor >> 8) & 0xFF; // Enviar los bits más significativos a PORTB
        RD7 = 0; // Deshabilitar latch 1
    }

}