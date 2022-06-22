#define red 13
#define orange 12
#define green 11

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(orange,OUTPUT);
  pinMode(green,OUTPUT);

  digitalWrite(red,0);
  digitalWrite(orange,0);
  digitalWrite(green,0);

}


//functions

void loop() {
  // put your main code here, to run repeatedly:
   redon();
   delay(2000);

   orangeon();   
   delay(2000);

   greenon();
   delay(2000);

}





void redon(){
   analogWrite(red,150);// red light on
   digitalWrite(orange,0);// orange light off
   digitalWrite(green,0);// green light off
}
void orangeon(){
   analogWrite(red,0);// red light off
   digitalWrite(orange,1);//orange light on
   digitalWrite(green,0);//green light off

}
void greenon(){
   analogWrite(red,0);// red light off
   digitalWrite(orange,0);//orange light off
   digitalWrite(green,1);//green light on

}
