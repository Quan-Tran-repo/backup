#include<TimerOne.h>


// Motor 1 Encoder Signal
#define Motor1_A 2 // Chan ngat cua Motor 1 - 0
#define Motor1_B 4 // Chan dem xung cua Motor 1

// Motor 2 Encoder Signal
#define Motor2_A 3 // Chan ngat cua Motor 2 - 1
#define Motor2_B 5 // Chan dem xung cua Motor 2

// Motor 3 Encoder Signal
#define Motor3_A 21 // Chan ngat cua Motor 3 - 2
#define Motor3_B 20 // Chan dem xung cua Motor 3

#define EN1 8 // Chan bam xung cho Motor 1 - L298N(1)
#define EN2 9 // Chan bam xung cho Motor 2 - L298N(1)
#define EN3 10 // Chan bam xung cho Motor 3 - L298N(2)

// Dieu huong Motor1
#define IN1_1 30 // Chan IN1 cua L298N(1)
#define IN2_1 31 // cChan IN2 cua L298N(1)

// Dieu huong Motor2
#define IN1_2 32 // Chan IN3 cua L298N(1)
#define IN2_2 33 // Chan IN4 cua L298N(1)

// Dieu huong Motor3
#define IN1_3 34 // Chan IN1 cua L298N(2)
#define IN2_3 35 // Chan IN2 cua L298N(2)

double T;
volatile double xung_1 = 0;
volatile double xung_2 = 0;
volatile double xung_3 = 0;
volatile double E_1,E1_1,E2_1,E_2,E1_2,E2_2,E_3,E1_3,E2_3;
double alpha_1, beta_1, gamma_1, Kp_1, Kd_1, Ki_1;
double alpha_2, beta_2, gamma_2, Kp_2, Kd_2, Ki_2;
double alpha_3, beta_3, gamma_3, Kp_3, Kd_3, Ki_3;
double Output_1, LastOutput_1;
double Output_2, LastOutput_2;
double Output_3, LastOutput_3;
volatile double vitri_1 = 0;
volatile double vitri_2 = 0;
volatile double vitri_3 = 0;
double THE1,THE2,THE3;




void setup()
{
  THE1=40; THE2=20;THE3=20;
  E_1 = 0; E1_1 = 0; E2_1 = 0;
  E_2 = 0; E1_2 = 0; E2_2 = 0;
  E_3 = 0; E1_3 = 0; E2_3 = 0;
  Output_1 = 0; LastOutput_1 = 0;
  Output_2 = 0; LastOutput_2 = 0;
  Output_3 = 0; LastOutput_3 = 0;
  // Thong so PID
  T = 0.01; // Thoi gian lay mau
  Kp_1 = 100; Kd_1 =0; Ki_1 = 0.1;
  Kp_2 = 63; Kd_2 =2; Ki_2 = 0.12;
  Kp_3 = 50; Kd_3 =2; Ki_3 = 0;
  Serial.begin(9600);
  delay(2000);
  attachInterrupt(0, Demxung1, FALLING);
  attachInterrupt(1, Demxung2, FALLING);
  attachInterrupt(2, Demxung3, FALLING);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(PID); 
  
}

void Demxung1()
{
  if(digitalRead(Motor1_B) == LOW)
    xung_1--;
  else
    xung_1++;
  
}

void Demxung2()
{
  if(digitalRead(Motor2_B) == LOW)
    xung_2++;
  else
    xung_2--;
  
}

void Demxung3()
{
  if(digitalRead(Motor3_B) == LOW)
    xung_3--;
  else
    xung_3++;
  
}

void PID()
{
  vitri_1 = ((xung_1*360)/990);
  E_1 = THE1 - vitri_1;
  alpha_1 = 2*T*Kp_1 + Ki_1*T*T + 2*Kd_1;
  beta_1 = T*T*Ki_1 - 4*Kd_1 - 2*T*Kp_1;
  gamma_1 = 2*Kd_1;
  Output_1 = (alpha_1*E_1 + beta_1*E1_1 + gamma_1*E2_1 + 2*T*LastOutput_1)/(2*T);
  LastOutput_1 = Output_1;
  E2_1 = E1_1;
  E1_1 = E_1;
  ///
  vitri_2 = ((xung_2*360)/1237.5);
  E_2 = THE2 - vitri_2;
  alpha_2 = 2*T*Kp_2 + Ki_2*T*T + 2*Kd_2;
  beta_2 = T*T*Ki_2 - 4*Kd_2 - 2*T*Kp_2;
  gamma_2 = 2*Kd_2;
  Output_2 = (alpha_2*E_2 + beta_2*E1_2 + gamma_2*E2_2 + 2*T*LastOutput_2)/(2*T);
  LastOutput_2 = Output_2;
  E2_2 = E1_2;
  E1_2 = E_2;
  ///
  vitri_3 = ((xung_3*360)/990);
  E_3 = THE3 - vitri_3;
  alpha_3 = 2*T*Kp_3 + Ki_3*T*T + 2*Kd_3;
  beta_3 = T*T*Ki_3 - 4*Kd_3 - 2*T*Kp_3;
  gamma_3 = 2*Kd_3;
  Output_3 = (alpha_3*E_3 + beta_3*E1_3 + gamma_3*E2_3 + 2*T*LastOutput_3)/(2*T);
  LastOutput_3 = Output_3;
  E2_3 = E1_3;
  E1_3 = E_3; 
  /// 
  if(Output_1 > 255)
    Output_1 = 255;

  if(Output_1<-255)
    Output_1 = -255;

  if(Output_1>0)
  {
    analogWrite(EN1, Output_1);
    digitalWrite(IN1_1,LOW);
    digitalWrite(IN2_1,HIGH);
  }
  else if(Output_1 < 0)
  {
    analogWrite(EN1, abs(Output_1));
    digitalWrite(IN1_1, HIGH);
    digitalWrite(IN2_1, LOW);
  }
  else
  {
    analogWrite(EN1,0);
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1, LOW);
  }
  ////
  if(Output_2 > 230)
    Output_2 = 230;

  if(Output_2<-150)
    Output_2 = -150;

  if(Output_2>0)
  {
    analogWrite(EN2, Output_2);
    digitalWrite(IN1_2,HIGH);
    digitalWrite(IN2_2,LOW);
  }
  else if(Output_2 < 0)
  {
    analogWrite(EN2, abs(Output_2));
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2, HIGH);
  }
  else
  {
    analogWrite(EN2,0);
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2, LOW);
  }
  ///----------------------------------------------
 if(Output_3 > 150)
    Output_3 = 150;

  if(Output_3<-150)
    Output_3 = -150;

  if(Output_3>0)
  {
    analogWrite(EN3, Output_3);
    digitalWrite(IN1_3,HIGH);
    digitalWrite(IN2_3,LOW);
  }
  else if(Output_3 < 0)
  {
    analogWrite(EN3, abs(Output_3));
    digitalWrite(IN1_3, LOW);
    digitalWrite(IN2_3, HIGH);
  }
  else
  {
    analogWrite(EN3,0);
    digitalWrite(IN1_3, LOW);
    digitalWrite(IN2_3, LOW);
  }  
}


void loop()
{
  int i;
  for(i=0;i<10;i++)
    delay(10);
  Serial.println(vitri_3);
}




