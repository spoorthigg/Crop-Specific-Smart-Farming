#include<dht.h>
#include<SoftwareSerial.h>

#define dht_apin A1 
dht DHT;

int Motor1A = 4;
int Motor1B = 5;
int enA = 3;

int BtTx = 13;
int BtRx = 12;
SoftwareSerial bt(BtTx, BtRx);

int lLight = 2; // GREEN
int lMois = 3; // white
int lTemp = 7; // RED


 
void setup()
{
   Serial.begin(9600);
   bt.begin(9600);


   pinMode( Motor1A, OUTPUT );
   pinMode( Motor1B, OUTPUT );

   pinMode(lLight, OUTPUT );
   pinMode(lMois, OUTPUT );
   pinMode(lTemp, OUTPUT ); 
   pinMode(9,OUTPUT);


}
 
void loop(){
  //Start of Program 
 
     DHT.read11(dht_apin);
     int mois = analogRead(A3);
     int light = analogRead(A5);
     int temp = DHT.temperature;
     int humd = DHT.humidity; 
     
    if(bt.available()){ //FOR BLUETOOTH CHANGE SERIAL TO BT 

      
      bt.print(temp);
      bt.print(" C");
      bt.print("|");
      bt.print(humd);            // COM3
      bt.print(" %");
      bt.print("|");
      bt.print(mois);
      //bt.println(" M");
      bt.print("|");
      bt.println(light);
     // bt.println(" L");
     
    } 

    
     Serial.print(temp);
      Serial.print(" C");
      Serial.print("|");
      Serial.print(humd);            // COM3
      Serial.print(" %");
      Serial.print("|");
      Serial.print(mois);
      Serial.println(" M");
      //bt.print("|");
      Serial.println(light);
      Serial.println(" L");

    

    // FOR LED

  /*  int flag = 0;
    
    if(temp < 40)
       digitalWrite(lTemp, HIGH);
   
    
    else digitalWrite(lTemp, LOW);
    
    if (mois < 300 )
        digitalWrite(lMois, HIGH);      // COM3
    
    else digitalWrite(lMois, LOW); 

    if(light < 300 )
        digitalWrite(lLight, HIGH);
    
    else 
        digitalWrite(lLight, LOW);*/


   int crop;
   
   if(bt.available()){
      crop = bt.read();
      
      if(crop == 48){
        
        Serial.println("wheat");
        if(temp > 40)
        digitalWrite(lTemp, HIGH);
   
    
        else digitalWrite(lTemp, LOW);
    
        if (mois > 300 )
        digitalWrite(lMois, HIGH);      // COM3
    
         else digitalWrite(lMois, LOW); 

         if(light > 300 )
        digitalWrite(lLight, HIGH);
    
         else 
        digitalWrite(lLight, LOW);

        digitalWrite(9,LOW);

      }

      else if(crop == 49){
        
        Serial.println("paddy");
        if(temp < 50)
        digitalWrite(lTemp, HIGH);
   
    
        else digitalWrite(lTemp, LOW);
    
        if (mois < 5000 )
        digitalWrite(lMois, HIGH);      // COM3
    
         else digitalWrite(lMois, LOW); 

         if(light < 1000 )
        digitalWrite(lLight, HIGH);
    
         else 
        digitalWrite(lLight, LOW);

        digitalWrite(9,HIGH);

      }
   }

    
   
    delay(2000);

    

   /*if( mois > X ){
     digitalWrite( Motor1A, LOW );
     digitalWrite( Motor1B, LOW );
   }
    ADD FLAG TO SHOW MOTOR RUNNING 
   else if( Y < mois < Z ){
    digitalWrite( Motor1A, HIGH );
    digitalWrite( Motor1B, HIGH );
   }

   else if( mois */
  
    
 
 
 
}// end loop() 
