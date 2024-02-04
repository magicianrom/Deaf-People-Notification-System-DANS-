//Microphone sensor sketch 
//connect the pins and tell the arduino about them:

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver; 
const int ledPin1 =8 ;
const int ledPin2 = 9;
const int ledPin3 =10 ;
const int micPin = A1; //setup pin for input from the sensor
const int btn = 4 ;
int micState; //declare a variable for microphone Analog Read 
int amplitude; //difference between microphone reading and baseline 
int btnState;
void setup() {
  //set LED pins as outputs 
  pinMode(ledPin1,OUTPUT);  
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(micPin,INPUT);
  pinMode(btn,INPUT);
  Serial.begin(9600);
  // Initialize ASK Object
  rf_driver.init();
}

void loop() {
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  micState=analogRead(micPin);
  amplitude = abs(micState);
  Serial.println(amplitude);
  btnState = digitalRead(btn);
  Serial.print("btnState: ");
  Serial.println(btnState);

  if(btnState==1){
    const char *msg = "help";
    int counter =0;
    while(counter<1){
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent();
        delay(90);
        counter++;
      }
    }
  
  if(amplitude>570){
    //turn all LEDs on
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin3,HIGH); 
  
    // delay(800);
  } else if (amplitude>550){
     digitalWrite(ledPin2,HIGH);
     digitalWrite(ledPin3,HIGH);

    //  delay(800);

  } else if(amplitude>535){
         digitalWrite(ledPin3,HIGH);

        //  delay(800);

  } else if(amplitude<=535) {
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin3,LOW);  

  }
  delay(30);
}
