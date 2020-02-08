void setup() {
  Serial.begin(9600);

}
void loop() {
  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.0 / 1024.0);
  float turbidity = (-1120.4*voltage*voltage) + (5724.4 * voltage) - 4352.9;
  Serial.println ("Sensor Output (V):");
  Serial.println (voltage);
  Serial.println ("Turbidity Output : ");
  Serial.println(turbidity);
  Serial.println();
  delay(1000);
}
