#include <PID_v1.h>
#include <Encoder.h>

#define PWM_PIN 7
#define DIR_PIN_1 45
#define DIR_PIN_2 44
#define ENCODER_PIN_A 21
#define ENCODER_PIN_B 53

Encoder myEncoder(ENCODER_PIN_A, ENCODER_PIN_B);

volatile long count = 0;
volatile long lastCount = 0;
unsigned long lastTime = 0;

double Setpoint = 90;
double Input = 0.0;
double Output = 0.0;

double Kp =  2.0626481;
double Ki =  10.313734;
double Kd = 0.0345;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIR_PIN_1, OUTPUT);
  pinMode(DIR_PIN_2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), updateEncoder, RISING);

  // Initialize the PID controller
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);


  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  if (now - lastTime >= 10) { // update every 10ms
    noInterrupts(); // disable interrupts while reading count
    long countDiff = count - lastCount;
    Input = (countDiff / ((now - lastTime) / 1000.0)) * 60 / 616; // convert to RPM
    lastCount = count;
    lastTime = now;
    interrupts(); // re-enable interrupts

    myPID.Compute();
    if (abs(Output) > 38){ 
      analogWrite(PWM_PIN, abs(Output));
    }
    else analogWrite(PWM_PIN, 38);
    if (Output < 0) {
      digitalWrite(DIR_PIN_1, HIGH);
      digitalWrite(DIR_PIN_2, LOW);
    } else if (Output > 0) {
      digitalWrite(DIR_PIN_1, LOW);
      digitalWrite(DIR_PIN_2, HIGH);
    } else {
      digitalWrite(DIR_PIN_1, LOW);
      digitalWrite(DIR_PIN_2, LOW);
    }

  // Print data to serial plotter
  Serial.print(Input);
  Serial.print(",");
  Serial.println(Output);
  }
}

void updateEncoder() {
  if (digitalRead(ENCODER_PIN_A) == HIGH) {
    if (digitalRead(ENCODER_PIN_B) == LOW) {
      count++;
    } else {
      count--;
    }
  } else {
    if (digitalRead(ENCODER_PIN_B) == LOW) {
      count--;
    } else {
      count++;
    }
  }
}
