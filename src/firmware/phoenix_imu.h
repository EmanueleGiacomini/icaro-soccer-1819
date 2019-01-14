/**
 * phoenix_imu.h
 **/

#pragma once

#include <Arduino.h>
#include <Wire.h>


typedef struct {
  int16_t yaw;
}PhoenixImu;


uint8_t PhoenixImu_init(PhoenixImu* m);
void PhoenixImu_handle(PhoenixImu* m);
void PhoenixImu_setOffset(PhoenixImu* m);
