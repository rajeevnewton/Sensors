#define in1 5 //L298n Motor Driver pins.
#define in2 6
#define in3 11
#define in4 10

#define fledp 22 // led front.
#define fledn 23 // led front.

#define bledp 24 // led back.
#define bledn 25 // led back.

#define hornp 26 // horn.
#define hornn 27 // horn.

#define rvcc A1
#define recho A2
#define rtrig A3
#define rgnd A4

#define cvcc A8
#define cecho A9
#define ctrig A10
#define cgnd A11

#define lvcc A12
#define lecho A13
#define ltrig A14
#define lgnd A15

#define LED 13
char command; //Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.
void setup() {
    
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT); //Set the LED pin.

  pinMode(fledp, OUTPUT); //Front LED pin.
  pinMode(fledn, OUTPUT); //Front LED pin.
  digitalWrite(fledp,LOW);
  digitalWrite(fledn,LOW);

  pinMode(bledp, OUTPUT); //Back LED pin.
  pinMode(bledn, OUTPUT); //Back LED pin.
  digitalWrite(bledp,LOW);
  digitalWrite(bledn,LOW);


  pinMode(hornp, OUTPUT); //Horn pin.
  pinMode(hornn, OUTPUT); //Horn LED pin.  
  digitalWrite(hornp,LOW);
  digitalWrite(hornn,LOW);

  ///////////////////////////////////////
  pinMode(rvcc, OUTPUT);
  pinMode(recho, INPUT);
  pinMode(rtrig, OUTPUT);
  pinMode(rgnd, OUTPUT);  
  digitalWrite(rvcc,HIGH);
  digitalWrite(rgnd,LOW);
  ///////////////////////////////////////
  ///////////////////////////////////////
  pinMode(cvcc, OUTPUT);
  pinMode(cecho, INPUT);
  pinMode(ctrig, OUTPUT);
  pinMode(cgnd, OUTPUT);  
  digitalWrite(cvcc,HIGH);
  digitalWrite(cgnd,LOW);
  ///////////////////////////////////////
  ///////////////////////////////////////
  pinMode(lvcc, OUTPUT);
  pinMode(lecho, INPUT);
  pinMode(ltrig, OUTPUT);
  pinMode(lgnd, OUTPUT);  
  digitalWrite(lvcc,HIGH);
  digitalWrite(lgnd,LOW);
  ///////////////////////////////////////  
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() {
     ///////////////////////////////////////
    ///////////////////////////////////////
  digitalWrite(rtrig,LOW);
  delayMicroseconds(2);
  digitalWrite(rtrig,HIGH);
  delayMicroseconds(2);
  long rt = pulseIn(recho,HIGH);
  long rcm = rt / 29 / 2;
    //////////////////////////////////////
   ///////////////////////////////////////
  digitalWrite(ctrig,LOW);
  delayMicroseconds(2);
  digitalWrite(ctrig,HIGH);
  delayMicroseconds(2);
  long ct = pulseIn(cecho,HIGH);
  long ccm = ct / 29 / 2;
    ///////////////////////////////////////
    ///////////////////////////////////////
  digitalWrite(ltrig,LOW);
  delayMicroseconds(2);
  digitalWrite(ltrig,HIGH);
  delayMicroseconds(2);
  long lt = pulseIn(lecho,HIGH);
  long lcm = lt / 29 / 2;
    ///////////////////////////////////////
   ///////////////////////////////////////
    Serial.println();
    Serial.print(lcm);
    Serial.print("\t");
    Serial.print(ccm);
    Serial.print("\t");
    Serial.print(rcm);
    Serial.print("\t");   
    Serial.println(); 

  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    Stop(); //Initialize with motors stoped.
    switch (command) {
      case 'F':
      if(ccm<20){
      Stop();
      }
      else{ 
      forward();
      }    
        break;
        
      case 'B':
        back();
        break;
      case 'L':
      if(lcm<20){
      Stop();
      }
      else{
        left();
      }  
        break;
        
      case 'R':
      if(rcm<20){
      Stop();
      }
      else{
        right();
      }  
        break;
//////////////////////////////////////////////////////////////////////////
     //FRONT LED ON
      case 'W':
        fledon();
        break;

     //FRONT LED OFF
      case 'w':
        fledoff();
        break;
     //BACK LED ON
      case 'U':
        bledon();
        break;

     //BACK LED OFF
      case 'u':
        bledoff();
        break;
        
     //HORN ON
      case 'V':
        hornon();
        break;
     //HORN OFF
      case 'v':
        hornoff();
        break;
        
     //LINE FOLLOWER ON
      case 'X':
        lfon();
        break;
     //LINE FOLLOWER OFF
      case 'x':
        lfoff();
        break;
        
//////////////////////////////////////////////////////////////
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

void forward() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speed);
}

void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}

void left() {
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
}

void right() {
  analogWrite(in4, Speed);
  analogWrite(in1, Speed);
}
void forwardleft() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}
void forwardright() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}
void backright() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void backleft() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}
void brakeOff() {

}


///////////////////////////////////////LIGHTS FRONT
void fledon(){
  digitalWrite(fledp,HIGH);
  digitalWrite(fledn,LOW);
  Serial.println("FRONT LED ON");
}
void fledoff(){
  digitalWrite(fledp,LOW);
  digitalWrite(fledn,LOW);
  Serial.println("FRONT LED OFF");
}

///////////////////////////////////////LIGHTS BACK
void bledon(){
  digitalWrite(bledp,HIGH);
  digitalWrite(bledn,LOW);
  Serial.println("BACK LED ON");
}
void bledoff(){
  digitalWrite(bledp,LOW);
  digitalWrite(bledn,LOW);
  Serial.println("BACK LED OFF");
}
///////////////////////////////////////HORN
void hornon(){
  digitalWrite(hornp,HIGH);
  digitalWrite(hornn,LOW);
  Serial.println("HORN ON");
}
void hornoff(){
  digitalWrite(hornp,LOW);
  digitalWrite(hornn,LOW);
  Serial.println("HORN ON");
}
