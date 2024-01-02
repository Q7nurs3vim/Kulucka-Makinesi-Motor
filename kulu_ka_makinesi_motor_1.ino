//Yangın Alarmı
  #include <Servo.h>
Servo motor;
const int red=5;
const int green=3;
const int blue=4;
double degrees;  
int sensorInput;

void setup(){ 
  motor.attach(2);
  motor.write(0);
}
void loop (){
  sensorInput = analogRead(A0);
degrees = (double)sensorInput / 1024;  
degrees = degrees * 5;                    
degrees = degrees - 0.5;                  
 degrees = degrees * 100;                
 
 
if(degrees < 36.5)
{
 motor.write(0);
digitalWrite(red,HIGH);
digitalWrite(green,LOW);
digitalWrite(blue,LOW);
}  
else if(degrees >= 37 && degrees <= 38)
{
motor.write(0);
digitalWrite(red,LOW);
digitalWrite(green,HIGH);
digitalWrite(blue,LOW);
}
else if(degrees>38.5 )
{
motor.write(90);
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(blue,HIGH);
}
delay(100);
}