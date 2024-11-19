#include <Servo.h>
//pins
const int cerberusPin = 9;
const int hadesPin = 10;
const int eurydicePin = 11;

const int cerberusButton = 8;
const int hadesButton = 7;

//Servos
Servo cerberusServo;  // create servo for Cerberus
Servo hadesServo;  // create servo for Hades
Servo eurydiceServo;  // create servo for Eurydice

//Variables
bool enemyDefeated = false;
int pos = 0;    // variable to store the servo position

void setup() {
  cerberusServo.attach(9);  // attaches the Cerberus servo on pin 9 to the servo object
  hadesServo.attach(10);  // attaches the Hades servo on pin 10 to the servo object
  eurydiceServo.attach(11);  // attaches the Eurydice servo on pin 11 to the servo object
  Serial.begin(9600);

  //Eurydice movement by completing the circuit
  for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    eurydiceServo.write(pos);}              // tell servo to go to position in variable 'pos'
}

void loop() {
  if (digitalRead(cerberusButton)== HIGH){
    enemyDefeated = true;}

  if (digitalRead(hadesButton)== HIGH){
    enemyDefeated = true;}

  if (enemyDefeated == false){ //Enemy is in the way
    pos = 0; } 
    else {
    pos = 180;} //enemy=true, they move out of the way
}
