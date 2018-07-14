
#include "MeOrion.h"

MeUltrasonicSensor ultraSensor(PORT_6); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */
Me7SegmentDisplay disp(PORT_3);

void setup()
{
  disp.init();
  disp.set(2);
}

void loop()
{
  disp.display(ultraSensor.distanceCm() );
  delay(200);
}

