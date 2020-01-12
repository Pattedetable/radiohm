
// Pin des capteurs
int VCAPTEUR = A0;
int VRESISTANCE = A5;

// Acquisitions par seconde
int nbParSeconde = 100;
int temps;
int nbmoy = 50;

float potCapteur;
float potResistance;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  pinMode(VCAPTEUR, INPUT);
  pinMode(VRESISTANCE, INPUT);
}

void loop() {
  potCapteur = 0.0;
  potResistance = 0.0;
  for (int i = 0; i < nbmoy; i++){
    potCapteur += analogRead(VCAPTEUR);
    potResistance += analogRead(VRESISTANCE);
  }

  potCapteur = potCapteur/nbmoy;
  potResistance = potResistance/nbmoy;
  
  Serial.print(potResistance);
  Serial.print(" ");
  Serial.println(potCapteur);
  temps = 1000/nbParSeconde;
  delay(temps);
  
}
