
#ifndef SOILMOISTURE_H
#define SOILMOISTURE_H
	#include <Arduino.h>
	#include <ArduinoJson.h>

	class soilmoistureClass
	{
		boolean _pullup 	= false;
		int  	_pin 		= 0;
		int 	_value 		= 0;
		int 	_valueMax 	= 300;
	public:
		soilmoistureClass 	(boolean pullup, int pin);
		void read 			();
		void read 			(int & result);
		void detect 		(boolean & result);
		void loop 			(boolean & result);
		void json 			(JsonObject & root);
		void domoticzJson	(JsonObject & root);
	};

	class soilmoistureManagment
	{
	private:
		int _pos = 0;
	public:
		soilmoistureManagment();
		~soilmoistureManagment(){};

		void create 	(boolean pullup, int pin, int & result);

		soilmoistureClass * module(int pos);
	};
#endif // SOLMOISURE_H