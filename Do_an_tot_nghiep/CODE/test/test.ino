#include <PID_v1.h>
#include <Encoder.h>

//---------- L298_1-----------------------------------------------
#define IN1 49 // PL0 // dong co 1
#define IN2 48 // PL1
#define IN3 47 // PL2 // dong co 2
#define IN4 46 // PL3
// Enable L298
#define ENA1 8
#define ENB1 5
//---------- L298_2-------------------------------------------------
#define IN5 45 // PL4 // dong co 4
#define IN6 44 // PL5
#define IN7 43 // PL6 // dong co 3
#define IN8 42 // PL7
// Enable L298
#define ENA2 6
#define ENB2 7
//--------------------------------------------------------------------
// Interrupt pins encoder
#define E1 18 // CH1
#define E2 50 

#define E3 19 // CH1
#define E4 51 

#define E5 20 // CH1
#define E6 52

#define E7 21 //CH1
#define E8 53

#define E9 2 //CH1 int.0
#define E10 24

#define E11 3 //CH1 int.1
#define E12 25
// Define encoder pins
Encoder encoder1(E1, E2);  // A channel on pin 2, B channel on pin 3
Encoder encoder2(E3, E4);  // A channel on pin 2, B channel on pin 3
Encoder encoder3(E5, E6);  // A channel on pin 2, B channel on pin 3
Encoder encoder4(E7, E8);  // A channel on pin 2, B channel on pin 3

//Define setpoint and angle
int setpoint=12000;
int angle=0;
//PID for motor1
double Kp1 = 0.08;
double Ki1 = 0;
double Kd1 = 0;
//PID for motor2
double Kp2 = 0.08;
double Ki2 = 0;
double Kd2 = 0;
//PID for motor3
double Kp3 = 0.08;
double Ki3 = 0;
double Kd3 = 0;
//PID for motor4
double Kp4 = 0.08;
double Ki4 = 0;
double Kd4 = 0;
//Define output for 4 motors
double output1,output2,output3,output4;
double error1,error2,error3,error4;
//-------------------------------------------------------------------
double s1,s2,s3,s4;
double input1=0,input2=0,input3=0,input4=0;
double input1t=0,input2t=0,input3t=0,input4t=0;
// Define PID for 4 motors
PID pid1(&input1, &output1, &s1, Kp1, Ki1, Kd1, DIRECT);
PID pid2(&input2, &output2, &s2, Kp2, Ki2, Kd2, DIRECT);
PID pid3(&input3, &output3, &s3, Kp3, Ki3, Kd3, DIRECT);
PID pid4(&input4, &output4, &s4, Kp4, Ki4, Kd4, DIRECT);

//----------------------FUNCTION--------------------------------------
//-------Function calculate pulse with input is Distance---------------
void tinhtoan_quangduong(int s, float degree)//degree integer number pls
{
  float x= degree/180*3.14;
  s1 = s * cos(3.14/4+x);
  s2 = s * sin(3.14/4+x)*(-1);
  s3 = s * cos(3.14/4+x)*(-1);
  s4 = s * sin(3.14/4+x);
}
//--------------------FORWARD-----------------------------------------
void dir()
{
  //Motor1
    if (output1>0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    }
    else  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2, HIGH);
    }
  //Motor2
    if (output2>0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    }
    else  {
    digitalWrite(IN3,LOW);
    digitalWrite(IN4, HIGH);
    }
  //Motor3
    if (output3>0) {
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
    }
    else  {
    digitalWrite(IN7,LOW);
    digitalWrite(IN8, HIGH);
    }
  //Motor4
    if (output4>0) {
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    }
    else  {
    digitalWrite(IN5,LOW);
    digitalWrite(IN6, HIGH);
    }
    
}
void di(int s, int deg)
{
  //Calculate the setpoint 
  tinhtoan_quangduong(s,deg);

  //Direction for 4 motor
  dir();

  //Calculate input and output for motor 1 to 4
  pid1.Compute();
  pid2.Compute();
  pid3.Compute();
  pid4.Compute();

  //Calculate error for motor 1 to 4
  error1=s1-input1;
  error2=s2-input2;
  error3=s3-input3;
  error4=s4-input4;

  //Run motor

  //Motor1  
  if (abs(output1)>50) analogWrite(ENA1, abs(output1));
  else if ((abs(error1)> 5) || (abs(output1)>1)) analogWrite(ENA1, 50);
  else analogWrite(ENA1,0); 

  //Motor2
  if (abs(output2)>40) analogWrite(ENB1, abs(output2));
  else if ((abs(error2)> 5) || (abs(output2)>1)) analogWrite(ENB1, 40);
  else analogWrite(ENB1,0); 

  //Motor3
  if (abs(output3)>40) analogWrite(ENA2, abs(output3));
  else if ((abs(error3)> 5) || (abs(output3)>1)) analogWrite(ENA2, 40);
  else analogWrite(ENA2,0);  

  //Motor4
  if (abs(output4)>40) analogWrite(ENA1, abs(output4));
  else if ((abs(error4)> 5) || (abs(output4)>1)) analogWrite(ENB2, 40);
  else analogWrite(ENB2,0);   
}  

void dithang(){

    analogWrite(ENA1, 255);

    analogWrite(ENB1, 195);

    analogWrite(ENA2, 250);
    
    analogWrite(ENB2, 195);
}

//--------------------------------------------------------------------
void setup() {
  // Set port is input or output | 0: input && 1: output
  DDRL =  0xff;

  // Set PWM frequency for the enable pin
  TCCR2B = (TCCR2B & 0b11111000) | 0x02;

  // Set output limit
  pid1.SetOutputLimits(-255, 255);
  pid2.SetOutputLimits(-250, 250);
  pid3.SetOutputLimits(-255, 255);
  pid4.SetOutputLimits(-250, 250);

  // Enable L298N
  digitalWrite(ENA1,HIGH);
  digitalWrite(ENB1,HIGH);
  digitalWrite(ENA2,HIGH);
  digitalWrite(ENB2,HIGH);

  Serial.begin(9600);

  //Set mode for PID
  pid1.SetMode(AUTOMATIC);
  pid2.SetMode(AUTOMATIC);
  pid3.SetMode(AUTOMATIC);
  pid4.SetMode(AUTOMATIC);
  //test 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //analogWrite(ENA1, 255);


  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //analogWrite(ENA1, 200);

  digitalWrite(IN7,HIGH);
  digitalWrite(IN8, LOW);
  //analogWrite(ENA1, 255);
    
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  //analogWrite(ENA1, 200);
}

void loop() {
  if((input1!=input1t) || (input2!=input2t) || (input3!=input3t) || (input4!=input4t))
  {
    Serial.print("V1=");Serial.print(input1);Serial.print(", V2=");Serial.print(input2);Serial.print(", V3=");Serial.print(input3);Serial.print(", V4=");Serial.println(input4);
    input1t=input1;
    input2t=input2;
    input3t=input3;
    input4t=input4;
  }

  // Read encoder position and convert to degrees
  input1 = (double)encoder1.read();
  input2 = (double)encoder2.read();
  input3 = (double)encoder3.read();
  input4 = (double)encoder4.read();

  //di(setpoint,0);
  dithang();
}