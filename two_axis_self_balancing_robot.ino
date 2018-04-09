#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   

Servo s1,s2,s3;

const int servo_pin1 = 9;
const int servo_pin2  = 10;
const int servo_pin3  = 11;

MPU6050 sensor;

int16_t ax, ay, az ;
int16_t gx, gy, gz ;

void setup()
{ 
  Wire.begin ( );
  Serial.begin  (9600); 
  
  s1.attach(servo_pin1);
  s2.attach(servo_pin2);
  s3.attach(servo_pin3);
  
  Serial.println  ( "Initializing the sensor" ); 
  sensor.initialize ( ); 
  
  Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
  delay (1000); 
  
  Serial.println ( "Taking Values from the sensor" );
  delay (1000);
}


void loop() 
{ 
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
  ay = map (ay, -17000, 17000, 180, 0) ;
  az = map (az, -17000, 17000, 205, 0) ;
  Serial.print(az);
  Serial.print("\t");
  Serial.print(ay);
  Serial.println("\t");
  s1.write(az); 
  delay(50);
  s2.write(ay);
  delay(50);
}
