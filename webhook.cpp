#include <BH1750.h>

BH1750 sensor(0x23, Wire);
int led = D7;

void setup()
{
  pinMode(led, OUTPUT);
  sensor.begin();
  sensor.set_sensor_mode(BH1750::forced_mode_high_res2);
}

void loop()
{
  sensor.make_forced_measurement();
  digitalWrite(led, HIGH);   // Turn ON the LED

  float bright = sensor.get_light_level();
  Particle.publish("bright", String(bright), PRIVATE);
  delay(15000);               // Wait for 15 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(15000);               // Wait for 15 seconds

}
