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
  mEmenu21line2
};
//Funktio joka piirtää yhden rivin valikkoon
void menu21line1(int row){
  lcd.setCursor(1,0);
  lcd.print("Menu 21 Line 1 param: ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu21line1{
  &menu21line1,
  MenuA0
};
//Valikko MenuA0
menuElement MenuA0[]={
  mEmenuA0,
  mEbackToMenu21
};
//Funktio joka piirtää yhden rivin valikkoon
void menuA0(int row)                    // Esimerkki valikkosisältö
{                                       // 
          lcd.clear();                  // pyyhkii näytön
          lcd.setCursor(1,0);           // asettaa merkin lähdön kohtaan 1 riville 0
          lcd.print("A0 ");             // tulostaa tekstin A0
          lcd.setCursor(5,0);           // asettaa merkin lähdön kohtaan 5 riville 0
          lcd.print(analogRead(A0));    // tulostaa saadun lukeman A1 pinniltä
          lcd.setCursor(15,0);          // asettaa merkin lähdön paikkaan 15 riville 0
          lcd.write(byte(0));           // piirtää biteillä luodun merkin paikalta 0
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA0{
  &menuA0,
  MenuA1
};
//Valikko MenuA1
menuElement MenuA1[]={
 mEmenuA1,
 mEbackToMenu21
};
//Funktio joka piirtää yhden rivin valikkoon          
void menuA1(int row)                    // Esimerkki valikkosisältö
{                                       //
          lcd.clear();                  // pyyhkii näytön
          lcd.setCursor(1,0);           // asettaa merkin lähdön kohtaan 1 riville 0
          lcd.print("A1 ");             // tulostaa tekstin A1
          lcd.setCursor(5,0);           // asettaa merkin lähdön kohtaan 5 riville 0
          lcd.print(analogRead(A1));    // tulostaa saadun lukeman A1 pinniltä
          lcd.setCursor(15,0);          // asettaa merkin lähdön paikkaan 15 riville 0
          lcd.write(byte(0));           // piirtää biteillä luodun merkin paikalta 0
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA1{
  &menuA1,
  MenuA2
};
//Valikko MenuA2
menuElement MenuA2[]={
 mEmenuA2,
 mEbackToMenu21
};
//Funktio joka piirtää yhden rivin valikkoon
void menuA2(int row)                    // Esimerkki valikkosisältö
{                                       //
          lcd.clear();                  // pyyhkii näytön
          lcd.setCursor(1,0);           // asettaa merkin lähdön kohtaan 1 riville 0
          lcd.print("A2 ");             // tulostaa tekstin A2
          lcd.setCursor(5,0);           // asettaa merkin lähdön kohtaan 5 riville 0
          lcd.print(analogRead(A2));    // tulostaa saadun lukeman A2 pinniltä
          lcd.setCursor(15,0);          // asettaa merkin lähdön paikkaan 15 riville 0
          lcd.write(byte(0));           // piirtää biteillä luodun merkin paikalta 0
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA2{
  &menuA2,
  MenuA3
};
//Valikko MenuA3
menuElement MenuA3[]={
 mEmenuA3,
 mEbackToMenu21
};
//Funktio joka piirtää yhden rivin valikkoon           
void menuA3(int row)                  // Esimerkki valikkosisältö
{                                     //
          lcd.clear();                // pyyhkii näytön
          lcd.setCursor(1,0);         // asettaa merkin lähdön kohtaan 1 riville 0
          lcd.print("A3 ");           // tulostaa tekstin A3
          lcd.setCursor(5,0);         // asettaa merkin lähdön kohtaan 5 riville 0
          lcd.print(analogRead(A3));  // tulostaa saadun lukeman A3 pinniltä
          lcd.setCursor(15,0);        // asettaa merkin lähdön paikkaan 15 riville 0
          lcd.write(byte(0));         // piirtää biteillä luodun merkin paikalta 0
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
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu21line2{
  &menu21line2,
  MenubackLightOff
};
//Valikko MenubackLightOff
menuElement MenubackLightOff[]={
  mEmenubackLightOff,
  mEbackToMenu21
};
//Funktio joka piirtää yhden rivin valikkoon
void menubackLightOff(int row)        // Esimerkki valikkosisältö
{                                     //
  lcd.clear();                        // pyyhkii näytön
  lcd.setCursor(1,0);                 // asettaa merkin lähdön kohtaan 1 riville 0
  lcd.print("LCDLight ");             // tulostaa tekstin LCDLight
  lcd.setCursor(11,0);                // asettaa merkin lähdön kohtaan 11 riville 0
  lcd.print(" OFF");                  // tulostaa tekstin OFF
  pinMode(LCDLight, OUTPUT);          // Määritellään pinni, LCDLight lähdöksi
  digitalWrite(LCDLight, LOW);        // sammuttaa lcd näytön taustavalon
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon  
menuElement mEmenubackLightOff{
  &menubackLightOff,
  MenubackLightOn
};
//Valikko MenubackLightOn
menuElement MenubackLightOn[]={
 mEmenubackLightOn,
 mEbackToMenu21
};
//Funktio joka piirtää yhden rivin valikkoon
void menubackLightOn(int row)       // Esimerkki valikko sisältö
{                                   //
  lcd.clear();                      // pyyhkii näytön
  lcd.setCursor(1,0);               // asettaa merkin lähdön kohtaan 1 riville 
  lcd.print("LCDLight ");           // tulostaa tekstin LCDLight
  lcd.setCursor(11,0);              // asettaa merkin lähdön kohtaan 11 riville 0
  lcd.print(" ON");                 // tulostaa tekstin ON
  pinMode(LCDLight, OUTPUT);        // Määritellään pinni, LCDLight lähdöksi
  digitalWrite(LCDLight, HIGH);     // sytyttää lcd näytön taustavalon
}                                   //
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
  mEmenu22line2
}; 
//Funktio joka piirtää yhden rivin valikkoon
void menu22line1(int row){
  lcd.setCursor(1,0);
  lcd.print("Menu 22 Line 1 param: ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22line1{
  &menu22line1,
  MenuDigitalPinsLow
};

//Valikko MenuDigitalPins
menuElement MenuDigitalPinsLow[]={
  mEmenuDigitalPinsLow,
  mEbackToMenu22
};
//Funktio joka piirtää yhden rivin valikkoon
void menuDigitalPinsLow(int row){     // Esimerkki valikkosisältö
          lcd.clear();                // Pyyhkii näytön
          lcd.setCursor(1,0);         // asettaa merkin lähdön kohtaan 1 riville 
          lcd.print("D_Pins ");       // tulostaa tekstin D_Pins
          lcd.setCursor(10,0);        // asettaa merkin lähdön kohtaan 10 riville 
          lcd.print(" LOW");          // tulostaa tekstin LOW
          pinMode(D0,OUTPUT);         // Määritellään pinni
          digitalWrite(D0, LOW);      // 
          pinMode(D1,OUTPUT);         // Määritellään pinni
          digitalWrite(D1, LOW);      //
          pinMode(D2,OUTPUT);         // Määritellään pinni
          digitalWrite(D2, LOW);      //
          pinMode(D3,OUTPUT);         // Määritellään pinni
          digitalWrite(D3, LOW);      //
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon  
menuElement mEmenuDigitalPinsLow{
  &menuDigitalPinsLow,
  MenuDigitalPinsHigh
};
//Valikko MenuD0High
menuElement MenuDigitalPinsHigh[]={
 mEmenuDigitalPinsHigh,
 mEbackToMenu22
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuDigitalPinsHigh(int row){      // Esimerkki valikkosisältö
          lcd.clear();                  // Pyyhkii näytön
          lcd.setCursor(1,0);           // asettaa merkin lähdön kohtaan 1 rivill
          lcd.print("D_Pins ");         // tulostaa tekstin D_Pins
          lcd.setCursor(10,0);          // asettaa merkin lähdön kohtaan 10 riville
          lcd.print(" HIGH");           // tulostaa tekstin HIGH
          pinMode(D0,OUTPUT);           // Määritellään pinni
          digitalWrite(D0, HIGH);       //
          pinMode(D1,OUTPUT);           // Määritellään pinni
          digitalWrite(D1, HIGH);       //
          pinMode(D2,OUTPUT);           // Määritellään pinni
          digitalWrite(D2, HIGH);       //
          pinMode(D3,OUTPUT);           // Määritellään pinni
          digitalWrite(D3, HIGH);       //
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuDigitalPinsHigh{
  &menuDigitalPinsHigh,
  MenuDigitalPinsLow
};
  
//Funktio joka piirtää yhden rivin valikkoon
void menu22line2(int row){
  lcd.setCursor(1,1);
  lcd.print("Menu 22 Line 2 param: ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22line2{
  &menu22line2,
  MenuRitari1
};
//Valikko MenuRitari
menuElement MenuRitari1[]={
  mEmenuRitari1,
  mEbackToMenu22
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuRitari1(int row){          // Esimerkki valikkosisältö
          lcd.clear();              // pyyhkii näytön
          lcd.setCursor(1,0);       // asettaa merkin lähdön kohtaan 1 riville
          lcd.print("RitariAssa "); // tulostaa tekstin RitariAssa
          lcd.setCursor(12,0);      // asettaa merkin lähdön kohtaan 12 riville
          lcd.print(" OFF");        // tulostaa tekstin OFF
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuRitari1{
  &menuRitari1,
  MenuRitari2
};
//Valikko MenuRitari2
menuElement MenuRitari2[]={
  mEmenuRitari2,
  mEbackToMenu22
};
//Funktio joka piirtää yhden rivin valikkoon  
void menuRitari2(int row){
  int VIIVE=60;                     // Esimerkki valikkosisältö
          lcd.clear();              //
          lcd.setCursor(1,0);       // 
          lcd.print("RitariAssa "); //
          lcd.setCursor(12,0);      //
          lcd.print(" ON");         //
for(int i=0; i<20; i++){            //
          pinMode(D0,OUTPUT);       //
          digitalWrite(D0, HIGH);   //
          delay(VIIVE);             //
          digitalWrite(D0, LOW);    //
          pinMode(D1,OUTPUT);       //
          digitalWrite(D1, HIGH);   //
          delay(VIIVE);             //
          digitalWrite(D1, LOW);    //
          pinMode(D2,OUTPUT);       //
          digitalWrite(D2, HIGH);   //
          delay(VIIVE);             //
          digitalWrite(D2, LOW);    //
          pinMode(D3,OUTPUT);       //
          digitalWrite(D3, HIGH);   //
          delay(VIIVE);             //
          digitalWrite(D3, LOW);    //
          digitalWrite(D2,HIGH);    //
          delay(VIIVE);             //
          digitalWrite(D2, LOW);    //
          digitalWrite(D1, HIGH);   //
          delay(VIIVE);             //
          digitalWrite(D1, LOW);    //
}                                   //
          MenuRitari1;              //
}                                   //
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuRitari2{
  &menuRitari2,
  MenuRitari1
};
/*
 * paluu valikkoon Menu21
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu21(int row){
  lcd.setCursor(1,1);
  lcd.print("Edellinen ");
}
//struct jossa tekstin luonti ja linkki edelliseen valikkoon 21
menuElement mEbackToMenu21{
  &backToMenu21,
  Menu21
  };
/*
 * paluu valikkoon Menu22
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu22(int row){
  lcd.setCursor(1,1);
  lcd.print("Edellinen ");
  }
  
//struct jossa tekstin luonti ja linkki edelliseen valikkoon 22
menuElement mEbackToMenu22{
  &backToMenu22,
  Menu22
  };
/*
 * paluu valikkoon Menu1
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu1(int row){
  lcd.setCursor(1,1);
  lcd.print("Back to main ");
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu1{
  &backToMenu1,
  Menu1
  };
