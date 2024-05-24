#include "Ojito_L.h" 

void initPWM0FastA(uint8_t inverted, uint16_t precaler){
	DDRD |= (1<<DDD6);  
	
	TCCR0A = 0;  
	if (inverted) {
		TCCR0A |= (1<<COM0A1)|(1<<COM0A0);  
		} else {
		TCCR0A |= (1<<COM0A1);  
	}
	
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	
	if (precaler == 1024) {
		TCCR0B |= (1<<CS02)|(1<<CS00);  
	}
}

void initPWM0FastB(uint8_t inverted, uint16_t precaler){
	DDRD |= (1<<DDD5);  
	
	TCCR0B = 0;  
	if (inverted) {
		TCCR0A |= (1<<COM0B1)|(1<<COM0B0);  
		} else {
		TCCR0A |= (1<<COM0B1);  
	}
	
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	
	TCCR0B |= (1<<CS02)|(1<<CS00);  
}

void updateDCA(uint8_t duty){
	OCR0A = duty;  
}

void updateDCB(uint8_t duty){
	OCR0B = duty; 
}




