#define _PARTICLE_BUILD_IDE_  // undefine for Particle CLI or Particle Dev
#if defined(_PARTICLE_BUILD_IDE_)
#  include "Adafruit_VL53L0X/Adafruit_VL53L0X.h"
#else
#  include "Adafruit_VL53L0X.h"
#endif

#define VL53L0X_LOG_ENABLE 0
uint32_t _trace_level = TRACE_LEVEL_ALL;

Adafruit_VL53L0X lox;
VL53L0X_RangingMeasurementData_t measure;

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
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, true); // pass in 'true' to get debug data printout!


  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(2000);
}

/*
Adafruit VL53L0X test
2931 <START> VL53L0X_DataInit

module: 1, level: 5, function: 2147483647
2932 <START> VL53L0X_GetDeviceParameters

module: 1, level: 5, function: 2147483647
2933 <START> VL53L0X_GetDeviceMode

module: 1, level: 5, function: 2147483647
2933 <END> VL53L0X_GetDeviceMode 0

module: 1, level: 5, function: 2147483647
2933 <START> VL53L0X_GetInterMeasurementPeriodMilliSeconds

module: 1, level: 5, function: 2147483647
2935 <END> VL53L0X_GetInterMeasurementPeriodMilliSeconds 0

module: 1, level: 5, function: 2147483647
2936 <START> VL53L0X_GetXTalkCompensationRateMegaCps

module: 1, level: 5, function: 2147483647
2937 <END> VL53L0X_GetXTalkCompensationRateMegaCps 0

module: 1, level: 5, function: 2147483647
2937 <START> VL53L0X_GetOffsetCalibrationDataMicroMeter

module: 1, level: 5, function: 2147483647
2938 <END> VL53L0X_GetOffsetCalibrationDataMicroMeter 0

module: 1, level: 5, function: 2147483647
2938 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
2939 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2939 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2940 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2940 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
2941 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2942 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2942 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2943 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
2943 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2943 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2944 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2944 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
2944 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2945 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2945 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2946 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
2947 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2947 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2947 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2948 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
2949 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2949 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2949 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2950 <START> VL53L0X_GetWrapAroundCheckEnable

module: 1, level: 5, function: 2147483647
2951 <END> VL53L0X_GetWrapAroundCheckEnable 0

module: 1, level: 5, function: 2147483647
2951 <START> VL53L0X_GetMeasurementTimingBudgetMicroSeconds

module: 1, level: 5, function: 2147483647
2952 <START> VL53L0X_get_measurement_timing_budget_micro_seconds

module: 1, level: 5, function: 2147483647
2952 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
2953 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2953 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2954 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2954 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2955 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2955 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2956 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2956 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2956 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2957 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2957 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
2957 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
2958 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
2959 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
2959 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
2960 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
2961 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
2961 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
2962 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
2963 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
2964 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
2964 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
2965 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2965 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2966 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2966 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2967 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2967 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2968 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2968 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2969 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
2969 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
2970 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
2970 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
2971 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
2972 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
2973 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
2974 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
2974 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
2975 <END> VL53L0X_get_measurement_timing_budget_micro_seconds 0

module: 1, level: 5, function: 2147483647
2975 <END> VL53L0X_GetMeasurementTimingBudgetMicroSeconds 0

module: 1, level: 5, function: 2147483647
2976 <END> VL53L0X_GetDeviceParameters 0

module: 1, level: 5, function: 2147483647
2978 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2979 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2979 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2980 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2980 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2981 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2981 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2981 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2982 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2983 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2984 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2985 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2985 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2986 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2986 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2987 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2987 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2989 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2989 <START> VL53L0X_SetLimitCheckEnable

module: 1, level: 5, function: 2147483647
2991 <END> VL53L0X_SetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
2991 <START> VL53L0X_SetLimitCheckValue

module: 1, level: 5, function: 2147483647
2992 <END> VL53L0X_SetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2992 <START> VL53L0X_SetLimitCheckValue

module: 1, level: 5, function: 2147483647
2993 <END> VL53L0X_SetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2994 <START> VL53L0X_SetLimitCheckValue

module: 1, level: 5, function: 2147483647
2994 <END> VL53L0X_SetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2995 <START> VL53L0X_SetLimitCheckValue

module: 1, level: 5, function: 2147483647
2995 <END> VL53L0X_SetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
2996 <END> VL53L0X_DataInit 0

module: 1, level: 5, function: 2147483647
2996 <START> VL53L0X_GetDeviceInfo

module: 1, level: 5, function: 2147483647
2996 <START> VL53L0X_check_part_used

module: 1, level: 5, function: 2147483647
2997 <START> VL53L0X_get_info_from_device

module: 1, level: 5, function: 2147483647
3000 <START> VL53L0X_PollingDelay

module: 2, level: 5, function: 2147483647
3000 <END> VL53L0X_PollingDelay 0

module: 2, level: 5, function: 2147483647
3002 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3003 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3004 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3005 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3006 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3008 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3009 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3011 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3012 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3013 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3015 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3016 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3019 <END> VL53L0X_get_info_from_device 0

module: 1, level: 5, function: 2147483647
3020 <END> VL53L0X_check_part_used 0

module: 1, level: 5, function: 2147483647
3021 <END> VL53L0X_GetDeviceInfo 0

module: 1, level: 5, function: 2147483647
VL53L0X API Simple Ranging example


Reading a measurement... Call of VL53L0X_StaticInit
3022 <START> VL53L0X_StaticInit

module: 1, level: 5, function: 2147483647
3022 <START> VL53L0X_get_info_from_device

module: 1, level: 5, function: 2147483647
3025 <START> VL53L0X_PollingDelay

module: 2, level: 5, function: 2147483647
3026 <END> VL53L0X_PollingDelay 0

module: 2, level: 5, function: 2147483647
3027 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3028 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3029 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3031 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3032 <START> VL53L0X_device_read_strobe

module: 1, level: 5, function: 2147483647
3033 <END> VL53L0X_device_read_strobe 0

module: 1, level: 5, function: 2147483647
3037 <END> VL53L0X_get_info_from_device 0

module: 1, level: 5, function: 2147483647
3041 <START> VL53L0X_load_tuning_settings

module: 1, level: 5, function: 2147483647
3064 <END> VL53L0X_load_tuning_settings 0

module: 1, level: 5, function: 2147483647
3065 <START> VL53L0X_SetGpioConfig

module: 1, level: 5, function: 2147483647
3066 <START> VL53L0X_ClearInterruptMask

module: 1, level: 5, function: 2147483647
3068 <END> VL53L0X_ClearInterruptMask 0

module: 1, level: 5, function: 2147483647
3068 <END> VL53L0X_SetGpioConfig 0

module: 1, level: 5, function: 2147483647
3069 <START> VL53L0X_GetDeviceParameters

module: 1, level: 5, function: 2147483647
3070 <START> VL53L0X_GetDeviceMode

module: 1, level: 5, function: 2147483647
3070 <END> VL53L0X_GetDeviceMode 0

module: 1, level: 5, function: 2147483647
3070 <START> VL53L0X_GetInterMeasurementPeriodMilliSeconds

module: 1, level: 5, function: 2147483647
3072 <END> VL53L0X_GetInterMeasurementPeriodMilliSeconds 0

module: 1, level: 5, function: 2147483647
3073 <START> VL53L0X_GetXTalkCompensationRateMegaCps

module: 1, level: 5, function: 2147483647
3074 <END> VL53L0X_GetXTalkCompensationRateMegaCps 0

module: 1, level: 5, function: 2147483647
3074 <START> VL53L0X_GetOffsetCalibrationDataMicroMeter

module: 1, level: 5, function: 2147483647
3075 <END> VL53L0X_GetOffsetCalibrationDataMicroMeter 0

module: 1, level: 5, function: 2147483647
3075 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
3076 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
3076 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
3077 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
3077 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
3079 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
3079 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
3079 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
3080 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
3080 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
3081 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
3081 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
3082 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
3082 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
3083 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
3083 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
3084 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
3085 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
3085 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
3093 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
3093 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
3098 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
3099 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
3101 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
3104 <START> VL53L0X_GetWrapAroundCheckEnable

module: 1, level: 5, function: 2147483647
3106 <END> VL53L0X_GetWrapAroundCheckEnable 0

module: 1, level: 5, function: 2147483647
3109 <START> VL53L0X_GetMeasurementTimingBudgetMicroSeconds

module: 1, level: 5, function: 2147483647
3110 <START> VL53L0X_get_measurement_timing_budget_micro_seconds

module: 1, level: 5, function: 2147483647
3114 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
3116 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3124 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3125 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3129 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3131 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3132 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3134 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3137 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3138 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3140 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3141 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
3144 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3148 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3154 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
3154 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
3158 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3160 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3161 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3163 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3166 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
3167 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
3169 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
3173 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3175 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3176 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3178 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3180 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3187 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3190 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3191 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3195 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3197 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3198 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
3200 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3203 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3205 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3208 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3210 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
3211 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
3216 <END> VL53L0X_get_measurement_timing_budget_micro_seconds 0

module: 1, level: 5, function: 2147483647
3220 <END> VL53L0X_GetMeasurementTimingBudgetMicroSeconds 0

module: 1, level: 5, function: 2147483647
3222 <END> VL53L0X_GetDeviceParameters 0

module: 1, level: 5, function: 2147483647
3225 <START> VL53L0X_GetFractionEnable

module: 1, level: 5, function: 2147483647
3226 <END> VL53L0X_GetFractionEnable 0

module: 1, level: 5, function: 2147483647
3229 <START> VL53L0X_SetSequenceStepEnable

module: 1, level: 5, function: 2147483647
3232 <START> VL53L0X_SetMeasurementTimingBudgetMicroSeconds

module: 1, level: 5, function: 2147483647
3233 <START> VL53L0X_set_measurement_timing_budget_micro_seconds

module: 1, level: 5, function: 2147483647
3236 <END> VL53L0X_SetMeasurementTimingBudgetMicroSeconds -4

module: 1, level: 5, function: 2147483647
3239 <END> VL53L0X_SetSequenceStepEnable 0

module: 1, level: 5, function: 2147483647
3244 <START> VL53L0X_SetSequenceStepEnable

module: 1, level: 5, function: 2147483647
3248 <END> VL53L0X_SetSequenceStepEnable 0

module: 1, level: 5, function: 2147483647
3249 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3252 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3254 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3255 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3258 <START> VL53L0X_GetSequenceStepTimeout

module: 1, level: 5, function: 2147483647
3261 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3263 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3264 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3268 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3269 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
3271 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
3281 <END> VL53L0X_GetSequenceStepTimeout 0

module: 1, level: 5, function: 2147483647
3283 <START> VL53L0X_GetSequenceStepTimeout

module: 1, level: 5, function: 2147483647
3284 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
3286 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3289 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3290 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3294 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3296 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3297 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3299 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3302 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3303 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
3311 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
3313 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
3316 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3318 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3321 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
3322 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
3325 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
3327 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
3328 <END> VL53L0X_GetSequenceStepTimeout 0

module: 1, level: 5, function: 2147483647
3331 <END> VL53L0X_StaticInit 0

module: 1, level: 5, function: 2147483647
Call of VL53L0X_PerformRefCalibration
3340 <START> VL53L0X_PerformRefCalibration

module: 1, level: 5, function: 2147483647
3343 <START> VL53L0X_measurement_poll_for_completion

module: 1, level: 5, function: 2147483647
3344 <START> VL53L0X_GetMeasurementDataReady

module: 1, level: 5, function: 2147483647
3346 <START> VL53L0X_GetInterruptMaskStatus

module: 1, level: 5, function: 2147483647
3350 <END> VL53L0X_GetInterruptMaskStatus 0

module: 1, level: 5, function: 2147483647
3353 <END> VL53L0X_GetMeasurementDataReady 0

module: 1, level: 5, function: 2147483647
3354 <START> VL53L0X_PollingDelay

module: 2, level: 5, function: 2147483647
3356 <END> VL53L0X_PollingDelay 0

module: 2, level: 5, function: 2147483647
3359 <START> VL53L0X_GetMeasurementDataReady

module: 1, level: 5, function: 2147483647
3360 <START> VL53L0X_GetInterruptMaskStatus

module: 1, level: 5, function: 2147483647
3364 <END> VL53L0X_GetInterruptMaskStatus 0

module: 1, level: 5, function: 2147483647
3365 <END> VL53L0X_GetMeasurementDataReady 0

module: 1, level: 5, function: 2147483647
3367 <START> VL53L0X_PollingDelay

module: 2, level: 5, function: 2147483647
3374 <END> VL53L0X_PollingDelay 0

module: 2, level: 5, function: 2147483647
3377 <START> VL53L0X_GetMeasurementDataReady

module: 1, level: 5, function: 2147483647
3378 <START> VL53L0X_GetInterruptMaskStatus

module: 1, level: 5, function: 2147483647
3382 <END> VL53L0X_GetInterruptMaskStatus -6

module: 1, level: 5, function: 2147483647
3383 <END> VL53L0X_GetMeasurementDataReady -6

module: 1, level: 5, function: 2147483647
3386 <END> VL53L0X_measurement_poll_for_completion -6

module: 1, level: 5, function: 2147483647
3387 <END> VL53L0X_PerformRefCalibration -6

module: 1, level: 5, function: 2147483647
Distance (mm): 0
Reading a measurement... Call of VL53L0X_StaticInit
5390 <START> VL53L0X_StaticInit

module: 1, level: 5, function: 2147483647
5391 <START> VL53L0X_get_info_from_device

module: 1, level: 5, function: 2147483647
5394 <START> VL53L0X_PollingDelay

module: 2, level: 5, function: 2147483647
5394 <END> VL53L0X_PollingDelay 0

module: 2, level: 5, function: 2147483647
5398 <END> VL53L0X_get_info_from_device 0

module: 1, level: 5, function: 2147483647
5401 <START> VL53L0X_load_tuning_settings

module: 1, level: 5, function: 2147483647
5425 <END> VL53L0X_load_tuning_settings 0

module: 1, level: 5, function: 2147483647
5425 <START> VL53L0X_SetGpioConfig

module: 1, level: 5, function: 2147483647
5427 <START> VL53L0X_ClearInterruptMask

module: 1, level: 5, function: 2147483647
5428 <END> VL53L0X_ClearInterruptMask 0

module: 1, level: 5, function: 2147483647
5429 <END> VL53L0X_SetGpioConfig 0

module: 1, level: 5, function: 2147483647
5430 <START> VL53L0X_GetDeviceParameters

module: 1, level: 5, function: 2147483647
5431 <START> VL53L0X_GetDeviceMode

module: 1, level: 5, function: 2147483647
5431 <END> VL53L0X_GetDeviceMode 0

module: 1, level: 5, function: 2147483647
5431 <START> VL53L0X_GetInterMeasurementPeriodMilliSeconds

module: 1, level: 5, function: 2147483647
5433 <END> VL53L0X_GetInterMeasurementPeriodMilliSeconds 0

module: 1, level: 5, function: 2147483647
5433 <START> VL53L0X_GetXTalkCompensationRateMegaCps

module: 1, level: 5, function: 2147483647
5435 <END> VL53L0X_GetXTalkCompensationRateMegaCps 0

module: 1, level: 5, function: 2147483647
5435 <START> VL53L0X_GetOffsetCalibrationDataMicroMeter

module: 1, level: 5, function: 2147483647
5436 <END> VL53L0X_GetOffsetCalibrationDataMicroMeter 0

module: 1, level: 5, function: 2147483647
5436 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
5437 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
5437 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
5438 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
5438 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
5439 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
5440 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
5440 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
5440 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
5441 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
5441 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
5442 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
5442 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
5443 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
5443 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
5443 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
5444 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
5445 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
5445 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
5446 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
5446 <START> VL53L0X_GetLimitCheckValue

module: 1, level: 5, function: 2147483647
5447 <END> VL53L0X_GetLimitCheckValue 0

module: 1, level: 5, function: 2147483647
5448 <START> VL53L0X_GetLimitCheckEnable

module: 1, level: 5, function: 2147483647
5448 <END> VL53L0X_GetLimitCheckEnable 0

module: 1, level: 5, function: 2147483647
5448 <START> VL53L0X_GetWrapAroundCheckEnable

module: 1, level: 5, function: 2147483647
5449 <END> VL53L0X_GetWrapAroundCheckEnable 0

module: 1, level: 5, function: 2147483647
5450 <START> VL53L0X_GetMeasurementTimingBudgetMicroSeconds

module: 1, level: 5, function: 2147483647
5450 <START> VL53L0X_get_measurement_timing_budget_micro_seconds

module: 1, level: 5, function: 2147483647
5451 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
5452 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5452 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5453 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5453 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5454 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5454 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5455 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5455 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5455 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5456 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5456 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
5457 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5458 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5459 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
5459 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
5459 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5460 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5461 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5462 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5463 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
5463 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
5463 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
5464 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5465 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5465 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5466 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5466 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5467 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5467 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5468 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5468 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5469 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5469 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
5470 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5471 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5472 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5473 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5474 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
5474 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
5474 <END> VL53L0X_get_measurement_timing_budget_micro_seconds 0

module: 1, level: 5, function: 2147483647
5475 <END> VL53L0X_GetMeasurementTimingBudgetMicroSeconds 0

module: 1, level: 5, function: 2147483647
5476 <END> VL53L0X_GetDeviceParameters 0

module: 1, level: 5, function: 2147483647
5476 <START> VL53L0X_GetFractionEnable

module: 1, level: 5, function: 2147483647
5477 <END> VL53L0X_GetFractionEnable 0

module: 1, level: 5, function: 2147483647
5478 <START> VL53L0X_SetSequenceStepEnable

module: 1, level: 5, function: 2147483647
5479 <START> VL53L0X_SetMeasurementTimingBudgetMicroSeconds

module: 1, level: 5, function: 2147483647
5479 <START> VL53L0X_set_measurement_timing_budget_micro_seconds

module: 1, level: 5, function: 2147483647
5480 <END> VL53L0X_SetMeasurementTimingBudgetMicroSeconds -4

module: 1, level: 5, function: 2147483647
5481 <END> VL53L0X_SetSequenceStepEnable 0

module: 1, level: 5, function: 2147483647
5481 <START> VL53L0X_SetSequenceStepEnable

module: 1, level: 5, function: 2147483647
5482 <END> VL53L0X_SetSequenceStepEnable 0

module: 1, level: 5, function: 2147483647
5482 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5483 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5484 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5485 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5485 <START> VL53L0X_GetSequenceStepTimeout

module: 1, level: 5, function: 2147483647
5485 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5486 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5487 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5488 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5489 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
5489 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
5489 <END> VL53L0X_GetSequenceStepTimeout 0

module: 1, level: 5, function: 2147483647
5490 <START> VL53L0X_GetSequenceStepTimeout

module: 1, level: 5, function: 2147483647
5490 <START> VL53L0X_GetSequenceStepEnables

module: 1, level: 5, function: 2147483647
5491 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5492 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5492 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5493 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5493 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5494 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5494 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5495 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5495 <START> sequence_step_enabled

module: 1, level: 5, function: 2147483647
5496 <END> sequence_step_enabled 0

module: 1, level: 5, function: 2147483647
5496 <END> VL53L0X_GetSequenceStepEnables 0

module: 1, level: 5, function: 2147483647
5497 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5498 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5499 <START> VL53L0X_GetVcselPulsePeriod

module: 1, level: 5, function: 2147483647
5500 <END> VL53L0X_GetVcselPulsePeriod 0

module: 1, level: 5, function: 2147483647
5501 <START> VL53L0X_calc_macro_period_ps

module: 1, level: 5, function: 2147483647
5501 <END> VL53L0X_calc_macro_period_ps 134899725

module: 1, level: 5, function: 2147483647
5501 <END> VL53L0X_GetSequenceStepTimeout 0

module: 1, level: 5, function: 2147483647
5502 <END> VL53L0X_StaticInit 0

module: 1, level: 5, function: 2147483647
Call of VL53L0X_PerformRefCalibration
5503 <START> VL53L0X_PerformRefCalibration

module: 1, level: 5, function: 2147483647
5504 <START> VL53L0X_measurement_poll_for_completion

module: 1, level: 5, function: 2147483647
5504 <START> VL53L0X_GetMeasurementDataReady

module: 1, level: 5, function: 2147483647
5505 <START> VL53L0X_GetInterruptMaskStatus

module: 1, level: 5, function: 2147483647
5506 <END> VL53L0X_GetInterruptMaskStatus -6

module: 1, level: 5, function: 2147483647
5506 <END> VL53L0X_GetMeasurementDataReady -6

module: 1, level: 5, function: 2147483647
5507 <END> VL53L0X_measurement_poll_for_completion -6

module: 1, level: 5, function: 2147483647
5508 <END> VL53L0X_PerformRefCalibration -6

module: 1, level: 5, function: 2147483647
Distance (mm): 0

  */
