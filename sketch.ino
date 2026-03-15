// ============================================================
// Smart Thermostat - Slice 3: PID Temperature Control ⭐
// Platform: STM32F103C8T6 Blue Pill (Wokwi)
// Sensor: NTC (A0) | Heater: PWM LED (A1)
// ============================================================

#define NTC_PIN     A0
#define HEATER_PIN  A1
#define BAUD_RATE   115200
#define PID_INTERVAL 1000

float Kp = 2.0, Ki = 0.5, Kd = 0.1;
float setpoint = 25.0;
float integral = 0.0, lastError = 0.0;
unsigned long lastPidTime = 0;

#define INTEGRAL_MAX  50.0
#define INTEGRAL_MIN -50.0
#define OUTPUT_MAX   100.0
#define OUTPUT_MIN     0.0

void setup() {
  Serial.begin(BAUD_RATE);
  delay(100);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(HEATER_PIN, OUTPUT);

  Serial.println("=== Smart Thermostat v0.3 ===");
  Serial.print("Target: ");
  Serial.print(setpoint, 1);
  Serial.println(" C");
  Serial.println("PID controller active");
  Serial.println();

  lastPidTime = millis();
}

float readTemperature() {
  int raw = analogRead(NTC_PIN);
  return 50.0 - (raw / 1023.0) * 60.0;
}

float computePID(float currentTemp) {
  float dt = PID_INTERVAL / 1000.0;
  float error = setpoint - currentTemp;

  integral += error * dt;
  if (integral > INTEGRAL_MAX) integral = INTEGRAL_MAX;
  if (integral < INTEGRAL_MIN) integral = INTEGRAL_MIN;

  float derivative = (error - lastError) / dt;
  lastError = error;

  float output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  if (output > OUTPUT_MAX) output = OUTPUT_MAX;
  if (output < OUTPUT_MIN) output = OUTPUT_MIN;

  return output;
}

void loop() {
  unsigned long now = millis();
  if (now - lastPidTime >= PID_INTERVAL) {
    lastPidTime = now;

    float temp = readTemperature();
    float pidOutput = computePID(temp);

    int pwmValue = (int)(pidOutput * 255.0 / 100.0);
    analogWrite(HEATER_PIN, pwmValue);

    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    Serial.print("Temp: ");
    Serial.print(temp, 1);
    Serial.print(" C | Target: ");
    Serial.print(setpoint, 1);
    Serial.print(" C | PID: ");
    Serial.print(pidOutput, 1);
    Serial.println("%");
  }
}
