#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


// LED Pins
int hotLedPin = 6;
int goneColdLedPin = 7;

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(hotLedPin,OUTPUT);

}

void loop(void){ 

  sensors.requestTemperatures(); 

  float temp = sensors.getTempCByIndex(0); 
  
  Serial.println(sensors.getDeviceCount());

  Serial.print("Celsius temperature: ");
  Serial.print(temp); 

  Serial.print('\n');
  Serial.print('\n');

  delay(500);

   //LED Code
  if (temp >= 80){
    digitalWrite(hotLedPin,HIGH);
    Serial.println("Your beverage is at an optimum temperature!: " + temp);
  }
  
  if (temp <= 40{
  pinMode(goneColdLedPin, HIGH);
  Serial.println("Your beverage is getting cold!: " + temp);
  }


}
}