void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  
  attachInterrupt(5, blink1, RISING);
  pinMode(5, INPUT_PULLDOWN);
  
  attachInterrupt(6, blink2, RISING);
  pinMode(6, INPUT_PULLDOWN);
  
  attachInterrupt(7, blink3, RISING);
  pinMode(7, INPUT_PULLDOWN);
  
  attachInterrupt(8, blink4, RISING);
  pinMode(8, INPUT_PULLDOWN);
}

void loop(){
   __bis_status_register(LPM3_bits+GIE);
}

void blink1(){
  digitalWrite(2, LOW);
  digitalWrite(14, LOW);
}
void blink2(){
  digitalWrite(2, HIGH);
  digitalWrite(14, LOW);
}
void blink3(){
  digitalWrite(2, HIGH);
  digitalWrite(14, HIGH);
}
void blink4(){
  digitalWrite(2, LOW);
  digitalWrite(14, HIGH);
}
