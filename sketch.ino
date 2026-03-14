// Smart Thermostat - Slice 1: Heartbeat
// Simulates Sinopé-style embedded thermostat
// Platform: STM32 L031K6 (Wokwi)

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("System OK");
  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
