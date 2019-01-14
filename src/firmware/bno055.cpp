/**
 * bno055.cpp
 **/

#include "bno055.h"

/**
 * Asks for the value saved in reg
 **/
static uint8_t read8(uint8_t addr, BNO055_reg reg) {
  uint8_t data=0x00;

  // Transmission of request
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  // Receive the data
  Wire.requestFrom(addr, sizeof(uint8_t));
  data=Wire.read();
  return data;  
}

static uint16_t read16(uint8_t addr, BNO055_reg reg) {
  uint16_t msb=0;
  uint16_t lsb=0;

  // Transmission of request
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  // Receive the data
  Wire.requestFrom(addr, sizeof(uint16_t));
  lsb=Wire.read();
  msb=Wire.read();
  return (lsb | msb<<8);
}

static BNO055_result readLen(uint8_t addr, BNO055_reg reg, uint8_t* buf, uint8_t len) {
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(addr, len);

  for(int i=0;i<len;++i) {
    buf[i]=Wire.read();
  }
  return SUCCESS;
}

static void write8(uint8_t addr, BNO055_reg reg, uint8_t data) {
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

static void _BNO055_setMode(uint8_t addr, BNO055_op op) {
  write8(addr, OPR_MODE, op);
  delay(MODE_SWITCH_DELAY);
}

static void _BNO055_setUnitTypes(BNO055* b) {
  uint8_t temp=0;
  temp |=
    (b->unit_acc<<ACCEL_UNIT) |    
    (b->unit_angr<<ANGULAR_RATE_UNIT) |
    (b->unit_eul<<EULER_ANGLES_UNIT) |
    (b->unit_temp<<TEMPERATURE_UNIT);
  write8(b->i2c_addr, UNIT_SEL, temp);
}

/**
 * Initializes I2C channel in clock stretching mode
 * then asks the dev for his ID saved in the CHIP_ID Register.
 * Fix everything on registers and stuff
 * finally enable the selected operating mode
 **/
BNO055_result BNO055_init(BNO055* b) {
  uint8_t temp=0x00;
  // Initializes I2C (through Wire library)
  // im lazy :/
  Wire.begin();

  if(read8(b->i2c_addr, CHIP_ID)!=BNO055_CHIP_ID)
    return UNKNOWN_DEVICE;

  // At this point connection between MCU and DEV is complete
  // time to initialize everything!
  
  // set units
  _BNO055_setUnitTypes(b);

  // TODO
  

  // set requested operation mode
  _BNO055_setMode(b->i2c_addr, b->op);
  return SUCCESS;
}

/**
 * Depending on the op selected, executes and 
 * gets data from the Device
 **/
void BNO055_handle(BNO055* b) {
  // TODO
  return;
}
