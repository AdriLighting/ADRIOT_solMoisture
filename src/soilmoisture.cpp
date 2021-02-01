#include "soilmoisture.h"



#define MAX_SENSOR 10
soilmoistureClass * soilmoistureClassArray[MAX_SENSOR];

soilmoistureManagment::soilmoistureManagment(){

}

void soilmoistureManagment::create(boolean pullup, int pin, int & result){
	soilmoistureClassArray[_pos] = new soilmoistureClass(pullup, pin);
	result = _pos;
	_pos++;
}

soilmoistureClass * soilmoistureManagment::module(int pos){
	return soilmoistureClassArray[pos];
}




soilmoistureClass::soilmoistureClass(boolean pullup, int pin) {
	_pullup = pullup; 
	_pin 	= pin;	
	if (pullup) pinMode(_pin, INPUT_PULLUP);
	else 		pinMode(_pin, INPUT);
}
void soilmoistureClass::read(int & result){
	result = analogRead(_pin);
	result = ESP.getVcc();
	_value = result;
}
void soilmoistureClass::read(){
	// _value = analogRead(_pin);
	_value = ESP.getVcc();
}
void soilmoistureClass::loop(boolean & result){
	read();
	detect(result);
}
void soilmoistureClass::detect(boolean & result){
	if (_value<_valueMax) 	result = true;
	else 					result = false;
}
void soilmoistureClass::json(JsonObject & root){
	// root[F("v1")] = analogRead(_pin);
	root[F("v1")] = ESP.getVcc();
}
void soilmoistureClass::domoticzJson(JsonObject & root){
	// root[F("v1")] = analogRead(_pin);
	root[F("nvalue")] = String(analogRead(_pin)) ;
	root[F("svalue")] = 0;
}