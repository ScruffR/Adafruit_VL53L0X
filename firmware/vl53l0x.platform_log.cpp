#include "vl53l0x_platform_log.h"
#include <stdarg.h>

#if defined(PARTICLE)
#  include "Particle.h"
#endif

int32_t VL53L0X_trace_config(char *filename, uint32_t modules, uint32_t level, uint32_t functions)
{
  return -1;
}

void trace_print_module_function(uint32_t module, uint32_t level, uint32_t function, const char *format, ...)
{
  char msg[256];
  va_list args;
  va_start(args, format);
  vsprintf(msg, format, args);
  va_end(args);

  Serial.printlnf("%s  module: %u, level: %u, function: %08x", msg, module, level, function);
}
