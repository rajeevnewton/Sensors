#define LIGHT 11
#define FAN 12
int state = '0';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LIGHT,OUTPUT);
  pinMode(FAN,OUTPUT);
  
  digitalWrite(LIGHT,1);
  digitalWrite(FAN,1);
}

void loop() {

  if(Serial.available()>0){
  state = Serial.read();
  Serial.println(state);
  
    ////////////////////////////////
    if(state == 97){
      digitalWrite(LIGHT,0);
    }
    if(state == 98){
      digitalWrite(LIGHT,1);
    }
     
    if(state == 99){
      digitalWrite(FAN,0);
    }
    if(state == 100){
      digitalWrite(FAN,1);
    }
     ////////////////////////////////
  
  }

}
