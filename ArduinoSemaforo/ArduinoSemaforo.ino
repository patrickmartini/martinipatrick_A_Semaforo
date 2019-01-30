int rosso = 1;
int giallo = 2;
int verde = 3;
int rosso_ = 4;
int giallo_ = 5;
int verde_ = 6;
int tempo = 100;

void lampeggia_(int tempo) {
  digitalWrite (verde_,LOW);
  delay(tempo);
  digitalWrite (verde_,HIGH);
  delay(tempo);
  digitalWrite (verde_,LOW);
  delay(tempo);
  digitalWrite (verde_,HIGH);
  delay(tempo);
  digitalWrite (verde_,LOW);
  delay(tempo);
  digitalWrite (verde_,HIGH);
  delay(tempo);
  digitalWrite (verde_,LOW);
  delay(tempo);
}

void lampeggia(int tempo){
  digitalWrite (verde,LOW);
  delay(tempo);
  digitalWrite (verde,HIGH);
  delay(tempo);
  digitalWrite (verde,LOW);
  delay(tempo);
  digitalWrite (verde,HIGH);
  delay(tempo);
  digitalWrite (verde,LOW);
  delay(tempo);
  digitalWrite (verde,HIGH);
  delay(tempo);
  digitalWrite (verde,LOW);
  delay(tempo);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(rosso, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rosso_, OUTPUT);
  pinMode(giallo_, OUTPUT);
  pinMode(verde_, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (rosso_, LOW);
  digitalWrite (giallo_, LOW);
  digitalWrite (rosso, HIGH);
  digitalWrite (verde_, HIGH);
  delay(4600);

  digitalWrite (giallo, HIGH);
  digitalWrite (giallo_, HIGH);
  lampeggia_(tempo);

  digitalWrite (rosso, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (verde, HIGH);
  digitalWrite (rosso_, HIGH);
  delay(4600);
  
  lampeggia(tempo);
  digitalWrite (giallo, HIGH);
  delay(5000);
  
}

//prova gitkraken
