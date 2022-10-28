const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
const int LEDPin[] = {6, 7, 8, 9};
const int ENA = 10;
const int ENB = 11;
const int SW = 12;
const int joystickAnalog[] = {A0, A1};
const int IRPin[] = {A2, A3, A4, A5};
int joystickAnalogValue[] = {0, 0};
int i;
int IR_SensorValue[] = {0,0,0,0};
unsigned long previousMillis = 0;
const long interval = 300;
const int F = 255, H = 125, Z = 0;
int ledState = HIGH; 
int forward = 1, backward = 1;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  for(i=0; i<4; i++)
  {
    pinMode(LEDPin[i], OUTPUT);
    digitalWrite(LEDPin[i], LOW);
  }
    pinMode(SW, INPUT);
    digitalWrite(SW, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(SW) == 1)
    Serial.println("First");
  while(digitalRead(SW) == 0);
  while(digitalRead(SW) == 1)
  {
    for(i=0;i<4;i++)
      IR_SensorValue[i] = analogRead(IRPin[i]);
    if(IR_SensorValue[0] < 100 || IR_SensorValue[1] <100)
      forward = 0;
    else 
      forward = 1;
    if(IR_SensorValue[2] < 100 || IR_SensorValue[3] <100)
      backward = 0;
    else 
      backward = 1;
    joystickAnalogValue[0] = analogRead(joystickAnalog[0]);
    joystickAnalogValue[1] = analogRead(joystickAnalog[1]);
    Serial.println(joystickAnalogValue[0]);
    Serial.println(joystickAnalogValue[1]);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;    
      if (ledState == HIGH)
        ledState = LOW;
      else
        ledState = HIGH;
    }
    for(i=0; i<2; i++)
    {
      if(joystickAnalogValue[i] >= 0 && joystickAnalogValue[i] <= 255)
        joystickAnalogValue[i] = 0;
      else if(joystickAnalogValue[i] >= 256 && joystickAnalogValue[i] <= 767)  
        joystickAnalogValue[i] = 1;
      else
        joystickAnalogValue[i] = 2;
    }
      Serial.println(joystickAnalogValue[0]);
      Serial.println(joystickAnalogValue[1]);
      if(joystickAnalogValue[0] == 2)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      }
      else if(joystickAnalogValue[0] == 1 && joystickAnalogValue[1] == 1)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      }
      else
      {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      }
      //NORTH
        if(joystickAnalogValue[0] == 0 && joystickAnalogValue[1] == 1 && forward == 1)
        {
          analogWrite(ENA, F);
          analogWrite(ENB, F);
          digitalWrite(LEDPin[0], LOW);
          digitalWrite(LEDPin[1], HIGH);
          digitalWrite(LEDPin[2], LOW);
          digitalWrite(LEDPin[3], LOW);
          Serial.println("north");
        }
        //NORTH EAST
        else if(joystickAnalogValue[0] == 0 && joystickAnalogValue[1] == 0 && forward == 1)
        {
          analogWrite(ENA, F);
          analogWrite(ENB, H);
          digitalWrite(LEDPin[0], LOW);
          digitalWrite(LEDPin[1], HIGH);
          digitalWrite(LEDPin[2], ledState);
          digitalWrite(LEDPin[3], LOW);
          Serial.println("north east");
        }
        //EAST
        else if(joystickAnalogValue[0] == 1 && joystickAnalogValue[1] == 0 && IR_SensorValue[0] < 100 && IR_SensorValue[3] < 100)
        {
          analogWrite(ENA, F);
          analogWrite(ENB, Z);
          digitalWrite(LEDPin[0], LOW);
          digitalWrite(LEDPin[1], HIGH);
          digitalWrite(LEDPin[2], ledState);
          digitalWrite(LEDPin[3], LOW);
          Serial.println("east");
        }
        //SOUTH EAST
        else if(joystickAnalogValue[0] == 2 && joystickAnalogValue[1] == 0 && backward == 1)
        {
          analogWrite(ENA, F);
          analogWrite(ENB, H);
          digitalWrite(LEDPin[0], LOW);
          digitalWrite(LEDPin[1], LOW);
          digitalWrite(LEDPin[2], ledState);
          digitalWrite(LEDPin[3], HIGH);
          Serial.println("south east");
        }
        //SOUTH
        else if(joystickAnalogValue[0] == 2 && joystickAnalogValue[1] == 1 && backward == 1)
        {
          analogWrite(ENA, F);
          analogWrite(ENB, F);
          digitalWrite(LEDPin[0], LOW);
          digitalWrite(LEDPin[1], LOW);
          digitalWrite(LEDPin[2], LOW);
          digitalWrite(LEDPin[3], HIGH);
          Serial.println("south");
        }
        //SOUTH WEST
        else if(joystickAnalogValue[0] == 2 && joystickAnalogValue[1] == 2 && backward == 1)
        {
          analogWrite(ENA, H);
          analogWrite(ENB, F);
          digitalWrite(LEDPin[0], ledState);
          digitalWrite(LEDPin[1], LOW);
          digitalWrite(LEDPin[2], LOW);
          digitalWrite(LEDPin[3], HIGH);
          Serial.println("south west");
        }
        //WEST
        else if(joystickAnalogValue[0] == 1 && joystickAnalogValue[1] == 2 IR_SensorValue[1] < 100 && IR_SensorValue[2] < 100)
        {
          analogWrite(ENA, Z);
          analogWrite(ENB, F);
          digitalWrite(LEDPin[0], ledState);
          digitalWrite(LEDPin[1], HIGH);
          digitalWrite(LEDPin[2], LOW);
          digitalWrite(LEDPin[3], LOW);
          Serial.println("west");
        }
        //NORTH WEST
        else if(joystickAnalogValue[0] == 0 && joystickAnalogValue[1] == 2 && forward == 1)
        {
          analogWrite(ENA, H);
          analogWrite(ENB, F);
          digitalWrite(LEDPin[0], ledState);
          digitalWrite(LEDPin[1], HIGH);
          digitalWrite(LEDPin[2], LOW);
          digitalWrite(LEDPin[3], LOW);
          Serial.println("north west");
        }
        //CENTRE
        else
        {
          analogWrite(ENA, Z);
          analogWrite(ENB, Z);
          digitalWrite(LEDPin[0], LOW);
          digitalWrite(LEDPin[1], LOW);
          digitalWrite(LEDPin[2], LOW);
          digitalWrite(LEDPin[3], LOW);
          Serial.println("centre");
        }
  }
  while(digitalRead(SW) == 0);
  }
