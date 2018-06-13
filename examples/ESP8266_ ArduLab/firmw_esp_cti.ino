/*
This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.

The CayenneMQTT Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. If you have not already installed the ESP8266 Board Package install it using the instructions here: https://github.com/esp8266/Arduino#installing-with-boards-manager.
2. Select your ESP8266 board from the Tools menu.
3. Set the Cayenne authentication info to match the authentication info from the Dashboard.
4. Set the network name and password.
5. Compile and upload the sketch.
6. A temporary widget will be automatically generated in the Cayenne Dashboard. To make the widget permanent click the plus sign on the widget.
*/

#include <CayenneMQTTESP8266.h>

#define INPUT_SIZE 30

// WiFi network info.
char ssid[] = "******";
char wifiPassword[] = "******";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "208786b0-2f63-11e7-8b86-73b5abd46b10";
char password[] = "f315ee0c92e83e9fdfece92aa589b756980f006a";
char clientID[] = "3beefb90-38f9-11e8-9beb-4d400e603e7e";



void setup() {
	Serial.begin(9600);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
  // read from port 1, send to port 0:
// Get next command from Serial (add 1 for final 0)
char input[INPUT_SIZE + 1];
byte size = Serial.readBytes(input, INPUT_SIZE);
// Add the final 0 to end the C string
input[size] = 0;

// Read each command pair 
char* command = strtok(input, "&");
while (command != 0)
{
    // Split the command in two values
    char* separator = strchr(command, ':');
    if (separator != 0)
    {
        // Actually split the string in 2: replace ':' with 0
        *separator = 0;
        int id = atoi(command);
        ++separator;
        int value = atoi(separator);
        ++separator;
        int type = atoi(separator);
        ++separator;
        if (type==0){
            Cayenne.virtualWrite(id, value);
        }
        else if (type == 1){
            Cayenne.virtualWrite(id, value, "temp", "c");
        }
        else if (type == 2){
            Cayenne.virtualWrite(id, value, "bp", "hpa");
        }
        String n_msg = String(id)+"_"+String(value)+"_"+String(type);
        Serial.println(n_msg);

    }
    // Find the next command in input string
    command = strtok(0, "&");
}  
	// Cayenne.virtualWrite(0, millis());
	// Some examples of other functions you can use to send data.
	//Cayenne.celsiusWrite(1, 22.0);
	//Cayenne.luxWrite(2, 700);
	//Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	Serial.print(request.channel);
	Serial.print(";");
	Serial.println(getValue.asString());
	
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
