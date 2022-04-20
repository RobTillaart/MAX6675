//
//    FILE: MAX6675_test_HWSPI.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//    DATE: 2022-01-12
//     URL: https://github.com/RobTillaart/MAX6675


#include "MAX6675.h"

const int selectPin   = 5;

MAX6675 thermoCouple;

uint32_t start, stop;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println(MAX6675_LIB_VERSION);
  Serial.println();

  thermoCouple.begin(selectPin);  // HW SPI


}


void loop()
{
  for (uint32_t s = 500; s < 4500; s += 500)
  {
    testPerformance(s * 1000);
    delay(500);
  }
  Serial.println();
}


void testPerformance(uint32_t speed)
{
  thermoCouple.setSPIspeed(speed);

  start = micros();
  int status = thermoCouple.read();
  stop = micros();
  float temp = thermoCouple.getTemperature();

  Serial.print(millis());
  Serial.print("\tspeed: ");
  Serial.print(speed / 1000);
  Serial.print("\tstatus: ");
  Serial.print(status);
  Serial.print("\ttemp: ");
  Serial.print(temp);
  Serial.print("\tus: ");
  Serial.println(stop - start);
  delay(100);
}





// -- END OF FILE --
