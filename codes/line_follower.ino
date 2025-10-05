//ir sensors
#define irSensorLeft 2
#define irSensorRight 3

#define motorSpeed 180

//left motor
//#define enableLeftMotor x
#define leftMotorPin1 9
#define leftMotorPin2 8

//right motor
//#define enableRightMotor x
#define rightMotorPin1 7
#define rightMotorPin2 6

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
    delay(200);
  }

}

void forward()
{
  //analogWrite(enableLeftMotor, abs(motorSpeed));  
  //analogWrite(enableRightMotor, abs(motorSpeed));
  //left motor
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH); 
  //right motor
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);  
  delay(500);
}

void left()
{
  //analogWrite(enableLeftMotor, abs(motorSpeed));  
  //analogWrite(enableRightMotor, abs(motorSpeed));
  //left motor
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);  
  //right motor
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  delay(500);
}

void right()
{
  //analogWrite(enableLeftMotor, abs(motorSpeed));  
  //analogWrite(enableRightMotor, abs(motorSpeed));
  //left motor
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);  
  //right motor
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  delay(500);
}

void backward()
{
  //analogWrite(enableLeftMotor, abs(motorSpeed));  
  //analogWrite(enableRightMotor, abs(motorSpeed));
  //left motor
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);  
  //right motor
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);  
  delay(500);
}

void stop()
{
  //left motor
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);  
  //right motor
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);  
  delay(700);
}




