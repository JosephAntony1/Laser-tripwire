#define RELAY1  7                        
#define PHOTO1  0
#define PHOTO2  3

void setup() {
Serial.begin(115200);

pinMode(4, OUTPUT);
digitalWrite(4, HIGH);
pinMode(RELAY1, OUTPUT);       

pinMode(12, OUTPUT);
digitalWrite(12, HIGH);
}

long leftTime = millis();
long rightTime = millis();
int people = 0;
boolean leftHit = false;
boolean rightHit = false; 

void loop(){
int left = analogRead(PHOTO1);
int right = analogRead(PHOTO2);

 if(!leftHit && left<600){
  leftHit = true;
  leftTime = millis();
  }
 if (!rightHit && right<400){
    rightHit = true;
    rightTime = millis();
 }
 if (rightTime < millis()-2000)
  rightHit = false;
 if (leftTime < millis()-2000)
  leftHit = false;
  
 Serial.print(leftHit);
 Serial.print(" - ");
 Serial.print(rightHit);
 
 if(leftHit && rightHit ){
      if(leftTime - rightTime <= 0){
        if(people<=0) Serial.println("-----------GHOST-----------");
        
        if(people>0)
          people--;
      } 
      if(leftTime - rightTime > 0){
        people++;

      }

  leftHit = false;
  rightHit = false;
  
  if(people == 0){
      
      digitalWrite(RELAY1, 0); //Off
      delay(300);
  }
  else
      digitalWrite(RELAY1, 1); // On
      delay(1000);      
}

Serial.print(" - ");
Serial.print(people);
Serial.print(" - ");
Serial.print(leftTime);
Serial.print(" - ");
Serial.print(rightTime);
Serial.print(" - ");
Serial.print(left); 
Serial.print(" - "); 
Serial.println  (right);
}
