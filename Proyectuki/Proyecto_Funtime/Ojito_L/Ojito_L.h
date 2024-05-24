#ifndef Ojito_L  
#define Ojito_L

#include <avr/io.h>   
#include <stdint.h>   

#define invertido 1      
#define no_invertido 0   

void initPWM0FastA(uint8_t inverted, uint16_t precaler);
void updateDCA(uint8_t duty);

void initPWM0FastB(uint8_t inverted, uint16_t precaler);
void updateDCB(uint8_t duty);

#endif  
