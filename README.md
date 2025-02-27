# 🔒 ESP32 Bluetooth-Controlled Latch & Motor System  

This project uses an **ESP32** to control a **motor-driven latch system** via **Bluetooth**. The system can unlock a latch, align in different directions, and stop based on Bluetooth commands sent from a mobile app or other Bluetooth-enabled devices.

## 🚀 Features  
- **Bluetooth Communication**: Connects via Bluetooth under the name **"ESP32_Jadu"**.  
- **Latch Unlocking**: Rotates a motor forward and backward to unlock a latch.  
- **Motor Alignment**: Allows manual alignment using left (`L`) and right (`R`) commands.  
- **Emergency Stop**: Stops motor operation instantly using the `S` command.  
- **Command Handling**: Listens for commands (`U`, `S`, `L`, `R`) and executes corresponding motor actions.  

## 📜 Commands  
| Command | Action |  
|---------|--------|  
| `U` | Unlocks the latch (rotates forward, stops, then reverses). |  
| `S` | Stops the motor immediately. |  
| `L` | Runs the motor backward for left alignment. |  
| `R` | Runs the motor forward for right alignment. |  

## 🛠️ Hardware Requirements  
- **ESP32**  
- **Motor Driver (H-Bridge or Relay Module)**  
- **DC Motor / Servo** (for latch control)  
- **Bluetooth-enabled Device** (to send commands)  

## 📌 How It Works  
1. The ESP32 initializes and starts listening for Bluetooth commands.  
2. When a command is received:  
   - `U` unlocks the latch by rotating the motor forward and then backward.  
   - `L` and `R` rotate the motor continuously until stopped manually (`S`).  
3. The motor state is tracked to ensure smooth operation.  

## 🔧 Setup Instructions  
1. Connect the motor driver to the ESP32 using the defined pins.  
2. Upload the provided Arduino code to the ESP32.  
3. Pair your Bluetooth-enabled device with **ESP32_Jadu**.  
4. Use a serial Bluetooth app to send commands (`U`, `L`, `R`, `S`).  
