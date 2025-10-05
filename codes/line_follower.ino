//ir sensors
#define irSensorLeft 2
#define irSensorRight 3

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

  //pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  //pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(irSensorLeft, INPUT);
  pinMode(irSensorRight, INPUT);
}

void loop() {
  //main code that runs repeatedly

  int leftIRvalue = digitalRead(irSensorLeft);
  int rightIRvalue = digitalRead(irSensorRight);

  if(leftIRvalue == HIGH && rightIRvalue == HIGH)
  {
    forward();
  }
  else if(leftIRvalue == LOW && rightIRvalue == HIGH)
  {
    right();
  }
  else if(leftIRvalue == HIGH && rightIRvalue == LOW)
  {
    left();
  }
  else 
  {
    stop();
  }
  delay(20);
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




