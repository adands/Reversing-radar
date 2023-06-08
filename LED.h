int rPin = 18;
int bPin = 5;
int gPin = 17;
int wPin = 16;

void initLEDlight(){
  pinMode(rPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(wPin,OUTPUT);
  }

void shine(unsigned long distance){
  
   if (distance > 35){
    digitalWrite(rPin,LOW);
    digitalWrite(bPin,LOW);
    digitalWrite(gPin,LOW);
    digitalWrite(wPin,LOW);
    }
  if (distance <= 35){
    digitalWrite(wPin,HIGH);
    digitalWrite(rPin,LOW);
    digitalWrite(bPin,LOW);
    digitalWrite(gPin,LOW);
   
    }
  if (distance <= 30){
    digitalWrite(gPin,HIGH);
    digitalWrite(wPin,HIGH);
    digitalWrite(bPin,LOW);
    digitalWrite(rPin,LOW);
   
    }
   if (distance <= 15){
    digitalWrite(bPin,HIGH);
    digitalWrite(wPin,HIGH);
    digitalWrite(gPin,HIGH);
    digitalWrite(rPin,LOW);
    
    }  
   if (distance <= 5){
    digitalWrite(rPin,HIGH);
    digitalWrite(wPin,HIGH);
    digitalWrite(bPin,HIGH);
    digitalWrite(gPin,HIGH);
    
    }
  }
