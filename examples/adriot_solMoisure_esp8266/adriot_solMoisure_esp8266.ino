
#include <ADRIOT_solmoisture.h>
#include <ADRIOT_relay.h>

solmoistureClass * sensorSolMoisture;
relaymanagement relay_managment;

int		relayPump 				= -1;
boolean relayPump_statu 		= false;
boolean sensorSolMoisture_cap 	= false;

void setup()
{
	sensorSolMoisture = new solmoistureClass(false,D1);
	relay_managment.create(D2, relayPump);
}

void loop()
{
	relayPump_statu 		= relay_managment.relay(relayPump)->getStatus();	
	sensorSolMoisture->loop(sensorSolMoisture_cap);
	if (sensorSolMoisture_cap) {
		if (!relayPump_statu) 	relay_managment.relay(relayPump)->open();
	} else {
		if (relayPump_statu) 	relay_managment.relay(relayPump)->close();
	}
}