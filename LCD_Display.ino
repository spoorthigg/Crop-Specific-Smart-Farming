// LCD DISPLAY
#include<dht.h>
#include<SoftwareSerial.h>
#include<LiquidCrystal.h>

#define dht_apin A0 
dht DHT;

const int rs =12 , en =11 , d4 =4 , d5 =5 , d6 =6 , d7 =7 ;
LiquidCrystal lcd(rs , en , d4 , d5 , d6 , d7 ); 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.clear();

  pinMode(2,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

     
     DHT.read11(dht_apin);
     int mois = analogRead(A2);
     int light = analogRead(A4);
     int temp = DHT.temperature;
     int humd = DHT.humidity; 

      Serial.print(temp);
      Serial.println(" C");
      //bt.print("|");
      Serial.print(humd); 
      Serial.println(" %");
      //bt.print("|");
      Serial.print(mois);
      Serial.println(" moisture");
      //bt.print("|");
      Serial.print(light);
      Serial.println(" light");

     
    if( digitalRead(2) == HIGH ){
          if(mois > 5000 || light > 1000 )
        {
          lcd.clear();
          lcd.print("ERROR, gr light");
          lcd.setCursor(0, 1);
          lcd.print("red temp, wh mois");
          Serial.print("HIGH");
          
          }
          else {
      lcd.clear();
      lcd.print(" EVERYTHING FINE");
      }
          
      }

        if( digitalRead(2) == LOW ){
          if (mois > 300 || light > 300 )
        {
          lcd.clear();
          lcd.print("crct, gr light"); //WHEAT
          lcd.setCursor(0, 1);
          lcd.print("red temp, wh mois");
          Serial.print("LOW");
          
          }
else {
      lcd.clear();
      lcd.print(" EVERYTHING FINE");
      }
       }

   

     delay(4000);


}
