// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
#include <LiquidCrystal.h>

// Create Amplitude 
RH_ASK driver;

int buzzerPin =8;

const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16,2);

  // lcd.print("Here");
  // lcd.print("Hello, World");
    // Initialize ASK Object
    // Setup Serial Monitor
    Serial.begin(9600);
    // put your setup code here, to run once:
    pinMode(8,OUTPUT);

      if (!driver.init())
       Serial.println("init failed");

  
}
 
void loop()
{
  //lcd.print("HI");
    // Set buffer to size of expected message
    uint8_t buf[4];
    uint8_t buflen = sizeof(buf);
    //lcd.clear();
    // Serial.println("here");
    //  lcd.clear();
      //lcd.setCursor(0,0);
      //lcd.println("HI");

    // Check if received packet is correct size
    if (driver.recv(buf, &buflen))
    {
      Serial.println((char*)buf);
      Serial.println("help me");
      lcd.display();
      lcd.print("Help");
      //lcd.print((char*)buf); 
      tone(8,1200);
      delay(1500);
      noTone(8);
      lcd.clear();
      delay(1000);

    }
  
}



