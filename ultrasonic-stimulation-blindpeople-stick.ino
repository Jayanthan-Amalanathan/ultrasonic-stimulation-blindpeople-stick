const int trigPin = A5;
const int echoPin = A4;
const int vib = 3;

long duration;
float distance;

void setup() {
Serial.begin(9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(vib, OUTPUT);

}
void loop() {

measure_distance();


if (distance < 70)
{
Serial.print(distance);
Serial.println("Object Alert");
digitalWrite(vib, HIGH);
delay(1000);
digitalWrite(vib, LOW);
delay(1000);
for (int i= (distance-40); i>0; i--)
delay(10);
}
}

void measure_distance()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2.0;
Serial.print("Distance: ");
Serial.println(distance);
}
