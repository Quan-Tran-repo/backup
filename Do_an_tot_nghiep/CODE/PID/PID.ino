#include <PID_v1.h>
#include <Encoder.h>

// Define motor pins
int motorPin1 = 45;
int motorPin2 = 44;
int enablePin = 7;

// Define encoder pins
Encoder encoder(21, 53);  // A channel on pin 2, B channel on pin 3

// Define PID constants
double Kp = 0.08;
double Ki = 0;
double Kd = 0;

// Define PID variables
double setpoint = 5000;
double input = 0;
double output = 0;
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  // Set motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Set PWM frequency for the enable pin
  TCCR2B = (TCCR2B & 0b11111000) | 0x02;

  // Set up PID controller
  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-255, 255);
  Serial.begin(9600);
}

void loop() {
  // Read encoder position and convert to degrees
  input = (double)encoder.read() * 360.0 / 1024.0;
  // Compute PID output
  double input_t=0;
  double error;
  error=setpoint-input;
  pid.Compute();

  // Set motor direction based on PID output
  if (output > 0) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } else if (output < 0) {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  } else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  if(input!=input_t)
    {
      Serial.println(input);
      input_t=input;
    }
  // Set motor speed using PWM on enable pin
/* // Dong co 2
  if (abs(output)>40) analogWrite(enablePin, abs(output));
  else if ((abs(error)> 5) || (abs(output)>1)) analogWrite(enablePin, 40);
  else analogWrite(enablePin,0);

// Dong co 1
  if (abs(output)>45) analogWrite(enablePin, abs(output));
  else if ((abs(error)> 5) || (abs(output)>1)) analogWrite(enablePin, 45);
  else analogWrite(enablePin,0);
*/  
// Dong co 3
  if (abs(output)>45) analogWrite(enablePin, abs(output));
  else if ((abs(error)> 5) || (abs(output)>1)) analogWrite(enablePin, 45);
  else analogWrite(enablePin,0);
  //analogWrite(enablePin,45);
}
