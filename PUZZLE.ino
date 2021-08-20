
// definition des PIN pour les capteurs de Hall (détecteurs d'aimant)
const int Hall1 = 11;
const int Hall2 = 10;
const int Hall3 = 12;
const int Hall4 = A0;
const int Hall5 = 8;
const int Hall6 = 7;
const int Hall7 = 2;
const int Hall8 = A3;
const int Hall9 = 6;
const int Hall10 = 9;
const int Hall11 = 5;
const int Hall12 = A4;
const int Hall13 = 3;
const int Hall14 = 4;
const int Hall15 = A1;
const int Hall16 = A5;


int total_puzzle; // nb pièces positionnées

// statut de chaque capteur
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

bool puzzle_status = false; // le puzzle est complété ou pas


void setup() {
  // setup Serial
  Serial.begin(9600);

  // setup all input PINS
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

  // Setup output for the lock relay
  pinMode(13, OUTPUT);
}

// the main loop of the program
void loop() {

  // read all sensors
  H1 = digitalRead(Hall1);
  H2 = digitalRead(Hall2);
  H3 = digitalRead(Hall3);
  H4 = digitalRead(Hall4);
  H5 = digitalRead(Hall5);
  H6 = digitalRead(Hall6);
  H7 = digitalRead(Hall7);
  H8 = digitalRead(Hall8);
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

  total_puzzle = (16 - (H1 + H2 + H3 + H4 + H5 + H6 + H7 + H8 + H9 + H10 + H11 + H12 + H13 + H14 + H15 + H16));
  Serial.print(" ");
  Serial.print("total_puzzle = ");
  Serial.println(total_puzzle );


  if (total_puzzle >= 16) {
    Serial.println("BRAVO");

    if (!puzzle_status) { // Ouvre la porte seulement une fois lorsque le puzzle est fini

      // Open the lock relay
      digitalWrite(13, HIGH);

      // wait 3 sec, not too long so that the lock does not heat
      delay(3000);

      // Close the lock relay
      digitalWrite(13, LOW);

      // sauvegarde l'état "fini" du puzzle
      puzzle_status = true;

    }

  } else {
    Serial.println("ENCORE UN EFFORT");

    // Let the relay closed
    digitalWrite(13, LOW);

    // sauvegarde l'état "pas fini" du puzzle
    puzzle_status = false;

  }


  Serial.println();
  Serial.println("xxxxxxxxxxxxxxxxxxxxx");

  Serial.println();

  // wait 2 sec
  delay(2000);

}
