int ECHO = 2;  //recetor do sensor ultrasónico
int TRIGGER = 4;  //emisor do sensor ultrasónico
int VIBRA = 6;  //AVISO - motor vibratório
int BUZZER = 8;  //AVISO - sinal sonoro
int BATERIA = 5;  //para sinalização de bateria fraca
int frequencia;
float valor; 
float voltagem;
long duracao;
float distancia;
float lista[10] = {};
int contagem;
float somatorio;
float somatorio1;
int i;
float media;



void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(VIBRA, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);  //velocidade de comunicação do Arduino com o computador
  

  //código para a sinalização de bateria fraca
  valor = analogRead(BATERIA);  //lê o valor em A5
  voltagem = valor * (5.00 / 1023.00) * 2;  //converção do valor em voltagem

  
  //caso não tenha bateria suficiente: 3 vezes sinal vibratório e sonoro, só depois pode começar usar/andar, mas atenão para trocar a pilha
  //caso tenha bateria suficiente: aguardar 3 segundos pelos testes: 1 - vibração, 2 - sonoro, 3 - ambos, para confirmação do bom funcionamento, só depois pode começar usar/andar
  if (voltagem < 7) {  //o arduino começa a trabalhar perto dos 4.5V, então asseguramos ainda tem alguma bateria, mínimo requesitado no datasheet
    frequencia = 700;
    for (i = 0; i < 5; i++) {
      tone(BUZZER, frequencia);
      delay(200);
      noTone(BUZZER);
      delay(200);
      frequencia = frequencia - 130;     
    }  
  }
  else {
    digitalWrite(VIBRA, HIGH);
    delay(1000);
    digitalWrite(VIBRA, LOW);
    delay(500);
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
    delay(500);
    digitalWrite(VIBRA, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(VIBRA, LOW);
    digitalWrite(BUZZER, LOW);
  }

 
  
  //confirmação dos digitais do sensor a 0
  digitalWrite(TRIGGER, LOW);
  digitalWrite(VIBRA, LOW);  
  
  
  contagem = 0;
  somatorio = 0;
  somatorio1 = 0;
  media = 0;
}



void loop() {
//medição da distância do sensor até ao objeto:
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  duracao = pulseIn(ECHO, HIGH);
  if (duracao < 100000) {
    distancia = duracao * 0.034 / 2;
  }
  Serial.println(distancia);
  


//fazer a média dos últimos 10 valores
  if (contagem < 10) {  //até aos primeiros 10 elementos da lista
    lista[contagem] = distancia;
    somatorio1 = somatorio1 + distancia;
    media = somatorio1 / (contagem + 1);
  }
  else {
    for (i = 0; i < 9; i++) {
      lista[i] = lista[i + 1];
      lista[9] = distancia;
      somatorio = somatorio + lista[i];
    }
    somatorio = somatorio + lista[9];
    media = somatorio / 10;
    somatorio = 0;
  }
  contagem = contagem + 1;


  //códigos de avisos para o utilizador:
  //para variações de distâncias bruscas
  //variações de 10 cm abaixo e acima do valor médio das últimas 10 medições
  if (distancia > 20 and distancia < (media - 15) or distancia > (media + 15)) {
    for (i = 0; i < 2; i++) {
      digitalWrite(VIBRA, HIGH);
      digitalWrite(BUZZER, HIGH);
      delay(100);
      digitalWrite(VIBRA, LOW);
      digitalWrite(BUZZER, LOW);
      delay(100);
    }  
  }
  else {
    //quanto mais perto mais vibra, do tipo, sensores de parque de estacionamento
    if (distancia <= 20) {
      digitalWrite(VIBRA, HIGH);
      digitalWrite(BUZZER, HIGH);
    }
    else if (distancia > 20 and distancia <= 150) {
      digitalWrite(BUZZER, LOW);
      digitalWrite(VIBRA, HIGH);
      delay(500);
      digitalWrite(VIBRA, LOW);
      delay(5 * distancia);
    }
    else if (distancia > 150 and distancia <= 300) {
      digitalWrite(BUZZER, LOW);
      digitalWrite(VIBRA, HIGH);
      delay(500);
      digitalWrite(VIBRA, LOW);
      delay(1000);
    }
    else  {
      digitalWrite(VIBRA, LOW);
      digitalWrite(BUZZER, LOW);
    }
  }
}
