#include <BluetoothSerial.h>

// Define motor control pins
#define IN1 25
#define IN2 26

// Create a BluetoothSerial object
BluetoothSerial SerialBT;

// Global flag to track motor state
char currentCommand = '\0'; // Stores the currently active command ('2', '3', or '\0' for none)

// Function to stop the motor
void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  currentCommand = '\0'; // Reset active command
  Serial.println("Motor stopped.");
}

// Function to run the motor forward
void runForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

// Function to run the motor backward
void runBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

// Function to unlock the latch
void unlockLatch() {
  Serial.println("Unlocking latch...");
  
  // Rotate motor forward
  runForward();
  delay(2500); // Adjust as needed for your setup
  stopMotor();
  delay(2000); // Brief pause

  // Rotate motor backward to return to original position
  runBackward();
  delay(2000); // Adjust as needed for your setup
  stopMotor();

  Serial.println("Latch unlocked and returned to original position.");
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Jadu"); // Bluetooth device name
  Serial.println("Bluetooth Device is Ready to Pair");

  // Initialize motor control pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.println("Waiting for Bluetooth commands...");
}

void loop() {
  // Check for incoming Bluetooth commands
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read(); // Read the received character
    Serial.print("Received: ");
    Serial.println(receivedChar);

    if (receivedChar == 'U') { // Command 'U' to unlock the latch
      unlockLatch();
    } else if (receivedChar == 'S') { // Command 'S' to stop the motor
      stopMotor();
    } else if (receivedChar == 'L') { // Align left (run motor backward until stopped)
      Serial.println("Aligning left...");
      runBackward();
      currentCommand = 'L'; // Set active command to '2'
    } else if (receivedChar == 'R') { // Align right (run motor forward until stopped)
      Serial.println("Aligning right...");
      runForward();
      currentCommand = 'R'; // Set active command to '3'
    } else {
      Serial.println("Unknown command");
    }
  }

  // Keep the motor running based on the active command
  if (currentCommand == 'L') {
    // Motor is already running backward for align left
  } else if (currentCommand == 'R') {
    // Motor is already running forward for align right
  }
}
