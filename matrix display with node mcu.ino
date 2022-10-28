#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#define SSID "ACT105485077527" 
#define PASS "Smilydad@1963"
   
String form =
  "<p>"
  "<center>"
  "<h1>WiFi Control MAX7219 DISPLAY Panel with ESP8266</h1>"
  "<form action='msg'><p>Message <input type='text' name='msg' size=80 autofocus> <input type='submit' value='Submit'></form>"
  "</center>";

ESP8266WebServer server(80);                           
long period;
int offset=1,refresh=0;
int pinCS = 0; 
int numberOfHorizontalDisplays = 8;
int numberOfVerticalDisplays = 1;
String decodedMsg;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "Arduino";
int wait = 40; 

int spacer = 2;
int width = 5 + spacer; // The font width is 5 pixels

void handle_msg() {
                        
  matrix.fillScreen(LOW);
  server.send(200, "text/html", form);   
  refresh=1;
  String msg = server.arg("msg");
  Serial.println(msg);
  decodedMsg = msg;

  decodedMsg.replace("+", " ");      
  decodedMsg.replace("%21", "!");  
  decodedMsg.replace("%22", "");  
  decodedMsg.replace("%23", "#");
  decodedMsg.replace("%24", "$");
  decodedMsg.replace("%25", "%");  
  decodedMsg.replace("%26", "&");
  decodedMsg.replace("%27", "'");  
  decodedMsg.replace("%28", "(");
  decodedMsg.replace("%29", ")");
  decodedMsg.replace("%2A", "*");
  decodedMsg.replace("%2B", "+");  
  decodedMsg.replace("%2C", ",");  
  decodedMsg.replace("%2F", "/");   
  decodedMsg.replace("%3A", ":");    
  decodedMsg.replace("%3B", ";");  
  decodedMsg.replace("%3C", "<");  
  decodedMsg.replace("%3D", "=");  
  decodedMsg.replace("%3E", ">");
  decodedMsg.replace("%3F", "?");  
  decodedMsg.replace("%40", "@"); 
}

void setup(void) {
matrix.setIntensity(15); // Use a value between 0 and 15 for brightness

// Adjust to your own needs
  matrix.setPosition(0, 7, 0); // The first display is at <0, 7>
  matrix.setPosition(1, 6, 0); // The second display is at <1, 0>
  matrix.setPosition(2, 5, 0); // The third display is at <2, 0>
  matrix.setPosition(3, 4, 0); // And the last display is at <3, 0>
  matrix.setPosition(4, 3, 0); // The first display is at <0, 0>
  matrix.setPosition(5, 2, 0); // The second display is at <1, 0>
  matrix.setPosition(6, 1, 0); // The third display is at <2, 0>
  matrix.setPosition(7, 0, 0); // And the last display is at <3, 0>

//ESP.wdtDisable();                               // used to debug, disable wachdog timer, 
  Serial.begin(115200);                           // full speed to monitor
                               
  WiFi.begin(SSID, PASS);                         // Connect to WiFi network
  while (WiFi.status() != WL_CONNECTED) {         // Wait for connection
    delay(500);
    Serial.print(".");
  }
  // Set up the endpoints for HTTP server,  Endpoints can be written as inline functions:
  server.on("/", []() {
    server.send(200, "text/html", form);
  });
  server.on("/msg", handle_msg);                  // And as regular external functions:
  server.begin();                                 // Start the server 


  Serial.print("SSID : ");                        // prints SSID in monitor
  Serial.println(SSID);                           // to monitor             
 
  char result[16];
  sprintf(result, "%3d.%3d.%1d.%3d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3]);
  Serial.println();
  Serial.println(result);
  decodedMsg = result;
  Serial.println("WebServer ready!   ");

  Serial.println(WiFi.localIP());                 // Serial monitor prints localIP
  Serial.print(analogRead(A0)); 
}


void loop(void) {

  for ( int i = 0 ; i < width * decodedMsg.length() + matrix.width() - 1 - spacer; i++ ) {
    server.handleClient();                        // checks for incoming messages
    if (refresh==1) i=0;
    refresh=0;
    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically
 
    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < decodedMsg.length() ) {
        matrix.drawChar(x, y, decodedMsg[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(wait);
  }
}
