const int trig = 6; // Trigger pin
const int echo = 7; // Echo pin

long totaltime;
long distance;

void setup() {
  pinMode(trig, OUTPUT);  // Set trig pin as output
  pinMode(echo, INPUT);   // Set echo pin as input
  Serial.begin(9600);     // Start serial communication at 9600 baud rate
}

void loop() {
  // Clear the trig pin by setting it LOW
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting the trig pin HIGH for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the echo pin and calculate the time it takes for the echo to return
  totaltime = pulseIn(echo, HIGH);

  // Calculate the distance (in cm) based on the speed of sound (343 m/s)
  distance = totaltime * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Wait for half a second before the next reading
}