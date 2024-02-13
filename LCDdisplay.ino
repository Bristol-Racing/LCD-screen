#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
#include <Wire.h>

LCDWIKI_KBV mylcd(ILI9341, A3, A2, A1, A0, 11); //model,cs,cd,wr,rd,reset

// Define some colour values
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

char receivedCommand;

void setup() {
  mylcd.Init_LCD();

  Wire.begin(8);                /* join i2c bus with address 8 */
  Wire.onReceive(receiveEvent); /* register receive event */
  //Wire.onRequest(requestEvent); /* register request event */
  Serial.begin(9600);

  Serial.println(mylcd.Read_ID(), HEX);
  mylcd.Fill_Screen(BLACK);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
   while (Wire.available()) {
     char c = Wire.read();      /* receive command */
     receivedCommand = c;
   }
}

void loop() {
  mylcd.Fill_Screen(BLACK);
  //displaying color
  if (receivedCommand == 'y' || receivedCommand == 'Y'){
    mylcd.Fill_Screen(YELLOW);
  }

  else if (receivedCommand == 'r' || receivedCommand == 'R'){
    mylcd.Fill_Screen(RED);
  }

  else if (receivedCommand == 'b' || receivedCommand == 'B'){
    mylcd.Fill_Screen(CYAN);
  }
  delay(3000);
}