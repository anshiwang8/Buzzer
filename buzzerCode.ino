const int buttonPin = 7;
const int ledPin = 1;

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);

    digitalWrite(ledPin, LOW);
}

void loop() {
    bool currentButtonState = digitalRead(buttonPin);

    if (lastButtonState == HIGH && currentButtonState == LOW) {
        ledState = !ledState;

        digitalWrite(ledPin, ledState);

        delay(200); 
    }

    lastButtonState = currentButtonState;
}