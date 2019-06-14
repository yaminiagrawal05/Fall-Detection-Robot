int lm1=6;   // LEFT MOTOR
int lm2=9;   
int rm1=10;      
int rm2=11;       // RIGHT MOTOR
int s1=12;         // IR SENSOR 1
int s2=13;         // IR SENSOR 2

void setup() {
  // put your setup code here, to run once:
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
        
     if(digitalRead(s1) &&  digitalRead(s2)){  // MOVE FORWARD 
       analogWrite(lm1,50);
       analogWrite(lm2,LOW);
       analogWrite(rm1,LOW);
       analogWrite(rm2,50);
     
      delay(10);
     }
     if(digitalRead(s1) &&  !digitalRead(s2)){  //IF EDGE ON THE LEFT SIDE , TURN RIGHT
       analogWrite(lm1,LOW);
       analogWrite(lm2,LOW);
       analogWrite(rm1,LOW);
       analogWrite(rm2,50);
     
      delay(10);
     }
     if(!digitalRead(s1) &&  digitalRead(s2)){  IF EDGE ON THE RIGHT SIDE TURN LEFT
       analogWrite(lm1,50);
       analogWrite(lm2,LOW);
       analogWrite(rm1,LOW);
       analogWrite(rm2,LOW);
     
      delay(10);
     }

     
     else{                             //IF EDGE IS DETECTED , STOP THE MOTION AND REVERSE
       analogWrite(lm1,LOW);
       analogWrite(lm2,LOW);
       analogWrite(rm1,LOW);
       analogWrite(rm2,LOW);
       delay(100);
       analogWrite(lm1,LOW);
       analogWrite(lm2,50);
       analogWrite(rm1,50);
       analogWrite(rm2,LOW);
       
     }
     
      
}
