#define x A0
#define y A1

const int in1 = 5;
const int in2 = 6;
const int in3 = 11;
const int in4 = 10;
const int sv = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int X = analogRead(x);
  int Y = analogRead(y);
//
//  Serial.print(X);
//  Serial.print("\t");
//  Serial.println(Y);

  if (X >= 800) {
    forward();
  } else if (X <= 200) {
    back();
  } else if (Y >= 800) {
    right();
  } else if (Y <= 200) {
    left();
  } else {
    Stop();
  }
}



void forward() {
  analogWrite(in1, sv);
  analogWrite(in2, 0);
  analogWrite(in3, sv);
  analogWrite(in4, 0);
  Serial.println("forward");
}

void back() {

  analogWrite(in1, 0);
  analogWrite(in2, sv);
  analogWrite(in3, 0);
  analogWrite(in4, sv);
  Serial.println("back");
}

void left() {
  analogWrite(in1, 0);
  analogWrite(in2, sv);
  analogWrite(in3, sv);
  analogWrite(in4, 0);
  Serial.println("left");
}

void right() {
  analogWrite(in1, sv);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, sv);
  Serial.println("right");
}
void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
  Serial.println("stop");
}
