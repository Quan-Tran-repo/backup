#include <util/atomic.h>
// Pin1
#define ENCA1 18
#define ENCB1 50
#define PWM1  8
#define IN1   49
#define IN2   48
// Pin2
#define ENCA2 19
#define ENCB2 51
#define PWM2  5
#define IN3   47
#define IN4   46
// Pin3
#define ENCA3 20
#define ENCB3 52
#define PWM3  6
#define IN5   43
#define IN6   42
// Pin4
#define ENCA4 21
#define ENCB4 53
#define PWM4  7
#define IN7   45
#define IN8   44

// globals
long prevT1 = 0;
int posPrev1 = 0;
float preve1;
long prevT2 = 0;
int posPrev2 = 0;
float preve2;
long prevT3 = 0;
int posPrev3 = 0;
float preve3;
long prevT4 = 0;
int posPrev4 = 0;
float preve4;

// Set a target
float vt1;
float vt2;
float vt3;
float vt4;
float v;

// Use the "volatile" directive for variables
// used in an interrupt
volatile int pos_i1 = 0;
volatile float velocity_i1 = 0;
volatile long prevT_i1 = 0;

volatile int pos_i2 = 0;
volatile float velocity_i2 = 0;
volatile long prevT_i2 = 0;

volatile int pos_i3 = 0;
volatile float velocity_i3 = 0;
volatile long prevT_i3 = 0;

volatile int pos_i4 = 0;
volatile float velocity_i4 = 0;
volatile long prevT_i4 = 0;

float vFilt = 0;
float vPrev = 0;
float vFiltPrev = 0;

float v1Filt = 0;
float v1Prev = 0;

float v2Filt = 0;
float v2Prev = 0;

float v3Filt = 0;
float v3Prev = 0;

float v4Filt = 0;
float v4Prev = 0;

float e=0;
float eintegral = 0;
float eintegral1 = 0;
float derivative1;
float eintegral2 = 0;
float derivative2;
float eintegral3 = 0;
float derivative3;
float eintegral4 = 0;
float derivative4;
int  pos1,pos2,pos3,pos4;
float distance,speed,deltad;

void setup() {
  Serial.begin(9600);
  pinMode(ENCA1,INPUT);
  pinMode(ENCB1,INPUT);

  pinMode(ENCA2,INPUT);
  pinMode(ENCB2,INPUT);

  pinMode(ENCA3,INPUT);
  pinMode(ENCB3,INPUT);

  pinMode(ENCA4,INPUT);
  pinMode(ENCB4,INPUT);  
  
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(PWM3,OUTPUT);
  pinMode(PWM4,OUTPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(IN5,OUTPUT);
  pinMode(IN6,OUTPUT);
  pinMode(IN7,OUTPUT);
  pinMode(IN8,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA1), readEncoder1,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA2), readEncoder2,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA3), readEncoder3,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA4), readEncoder4,RISING);

  delay(5000);
}

void loop() {
  // read the position in an atomic block
  // to avoid potential misreads
  pos1 = 0;
  pos2 = 0;
  pos3 = 0;
  pos4 = 0;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
    pos1 = pos_i1;
    pos2 = pos_i2;
    pos3 = pos_i3;
    pos4 = pos_i4;
    }
  // Compute velocity with method 1
  long currT1 = micros();
  long currT2 = micros();
  long currT3 = micros();
  long currT4 = micros();
  
  float deltaT1 = ((float) (currT1-prevT1))/1.0e6; //1e6=10^6
  float deltaT2 = ((float) (currT2-prevT2))/1.0e6;
  float deltaT3 = ((float) (currT3-prevT3))/1.0e6;
  float deltaT4 = ((float) (currT4-prevT4))/1.0e6;
  //Serial.print (deltaT1);Serial.print(deltaT2);Serial.println(deltaT3);
  float velocity1 = (pos1 - posPrev1)/deltaT1;
  float velocity2 = (pos2 - posPrev2)/deltaT2;
  float velocity3 = (pos3 - posPrev3)/deltaT3;
  float velocity4 = (pos4 - posPrev4)/deltaT4;
  //Serial.print(velocity1);Serial.println(velocity3);
  posPrev1 = pos1;
  posPrev2 = pos2;
  posPrev3 = pos3;
  posPrev4 = pos4;
  
  prevT1 = currT1;
  prevT2 = currT2;
  prevT3 = currT3;
  prevT4 = currT4;

  // Convert count/s to RPM
  float v1 = velocity1/616.0*60;
  float v2 = velocity2/616.0*60;
  float v3 = velocity3/616.0*60;
  float v4 = velocity4/616.0*60;

  // Low-pass filter (25 Hz cutoff)
  v1Filt = 0.854*v1Filt + 0.0728*v1 + 0.0728*v1Prev;
  v1Prev = v1;
  v2Filt = 0.854*v2Filt + 0.0728*v2 + 0.0728*v2Prev;
  v2Prev = v2;
  v3Filt = 0.854*v3Filt + 0.0728*v3 + 0.0728*v3Prev;
  v3Prev = v3;
  v4Filt = 0.854*v4Filt + 0.0728*v4 + 0.0728*v4Prev;
  v4Prev = v4;

  // Compute the control signal u
  float kp1 = 2.4064;
  float ki1 = 9.6228;
  float kd1 = 0.6038;  

  float kp2 = 2.1543;
  float ki2 = 8.5818;
  float kd2 = 0.5382;

  float kp3 = 2.0626481;
  float ki3 = 10.313734;
  float kd3 = 0.3666;

  float kp4 = 2.0626481;
  float ki4 = 10.313734;
  float kd4 = 0.3666;

  float e1 = vt1 - v1Filt;
  float e2 = vt2 - v2Filt;
  float e3 = vt3 - v3Filt;
  float e4 = vt4 - v4Filt;

  // Compute the integral term
  eintegral1 = eintegral1 + e1 * deltaT1;
  eintegral2 = eintegral2 + e2 * deltaT2;
  eintegral3 = eintegral3 + e3 * deltaT3;
  eintegral4 = eintegral4 + e4 * deltaT4;
  
  // Compute the derivative term
  derivative1 = (e1 - preve1) / deltaT1;
  derivative2 = (e2 - preve2) / deltaT2;
  derivative3 = (e3 - preve3) / deltaT3;
  derivative4 = (e4 - preve4) / deltaT4;

  float u1 = kp1 * e1 + ki1 * eintegral1 + kd1 * derivative1;  // updated control signal
  float u2 = kp2 * e2 + ki2 * eintegral2 + kd2 * derivative2;  // updated control signal
  float u3 = kp3 * e3 + ki3 * eintegral3 + kd3 * derivative3;  // updated control signal
  float u4 = kp4 * e4 + ki4 * eintegral4 + kd4 * derivative4;  // updated control signal
  preve1 = e1;
  preve2 = e2;
  preve3 = e3;
  preve4 = e4;

  // Set the motor 1 speed and direction
  int dir1 = 1;
  if (u1 < 0) {
    dir1 = -1;
  }
  int pwr1 = (int) fabs(u1);
  if (pwr1 > 255) {
    pwr1 = 255;
  }
  // Set the motor 2 speed and direction
  int dir2 = 1;
  if (u2 < 0) {
    dir2 = -1;
  }
  int pwr2 = (int) fabs(u2);
  if (pwr2 > 255) {
    pwr2 = 255;
  }
  // Set the motor 3 speed and direction
  int dir3 = 1;
  if (u3 < 0) {
    dir3 = -1;
  }
  int pwr3 = (int) fabs(u3);
  if (pwr3 > 255) {
    pwr3 = 255;
  }
  // Set the motor 4 speed and direction
  int dir4 = 1;
  if (u4 < 0) {
    dir4 = -1;
  }
  int pwr4 = (int) fabs(u4);
  if (pwr4 > 255) {
    pwr4 = 255;
  }


  setMotor(dir1, pwr1, PWM1, IN1, IN2);
  setMotor(dir2, pwr2, PWM2, IN3, IN4);
  setMotor(dir3, pwr3, PWM3, IN5, IN6);
  setMotor(dir4, pwr4, PWM4, IN7, IN8);


































  //di vong quanh the gioi
  //go(700,0);
  // if (millis()<10000) speed=200;
  // else if (millis()<20000) speed=100;
  // else speed=50;
  go(1000,0);
  calculate_s(speed,v1,v2,v3,v4,deltaT1);
  // tinhtoan_quangduong_di(speed,0);
  //Print
  Serial.print(vt1);
  Serial.print(" ");
  Serial.print(v1Filt);
  Serial.print(" ");
  Serial.print(vt2);
  Serial.print(" ");
  Serial.print(v2Filt);
  Serial.print(" ");
  Serial.print(v3Filt);
  Serial.print(" ");
  Serial.print(v4Filt);
  Serial.print(" ");
  Serial.println(distance);
  delay(1);
}
void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal); // Motor speed
  if(dir == 1){ 
    // Turn one way
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    // Turn the other way
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    // Or dont turn
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);    
  }
}
void readEncoder1(){
  // Read encoder B when ENCA rises
  int b1 = digitalRead(ENCB1);
  int increment1 = 0;
  if(b1>0){
    // If B is high, increment forward
    increment1 = 1;
  }
  else{
    // Otherwise, increment backward
    increment1 = -1;
  }
  pos_i1 = pos_i1 + increment1;
}
void readEncoder2(){
  // Read encoder B when ENCA rises
  int b2 = digitalRead(ENCB2);
  int increment2 = 0;
  if(b2>0){
    // If B is high, increment forward
    increment2 = 1;
  }
  else{
    // Otherwise, increment backward
    increment2 = -1;
  }
  pos_i2 = pos_i2 + increment2;
}
void readEncoder3(){
  // Read encoder B when ENCA rises
  int b3 = digitalRead(ENCB3);
  int increment3 = 0;
  if(b3>0){
    // If B is high, increment forward
    increment3 = 1;
  }
  else{
    // Otherwise, increment backward
    increment3 = -1;
  }
  pos_i3 = pos_i3 + increment3;
}
void readEncoder4(){
  // Read encoder B when ENCA rises
  int b4 = digitalRead(ENCB4);
  int increment4 = 0;
  if(b4>0){
    // If B is high, increment forward
    increment4 = 1;
  }
  else{
    // Otherwise, increment backward
    increment4 = -1;
  }
  pos_i4 = pos_i4 + increment4;
}

void tinhtoan_quangduong_di(int v, float degree)//degree integer number pls
{
  float x= degree/180*3.14;
  vt1 = v * cos(3.14/4+x);
  vt2 = v * sin(3.14/4+x)*(-1);
  vt3 = v * cos(3.14/4+x)*(-1);
  vt4 = v * sin(3.14/4+x);
} 
void calculate_s(float s, float v1, float v2, float v3, float v4, float deltaT)
{
  // v(rpm)
  v=sqrt(pow((abs(v1)+abs(v3))/2,2)+pow((abs(v2)+abs(v4))/2,2));
  vFilt = 0.854*vFilt + 0.0728*v + 0.0728*vPrev;
  vPrev = v;
  // distance(count)
  distance = distance + (vFilt+vFiltPrev)/2 * deltaT;
  // if(deltad!=700-distance)
  // {Serial.print("Vfilt: ");Serial.print(vFilt);Serial.print("\t");Serial.print("V: ");Serial.print(v);Serial.print("\t");Serial.print("Distance: ");Serial.print(deltad); Serial.print("\t");Serial.print("speed: ");Serial.print(speed);
  // Serial.print("\tTotal distance: ");Serial.println(distance);}
  // vFiltPrev=vFilt;
}
void go(float d, float angle)
{
  tinhtoan_quangduong_di(speed,angle);
  deltad=d-distance;
  if (deltad>1200) {speed=200;}
  else if (deltad>800) {speed=150 + (deltad-800)*(200-150)/(1200-800);}
  else if (deltad>400) {speed=100 + (deltad-400)*(150-100)/(800-400);}
  else if (deltad>100) {speed=50  + (deltad-100)*(100-50)/(400-100);}
  else if (deltad>0)   {speed=0   + (deltad-0)  *(50-0)/(100-0);}
}

