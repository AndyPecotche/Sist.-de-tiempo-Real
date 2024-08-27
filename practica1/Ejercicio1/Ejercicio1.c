// Utilice el entorno ISIS para abrir el diseño del circuito que se encuentra en la carpeta 
// “Samples\VSM for PICMICRO\VSM for PIC16\PIC Doorbell”. En este esquema se observa 
// un microcontrolador PIC 16F84; dos pulsadores conectados a los pines RA0 y RA1 como 
// entradas; dos leds conectados a los pines RB4 y RB5 como salidas. Configure el entorno 
// y realice un programa C que permita encender y apagar los leds de manera alternada 
// cada 250 milisegundos utilizando la función “__delay_ms”. Cuando inicia el programa 
// ambos leds deben estar encendidos. Luego de presionar alguno de los pulsadores deben 
// comenzar  a  titilar.  Nota:  Observe  en  la  barra  inferior  del  simulador  el  tiempo  de 
// simulación para confirmar la precisión de la espera.  

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