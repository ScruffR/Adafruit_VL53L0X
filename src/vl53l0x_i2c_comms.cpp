#include "vl53l0x_i2c_platform.h"
#include "vl53l0x_def.h"

//#define I2C_DEBUG

int VL53L0X_i2c_init(void) {
  Wire.begin();
  return VL53L0X_ERROR_NONE;
}

int VL53L0X_write_multi(uint8_t deviceAddress, uint8_t index, uint8_t *pdata, uint32_t count) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(index);
#ifdef I2C_DEBUG
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
  Log.info("\tWriting %d to addr 0x02x : ", count, index);
#else
  Serial.print("\tWriting "); Serial.print(count); Serial.print(" to addr 0x"); Serial.print(index, HEX); Serial.print(": ");
#endif
#endif
  while(count--) {
    Wire.write((uint8_t)pdata[0]);
#ifdef I2C_DEBUG
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
    Log.info("0x%02x, ", pdata[0]);
#else
    Serial.print("0x"); Serial.print(pdata[0], HEX); Serial.print(", ");
#endif
#endif
    pdata++;
  }
#ifdef I2C_DEBUG
#if !(defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000))
  Serial.println();
#endif
#endif
  Wire.endTransmission();
  return VL53L0X_ERROR_NONE;
}

int VL53L0X_read_multi(uint8_t deviceAddress, uint8_t index, uint8_t *pdata, uint32_t count) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(index);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, (byte)count);
#ifdef I2C_DEBUG
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
  Log.info("\tReading %d from addr 0x%02x : ", count, index);
#else
  Serial.print("\tReading "); Serial.print(count); Serial.print(" from addr 0x"); Serial.print(index, HEX); Serial.print(": ");
#endif
#endif

  while (count--) {
    pdata[0] = Wire.read();
#ifdef I2C_DEBUG
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
    Log.info("0x%02x,", pdata[0]);
#else
    Serial.print("0x"); Serial.print(pdata[0], HEX); Serial.print(", ");
#endif
#endif
    pdata++;
  }
#ifdef I2C_DEBUG
#if !(defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000))
  Serial.println();
#endif
#endif
  return VL53L0X_ERROR_NONE;
}

int VL53L0X_write_byte(uint8_t deviceAddress, uint8_t index, uint8_t data) {
  return VL53L0X_write_multi(deviceAddress, index, &data, 1);
}

int VL53L0X_write_word(uint8_t deviceAddress, uint8_t index, uint16_t data) {
  uint8_t buf[4];
  buf[1] = data>>0&0xFF;
  buf[0] = data>>8&0xFF;
  return VL53L0X_write_multi(deviceAddress, index, buf, 2);
}

int VL53L0X_write_dword(uint8_t deviceAddress, uint8_t index, uint32_t data) {
  uint8_t buf[4];
  buf[3] = data>>0&0xFF;
  buf[2] = data>>8&0xFF;
  buf[1] = data>>16&0xFF;
  buf[0] = data>>24&0xFF;
  return VL53L0X_write_multi(deviceAddress, index, buf, 4);
}

int VL53L0X_read_byte(uint8_t deviceAddress, uint8_t index, uint8_t *data) {
  return VL53L0X_read_multi(deviceAddress, index, data, 1);
}

int VL53L0X_read_word(uint8_t deviceAddress, uint8_t index, uint16_t *data) {
  uint8_t buf[2];
  int r = VL53L0X_read_multi(deviceAddress, index, buf, 2);
  uint16_t tmp = 0;
  tmp |= buf[1]<<0;
  tmp |= buf[0]<<8;
  *data = tmp;
  return r;
}

int VL53L0X_read_dword(uint8_t deviceAddress, uint8_t index, uint32_t *data) {
  uint8_t buf[4];
  int r = VL53L0X_read_multi(deviceAddress, index, buf, 4);
  uint32_t tmp = 0;
  tmp |= buf[3]<<0;
  tmp |= buf[2]<<8;
  tmp |= buf[1]<<16;
  tmp |= buf[0]<<24;
  *data = tmp;
  return r;
}
