short ledPin = 11;
short led2Pin = 8;
short led3Pin = 4;
int lightResistorAnalog = A1;

long currentMillis = 0;
long lastStopMillis = 0;
int mode = 0x0;

int FIRST_LED = 0x1;
int SECOND_LED = 0x2;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
    pinMode(led3Pin, OUTPUT);
}

void loop() {
    currentMillis = millis();

    if(currentMillis - lastStopMillis > 1000) {
        mode = mode == FIRST_LED ? SECOND_LED : FIRST_LED;
        lastStopMillis = currentMillis;
    }

    if(mode == FIRST_LED) {
        digitalWrite(ledPin, HIGH);
        digitalWrite(led2Pin, LOW);
    } else {
        digitalWrite(led2Pin, HIGH);
        digitalWrite(ledPin, LOW);
    }

    int lightResistorValue = analogRead(lightResistorAnalog);

    if(lightResistorValue < 20) {
        digitalWrite(led3Pin, HIGH);
    } else {
        digitalWrite(led3Pin, LOW);
    }
}
