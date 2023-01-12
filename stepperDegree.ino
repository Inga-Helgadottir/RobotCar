#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038; //eller 64?
const float resolution = 5.625; //dette er også kaldet for 5.635 degree resolution / 64 steps per revolution

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

//
int moveToDegree(float wantedDegree){
  return(wantedDegree/resolution);
}

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
}

/*void loop() {
  // Rotate CW slowly at 5 RPM
  myStepper.setSpeed(5);
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  // Rotate CCW quickly at 10 RPM
  myStepper.setSpeed(10);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}*/

void loop(){
  //langsomt for at sikre at der ikke sker fejl og det ikke brænder sammen
  myStepper.setSpeed(5);
  //hen til sensor
  myStepper.step(moveToDegree(45));
  delay(700);

  //hen til sliske
  myStepper.step(moveToDegree(45));
  delay(200);

  //tilbage til for at samle en ny skittle op;
  myStepper.step(moveToDegree(180));
  delay(200);

  //alt efter hvordan motoren sættes op så kan den køre begge veje, 
  //ved at sætte et minus for an den vinkel den skal dreje

}
