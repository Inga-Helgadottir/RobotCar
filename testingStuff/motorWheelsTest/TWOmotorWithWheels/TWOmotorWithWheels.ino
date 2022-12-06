int rightWheel1 = 4;
int rightWheel2 = 5;

int leftWheel1 = 6;
int leftWheel2 = 7;

void setup() {
  pinMode(rightWheel1, OUTPUT);
  pinMode(rightWheel2, OUTPUT);
  pinMode(leftWheel1, OUTPUT);
  pinMode(leftWheel2, OUTPUT);
}

void loop() {
  
//right wheels forward{
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, HIGH);
  delay(2000);
  // }

 // right wheels backwards{
  digitalWrite(rightWheel1, HIGH);
  digitalWrite(rightWheel2, LOW);
  delay(2000);
  // }

//stop right wheels{
  digitalWrite(rightWheel1, LOW);
  digitalWrite(rightWheel2, LOW);
  delay(2000);
// }

//left wheels forward{
  digitalWrite(leftWheel1, HIGH);
  digitalWrite(leftWheel2, LOW);
  delay(2000);
  // }

// left wheels backward{
  digitalWrite(leftWheel1, LOW);
  digitalWrite(leftWheel2, HIGH);
  delay(2000);
  // }

//stop left wheels{
  digitalWrite(leftWheel1, LOW);
  digitalWrite(leftWheel2, LOW);
  delay(2000);
// }
}
