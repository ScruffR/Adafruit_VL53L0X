#include "Adafruit_VL53L0X.h"

#define VL53L0X_LOG_ENABLE 0
uint32_t _trace_level = TRACE_LEVEL_ALL; 

#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
SerialLogHandler logHandler(LOG_LEVEL_ALL);
#endif

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial1.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial1) {
    delay(1);
  }

  Serial1.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial1.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  Serial1.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial1.print("Reading a measurement... ");
  lox.rangingTest(&measure, true); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial1.print("Distance (mm): "); Serial1.println(measure.RangeMilliMeter);
  } else {
    Serial1.println(" out of range ");
  }

  delay(1000);
}
