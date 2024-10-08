// Rehaga el ejercicio anterior conservando la misma funcionalidad pero modificando la 
// implementación. Utilice el módulo del Timer0 con el prescaler para controlar el tiempo 
// de espera y la interrupción para controlar el estado de los leds.

#include <htc.h>

// constante requerida para funciones
// de espera de tiempo
#define _XTAL_FREQ 1000000 //1MHz oscilador interno

int flag1 = 0;
int contador = 0;

void main(){
    //OPTION_REG = [-,-,T0CS,T0SE,PSA,PS2,PS1,PS0]
    T0CS = 0; //-> Bit de selección de reloj para incremento (TMR0ClockSourceSelect):
                // 1 = reloj externo conectado a pin T0CKI (en este caso no importa el valor de T0SE)
                // 0 = reloj interno asociado al ciclo de instrucción.
    T0SE = 0; //-> Bit de selección de flanco de transición (TMR0SourceEdgeSelect), 
                //solo tiene sentido cuando la fuente es reloj externo (T0CS=1)
                //1 = Incrementa en transición alto-bajo del pin T0CKI.
                //0 = Incrementa en transición bajo-alto del pin T0CKI.
    PSA = 0; //-> Prescaler asignado a Timer0:
                //1 = Prescaler asignado a Temporizador Watchdog
                //0 = Prescaler asignado a módulo del Timer0. 
    PS2= 0;
    PS1= 0;
    PS0= 0;// -> PS2-PS0=0 -> Prescaler 1:2 = 1:2^(1+1)
    //OPTION_REG = 0b00000000; //valor final de OPTION_REG

    //INTCON = [GIE,PEIE,T0IE,INTE,RBIE,T0IF,INTF,RBIF]
    GIE = 1; //-> Habilitar interrupciones generales (GlobalInterruptEnable): 
            // 1 = Habilitar interrupciones generales
            // 0 = Deshabilitar interrupciones generales

    //PEIE = 0; //-> Habilitar interrupciones de periféricos
            // 1 = Habilitar interrupciones de periféricos
            // 0 = Deshabilitar interrupciones de periféricos //POR COPILOT

    T0IE = 1; //-> Habilitación de interrupción por desborde del Timer0 (TMR0OverflowInterruptEnable):
            // 1 = Habilitar interrupción por desborde del Timer0
            // 0 = Deshabilitar interrupción por desborde del Timer0

    //INTE = 0; //-> Habilitación de interrupción por cambio en RB0/INT (ExternalInterruptEnable):
            // 1 = Habilitar interrupción por cambio en RB0/INT
            // 0 = Deshabilitar interrupción por cambio en RB0/INT //POR COPILOT

    //RBIE = 0; //-> Habilitación de interrupción por cambio en RB4-RB7 (RBPortChangeInterruptEnable):
            // 1 = Habilitar interrupción por cambio en RB4-RB7
            // 0 = Deshabilitar interrupción por cambio en RB4-RB7 //POR COPILOT

    //T0IF = 0; //-> Bandera de desborde del Timer0 (TMR0OverflowInterruptFlag):
            // 1 = El registro TMR0 ha desbordado (requiere limpiado por soft).
            // 0 = El registro TMR0 no ha desbordado

    //INTF = 0; //-> Bandera de interrupción por cambio en RB0/INT (ExternalInterruptFlag):
            // 1 = Cambio en RB0/INT
            // 0 = No ha ocurrido cambio en RB0/INT //POR COPILOT

    //RBIF = 0; //-> Bandera de interrupción por cambio en RB4-RB7 (RBPortChangeInterruptFlag):
            // 1 = Cambio en RB4-RB7
            // 0 = No ha ocurrido cambio en RB4-RB7 //POR COPILOT
    //INTCON = 0b10100000; //valor final de INTCON (alternativo a las asignaciones anteriores)

    //Velocidad Clock interno = 1MHz, ciclo de instrucción = 4 ciclos de reloj -> 250KHz -> 4us
    //Si por ejemplo Prescaler 1:2 -> 4us * 2 = 8us.
    //TMR0 = 256 - 131 = 125 --> Inicializo TMR0 en 131 para que desborde con 125 ciclos: 125 * 8us = 1ms
    //Cada 1ms se desborda el Timer0 y se llama a interrupcion
    //Si quiero que el desborde sea cada 250ms -> 250ms / 1ms = 250 -> 250 desbordes
    //1ms * 250 = 250ms 

    //PORTB = [RB7,RB6,RB5,RB4,RB3,RB2,RB1,RB0]
    //TRISB = [TRISB7,TRISB6,TRISB5,TRISB4,TRISB3,TRISB2,TRISB1,TRISB0]
    //PORTA = [-,-,RA5,RA4,RA3,RA2,RA1,RA0]
    //TRISA = [-,-,TRISA5,TRISA4,TRISA3,TRISA2,TRISA1,TRISA0]
    TRISB = 0b11101111; //registro PORTB(RB4) como salida
    TRISA = 0b00000011; //registro PORTA(RA0,RA1) como entrada
    while(1) {
        // Esperar hasta que se presione alguno de los pulsadores
        TMR0 = 131; // Reiniciar Timer0 para que no se active la interrupción hasta oprimir
        if (RA0 == 0 || RA1 == 0) {
                // Comenzar a titilar los LEDs de manera alternada cada 250 ms
                while(1) {
                        if (flag1 == 1) {
                                PORTB = PORTB ^ 0b00010000; // Alternar los LEDs RB4 y RB5
                                flag1 = 0;
                        }
                }
        }
    }
}

void interrupt isr(void) {
        // GIE = 0; //Esto es implicito! no es necesario escribirlo
        if (T0IF) { // Verificar si la interrupción es por desbordamiento del Timer0
                T0IF = 0; // Limpiar el flag de interrupción del Timer0
                TMR0 = 143; // reiniciar contador registro timer0
                //el valor teorico era 131, pero se necesita un ajuste para que sea exacto por las lineas de codigo
                if (++contador == 250){
                        flag1=1;
                        contador = 0;
                }
        }
        asm("nop"); //Con estas lineas queda en 250ms clavado (cada 2 nop es +1 en tmr0)
        asm("nop");
        asm("nop");
        asm("nop");
}