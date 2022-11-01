/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
   More info: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com */

//Libraries
#include "dht.h"
#include "pluvio.h"

//Constants
#define PLUVIO 2
#define T1 3     // DHT 22  (AM2302) - what pin we're connected to
#define T2 4     // DHT 22  (AM2302) - what pin we're connected to

//Variables
pluvio PL(PLUVIO);
dht DHT1;
dht DHT2;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Sensor 1");
    int chk = DHT1.read22(T1);
    if(chk != DHTLIB_OK) {
      Serial.print("[E] DHT lib error ");
      Serial.println(chk);
     }
    //Read data and store it to variables hum and temp
    hum = DHT1.humidity;
    temp= DHT1.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");

    Serial.println("Sensor 2");
    chk = DHT2.read22(T2);
    if(chk != DHTLIB_OK) {
      Serial.print("[E] DHT lib error ");
      Serial.println(chk);
     }
    //Read data and store it to variables hum and temp
    hum = DHT2.humidity;
    temp= DHT2.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");

    Serial.println("Rain");
    double rain = PL.getRain();
    Serial.print("Rain: ");
    Serial.println(rain);
    if(rain > 1) {
     PL.resetRain();
    }

    
    delay(5000); //Delay 1 sec.
}
