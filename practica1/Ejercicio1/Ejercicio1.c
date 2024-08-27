#include <htc.h>

// constante requerida para funciones
// de espera de tiempo
#define _XTAL_FREQ 1000000 //1MHz osc

void main(){
    // configura en binario el bit4 de
    // registro PORTB(RB4) como salida,
    // los demás bits como entradas
    // bits 76543210
    TRISB = 0b11101111;
    TRISA = 0b00000011;
    while(1) {
        // Esperar hasta que se presione alguno de los pulsadores
        if (RA0 == 0 || RA1 == 0) {
            // Comenzar a titilar los LEDs de manera alternada cada 250 ms
            while(1) {
               PORTB = PORTB ^ 0b00010000; // Alternar los LEDs RB4 y RB5
                __delay_ms(250); // Esperar 250 milisegundos
            }
        }
    }
}