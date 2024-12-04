#include <Servo.h>

// Create servo objects
Servo cerberus;
Servo hades;
Servo eurydice;

// Define pin connections
const int cerberusServoPin = 9;   // Pin for Cerberus servo
const int hadesServoPin = 10;     // Pin for Hades servo
const int eurydiceServoPin = 11;  // Pin for Eurydice servo

const int cerberusSwitchPin = 2;  // Pin for Cerberus toggle switch
const int hadesSwitchPin = 3;     // Pin for Hades toggle switch
const int eurydiceSwitchPin = 4;  // Pin for Eurydice toggle switch

// Independent starting and activated positions
int cerberusStartingPosition = 45;  
int cerberusActivatedPosition = 135;

int hadesStartingPosition = 10;     
int hadesActivatedPosition = 100;

int eurydiceStartingPosition = 40;  
int eurydiceActivatedPosition = 180;

// Previous states for switch debouncing
bool cerberusSwitchPrevState = HIGH;
bool hadesSwitchPrevState = HIGH;
bool eurydiceSwitchPrevState = HIGH;

// Servo states
bool cerberusState = false;
bool hadesState = false;
bool eurydiceState = false;

void setup() {
  // Attach servos to their respective pins
  cerberus.attach(cerberusServoPin);
  hades.attach(hadesServoPin);
  eurydice.attach(eurydiceServoPin);

  // Set initial servo positions
  cerberus.write(cerberusStartingPosition);
  hades.write(hadesStartingPosition);
  eurydice.write(eurydiceStartingPosition);

  // Set switch pins as input
  pinMode(cerberusSwitchPin, INPUT_PULLUP);
  pinMode(hadesSwitchPin, INPUT_PULLUP);
  pinMode(eurydiceSwitchPin, INPUT_PULLUP);
}

void loop() {
  // Check each switch and control the respective servo
  handleServo(cerberus, cerberusSwitchPin, cerberusState, cerberusSwitchPrevState, cerberusStartingPosition, cerberusActivatedPosition);
  handleServo(hades, hadesSwitchPin, hadesState, hadesSwitchPrevState, hadesStartingPosition, hadesActivatedPosition);
  handleServo(eurydice, eurydiceSwitchPin, eurydiceState, eurydiceSwitchPrevState, eurydiceStartingPosition, eurydiceActivatedPosition);
}

void handleServo(Servo &servo, int switchPin, bool &state, bool &prevSwitchState, int startingPosition, int activatedPosition) {
  // Read the current switch state
  bool currentSwitchState = digitalRead(switchPin);

  // Detect a toggle (button press from HIGH to LOW)
  if (currentSwitchState == LOW && prevSwitchState == HIGH) {
    // Flip the state
    state = !state;

    // Update servo position based on the new state
    if (state) {
      servo.write(activatedPosition);
    } else {
      servo.write(startingPosition);
    }
  }

  // Update the previous switch state
  prevSwitchState = currentSwitchState;
}
