#include <Arduino.h>
#include "menuElement.h"
/*
 * Menu1
 */
//Valikko Menu1
menuElement Menu1[]={
  mEmenu1line1,
  mEmenu1line2
}; 
//Funktio joka piirtää yhden rivin valikkoon
void menu1line1(int row){
  lcd.setCursor(1,0);
  lcd.print("Menu 1 Line 1 param: ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu1line1{
  &menu1line1,
  Menu21
};
//Funktio joka piirtää yhden rivin valikkoon
void menu1line2(int row){
  lcd.setCursor(1,1);
  lcd.print("Menu 1 Line 2 param: ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu1line2{
  &menu1line2,
  Menu22
};
/*
 * Menu21
 */
//Valikko Menu21
menuElement Menu21[]={
  mEmenu21line1,
  mEmenu21line2,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon
void menu21line1(int row){
  lcd.setCursor(1,0);
  lcd.print("Menu 21 Line 1 param: ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu21line1{
  &menu21line1,
  MenuA0
};
//Valikko MenuA0
menuElement MenuA0[]={
  mEmenuA0,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon
void menuA0(int row) {
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("A0 ");
          lcd.setCursor(5,0);
          lcd.print(analogRead(A0));
          lcd.setCursor(15,0);
          lcd.write(byte(0));
          Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA0{
  &menuA0,
  MenuA1
};
//Valikko MenuA1
menuElement MenuA1[]={
 mEmenuA1,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon          
void menuA1(int row){      
          lcd.clear();   
          lcd.setCursor(1,0);
          lcd.print("A1 ");
          lcd.setCursor(5,0);
          lcd.print(analogRead(A1));
          lcd.setCursor(15,0);
          lcd.write(byte(0));
          Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA1{
  &menuA1,
  MenuA2
};
//Valikko MenuA2
menuElement MenuA2[]={
 mEmenuA2,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon
void menuA2(int row){                    
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("A2 ");
          lcd.setCursor(5,0);
          lcd.print(analogRead(A2));
          lcd.setCursor(15,0);
          lcd.write(byte(0));
          Serial.println(row);     
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA2{
  &menuA2,
  MenuA3
};
//Valikko MenuA3
menuElement MenuA3[]={
 mEmenuA3,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon           
void menuA3(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("A3 ");
          lcd.setCursor(5,0);
          lcd.print(analogRead(A3));
          lcd.setCursor(15,0);
          lcd.write(byte(0));
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA3{
  &menuA3,
  MenuA0
}; 
//Funktio joka piirtää yhden rivin valikkoon
void menu21line2(int row){
  lcd.setCursor(1,1);
  lcd.print("Menu 21 Line 2 param: ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu21line2{
  &menu21line2,
  MenubackLightOff
};
//Valikko MenubackLightOff
menuElement MenubackLightOff[]={
  mEmenubackLightOff,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon
void menubackLightOff(int row)
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("LCDLight ");
  lcd.setCursor(11,0);
  lcd.print(" OFF");
  pinMode(LCDLight, OUTPUT);
  digitalWrite(LCDLight, LOW);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon  
menuElement mEmenubackLightOff{
  &menubackLightOff,
  MenubackLightOn
};
//Valikko MenubackLightOn
menuElement MenubackLightOn[]={
 mEmenubackLightOn,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon
void menubackLightOn(int row) 
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("LCDLight ");
  lcd.setCursor(11,0);
  lcd.print(" ON");
  pinMode(LCDLight, OUTPUT);
  digitalWrite(LCDLight, HIGH);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenubackLightOn{
  &menubackLightOn,
  MenubackLightOff
};
/*
 * Menu22
 */
//Valikko Menu22
menuElement Menu22[]={
  mEmenu22line1,
  mEmenu22line2,
  mEbackToMenu1
}; 
//Funktio joka piirtää yhden rivin valikkoon
void menu22line1(int row){
  lcd.setCursor(1,0);
  lcd.print("Menu 22 Line 1 param: ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22line1{
  &menu22line1,
  MenuD0Low
};
/*
 * TODO menu jonka sisällä kaikki digital elementit
 */
/*menuElement MenuDigital[]={
  mEmenuD0Low,
  mEmenuD1Low,
  mEmenuD2Low,
  mEmenuD3Low,
  mEbackToMenu1
};*/
//Valikko MenuD0Low
menuElement MenuD0Low[]={
  mEmenuD0Low,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon
void menuD0Low(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D0 ");
          lcd.setCursor(10,0);
          lcd.print(" LOW");
          pinMode(D0,OUTPUT);
          digitalWrite(D0, LOW);
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon  
menuElement mEmenuD0Low{
  &menuD0Low,
  MenuD0High
};
//Valikko MenuD0High
menuElement MenuD0High[]={
 mEmenuD0High,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuD0High(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D0 ");
          lcd.setCursor(10,0);
          lcd.print(" HIGH");
          pinMode(D0,OUTPUT);
          digitalWrite(D0, HIGH);
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD0High{
  &menuD0High,
  MenuD0Low
};
//Valikko MenuD1Low
menuElement MenuD1Low[]={
  mEmenuD1Low,
  mEbackToMenu1
};  
//Funktio joka piirtää yhden rivin valikkoon
void menuD1Low(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D1 ");
          lcd.setCursor(10,0);
          lcd.print(" LOW");
          digitalWrite(D1, LOW);
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD1Low{
  &menuD1Low,
  MenuD1High
};  
//Valikko MenuD1High
menuElement MenuD1High[]={
 mEmenuD1High,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuD1High(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D1 ");
          lcd.setCursor(10,0);
          lcd.print(" HIGH");
          pinMode(D1,OUTPUT);
          digitalWrite(D1, HIGH);
          Serial.println(row);
  }  
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD1High{
  &menuD1High,
  MenuD1Low
};
//Valikko MenuD2Low
menuElement MenuD2Low[]={
  mEmenuD2Low,
  mEbackToMenu1
};  
//Funktio joka piirtää yhden rivin valikkoon  
  void menuD2Low(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D2 ");
          lcd.setCursor(10,0);
          lcd.print(" LOW");
          digitalWrite(D2, LOW);
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD2Low{
  &menuD2Low,
  MenuD2High
};
//Valikko MenuD2High
menuElement MenuD2High[]={
 mEmenuD2High,
 mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuD2High(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D2 ");
          lcd.setCursor(10,0);
          lcd.print(" HIGH");
          pinMode(D2,OUTPUT);
          digitalWrite(D2, HIGH);
          Serial.println(row);
  }

//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD2High{
  &menuD2High,
  MenuD2Low
};
//Valikko MenuD3Low
menuElement MenuD3Low[]={
  mEmenuD3Low,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon  
  void menuD3Low(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D3 ");
          lcd.setCursor(10,0);
          lcd.print(" LOW");
          digitalWrite(D3, LOW);
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD3Low{
  &menuD3Low,
  MenuD3High
};
//Valikko MenuD3High
menuElement MenuD3High[]={
 mEmenuD3High,
 mEbackToMenu1
}; 
//Funktio joka piirtää yhden rivin valikkoon  
void menuD3High(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("D3 ");
          lcd.setCursor(10,0);
          lcd.print(" HIGH");
          pinMode(D3,OUTPUT);
          digitalWrite(D3, HIGH);
          Serial.println(row);
  }      
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuD3High{
  &menuD3High,
  MenuD3Low
};

//Funktio joka piirtää yhden rivin valikkoon
void menu22line2(int row){
  lcd.setCursor(1,1);
  lcd.print("Menu 22 Line 2 param: ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22line2{
  &menu22line2,
  MenuRitari1
};
//Valikko MenuRitari
menuElement MenuRitari1[]={
  mEmenuRitari1,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuRitari1(int row){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("RitariAssa ");
          lcd.setCursor(12,0);
          lcd.print(" OFF");
          Serial.println(row);
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuRitari1{
  &menuRitari1,
  MenuRitari2
};
//Valikko MenuRitari2
menuElement MenuRitari2[]={
  mEmenuRitari2,
  mEbackToMenu1
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuRitari2(int row){
  int VIIVE=70;
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("RitariAssa ");
          lcd.setCursor(12,0);
          lcd.print(" ON");
/*for(int i=0; i<20; i++){         
          pinMode(D0,OUTPUT);
          digitalWrite(D0, HIGH);
          delay(VIIVE);
          digitalWrite(D0, LOW);
          pinMode(D1,OUTPUT);
          digitalWrite(D1, HIGH);
          delay(VIIVE);
          digitalWrite(D1, LOW);
          pinMode(D2,OUTPUT);
          digitalWrite(D2, HIGH);
          delay(VIIVE);
          digitalWrite(D2, LOW);
          pinMode(D3,OUTPUT);
          digitalWrite(D3, HIGH);
          delay(VIIVE);
          digitalWrite(D3, LOW);
          digitalWrite(D2,HIGH);
          delay(VIIVE);
          digitalWrite(D2, LOW);
          digitalWrite(D1, HIGH);
          delay(VIIVE);
          digitalWrite(D1, LOW);
}
          MenuRitari1;*/
          Serial.println(row);
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuRitari2{
  &menuRitari2,
  MenuRitari1
};
/*
 * paluu valikkoon Menu1
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu1(int row){
  lcd.setCursor(1,1);
  lcd.print("Back to main ");
  Serial.println(row);
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu1{
  &backToMenu1,
  Menu1
  };
