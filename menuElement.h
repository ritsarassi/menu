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
//Rivien tiedot
extern menuElement mENULL;
/*
 * Menu1
 */
//Rivin tulostus-funktiot
void menu1rivi1(int row);
void menu1rivi2(int row);
void menu1rivi3(int row);
void menu1rivi4(int row);
//Rivien tiedot
extern menuElement mEmenu1rivi1;
extern menuElement mEmenu1rivi2;
extern menuElement mEmenu1rivi3;
extern menuElement mEmenu1rivi4;
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
 * Menu23
 */
//Rivin tulostus-funktiot
void menu23rivi1(int row);
void menu23rivi2(int row);
//Rivien tiedot
extern menuElement mEmenu23rivi1;
extern menuElement mEmenu23rivi2;
//Taulukko riveistä > eli valikko
extern menuElement Menu23[];

/*
 * Menu24
 */
//Rivin tulostus-funktiot
void menu24rivi1(int row);
void menu24rivi2(int row);
//Rivien tiedot
extern menuElement mEmenu24rivi1;
extern menuElement mEmenu24rivi2;
//Taulukko riveistä > eli valikko
extern menuElement Menu24[];

/*
 * Analog esimerkki valikko
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
 * LCDtaustavalo menu
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
 * Menu22_1 ja 22_2
 */

//Taulukko riveistä > eli valikko
extern menuElement Menu22_1[];
//Rivin tulostus-funktiot
void menu22_1(int row);
//Rivien tiedot
extern menuElement mEmenu22_1;
//Taulukko riveistä > eli valikko
extern menuElement Menu22_2[];
//Rivin tulostus-funktiot
void menu22_2(int row);
//Rivien tiedot
extern menuElement mEmenu22_2;

/*
 * Menu 23_1 ja 23_2
 */
//Taulukko riveistä > eli valikko
extern menuElement Menu23_1[];
//Rivin tulostus-funktiot
void menu23_1(int row);
//Rivien tiedot
extern menuElement mEmenu23_1;
//Taulukko riveistä > eli valikko
extern menuElement Menu23_2[];
//Rivin tulostus-funktiot
void menu23_2(int row);
//Rivien tiedot
extern menuElement mEmenu23_2;

/*
 * Menu 24_1 ja 24_2
 */
//Taulukko riveistä > eli valikko
extern menuElement Menu24_1[];
//Rivin tulostus-funktiot
void menu24_1(int row);
//Rivien tiedot
extern menuElement mEmenu24_1;
//Taulukko riveistä > eli valikko
extern menuElement Menu24_2[];
//Rivin tulostus-funktiot
void menu24_2(int row);
//Rivien tiedot
extern menuElement mEmenu24_2;
/*
 * Back to 21
 */
//Rivin tulostus-funktiot
void backToMenu21(int row);
//Rivien tiedot
extern menuElement mEbackToMenu21;
/*
 * Back to 22
 */
//Rivin tulostus-funktiot
void backToMenu22(int row);
//Rivien tiedot
extern menuElement mEbackToMenu22;
/*
 * Back to 23
 */
//Rivin tulostus-funktiot
void backToMenu23(int row);
//Rivien tiedot
extern menuElement mEbackToMenu23;
/*
 * Back to 24
 */
//Rivin tulostus-funktiot
void backToMenu24(int row);
//Rivien tiedot
extern menuElement mEbackToMenu24;
/*
 * Back to main menu
 */
//Rivin tulostus-funktiot
void backToMenu1(int row);
//Rivien tiedot
extern menuElement mEbackToMenu1;
#endif
