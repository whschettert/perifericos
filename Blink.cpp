/* 
* Inicializacao dos leds referentes aos pinos PB da GertBoard
* Inicializao das demais variaveis utilizadas
*/
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int countP1 = 0;
int countP2 = 0;
int inByte = 0;
int curPattern = 1;  

// the setup routine runs once when you press reset:
void setup() {                
  
  /* Inicializa a porta serial em 9600 bytes/s */ 
  Serial.begin(9600); 
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);     
  pinMode(led3, OUTPUT);     
  pinMode(led4, OUTPUT);       
  pinMode(led5, OUTPUT);       
}

void pattern1(){
  digitalWrite(led1, HIGH);   
  delay(125);  
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(125);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(125);
  digitalWrite(led3, LOW);    
  digitalWrite(led4, HIGH);
  delay(125);               
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(125);  
  digitalWrite(led5, LOW);
}

void pattern2(){
  digitalWrite(led5, HIGH);   
  delay(125);  
  digitalWrite(led5, LOW);
  digitalWrite(led4, HIGH);
  delay(125);
  digitalWrite(led4, LOW);
  digitalWrite(led3, HIGH);
  delay(125);
  digitalWrite(led3, LOW);    
  digitalWrite(led2, HIGH);
  delay(125);               
  digitalWrite(led2, LOW);
  digitalWrite(led1, HIGH);
  delay(125);  
  digitalWrite(led1, LOW);
}


// the loop routine runs over and over again forever:
void loop() {
  
  if (Serial.available()) { 
    /* Le byte da serial */ 
    inByte = Serial.read(); 

    /* Troca os padroes */    
    if (inByte == 'a'){
      curPattern = 2;
      countP2++;  
    }
    if (inByte == 'b'){
      curPattern = 1;
      countP1++;      
    }    
    if (inByte == 'c'){
      Serial.print(countP1);
      Serial.print(countP2);  
    }
 
  }
  
  // Deixa os padroes em loop ate que sejam trocados
  // Isto nao incrementa os contadores
  switch (curPattern){
    case 1: pattern1();
            break;
    case 2: pattern2();
            break;    
  }  
  
}