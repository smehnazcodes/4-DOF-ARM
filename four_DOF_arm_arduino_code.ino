#include <Servo.h>

//Starting of Program
#include <Servo.h> 


char val;



Servo servoBase; 
Servo servoGrabber;
Servo servoLeft; 
Servo servoRight;

int base =110;
int left =150;
int right =60;
int grab= 60;


void setup() 
{  

Serial.begin(9600);
  servoGrabber.attach(10);  //start from 60 degree and end at 0 or 10
  servoLeft.attach(9);  //start from 130 degree faced forward, here 0 degree forward and 180 degree backward
  servoBase.attach(5);  //start from 70 degree , here 0 extreme right and 180 extreme left when faced forward
  servoRight.attach(6); //start from 60 degree faced forward, here 0 degree backward and 150 degree forward

    servoBase.write(110);
    servoRight.write(60);
    servoLeft.write(150);
    servoGrabber.write(60);
}

void loop()
{
  
  
  if (Serial.available() > 0)
  {
  val = Serial.read();
  
  Serial.println(val);
 

    if(val == 87){
      Serial.println("Forward");
      right = right-10;
      servoRight.write(right);
      delay(200);
        
    }else if(val == 83){
      
      Serial.println("Backward");
      right = right+10;
      servoRight.write(right);
      delay(200);
      
    }else if(val == 65){
      Serial.println("left");
      base = base+10;
      servoBase.write(base);
      delay(200);
      
    }else if(val == 68){
      Serial.println("Right");
        base = base-10;
      servoBase.write(base);
      delay(200);
      
      
    }else if(val == 89){
      Serial.println("Left Forward");
        left = left-10;
      servoLeft.write(left);
      delay(200);
      
      
    }else if(val == 72){
      Serial.println("Left Backward");
       left = left+10;
      servoLeft.write(left);
      delay(200);
      
      
    }else if(val == 79){
      Serial.println("Open");
        grab = grab+10;
      servoGrabber.write(grab);
      delay(200);
      
      
    }else if(val == 67){
      Serial.println("Close");
       grab = grab-10;
      servoGrabber.write(grab);
      delay(200);
    
    }
    
    else{}
    
  }
 
}

