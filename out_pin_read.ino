int arr [] = {2,4,5,12,13,14,15,16,17,18,19,20,21,22,23,25,26,27,32,33};
void setup() {
  Serial.begin(115200);
  for (int i = 0; i <= 19; i++) {
    pinMode(arr[i], OUTPUT);
    digitalWrite(arr[i], LOW);
  }
  Serial.println("START");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 19; i++) {
    if (digitalRead(arr[i])) {
      digitalWrite(arr[i], LOW);
    } else {
      digitalWrite(arr[i], HIGH);
    }
  }
  for (int i = 0; i <= 19; i++) {
    if (digitalRead(arr[i])) {
      Serial.println(arr[i]);
    }
  }
  
  delay(5000);
}

int digitalReadOutputPin(uint8_t pin) {
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  if (port == NOT_A_PIN)
    return LOW;

  return (*portOutputRegister(port) & bit) ? HIGH : LOW;
}
