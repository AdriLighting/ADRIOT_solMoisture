
#ifndef SOLMOISTURE_H
#define SOLMOISTURE_H
	#include <Arduino.h>

	class solmoistureClass
	{
		boolean _pullup 	= false;
		int  	_pin 		= 0;
		int 	_value 		= 0;
		int 	_valueMax 	= 300;
	public:
		solmoistureClass (boolean pullup, int pin);
		void read 		();
		void read 		(int & result);
		void detect 	(boolean & result);
		void loop 		(boolean & result);
	};

#endif // SOLMOISURE_H