
#include <ADRIOT_solmoisture.h>
#include <ADRIOT_relay.h>

solmoistureClass * sensorSolMoisture;

boolean sensorSolMoisture_cap 	= false;

void setup()
{
	sensorSolMoisture = new solmoistureClass(false,D1);
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