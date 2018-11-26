#ifndef menuElement_h
#define menuElement_h
#include <LiquidCrystal.h>
#include "Button.h"
/*
 * Shieldin pinnimääritelmät
 */
#define D0 3
#define D1 4
#define D2 5
#define D3 6
#define LCDLight 13


//funktio-osoitin
typedef void (* menuLine)(int);
struct menuElement{
  menuLine mL;
  struct menuElement* t;
};

extern LiquidCrystal lcd;

/*
 * Menu1
 */
//Rivin tulostus-funktiot
void menu1line1(int row);
void menu1line2(int row);
//Rivien tiedot
extern menuElement mEmenu1line1;
extern menuElement mEmenu1line2;
//Valikko Menu1
extern menuElement Menu1[];

/*
 * Menu21
 */
//Rivin tulostus-funktiot
void menu21line1(int row);
void menu21line2(int row);
//Rivien tiedot
extern menuElement mEmenu21line1;
extern menuElement mEmenu21line2;
//Taulukko riveistä > eli valikko
extern menuElement Menu21[];

/*
 * Menu22
 */
//Rivin tulostus-funktiot
void menu22line1(int row);
void menu22line2(int row);
//Rivien tiedot
extern menuElement mEmenu22line1;
extern menuElement mEmenu22line2;
//Taulukko riveistä > eli valikko
extern menuElement Menu22[];


/*
 * Back to main menu
 */
//Rivin tulostus-funktiot
void backToMenu1(int row);
//Rivien tiedot
extern menuElement mEbackToMenu1;

/*
 * Analogread menus
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
 * digital write menu
 */
extern menuElement MenuDigital[]; 
 //Taulukko riveistä > eli valikko
extern menuElement MenuD0Low[];
//Rivin tulostus-funktiot
void menuD0Low(int row);
//Rivien tiedot
extern menuElement mEmenuD0Low;

//Taulukko riveistä > eli valikko
extern menuElement MenuD0High[];
//Rivin tulostus-funktiot
void menuD0High(int row);
//Rivien tiedot
extern menuElement mEmenuD0High;

//Taulukko riveistä > eli valikko
extern menuElement MenuD1Low[];
//Rivin tulostus-funktiot
void menuD1Low(int row);
//Rivien tiedot
extern menuElement mEmenuD1Low;

//Taulukko riveistä > eli valikko
extern menuElement MenuD1High[];
//Rivin tulostus-funktiot
void menuD1High(int row);
//Rivien tiedot
extern menuElement mEmenuD1High;

//Taulukko riveistä > eli valikko
extern menuElement MenuD2Low[];
//Rivin tulostus-funktiot
void menuD2Low(int row);
//Rivien tiedot
extern menuElement mEmenuD2Low;

//Taulukko riveistä > eli valikko
extern menuElement MenuD2High[];
//Rivin tulostus-funktiot
void menuD2High(int row);
//Rivien tiedot
extern menuElement mEmenuD2High;

//Taulukko riveistä > eli valikko
extern menuElement MenuD3Low[];
//Rivin tulostus-funktiot
void menuD3Low(int row);
//Rivien tiedot
extern menuElement mEmenuD3Low;

//Taulukko riveistä > eli valikko
extern menuElement MenuD3High[];
//Rivin tulostus-funktiot
void menuD3High(int row);
//Rivien tiedot
extern menuElement mEmenuD3High;

/*
 * LCDbacklight menu
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
 * Ritari ässä menu
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
#endif
