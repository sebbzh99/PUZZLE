const int Hall1 = 10; //ok physical
const int Hall2 = 11; //ok physical
const int Hall3 = 12; //ok physical
const int Hall4 = A0; //ok physical
const int Hall5 = 6; //ok physical
const int Hall6 = 8; //ok physical
const int Hall7 = 9; //ok physical
const int Hall8 = A7;  //ok physical - NOT DETECTED
const int Hall9 = 7; //ok physical
const int Hall10 = 5;  //ok physical
const int Hall11 = 4;  //ok physical
const int Hall12 = A4;  //ok physical
const int Hall13 = 0;   //ok physical
const int Hall14 = 2;  //ok physical
const int Hall15 = A1;  //ok physical
const int Hall16 = A5;  //ok physical


int total_puzzle;

int H1;
int H2;
int H3;
int H4;
int H5;
int H6;
int H7;
int H8;
int H9;
int H10;
int H11;
int H12;
int H13;
int H14;
int H15;
int H16;




void setup() {
  Serial.begin(9600);
  pinMode(Hall1, INPUT_PULLUP);
  pinMode(Hall2, INPUT_PULLUP);
  pinMode(Hall3, INPUT_PULLUP);
  pinMode(Hall4, INPUT_PULLUP);
  pinMode(Hall5, INPUT_PULLUP);
  pinMode(Hall6, INPUT_PULLUP);
  pinMode(Hall7, INPUT_PULLUP);
  pinMode(Hall8, INPUT_PULLUP);
  pinMode(Hall9, INPUT_PULLUP);
  pinMode(Hall10, INPUT_PULLUP);
  pinMode(Hall11, INPUT_PULLUP);
  pinMode(Hall12, INPUT_PULLUP);
  pinMode(Hall13, INPUT_PULLUP);
  pinMode(Hall14, INPUT_PULLUP);
  pinMode(Hall15, INPUT_PULLUP);
  pinMode(Hall16, INPUT_PULLUP);

  pinMode(A3, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  H1 = digitalRead(Hall1);
  H2 = digitalRead(Hall2);
  H3 = digitalRead(Hall3);
  H4 = digitalRead(Hall4);
  H5 = digitalRead(Hall5);
  H6 = digitalRead(Hall6);
  H7 = digitalRead(Hall7);
  H8 = 0;
  H9 = digitalRead(Hall9);
  H10 = digitalRead(Hall10);
  H11 = digitalRead(Hall11);
  H12 = digitalRead(Hall12);
  H13 = digitalRead(Hall13);
  H14 = digitalRead(Hall14);
  H15 = digitalRead(Hall15);
  H16 = digitalRead(Hall16);


  Serial.print("H_1 = ");
  Serial.println(H1);

  Serial.print("H_2 = ");
  Serial.println(H2);

  Serial.print("H_3 = ");
  Serial.println(H3);

  Serial.print("H_4 = ");
  Serial.println(H4);


  Serial.print("H_5 = ");
  Serial.println(H5);

  Serial.print("H_6 = ");
  Serial.println(H6);

  Serial.print("H_7 = ");
  Serial.println(H7);

  Serial.print("H_8 = ");
  Serial.println(H8);


  Serial.print("H_9 = ");
  Serial.println(H9);

  Serial.print("H_10 = ");
  Serial.println(H10);

  Serial.print("H_11 = ");
  Serial.println(H11);

  Serial.print("H_12 = ");
  Serial.println(H12);

  Serial.print("H_13 = ");
  Serial.println(H13);

  Serial.print("H_14 = ");
  Serial.println(H14);

  Serial.print("H_15 = ");
  Serial.println(H15);

  Serial.print("H_16 = ");
  Serial.println(H16);

  total_puzzle = (H1 + H2 + H3 + H4 + H5 + H6 + H7 + H8 + H9 + H10 + H11 + H12 + H13 + H14 + H15 + H16);
  Serial.print(" ");
  Serial.print("total_puzzle =");
  Serial.println(total_puzzle );

  if (total_puzzle <= 0) {
    Serial.println("BRAVO");
    digitalWrite(13, HIGH);
    analogWrite(A3, 200);
  } else {
    Serial.println("ENCORE UN EFFORT");
    digitalWrite(13, LOW);
    analogWrite(A3, 0);
  }



  Serial.println();
  Serial.println("xxxxxxxxxxxxxxxxxxxxx");

  Serial.println();

  delay(2000);
}
