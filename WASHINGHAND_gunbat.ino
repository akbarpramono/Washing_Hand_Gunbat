int LED = 7; // Use the onboard Uno LED
int trigPin = 2;
int echoPin = 3;
int long duration;
int distance;
//int isObstacle = LOW;  // HIGH MEANS NO OBSTACLE
int ledPin = 13;               // LED 
int pirPin = 8;                 
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);     
  pinMode(pirPin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  digitalWrite(trigPin,LOW);
  
  digitalWrite(trigPin,HIGH);
  
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  if (distance <= 12)
  {
    delay(200);
    Serial.println(distance);
    digitalWrite(LED, LOW);
    delay (1400);
    digitalWrite(LED, HIGH);
    delay (3000);
    digitalWrite(LED, HIGH);
    
  }
  else
  {
    digitalWrite(LED, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  int val = digitalRead(pirPin);
  if (val == 0) {            // if motion detected
   
   digitalWrite(ledPin, LOW);  // turn LED ON
   delay (3000);
   Serial.println("WASH");
  }  
  else
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(LED, HIGH);
  }
 
}
