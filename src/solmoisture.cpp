#include "solmoisture.h"

solmoistureClass::solmoistureClass(boolean pullup, int pin) {
	_pullup = pullup; 
	_pin 	= pin;	
	if (pullup) pinMode(_pin, INPUT_PULLUP);
	else 		pinMode(_pin, INPUT);
}
void solmoistureClass::read(int & result){
	result = analogRead(_pin);
	_value = result;
}
void solmoistureClass::read(){
	_value = analogRead(_pin);
}
void solmoistureClass::loop(boolean & result){
	read();
	detect(result);
}
void solmoistureClass::detect(boolean & result){
	if (_value<_valueMax) 	result = true;
	else 					result = false;
}