#ifndef menuElement_h
#define menuElement_h
#include <LiquidCrystal.h> //liitetään LCD näytön kirjastot
#include "Button.h" // liitetään painikkeiden kirjastot

#define D0 3        //
#define D1 4        // Shieldin 
#define D2 5        // pinnimääritelmät
#define D3 6        //
#define LCDLight 13 //

//funktio-osoitin
typedef void (* menuLine)(int);
struct menuElement{
  menuLine mL; //Osoitin funktioon joka rakentaa rivin sisällön
  struct menuElement* t; //Osoitin taulukkoon joka muodostaa seuraavan valikon
};
extern LiquidCrystal lcd;

/*
 * Menu1
 */
//Rivin tulostus-funktiot
void menu1rivi1(int row);
void menu1rivi2(int row);
//Rivien tiedot
extern menuElement mEmenu1rivi1;
extern menuElement mEmenu1rivi2;
//Valikko Menu1
extern menuElement Menu1[];
/*
 * Menu21
 */
//Rivin tulostus-funktiot
void menu21rivi1(int row);
void menu21rivi2(int row);
//Rivien tiedot
extern menuElement mEmenu21rivi1;
extern menuElement mEmenu21rivi2;
//Taulukko riveistä > eli valikko
extern menuElement Menu21[];
/*
 * Menu22
 */
//Rivin tulostus-funktiot
void menu22rivi1(int row);
void menu22rivi2(int row);
//Rivien tiedot
extern menuElement mEmenu22rivi1;
extern menuElement mEmenu22rivi2;
//Taulukko riveistä > eli valikko
extern menuElement Menu22[];
/*
 * Analog pinnien valikko
 */
 //Taulukko riveistä > eli valikko
extern menuElement MenuA0[];
//Rivin tulostus-funktiot
void menuA0(int row);
//Rivien tiedot
extern menuElement mEmenuA0;

//Taulukko riveistä > eli valikko
extern menuElement MenuA1[];
//Rivin tulostus-funktiot
void menuA1(int row);
//Rivien tiedot
extern menuElement mEmenuA1;

//Taulukko riveistä > eli valikko
extern menuElement MenuA2[];
//Rivin tulostus-funktiot
void menuA2(int row);
//Rivien tiedot
extern menuElement mEmenuA2;

//Taulukko riveistä > eli valikko
extern menuElement MenuA3[];
//Rivin tulostus-funktiot
void menuA3(int row);
//Rivien tiedot
extern menuElement mEmenuA3;
/*
 * Digital pinnien valikko
 */
extern menuElement MenuDigitalPinsLow[]; 
 //Taulukko riveistä > eli valikko
extern menuElement MenuDigitalPinsLow[];
//Rivin tulostus-funktiot
void menuDigitalPinsLow(int row);
//Rivien tiedot
extern menuElement mEmenuDigitalPinsLow;

//Taulukko riveistä > eli valikko
extern menuElement MenuDigitalPinsHigh[];
//Rivin tulostus-funktiot
void menuDigitalPinsHigh(int row);
//Rivien tiedot
extern menuElement mEmenuDigitalPinsHigh;
/*
 * LCDbacklight valikko
 */
 //Taulukko riveistä > eli valikko
extern menuElement MenubackLightOff[];
//Rivin tulostus-funktiot
void menubackLightOff(int row);
//Rivien tiedot
extern menuElement mEmenubackLightOff;

//Taulukko riveistä > eli valikko
extern menuElement MenubackLightOn[];
//Rivin tulostus-funktiot
void menubackLightOn(int row);
//Rivien tiedot
extern menuElement mEmenubackLightOn;
/*
 * Ritari ässä valikko
 */
 //Taulukko riveistä > eli valikko
extern menuElement MenuRitari1[];
//Rivin tulostus-funktiot
void menuRitari1(int row);
//Rivien tiedot
extern menuElement mEmenuRitari1;

//Taulukko riveistä > eli valikko
extern menuElement MenuRitari2[];
//Rivin tulostus-funktiot
void menuRitari2(int row);
//Rivien tiedot
extern menuElement mEmenuRitari2;
/*
 * Takaisin menu21
 */
//Rivin tulostus-funktiot
void backToMenu21(int row);
//Rivien tiedot
extern menuElement mEbackToMenu21;
/*
 * Takaisin menu22
 */
//Rivin tulostus-funktiot
void backToMenu22(int row);
//Rivien tiedot
extern menuElement mEbackToMenu22;
/*
 * Takaisin alkuvalikkoon
 */
//Rivin tulostus-funktiot
void backToMenu1(int row);
//Rivien tiedot
extern menuElement mEbackToMenu1;
#endif
//Tehnyt Marko Saari 2018
