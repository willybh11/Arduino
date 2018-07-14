const byte pulsePin = 2;
const unsigned long resistance = 10000;

volatile boolean triggered;
volatile boolean active;
volatile unsigned long startTime;
volatile unsigned long duration;

ISR (ANALOG_COMP_vect)
  {
  unsigned long now = micros ();
  if (active)
    {
    duration = now - startTime;
    triggered = true;
    digitalWrite (pulsePin, LOW); 
    }
  }

void setup ()
  {
  pinMode(pulsePin, OUTPUT);
  digitalWrite(pulsePin, LOW);
  Serial.begin(9600);
  ADCSRB = 0;          
  ACSR =  _BV (ACI)     
        | _BV (ACIE)    
        | _BV (ACIS0) | _BV (ACIS1);  
   }  

void loop ()
  {
  if (!active)
    {
    active = true;
    triggered = false;
    digitalWrite (pulsePin, HIGH); 
    startTime = micros ();  
    }

  if (active && triggered)
    {
    active = false;
    Serial.print (duration / resistance);
    Serial.println (" uF");
    triggered = false;
    delay (1000);
    }
} 
