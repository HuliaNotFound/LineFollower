//distance sensor
#define trigPin 12
#define echoPin 8

#define motorSpeed 140

//left motor
#define leftMotorPin1 10
#define leftMotorPin2 9

//right motor
#define rightMotorPin1 6
#define rightMotorPin2 5

void setup() {
  //setup code that only runs once, when the code starts
  Serial.begin(9600);

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

void loop() {
  //main code that runs repeatedly
  int duration, distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);

  //w przod
  forward();
  delay(200);

  if (distance < 25)
  {  
    stop();
    delay(300);
    backward();
    delay(800);
    left();
    delay(600);
    backward();
    delay(700);
  }
}


void forward()
{
  //left motor
  analogWrite(leftMotorPin1, motorSpeed);
  digitalWrite(leftMotorPin2, LOW); 
  //right motor
  analogWrite(rightMotorPin1, motorSpeed);
  digitalWrite(rightMotorPin2, LOW);  
  //delay(800);
}

void left()
{
  //left motor
  digitalWrite(leftMotorPin1, LOW);
  analogWrite(leftMotorPin2, motorSpeed);  
  //right motor
  analogWrite(rightMotorPin1, motorSpeed);
  digitalWrite(rightMotorPin2, LOW);
  //delay(800);
}

void right()
{
  //left motor
  analogWrite(leftMotorPin1, motorSpeed);
  digitalWrite(leftMotorPin2, LOW);  
  //right motor
  digitalWrite(rightMotorPin1, LOW);
  analogWrite(rightMotorPin2, motorSpeed);
  //delay(800);
}

void backward()
{
  //left motor
  digitalWrite(leftMotorPin1, LOW);
  analogWrite(leftMotorPin2, motorSpeed);  
  //right motor
  digitalWrite(rightMotorPin1, LOW);
  analogWrite(rightMotorPin2, motorSpeed);  
  //delay(800);
}

void stop()
{
  //left motor
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);  
  //right motor
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);  
  //delay(2000);
}
