#include <Servo.h>  
#include <SPI.h> // SPI library
#include <MFRC522.h> // RFID library (https://github.com/miguelbalboa/rfid)
const int pinRST = 9;
const int pinSDA = 10;
MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino
//int Data [4] = {7,D0,1,34};
//int Count = 0;

#include <Servo.h>             //Servo library 
Servo servo_test;        //initialize a servo object for the connected servo                  
int angle = 0;    
 
void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
  servo_test.attach(5);
  Serial.print("Hi setup finished");
}
void loop() {
if ( ! mfrc522.PICC_IsNewCardPresent()) {
    Serial.println("No card");
    return;
    delay(50);
  }
  Serial.println("Present");
  mfrc522.PICC_HaltA();
  delay(50);
// White CARD  6A EC 91 19
// BLUE CARD   7 D0 1 34




/*if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
   Serial.println("Present");
    if(mfrc522.PICC_ReadCardSerial()) { // true, if RFID tag/card was read
      Serial.print("RFID TAG ID:");
      for (byte i = 0; i < mfrc522.uid.size; ++i) { // read id (in parts)
        Serial.print(mfrc522.uid.uidByte[i], HEX); // print id as hex values
        Serial.print(" "); // add space between hex blocks to increase readability
      }
      Serial.println(); // Print out of id is complete.
    }
  }*/
}
