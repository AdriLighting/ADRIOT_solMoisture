
#include <ADRIOT_solmoisture.h>
#include <ADRIOT_relay.h>

solmoistureClass * sensorSolMoisture;
relaymanagement relay_managment;

int		relayPump;
boolean relayPump_statu;
boolean sensorSolMoisture_cap;

void setup()
{
	sensorSolMoisture = new solmoistureClass(false,D1);
	relay_managment.create(D2, relayPump);
}

void loop()
{
	sensorSolMoisture_cap = false;
	sensorSolMoisture->loop(sensorSolMoisture_cap);
	if (sensorSolMoisture_cap) {
		relayPump_statu = relay_managment.relay(relayPump)->getStatus();
		if (!relayPump_statu) relay_managment.relay(relayPump)->open();
	} else {
		relayPump_statu = relay_managment.relay(relayPump)->getStatus();
		if (relayPump_statu) relay_managment.relay(relayPump)->close();
	}
}