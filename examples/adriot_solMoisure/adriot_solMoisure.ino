
#include <ADRIIOT_soilmoisture.h>

soilmoistureClass * sensorSolMoisture;

boolean sensorSolMoisture_cap 	= false;

void setup()
{
	sensorSolMoisture = new soilmoistureClass(false,D1);
}

void loop()
{
	sensorSolMoisture->loop(sensorSolMoisture_cap);
	if (sensorSolMoisture_cap) {
		/* -- NEED WATER 		*/
	} else {
		/* -- NO NEED WATER 	*/
	}
}