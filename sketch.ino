#define NTC_PIN   A0
#define BAUD_RATE 115200

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("System OK");
}

void loop() {
  int raw = analogRead(NTC_PIN);
  float temp = map(raw, 0, 1023, -10, 50);  // 模擬 -10°C ~ 50°C

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Temp: ");
  Serial.print(temp, 1);
  Serial.println(" C");
  digitalWrite(LED_BUILTIN, LOW);

  delay(1000);
}
