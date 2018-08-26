int led_pin = 7;    // Initializing the LED pin
int pot_pin = A0;   // Initializing the Potentiometer pin
int pot_output;     // Declaring a variable for potentiometer output

void setup ( ) {

  pinMode(led_pin, OUTPUT); // Declaring the LED pin as output pin
  Serial.begin(9600);       // Starting the serial communication at 9600 baud rate

}

void loop ( ) {

  pot_output = analogRead (pot_pin); // Reading from the potentiometer
  int mapped_output = map (pot_output, 0, 1023, 0, 255); // Mapping the output of potentiometer to 0-255 to be read by the Processing IDE
  Serial.println (mapped_output);     // Sending the output to Processing IDE

  if (Serial.available ( ) > 0) {   // Checking if the Processing IDE has send a value or not
    char state = Serial.read ( );    // Reading the data received and saving in the state variable
    if (state == '1')            // If received data is '1', then turn on LED
    {
      digitalWrite (led_pin, HIGH);
    }

    if (state == '0') {     // If received data is '0', then turn off led
      digitalWrite (led_pin, LOW);
    }

  }

  delay(50);

}
