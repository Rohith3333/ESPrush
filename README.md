# ESPrush
A 2-player speed and reflex game built using an ESP8266 microcontroller. Players must press their button **as fast as possible** after a 3-LED countdown. The fastest player wins, and their LED lights up.

## 🛠️ Hardware
- ESP8266 (e.g., NodeMCU)
- 3x Countdown LEDs (GPIOs 4, 0, 2)
- 2x Player LEDs (GPIOs 10, 14)
- 2x Push Buttons (GPIOs 9, 12)

## 🎮 Gameplay
1. Countdown begins: 3 LEDs light up in sequence.
2. Once countdown ends, the game listens for button presses.
3. First player to press wins, and their LED lights up.
4. If no one presses within 3 seconds, countdown LEDs flash.

## 🔁 Features
- Internal pull-up resistors for buttons
- Clean GPIO pin setup
- Fast and fun rounds (~5 seconds each)

## 🔧 How to Upload
- Flash using Arduino IDE
- Choose `NodeMCU 1.0 (ESP-12E)` board

