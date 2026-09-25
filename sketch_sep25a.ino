
// Arduino UNO + HC-SR04 + LEDs + Buzzer

#define TRIG_PIN 9
#define ECHO_PIN 10

#define GREEN_LED 2
#define YELLOW_LED 3
#define RED_LED 4
#define BUZZER 5

#define OBJECT_HEIGHT 20.0

// Function to measure distance
float getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 40000);

  if (duration == 0)
  {
    return -1;
  }

  float distance = duration * 0.0343 / 2;

  return distance;
}

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Turn everything OFF initially
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);

  Serial.println("OBJECT DETECTION SYSTEM");
  Serial.println("--------------------------------");
}

void loop()
{
  float distance = -1;

  // Take up to 3 attempts
  for (int i = 0; i < 3; i++)
  {
    distance = getDistance();

    if (distance > 0)
    {
      break;
    }

    delay(50);
  }

  // If sensor doesn't respond
  if (distance < 0)
  {
    Serial.println("No Echo - Check Sensor Connection");
    delay(500);
    return;
  }

  float objectDist = OBJECT_HEIGHT - distance;

  // Keep value within tank limits
  if (objectDist < 0)
  {
    objectDist = 0;
  }

  if (objectDist > OBJECT_HEIGHT)
  {
    objectDist = OBJECT_HEIGHT;
  }

  // Calculate percentage
  float percentage = (objectDist / OBJECT_HEIGHT) * 100;

  // Display readings
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  Serial.print(" | objectDist: ");
  Serial.print(objectDist);
  Serial.print(" cm");

  Serial.print(" | Level: ");
  Serial.print(percentage);
  Serial.println("%");


  

  if (percentage < 35)
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.println("Status: LOW DISTANCE");
  }


  

  else if (percentage < 75)
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.println("Status: MEDIUM DISTANCE");
  }


  

  else
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    // Buzzer ON
    digitalWrite(BUZZER, HIGH);

    Serial.println("Status: HIGH DISTANCE- WARNING!");
  }

  Serial.println("--------------------------------");

  delay(500);
}