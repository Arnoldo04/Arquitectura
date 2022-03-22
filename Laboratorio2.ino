const int pinLed1 = 8;
const int pinLed2 = 12;
const int pinpush1 = 2;
const int pinpush2 = 4;


void setup() {
  Serial.begin(9600);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinpush1, INPUT);
  pinMode(pinpush2, INPUT);
  digitalWrite(pinLed1, 0);
  digitalWrite(pinLed2, 0);
}

int contadorpush1 = 0;
int contadorpush2 = 0;

void loop() {  
  
  if(digitalRead(pinpush1) == HIGH){
    if(digitalRead(pinpush1) == LOW){
       contadorpush1++;
       Serial.print("contador 1:");
       Serial.println(contadorpush1);
        Serial.print("contador 2:");
       Serial.println(contadorpush2);      
      }
   }

   if(digitalRead(pinpush2) == HIGH){
    if(digitalRead(pinpush2) == LOW){
       contadorpush2++;
       Serial.print("contador 1:");
       Serial.println(contadorpush1);
        Serial.print("contador 2:");
       Serial.println(contadorpush2);
      }
   }
  //encendiendo leds de forma analoga 
  if(contadorpush1 == 2){
      //Serial.println(contadorpush1);
      digitalWrite(pinLed1, 1);
      delay(5000);
      digitalWrite(pinLed1, 0);
      contadorpush1= 0;
      //Serial.println(contadorpush1);
   }
   if(contadorpush2 == 2){
      digitalWrite(pinLed2, 1);
      delay(5000);
      digitalWrite(pinLed2, 0);
      contadorpush2=0;
   }
  //pendiendo led de forma logica     
  if(Serial.available() > 0){
      char serialData = Serial.read();
    if(serialData == '1'){
      digitalWrite(pinLed1, 0);
      delay(10000);
      digitalWrite(pinLed1, 1);
    }
    if(serialData == '2'){
      digitalWrite(pinLed2, 0);
      delay(10000);
      digitalWrite(pinLed2, 1);
    }
  }

}
