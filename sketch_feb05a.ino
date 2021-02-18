const int Laser = 6;
const int Detector = 7;
const int buzzer = 8;

unsigned long lastHitMillis = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Laser, OUTPUT);
  pinMode(Detector, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(Laser, HIGH);
}

void loop() {
      
    unsigned long currentMillis = millis();

    /*
    Create multitasking to reading analog input
    To avoid false triggers test if the debounce delay
    period has passed
    */
    if(currentMillis - lastHitMillis >= 60){
      boolean laserSensorData = digitalRead(Detector);
              
      //Set the hit time for pseudo debouncing
      lastHitMillis = millis();

      if(laserSensorData == 1) {
        // Data disini yang dikirim ke serial communication
        Serial.write(1);
        digitalWrite(buzzer, HIGH);
      } else {
        Serial.write(0);
        digitalWrite(buzzer, LOW);
      } 
   }
}
