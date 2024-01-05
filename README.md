# Smart Doorbell Project

## Description
This project implements a smart doorbell system using Arduino. It includes features such as infrared remote control, PIR motion detection, and photoresistor-based night light.

## Components Used
- Arduino Board
- Infrared (IR) Receiver
- PIR Motion Sensor
- Photoresistor (LDR)
- LiquidCrystal Display
- Buzzer
- LEDs (for intruder and night lights)
- Push Button

## Dependencies
- [LiquidCrystal Library](https://www.arduino.cc/en/Reference/LiquidCrystal)
- [IRremote Library](https://github.com/z3t0/Arduino-IRremote)

## Pin Configuration
- **IR Receiver (ir):** Digital pin 3
- **PIR Motion Sensor (pir):** Digital pin 5
- **Photoresistor (photo):** Analog pin A1
- **Intruder Light (intruder_light):** Digital pin 8
- **Night Light (night_light):** Digital pin 9
- **Button (button):** Digital pin 7
- **Buzzer (buzzer):** Digital pin 6

## Circuit Diagram

![image](https://github.com/BibekJoshi4000/Smart_Door_bell/assets/97554714/09741e6a-df0b-44c7-950d-0ec6306a5a36)

## Setup Instructions
1. Connect the components based on the provided pin configuration in the Arduino sketch.
2. Install the necessary Arduino libraries:
    - LiquidCrystal
    - IRremote
3. Upload the sketch (`SmartDoorbell.ino`) to your Arduino board.

## Usage
- The doorbell recognizes different infrared remote codes and displays personalized messages on the LCD.
- PIR motion detection triggers an intruder alert with lights.
- Pressing the button simulates a guest, displaying a greeting on the LCD.
- The night light adjusts based on the ambient light using the photoresistor.

## Additional Notes
- Make sure to adjust the pin configuration in the sketch according to your actual wiring.
- Feel free to customize the infrared remote codes and associated messages in the code.
- For better security, consider enhancing the intruder alert system with additional sensors.
- You can expand the functionality by integrating it with IoT platforms or home automation systems.

## Contributors
- Bibek Joshi

