#include <Arduino.h>
#include "menuElement.h"
/*
 * Menu1
 */
//Valikko Menu1
menuElement Menu1[]={
  mEmenu1rivi1,
  mEmenu1rivi2,
  mEmenu1rivi3,
  mEmenu1rivi4,
  mENULL
}; 
// Tyhjä valikko rivi pysäyttämään
menuElement mENULL{
  NULL,
  NULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menu1rivi1(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 1 rivi 1 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu1rivi1{
  &menu1rivi1,
  Menu21
};
//Funktio joka piirtää yhden rivin valikkoon
void menu1rivi2(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 1 rivi 2 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu1rivi2{
  &menu1rivi2,
  Menu22
};
//Funktio joka piirtää yhden rivin valikkoon
void menu1rivi3(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 1 rivi 3 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu1rivi3{
  &menu1rivi3,
  Menu23
};
//Funktio joka piirtää yhden rivin valikkoon
void menu1rivi4(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 1 rivi 4 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu1rivi4{
  &menu1rivi4,
  Menu24
};
/*
 * Menu21
 */
//Valikko Menu21
menuElement Menu21[]={
  mEmenu21rivi1,
  mEmenu21rivi2,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menu21rivi1(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 21 rivi 1 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu21rivi1{
  &menu21rivi1,
  MenuA0
};
// Esimerkkisisältö Valikko MenuA0, painattaessa vaihtaa analog pinnin lukemaan seuraavaa A0->A1->A2->A3->A0 jne
menuElement MenuA0[]={
  mEmenuA0,
  mEbackToMenu21,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menuA0(int row) {
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("A0 ");
          lcd.setCursor(5,row);
          lcd.print(analogRead(A0));
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA0{
  &menuA0,
  MenuA1
};
//Valikko MenuA1
menuElement MenuA1[]={
 mEmenuA1,
 mEbackToMenu21,
 mEbackToMenu1,
 mENULL
};
//Funktio joka piirtää yhden rivin valikkoon          
void menuA1(int row){      
          lcd.clear();   
          lcd.setCursor(1,row);
          lcd.print("A1 ");
          lcd.setCursor(5,row);
          lcd.print(analogRead(A1));
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA1{
  &menuA1,
  MenuA2
};
//Valikko MenuA2
menuElement MenuA2[]={
 mEmenuA2,
 mEbackToMenu21,
 mEbackToMenu1,
 mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menuA2(int row){                    
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("A2 ");
          lcd.setCursor(5,row);
          lcd.print(analogRead(A2));
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA2{
  &menuA2,
  MenuA3
};
//Valikko MenuA3
menuElement MenuA3[]={
 mEmenuA3,
 mEbackToMenu21,
 mEbackToMenu1,
 mENULL
};
//Funktio joka piirtää yhden rivin valikkoon           
void menuA3(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("A3 ");
          lcd.setCursor(5,row);
          lcd.print(analogRead(A3));
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenuA3{
  &menuA3,
  MenuA0
}; 
//Funktio joka piirtää yhden rivin valikkoon
void menu21rivi2(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 21 rivi 2 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu21rivi2{
  &menu21rivi2,
  MenubackLightOff
};
//Esimerkki sisältö Valikko MenubackLightOff, painattaessa sytyttää/sammuttaa taustavalon
menuElement MenubackLightOff[]={
  mEmenubackLightOff,
  mEbackToMenu21,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menubackLightOff(int row)
{
  lcd.clear();
  lcd.setCursor(1,row);
  lcd.print("LCDLight ");
  lcd.setCursor(11,row);
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
 mEbackToMenu21,
 mEbackToMenu1,
 mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menubackLightOn(int row) 
{
  lcd.clear();
  lcd.setCursor(1,row);
  lcd.print("LCDLight ");
  lcd.setCursor(11,row);
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
  mEmenu22rivi1,
  mEmenu22rivi2,
  mEbackToMenu1,
  mENULL
}; 
//Funktio joka piirtää yhden rivin valikkoon
void menu22rivi1(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 22 rivi 1 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22rivi1{
  &menu22rivi1,
  Menu22_1
};
/*
 * Menu22_1
 */
//Valikko Menu22_1
menuElement Menu22_1[]={
  mEmenu22_1,
  mEbackToMenu22,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon  
void menu22_1(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("Esim_22_1 ");
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22_1{
  &menu22_1,
  Menu22
};  

//Funktio joka piirtää yhden rivin valikkoon
void menu22rivi2(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 22 rivi 2 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22rivi2{
  &menu22rivi2,
  Menu22_2
};
/*
 * Menu22_2
 */
//Valikko Menu22_2
menuElement Menu22_2[]={
  mEmenu22_2,
  mEbackToMenu22,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon  
void menu22_2(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("Esim_22_2 ");
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu22_2{
  &menu22_2,
  Menu22
};  
/*
 * Menu23
 */
//Valikko Menu23
menuElement Menu23[]={
  mEmenu23rivi1,
  mEmenu23rivi2,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menu23rivi1(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 23 rivi 1 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu23rivi1{
  &menu23rivi1,
  Menu23_1
};
//Valikko Menu23_1
menuElement Menu23_1[]={
  mEmenu23_1,
  mEbackToMenu23,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon  
void menu23_1(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("Esim_23_1 ");
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu23_1{
  &menu23_1,
  Menu23
};  
//Funktio joka piirtää yhden rivin valikkoon
void menu23rivi2(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 23 rivi 2 ");
}

//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu23rivi2{
  &menu23rivi2,
  Menu23_2
};
//Valikko Menu23_2
menuElement Menu23_2[]={
  mEmenu23_2,
  mEbackToMenu23,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon  
void menu23_2(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("Esim_23_2 ");
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu23_2{
  &menu23_2,
  Menu23
};    
/*
 * Menu24
 */
//Valikko Menu24
menuElement Menu24[]={
  mEmenu24rivi1,
  mEmenu24rivi2,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon
void menu24rivi1(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 24 rivi 1 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu24rivi1{
  &menu24rivi1,
  Menu24_1
};
//Valikko Menu24_1
menuElement Menu24_1[]={
  mEmenu24_1,
  mEbackToMenu24,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon  
void menu24_1(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("Esim_24_1 ");
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu24_1{
  &menu24_1,
  Menu24
};   
//Funktio joka piirtää yhden rivin valikkoon
void menu24rivi2(int row){
  lcd.setCursor(1,row);
  lcd.print("Menu 24 rivi 2 ");
}
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu24rivi2{
  &menu24rivi2,
  Menu24_2
};
//Valikko Menu24_2
menuElement Menu24_2[]={
  mEmenu24_2,
  mEbackToMenu24,
  mEbackToMenu1,
  mENULL
};
//Funktio joka piirtää yhden rivin valikkoon  
void menu24_2(int row){
          lcd.clear();
          lcd.setCursor(1,row);
          lcd.print("Esim_24_2 ");
  }
//struct jossa tekstin luonti ja linkki seuraavaan valikkoon
menuElement mEmenu24_2{
  &menu24_2,
  Menu24
}; 
/*
 * paluu valikkoon Menu21
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu21(int row){
  lcd.setCursor(1,row);
  lcd.print("Edellinen ");
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu21{
  &backToMenu21,
  Menu21
  };
/*
 * paluu valikkoon Menu22
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu22(int row){
  lcd.setCursor(1,row);
  lcd.print("Edellinen ");
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu22{
  &backToMenu22,
  Menu22
  };  
/*
 * paluu valikkoon Menu23
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu23(int row){
  lcd.setCursor(1,row);
  lcd.print("Edellinen ");
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu23{
  &backToMenu23,
  Menu23
  };
/*
 * paluu valikkoon Menu24
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu24(int row){
  lcd.setCursor(1,row);
  lcd.print("Edellinen ");
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu24{
  &backToMenu24,
  Menu24
  };
/*
 * paluu valikkoon Menu1
 */
//Funktio joka piirtää yhden rivin valikkoon
void backToMenu1(int row){
  lcd.setCursor(1,row);
  lcd.print("Back to main ");
}
//struct jossa tekstin luonti ja linkki ensimmäiseen valikkoon
menuElement mEbackToMenu1{
  &backToMenu1,
  Menu1
  };
