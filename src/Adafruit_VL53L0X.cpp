#include "Adafruit_VL53L0X.h"

#define VERSION_REQUIRED_MAJOR 1
#define VERSION_REQUIRED_MINOR 0
#define VERSION_REQUIRED_BUILD 1
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)


boolean Adafruit_VL53L0X::begin(void) {
  //int32_t status_int;
  //int32_t init_done = 0;

  // Initialize Comms
  pMyDevice->I2cDevAddr      = VL53L0X_I2C_ADDR;  // 7 bit addr
  pMyDevice->comms_type      = 1;
  pMyDevice->comms_speed_khz = 400;

  
  Wire.begin();  // VL53L0X_i2c_init();

  // unclear if this is even needed:
  if( VL53L0X_IMPLEMENTATION_VER_MAJOR != VERSION_REQUIRED_MAJOR ||
      VL53L0X_IMPLEMENTATION_VER_MINOR != VERSION_REQUIRED_MINOR ||
      VL53L0X_IMPLEMENTATION_VER_SUB != VERSION_REQUIRED_BUILD )  {
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
    Log.info("Found " STR(VL53L0X_IMPLEMENTATION_VER_MAJOR) "." STR(VL53L0X_IMPLEMENTATION_VER_MINOR) "."  STR(VL53L0X_IMPLEMENTATION_VER_SUB) " rev " STR(VL53L0X_IMPLEMENTATION_VER_REVISION));
    Log.info("Requires " STR(VERSION_REQUIRED_MAJOR) "." STR(VERSION_REQUIRED_MINOR) "." STR(VERSION_REQUIRED_BUILD));
#else
    Serial.println(F("Found " STR(VL53L0X_IMPLEMENTATION_VER_MAJOR) "." STR(VL53L0X_IMPLEMENTATION_VER_MINOR) "."  STR(VL53L0X_IMPLEMENTATION_VER_SUB) " rev " STR(VL53L0X_IMPLEMENTATION_VER_REVISION)));
    Serial.println(F("Requires " STR(VERSION_REQUIRED_MAJOR) "." STR(VERSION_REQUIRED_MINOR) "." STR(VERSION_REQUIRED_BUILD)));
#endif
    return false;
  }

  Status = VL53L0X_DataInit(&MyDevice); // Data initialization

  Status = VL53L0X_GetDeviceInfo(&MyDevice, &DeviceInfo);

  if (Status != VL53L0X_ERROR_NONE)
    return false;

  if(Status == VL53L0X_ERROR_NONE)  {
    //Serial.println(F("VL53L0X_GetDeviceInfo:"));
    //Serial.print(F("Device Name : ")); Serial.println(DeviceInfo.Name);
    //Serial.print(F("Device Type : ")); Serial.println(DeviceInfo.Type);
    //Serial.print(F("Device ID : ")); Serial.println(DeviceInfo.ProductId);
    //Serial.print(F("ProductRevisionMajor : ")); Serial.println(DeviceInfo.ProductRevisionMajor);
    //Serial.print(F("ProductRevisionMinor : ")); Serial.println(DeviceInfo.ProductRevisionMinor);

    if ((DeviceInfo.ProductRevisionMinor != 1) || (DeviceInfo.ProductRevisionMinor != 1)) {
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
      Log.info("Error expected cut 1.1 but found cut %d.%d", DeviceInfo.ProductRevisionMajor, DeviceInfo.ProductRevisionMinor);
#else
      Serial.print(F("Error expected cut 1.1 but found cut ")); 
      Serial.print(DeviceInfo.ProductRevisionMajor);
      Serial.print('.');
      Serial.println(DeviceInfo.ProductRevisionMinor);
#endif
      Status = VL53L0X_ERROR_NOT_SUPPORTED;

      return false;     
     }
  }
  return true;
}


VL53L0X_Error Adafruit_VL53L0X::rangingTest(VL53L0X_RangingMeasurementData_t *RangingMeasurementData, boolean debug)
{
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    //int i;
    FixPoint1616_t LimitCheckCurrent;
    uint32_t refSpadCount;
    uint8_t isApertureSpads;
    uint8_t VhvSettings;
    uint8_t PhaseCal;

    if(Status == VL53L0X_ERROR_NONE)
    {
      if (debug)
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("Call of VL53L0X_StaticInit");
#else
      	Serial.println(F("Call of VL53L0X_StaticInit"));
#endif
      Status = VL53L0X_StaticInit(pMyDevice); // Device Initialization
    }
    
    if(Status == VL53L0X_ERROR_NONE)
    {
      if (debug)
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("Call of VL53L0X_PerformRefCalibration");
#else
        Serial.println(F("Call of VL53L0X_PerformRefCalibration"));
#endif
      Status = VL53L0X_PerformRefCalibration(pMyDevice,
		&VhvSettings, &PhaseCal); // Device Initialization
    }

    if(Status == VL53L0X_ERROR_NONE)
    {
      if (debug)
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("Call of VL53L0X_PerformRefSpadManagement");
#else
        Serial.println(F("Call of VL53L0X_PerformRefSpadManagement"));
#endif
      Status = VL53L0X_PerformRefSpadManagement(pMyDevice,
            &refSpadCount, &isApertureSpads); // Device Initialization
      if (debug) {
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("refSpadCount = %u, isApertureSpads = %u", refSpadCount, isApertureSpads);
#else
        Serial.print(F("refSpadCount = "));
        Serial.print(refSpadCount);
        Serial.print(F(", isApertureSpads = "));
        Serial.println(isApertureSpads);
#endif
      }
    }

    if(Status == VL53L0X_ERROR_NONE)
    {
        // no need to do this when we use VL53L0X_PerformSingleRangingMeasurement
      if (debug)
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("Call of VL53L0X_SetDeviceMode");
#else
        Serial.println(F("Call of VL53L0X_SetDeviceMode"));
#endif
      Status = VL53L0X_SetDeviceMode(pMyDevice, VL53L0X_DEVICEMODE_SINGLE_RANGING); // Setup in single ranging mode
    }

    // Enable/Disable Sigma and Signal check
    if (Status == VL53L0X_ERROR_NONE) {
        Status = VL53L0X_SetLimitCheckEnable(pMyDevice,
            VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
    }
    if (Status == VL53L0X_ERROR_NONE) {
        Status = VL53L0X_SetLimitCheckEnable(pMyDevice,
            VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
    }

    if (Status == VL53L0X_ERROR_NONE) {
        Status = VL53L0X_SetLimitCheckEnable(pMyDevice,
            VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD, 1);
    }

    if (Status == VL53L0X_ERROR_NONE) {
        Status = VL53L0X_SetLimitCheckValue(pMyDevice,
            VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD,
            (FixPoint1616_t)(1.5*0.023*65536));
    }


    /*
     *  Step  4 : Test ranging mode
     */

    if(Status == VL53L0X_ERROR_NONE)
    {
      if (debug)
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("Call of VL53L0X_PerformSingleRangingMeasurement");
#else
        Serial.println(F("Call of VL53L0X_PerformSingleRangingMeasurement"));
#endif
      Status = VL53L0X_PerformSingleRangingMeasurement(pMyDevice,
						       RangingMeasurementData);
      
      if (debug)
	print_range_status(RangingMeasurementData);
      
      VL53L0X_GetLimitCheckCurrent(pMyDevice,
				   VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD, &LimitCheckCurrent);
      
      if (debug) {
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
        Log.info("RANGE IGNORE THRESHOLD: %f, Measured distance: %d", (float)LimitCheckCurrent / 65536.0, RangingMeasurementData->RangeMilliMeter);
#else
        Serial.print(F("RANGE IGNORE THRESHOLD: "));
	      Serial.println((float)LimitCheckCurrent/65536.0);
	    	Serial.print(F("Measured distance: "));
      	Serial.println(RangingMeasurementData->RangeMilliMeter);
#endif
      }
    }
    return Status;
}

void Adafruit_VL53L0X::print_range_status(VL53L0X_RangingMeasurementData_t* pRangingMeasurementData){
    char buf[VL53L0X_MAX_STRING_LENGTH];
    uint8_t RangeStatus;

    /*
     * New Range Status: data is valid when pRangingMeasurementData->RangeStatus = 0
     */

    RangeStatus = pRangingMeasurementData->RangeStatus;

    VL53L0X_GetRangeStatusString(RangeStatus, buf);
#if defined(PARTICLE) && (SYSTEM_VERSION >= 0x00060000)
    Log.info("Range Status: %u : %s", RangeStatus, buf);
#else
    Serial.print(F("Range Status: "));
    Serial.print(RangeStatus);
    Serial.print(" : "); 
    Serial.println(buf);
#endif
}

