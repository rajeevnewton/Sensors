int state = "0";

void setup(){
Serial.begin(9600);
}



void setup(){


if(Serial.avalible() > 0){      // to check bluetooth is connected

    state = Serial.receive(); //reveive data from bluethoth
    

}

}