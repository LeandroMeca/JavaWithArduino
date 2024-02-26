#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo myservo;

int pos = 0;

char c;

#define SS_PIN 9
#define RST_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);



void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(10);
  myservo.write(0);
  Serial.println();
}

void loop() {


 
      String UIDD="";
     
         if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        
              for (byte i = 0; i < mfrc522.uid.size; i++) {
                  UIDD += String(mfrc522.uid.uidByte[i]);
              }          
             Serial.println(UIDD); 
             delay(3000);
         }

   

   if (Serial.available() > 0) {

    c = Serial.read();

    if(c=='l'){
        for (pos = 0; pos <= 100; pos += 1) {  
          myservo.write(pos);              
          delay(15);                       
        }
        delay(2000); 
        for (pos = 100; pos >= 0; pos -= 1) { 
          myservo.write(pos);              
          delay(15);                       
        }
    }
  }
   
}
