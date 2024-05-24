//*****************************************************************************
//Universidad del Valle de Guatemala
//Programación de Microcontroladores
//Archivo:Funtime_Foxy_eyes
//Hardware:ATMEGA328P
//Autor:Adriana Marcela Gonzalez
//Carnet:22438
//*****************************************************************************

#define F_CPU 16000000  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Ojito_L/Ojito_L.h"  
#include "Ojito_R/Ojito_R.h"  

void initADC(void){
	ADMUX = 0;  
	

	ADMUX |= (1<<REFS0);  
	ADMUX &= ~(1<<REFS1); 
	ADMUX |= (1<<ADLAR);  

	ADCSRA = 0;  
	
	ADCSRA |= (1<<ADEN); 
	
	ADCSRA |= (ADPS2)|(ADPS1)|(ADPS0);  
	
	DIDR0 |= (1<<ADC5D); 
	
	DIDR0 |= (1<<ADC4D); 
}


uint16_t valorADC (uint8_t canal) {
	ADMUX &= 0xF0;  
	ADMUX |= canal; 
	
	ADCSRA |= (1 << ADSC);  
	
	while (ADCSRA & (1 << ADSC));  
	
	return ADCH; 
}


void setup (void){
	
}


int main(void)
{  
	initPWM0FastA(0,1024);  
	initPWM0FastB(0,1024);  
	initPWM1FastA(0,1024);
	initPWM1FastB(0,1024);
	setup();  
	initADC();  
	sei();

	uint16_t dutyCycle1 = valorADC(6);
	uint16_t dutyCycle2 = valorADC(7);
	uint16_t dutyCycle3 = valorADC(5);
	uint16_t dutyCycle4 = valorADC(4);
	
    while (1) 
    {
			//Ojo izquierdo
			dutyCycle1 = valorADC(6);
			_delay_ms(10);  
			
			updateDCA(dutyCycle1);

			dutyCycle2 = valorADC(7);
			_delay_ms(10);  
			
			updateDCB(dutyCycle2);
			
			//Ojo derecho 
			dutyCycle3 = valorADC(5);
			_delay_ms(10);
			
			updateDCA1(dutyCycle3);

			dutyCycle4 = valorADC(4);
			_delay_ms(10);
			
			updateDCB1(dutyCycle4);
			
			_delay_ms(25);  
    }
	
	return 0; 
}


