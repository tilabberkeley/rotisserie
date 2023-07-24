/*
  
  Code to control rotisserie.
  Full guide in Lab Drive.

  Adapted from SparkFun Inventor's Kit Circuit 5A
  Original Code: https://github.com/sparkfun/SIK-Guide-Code/blob/master/SIK_Circuit_5A-MotorBasics/SIK_Circuit_5A-MotorBasics.ino
  
  Hardware Connections:
  Switch - Pin 7
  Motor Driver
    PWMA: Pin 13
    A12:  Pin 12
    A11:  Pin 11
    STBY: Pin 10
    B11:  Pin 9
    B12:  Pin 8
    PWMB: Pin 7
  
*/

//PIN VARIABLES

//motor controlled by the motor A pins on motor driver

const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;           //control pin 2 on the motor driver for the right motor
const int PWMA = 11;           //speed control pin on the motor driver for the right motor

const int switchPin = 7;       //switch to turn the robot on and off


//VARIABLES

int motorSpeed = 100;         // rpm. starting speed for the motor w/ 9V power supply. works for 9-277 rpm.
int motorPWM = round((abs(motorSpeed) + 8.12) / 1.12); // transfer function based on experimental calibration


void setup() {

  // set this as a pullup to sense whether the switch is flipped
  pinMode(switchPin, INPUT_PULLUP);
    
  // set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}


void loop() {

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, abs(motorPWM));

}
