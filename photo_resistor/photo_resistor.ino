// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(5, INPUT_PULLUP);
  pinMode(14, OUTPUT);
  digitalWrite(14, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A3:
  int adc_value = analogRead(A3);
  analogWrite(2, adc_value);  
  analogReference(INTERNAL1V5);
  int temp = ((float)analogRead(TEMPSENSOR))*0.0014648 + 0.896;
  
  analogReference(INTERNAL2V5);
  
  //Temp Sensor is A10
  Serial.println(adc_value);
  Serial.println("Internal Temperature: " + String(temp));
  delay(750); // delay in between reads for stability
}

