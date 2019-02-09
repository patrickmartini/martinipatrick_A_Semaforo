int rossoSemaforo1 = 2;
int gialloSemaforo1 = 3;
int verdeSemaforo1 = 4;
int rossoSemaforo2 = 5;
int gialloSemaforo2 = 6;
int verdeSemaforo2 = 7;
int tempo;
int ripetizioni;
int durataVerde;
int durataGiallo;

void setup() {
  
  Serial.begin(9600);
  tempoVerde();
  tempoGiallo();
  tempoLampeggio();
  conteggioLampeggi();
  pinMode(rossoSemaforo1, OUTPUT);
  pinMode(gialloSemaforo1, OUTPUT);
  pinMode(verdeSemaforo1, OUTPUT);
  pinMode(rossoSemaforo2, OUTPUT);
  pinMode(gialloSemaforo2, OUTPUT);
  pinMode(verdeSemaforo2, OUTPUT);
}

void loop() {

  // accendo il rosso ed il verde dei due semafori,
  //mentre tengo spento il giallo del primo semaforo, 
  //ed il rosso ed il verde del secondo
  digitalWrite (rossoSemaforo2, LOW);
  digitalWrite (gialloSemaforo2, LOW);
  digitalWrite (gialloSemaforo1, LOW);
  digitalWrite (rossoSemaforo1, HIGH);
  digitalWrite (verdeSemaforo2, HIGH);
  delay(durataVerde);

  //accendo il giallo
  digitalWrite (gialloSemaforo1, HIGH);

  // faccio lampeggiare (tramite il metodo)
  //il verde del secondo semaforo
  lampeggio(verdeSemaforo2, tempo, ripetizioni);

  //accendo il giallo del secondo semaforo
  //usando il tempo che abbiamo indicato all'avvio del programma
  digitalWrite (gialloSemaforo2, HIGH);
  delay(durataGiallo);

  //accendo il verde del primo semaforo ed il rosso del secondo
  //mentre spengo il rosso ed il giallo del primo semaforo,
  //ed il giallo del secondo semaforo. IL verde usa il tempo
  //che abbiamo indicato all'avvio del programma
  digitalWrite (rossoSemaforo1, LOW);
  digitalWrite (gialloSemaforo1, LOW);
  digitalWrite (verdeSemaforo1, HIGH);
  digitalWrite (gialloSemaforo2, LOW);
  digitalWrite (rossoSemaforo2, HIGH);
  delay(durataVerde);

  //
  digitalWrite (gialloSemaforo2, HIGH);
  lampeggio(verdeSemaforo1, tempo, ripetizioni);
  digitalWrite (gialloSemaforo1, HIGH);
  delay(durataGiallo);
  
}

// durata di UN lampeggio
void tempoLampeggio(){
  Serial.println ("quanto vuoi far durare un lampeggio in millisecondi?");
  while(Serial.available() == 0) {};
  tempo = Serial.readString().toInt();
}

//numero dei lampeggi
void conteggioLampeggi(){
  Serial.println ("quante volte vuoi far lampeggiare il verde?");
  while(Serial.available() == 0) {};
  ripetizioni = Serial.readString().toInt();
}

//durata del verde
void tempoVerde(){
  Serial.println ("quanto vuoi far durare il verde in millisecondi?");
  while(Serial.available() == 0) {};
  durataVerde = Serial.readString().toInt();
}

//durata del giallo
void tempoGiallo(){
  Serial.println ("quanto vuoi far durare il giallo in millisecondi?");
  while(Serial.available() == 0) {};
  durataGiallo = Serial.readString().toInt();
}

//fa fare i lampeggi
void lampeggio(int led, int tempo, int ripetizioni) {
  for (int i = 0;i <= ripetizioni;i++)
  {
  digitalWrite (led,LOW);
  delay(tempo);
  digitalWrite (led,HIGH);
  delay(tempo);
  digitalWrite (led,LOW);
  }
}
