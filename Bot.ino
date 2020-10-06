//L293D
//Motor A
const int motorPin1 = 3;
const int motorPin2 = 4;
//Motor B
const int motorPin3 = 5;
const int motorPin4 = 6;
//Motor C
const int motorPin5 = 8;
const int motorPin6 = 9;
//Motor D
const int motorPin7 = 10;
const int motorPin8 = 11;
int data;
 // A as gripper
 // B as base
 // C as front and back
 // D as extension
void setup(){
  Serial.begin(9600);
 //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);
}
void bend_forward()
{
 // Bend Forward
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW); //HIGH
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, LOW);
  delay(300);
}
void rotate_left()
{
 // Bend Forward
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW); //HIGH
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(1000);
}
void rotate_right()
{
 // Bend Forward
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin5, LOW); //HIGH
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(1000);
}
void place()
{
 // Close gripper
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(500);
}
void pick()
{
 // Open gripper
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(600);
}
void bend_backward()
{
 // Bend Backward
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);//HIGH
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, HIGH);
  delay(600);
}
void up()
{
 // Turn left
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(500);
}
void down()
{
 // Turn right
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(500);
}
void stop_all()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
}
void action_yes()
{
  place();
  bend_forward();
  pick();
  bend_backward();
  rotate_right();
  bend_forward();
  place();
  bend_backward();
  pick();
  rotate_left();
  stop_all();
}
void action_no()
{
 //dummy function that just opens and closes gripper to test that its working
  place();
  pick();
  stop_all();
}
void loop(){
  if(Serial.available()){
      data=Serial.read();
      if(data=='0')
      action_yes();
      if(data=='1')
      place();
      delay(200);
      pick();
 /*{
 case 48: stop_all();
 break;
 case 49: bend_forward();
stop_all();
 break;
 case 50: bend_backward();
stop_all();
 break;
 case 51: place();
stop_all();
 break;
 case 52 : pick();
stop_all();
 break;
 case 53: rotate_left();
stop_all();
 break;
 case 54:rotate_right();
stop_all();
 break;
 case 55:up();
stop_all();
 break;
 case 56:down();
stop_all();
 break;
}*/
}
//turn_right();
//bend_forward();
//place();
//bend_backward();
//turn_left()
 //And this code will stop motors
 //exit(0);
}
