
#define _PARTICLE_BUILD_IDE_  // undefine for Particle CLI or Particle Dev
#if define(_PARTICLE_BUILD_IDE_)
#  include "Adafruit_VL53L0X/Adafruit_VL53L0X.h"
#else
#  include "Adafruit_VL53L0X.h"
#endif

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println("Failed to boot VL53L0X");
    while(1) Particle.process();
  }
  // power 
  Serial.println("VL53L0X API Simple Ranging example\n\n"); 
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);
}
