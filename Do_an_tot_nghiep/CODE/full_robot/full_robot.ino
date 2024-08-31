
//---------- L298_1-----------------------------------------------
#define IN1 49 // PL0 // dong co 1
#define IN2 48 // PL1
#define IN3 47 // PL2 // dong co 2
#define IN4 46 // PL3
// Enable L298
#define ENA1 4
#define ENB1 5
//---------- L298_2-------------------------------------------------
#define IN7 43 // PL6 // dong co 3
#define IN8 42 // PL7
#define IN5 45 // PL4 // dong co 4
#define IN6 44 // PL5
// Enable L298
#define ENA2 6
#define ENB2 7
//--------------------------------------------------------------------
// Interrupt pins encoder
#define E1 18 // Động cơ 1
#define E2 50 

#define E3 19 // Động cơ 2
#define E4 51 

#define E5 20 // Động cơ 3
#define E6 52

#define E7 21 //Động cơ 4
#define E8 53

#define E9 2 //CH1 int.0
#define E10 24

#define E11 3 //CH1 int.1
#define E12 25
//-------------------------------------------------------------------
int temp = 0;
int vitri_en1 = 0;
int vitri_en2 = 0;
int vitri_en3 = 0;
int vitri_en4 = 0;
int vitri_en5 = 0;
int vitri_en6 = 0;
float flag,quang_duong1,quang_duong2,quang_duong3,quang_duong4,quang_duong;
float xung;
float vt_now1=0,vt_now2=0,vt_now3=0,vt_now4=0,vt_now5=0,vt_now6=0;
float vt_now1t=0,vt_now2t=0,vt_now3t=0,vt_now4t=0,vt_now5t=0,vt_now6t=0;
//----------------------FUNCTION--------------------------------------
//-----------Function call when Interrupt------------------------------
void tam1(){
  if (digitalRead(E2)==1) {vitri_en1++;}
  else {vitri_en1--;}
}
void tam2(){
  if (digitalRead(E4)==1) {vitri_en2--;}
  else {vitri_en2++;}
}
void tam3(){
  if (digitalRead(E6)==1) {vitri_en3--;}
  else {vitri_en3++;}
}
void tam4(){
  if (digitalRead(E8)==1) {vitri_en4++;}
  else {vitri_en4--;}
}
void tam5(){
  if (digitalRead(E10)==1) {vitri_en5++;}
  else {vitri_en5--;}
}
void tam6(){
  if (digitalRead(E12)==1) {vitri_en6++;}
  else {vitri_en6--;}
}
//-------Function calculate pulse with input is Distance---------------
void tinhtoan_xung (int quang_duong){
  xung = quang_duong/ ((58*3.14)/616);
  vt_now1 = vitri_en1*((58*3.14)/616);
  vt_now2 = vitri_en2*((58*3.14)/616);
  vt_now3 = vitri_en3*((58*3.14)/616);
  vt_now4 = vitri_en4*((58*3.14)/616);
}
void tinhtoan_quangduong(int s, float degree)//degree integer number pls
{
  float x= degree/180*3.14;
  quang_duong1 = s * cos(3.14/4+x);
  quang_duong2 = s * sin(3.14/4+x);
  quang_duong3 = s * cos(3.14/4+x);
  quang_duong4 = s * sin(3.14/4+x);
}
//--------------------FORWARD-----------------------------------------
void di(int s, int deg){
  quang_duong=s;
  tinhtoan_xung(s);
  tinhtoan_quangduong(quang_duong,deg);
// GO   
  if ((quang_duong2<0)&&(vt_now2>quang_duong2)) {PORTL&=B11101011;PORTL|=B00101000;/*Serial.println("2");*/}//PORTL=B01010101=>PORTL=00001
  else if ((quang_duong2>0)&&(vt_now2<quang_duong2)) {PORTL&=B11010111;PORTL|=B00010100;/*Serial.println("3");*/}
  if ((quang_duong3<0)&&(vt_now3>quang_duong3)) {PORTL&=B10111110;PORTL|=B10000010;/*Serial.println("4");*/}
  else if ((quang_duong3>0)&&(vt_now3<quang_duong3)) {PORTL&=B01111101;PORTL|=B01000001;/*Serial.println("5");*/}
// STOP
  if (((quang_duong2<0)&&(vt_now2<quang_duong2))||((quang_duong2>0)&&(vt_now2>quang_duong2))) {PORTL&=B11000011;/*Serial.println("6");*/}
  if ((((quang_duong3<0)&&(vt_now3<quang_duong3)))||(((quang_duong3>0)&&(vt_now3>quang_duong3)))) {PORTL&=B0111100;/*Serial.println("7");*/}
}
//--------------------------------------------------------------------
void setup() {
DDRL =  0xff;

digitalWrite(ENA1,HIGH);
digitalWrite(ENB1,HIGH);
digitalWrite(ENA2,HIGH);
digitalWrite(ENB2,HIGH);
PORTL=0x55; // 00000000
attachInterrupt(5,tam1,RISING); // PIN 21 - ENCODER m1
attachInterrupt(4,tam2,RISING); // PIN 20 - ENCODER m2
attachInterrupt(3,tam3,RISING); // PIN 19 - ENCODER m1
attachInterrupt(2,tam4,RISING); // PIN 18 - ENCODER m2
Serial.begin(9600);
}

void loop() {
  if((vt_now1!=vt_now1t) || (vt_now2!=vt_now2t) || (vt_now3!=vt_now3t) || (vt_now4!=vt_now4t) || (vt_now5!=vt_now5t) || (vt_now6!=vt_now6t))
  {
    Serial.print("V1=");Serial.print(vt_now1);Serial.print(", V2=");Serial.print(vt_now2);Serial.print(", V3=");Serial.print(vt_now3);Serial.print(", V4=");Serial.print(vt_now4);Serial.print(",      V5=");Serial.print(vitri_en5);Serial.print(",      V6=");Serial.println(vitri_en6);
    vt_now1t=vt_now1;
    vt_now2t=vt_now2;
    vt_now3t=vt_now3;
    vt_now4t=vt_now4;
    vt_now5t=vt_now5;
    vt_now6t=vt_now6;
  }
  di(5000,21);
  //dithang(300); // 10101010 ---> 10010101 di thang
}