const int led[3] = {4, 0, 2};              // Countdown LEDs
const int playerled[2] = {10, 14};         // Player indicators
const int playerbutton[2] = {9, 12};      // Player buttons

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(playerled[i], OUTPUT);
    pinMode(playerbutton[i], INPUT_PULLUP); // Buttons use internal pull-ups
  }
}

void loop() {
  // 🔄 Reset player LEDs at the start of each round
  for (int i = 0; i < 2; i++) {
    digitalWrite(playerled[i], LOW);
  }

  // Countdown LEDs (1, 2, 3)
  for (int i = 0; i < 3; i++) {
    digitalWrite(led[i], HIGH);
    delay(1000);
  }

  // Turn off countdown LEDs
  for (int i = 0; i < 3; i++) {
    digitalWrite(led[i], LOW);
  }

  // Check for button press within reaction time
  bool winnerDecided = false;

  for (int i = 0; i < 30; i++) { // 3 seconds (30 × 100ms)
    if (digitalRead(playerbutton[0]) == LOW) {
      digitalWrite(playerled[0], HIGH);  // Player 1 wins
      winnerDecided = true;
      break;
    } else if (digitalRead(playerbutton[1]) == LOW) {
      digitalWrite(playerled[1], HIGH);  // Player 2 wins
      winnerDecided = true;
      break;
    }
    delay(100);
  }

  if (!winnerDecided) {
    // No one pressed - flash all countdown LEDs
    for (int i = 0; i < 3; i++) {
      digitalWrite(led[i], HIGH);
    }
    delay(200);
    for (int i = 0; i < 3; i++) {
      digitalWrite(led[i], LOW);
    }
  }

  delay(2000); // Wait before next round
}
