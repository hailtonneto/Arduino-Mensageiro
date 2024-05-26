#include <LiquidCrystal.h>

#define ESQUERDA 2
#define CIMA 3
#define DIREITA 4
#define BAIXO 5

int letraAtual = 65;
int coluna = 0;
int linha = 0;

// LiquidCrystal lcd(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup(){
  pinMode(CIMA, INPUT_PULLUP);
  pinMode(BAIXO, INPUT_PULLUP);
  pinMode(ESQUERDA, INPUT_PULLUP);
  pinMode(DIREITA, INPUT_PULLUP);
  
  // lcd.begin(Colunas, Linhas)
  lcd.begin(16, 2);
  
  lcd.blink();
  lcd.write(letraAtual);
  lcd.setCursor(coluna, linha);
}

void paraCima(){
  if(letraAtual < 90){
    letraAtual++;
  }
  lcd.write(letraAtual);
  lcd.setCursor(coluna % 16, linha);
}

void paraBaixo(){
  if(letraAtual > 65){
    letraAtual--;
  }
  lcd.write(letraAtual);
  lcd.setCursor(coluna % 16, linha);
}

void loop(){
  while(digitalRead(CIMA) == 0){
    paraCima();
    delay(500);
  }
  
  while(digitalRead(BAIXO) == 0){
    paraBaixo();
    delay(500);
  }
  
  while(digitalRead(DIREITA) == 0){
    coluna++;
    if(coluna > 15){
      linha = 1;
    }
    lcd.setCursor(coluna % 16, linha);
    delay(500);
  }
  
  while(digitalRead(ESQUERDA) == 0){
    if(coluna > 0){
      coluna--;
    }
    if(coluna < 16){
      linha = 0;
    }
    lcd.setCursor(coluna % 16, linha);
    delay(500);
  }
}