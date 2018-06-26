/******************************************************************************

Taller_VII.ino
Presence sensor alarm with IoT.
Created by J.G.Aguado
June 19, 2018  
https://github.com/SpaceDIY/ArduLab

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact jon-garcia@hotmail.com.
Distributed as-is; no warranty is given.

******************************************************************************/

//#define CAYENNE_DEBUG       // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneMQTTESP8266Shield.h>

// WiFi network info.
char ssid[] = "******";
char wifiPassword[] = "******";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "******";
char password[] = "******";
char clientID[] = "******";

// Set ESP8266 Serial object. In this example we use the Serial1 hardware serial which is available on boards like the Arduino Mega.
#define EspSerial Serial1

ESP8266 wifi(&EspSerial);

bool pirState = LOW;

void setup()
{
	Serial.begin(9600);
	delay(10);

	// Set ESP8266 baud rate
	EspSerial.begin(115200);
	delay(10);

	Cayenne.begin(username, password, clientID, wifi, ssid, wifiPassword);
}

void loop()
{
    int val = analogRead(A2);
    if (val>500){
        digitalWrite(13, HIGH);
        Cayenne.loop();
        digitalWrite(13, LOW);
    }
}


// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
    Cayenne.virtualWrite(1, HIGH);
    delay(10000);
    Cayenne.virtualWrite(1, LOW);

}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}