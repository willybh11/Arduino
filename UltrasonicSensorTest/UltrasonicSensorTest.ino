/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    UltrasonicSensorTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/01
 * @brief   Description: this file is sample code for Me ultrasonic sensor module.
 *
 * Function List:
 * 1. double MeUltrasonicSensor::distanceCm(uint16_t MAXcm)
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2015/09/01    1.0.0          rebuild the old lib
 * </pre>
 */
#include "MeOrion.h"

MeUltrasonicSensor ultraSensor(PORT_6); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */
Me7SegmentDisplay disp(PORT_3);

void setup()
{
  //Serial.begin(9600);
  disp.init();
  disp.set(2);
}

void loop()
{
  disp.display(ultraSensor.distanceCm() );
  delay(200);
}

