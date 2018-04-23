#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00006";
const int startButton = 3;
const int speaker = 12;

const int square1 = A0;
const int square2 = A1;
const int square3 = A2;
const int square4 = A3;
const int square5 = A4;
const int square6 = A5;
const int square7 = A6;
const int square8 = A7;
const int square9 = A8;


void setup() {

  Serial.begin(9600);
  
  //start bluetooth communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.println("Bluetooth on");

  //set pins as input
  pinMode(startButton, INPUT);
  pinMode(speaker, OUTPUT);
  pinMode(square1, INPUT);
  pinMode(square2, INPUT);
  pinMode(square3, INPUT);
  pinMode(square4, INPUT);
  pinMode(square5, INPUT);
  pinMode(square6, INPUT);
  pinMode(square7, INPUT);
  pinMode(square8, INPUT);
  pinMode(square9, INPUT);

  
  

}


   
  
  int nums[9] = {0,0,0,0,0,0,0,0,0};

void loop() {

  int reset = digitalRead(startButton);

  //set squares as button states
  int buttonState1 = analogRead(square1);
  int buttonState2 = analogRead(square2);
  int buttonState3 = analogRead(square3);
  int buttonState4 = analogRead(square4);
  int buttonState5 = analogRead(square5);
  int buttonState6 = analogRead(square6);
  int buttonState7 = analogRead(square7);
  int buttonState8 = analogRead(square8);
  int buttonState9 = analogRead(square9);
  

  //check if pin has completed a circuit. if so, make nums[i] = 1
  if(buttonState1 <= 10){
    nums[0] = 1;
    Serial.println("Boat on square 0");
            Serial.flush();
   }
    else{
      nums[0] = 0;
      }
    if(buttonState2 <= 10){
    nums[1] = 1;
        Serial.println("Boat on square 1");
        Serial.flush();
    }
    else{
      nums[1] = 0;
      }
    if(buttonState3 <= 10){
    nums[2] = 1;
        Serial.println("Boat on square 2");
        Serial.flush();
    }
    else{
      nums[2] = 0;
      }
    if(buttonState4 <= 10){
    nums[3] = 1;
        Serial.println("Boat on square 3");
        Serial.flush();
    }
    else{
      nums[3] = 0;
      }
    if(buttonState5 <= 10){
    nums[4] = 1;
        Serial.println("Boat on square 4");
        Serial.flush();

    }
    else{
      nums[4] = 0;
      }
    if(buttonState6 <= 10){
    nums[5] = 1;
        Serial.println("Boat on square 5");
        Serial.flush();
    }
    else{
      nums[5] = 0;
      }
    if(buttonState7 <= 10){
    nums[6] = 1;
        Serial.println("Boat on square 6");
        Serial.flush();
    }
    else{
      nums[6] = 0;
      }
    if(buttonState8 <= 10){
    nums[7] = 1;
        Serial.println("Boat on square 7");
        Serial.flush();
    }
    else{
      nums[7] = 0;
      }
    if(buttonState9 <= 10){
    nums[8] = 1;
        Serial.println("Boat on square 8");
        Serial.flush();
    }
    else{
      nums[8] = 0;
      }



  radio.write(&nums, sizeof(nums));
  delay(1000);
  Serial.println("");
  Serial.println("Next:");
 
}
