//-------------------Importacion de librerias-----------------------------------
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <pic16f887.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "UART.h"
#define _XTAL_FREQ 4000000

//------------------declaracion de variables------------------------------------
uint8_t PC = 0;       
uint8_t cont = 0;       
char s[20];

//--------------------------Envio de caracteres---------------------------------
void Envio_caracter(char caracter)
{
    while(!TXIF);       //Espera que envie dato TXIF = 1 siempre
    TXREG = caracter;   //Carga el caracter a TXREG y envía 
    return; 
}
//------------------Generacion de cadenas de caracteres-------------------------
void cadena_caracteres(char st[])
{
    int i = 0;          //i igual 0 posicion 
    while (st[i] !=0)   //revisar la posicion de valor de i 
    {
        Envio_caracter(st[i]); //enviar caracter de esa posicion 
        i++;                //incrementar variable para pasar a otra posicion 
    }                       //de cadena 
    return;
}
//-----------------------configuracion------------------------------------------
void config_UART(void)
{
    TXSTAbits.SYNC = 0;             //Modo asíncrono
    TXSTAbits.BRGH = 1;             //Seleccion BAUD RATE
    BAUDCTLbits.BRG16 = 0; 
    
    SPBRG = 25;                     //Registros para valor BAUD RATE
    SPBRGH = 0; 
    
    RCSTAbits.SPEN = 1;         //Habilitar puerto serial asíncrono
    RCSTAbits.RX9 = 0;
    RCSTAbits.CREN = 1;         //Habilitar recepción de datos 

    TXSTAbits.TXEN = 1;         //Habilitar transmision
}
//------------------------------------Impresion---------------------------------
void valorsensores(void)
{
    sprintf(s, "\r Contador=%d\n",cont);
    cadena_caracteres(s);
   
    sprintf(s, "\n V_PC=%d", PC);
    cadena_caracteres(s);
}
