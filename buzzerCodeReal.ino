
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

int buzzerNoise = A0;

int reset = 13;
int playerButtons[] = {2, 3, 4, 5, 6, 7, 9, 10};
bool lock = false;

void setup() {
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
  	pinMode(buzzerNoise, OUTPUT);
  	pinMode(reset, INPUT_PULLUP);
  for (int i = 0; i < 8; i++){
    pinMode(playerButtons[i], INPUT_PULLUP);
  }
}
void loop() {
  if (digitalRead(reset) == LOW){
    lock = false; 
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0);
    digitalWrite(latchPin, HIGH);
    delay (500);
  }

  if (!lock){
  	for (int i = 0; i < 8; i++){
    	if (digitalRead(playerButtons[i]) == LOW){
     	 	lightSwitch(i);
      		lock = true;
        	delay (500);
        	break;
    	}
  	}
  }  
}    
void lightSwitch(int buttonIndex){
  buzzer();
  int binaryIndex = 1 << 7-buttonIndex;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryIndex);
  digitalWrite(latchPin, HIGH);
}
void buzzer(){
  tone(buzzerNoise, 440, 500);
}
  