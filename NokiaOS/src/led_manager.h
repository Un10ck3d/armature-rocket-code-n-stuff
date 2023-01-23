void BlinkDebug(int led) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}

void BlinkNormal(int led) {
    digitalWrite(led, HIGH);
    delay(75);
    digitalWrite(led, LOW);
    delay(50);
    digitalWrite(led, HIGH);
    delay(75);
    digitalWrite(led, LOW);
    delay(500);
}

void BlinkWifi(int led) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
}