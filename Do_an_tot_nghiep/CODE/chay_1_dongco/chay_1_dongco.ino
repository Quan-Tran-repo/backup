#define ENA 50



#define IN1 49 // PL0
#define IN2 48 // PL1


#define E1 18
#define E2 22

int vitri_en1,vitri_en1t;

void tam1(){
  if (digitalRead(E2)==1) {vitri_en1++;}
  else {vitri_en1--;}
}

void setup() {
  // put your setup code here, to run once:
  DDRL =  0x00;
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);

  pinMode(VCC,OUTPUT);

  digitalWrite(ENA,HIGH);

  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);

  attachInterrupt(5,tam1,RISING); // PIN 20 - ENCODER m1
  Serial.begin(115200);
} 

void loop() {
  // put your main code here, to run repeatedly:
  PORTL=0x05;
  if(vitri_en1!=vitri_en1t)
    {Serial.println(vitri_en1);vitri_en1t=vitri_en1;}
  Serial.println(digitalRead(0));Serial.println(digitalRead(1));
}
