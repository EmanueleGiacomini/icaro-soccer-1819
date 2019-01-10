/**
 * phoenix_globals.cpp
 **/

#include "phoenix_globals.h"

PhoenixJoint joints[NUM_JOINTS] = {
  {// Joint 0
  pin_dira : 8,
  pin_dirb : 9,
  pin_pwm : 5,
  direzione : 0,
  velocita : 0
  },
  {// Joint 1
  pin_dira : 10,
  pin_dirb : 11,
  pin_pwm : 6,
  direzione : 0,
  velocita : 0
  },
  {// Joint 2
  pin_dira : 12,
  pin_dirb : 13,
  pin_pwm : 7,
  direzione : 0,
  velocita : 0
  }
};


PhoenixDrive drive;

PhoenixLineSensor line_sensors[NUM_LINE_SENSORS] = {
  {// Sensore 0
  x : 0,
  y : 0,
  soglia : 0,
  misura : 0,
  misura_min : 0,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  adc_addr : 0,
  adc_idx : 0,
  pin_reading: 0
  },
  {// Sensore 1
  x : 0,
  y : 0,
  soglia : 0,
  misura : 0,
  misura_min : 0,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  adc_addr : 0,
  adc_idx : 0,
  pin_reading: 0
  },
  {// Sensore 2
  x : 0,
  y : 0,
  soglia : 0,
  misura : 0,
  misura_min : 0,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  adc_addr : 0,
  adc_idx : 0,
  pin_reading: 0
  },
  {// Sensore 3
  x : 0,
  y : 0,
  soglia : 0,
  misura : 0,
  misura_min : 0,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  adc_addr : 0,
  adc_idx : 0,
  pin_reading: 0
  },
  {// Sensore 4
  x : 0,
  y : 0,
  soglia : 0,
  misura : 0,
  misura_min : 0,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  adc_addr : 0,
  adc_idx : 0,
  pin_reading: 0
  }
};
PhoenixLineHandler line_handler;
