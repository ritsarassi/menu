/*
 * Kahden rivin valikko jossa laajennus mahdollisuus, käyttäen struktuureja sekä kirjastoja
 */

#include "menuElement.h" //liitetty menuElement kirjasto
#include <LiquidCrystal.h> //liitetty LCD kirjasto
#include "Button.h" //liitetty painike kirjasto

#define rs 12 //
#define en 11 //
#define d4 10 // LCD Näytön pinnimääritelmät
#define d5 9  //
#define d6 8  //
#define d7 7  //
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//painikkeet ja niiden pinnimääritelmät
Button S1 (2); //painike ylös
Button S2 (1); //painike valinta/pitkä painallus palauttaa Menu1 valikkoon
Button S3 (0); //painike alas
/*
 * kursorit valikolle
 */ 
byte menuCursor[8] = { //kursori joka osoittaa rivin jolla ollaan
  B01000, //  *
  B00100, //   *
  B00010, //    *
  B00001, //     *
  B00010, //    *
  B00100, //   *
  B01000, //  *
  B00000  //
};
byte downArrow[8] = { //Varaus käytettäväksi myöhemmin
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b10101, // * * *
  0b01110, //  ***
  0b00100  //   *
};
byte upArrow[8] = { //Varaus käytettäväksi myöhemmin
  0b00100, //   *
  0b01110, //  ***
  0b10101, // * * *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100  //   *
};
int cursorPosition = 0; //kursorimuuttuja
int menuRow = 0; // valikkorivimuuttuja 
menuElement *menu=Menu1; 

void setup(){
  lcd.clear();
  lcd.begin(16, 2);
  lcd.createChar(0, menuCursor);
  lcd.createChar(1, downArrow);
  lcd.createChar(2, upArrow);
  menu[0].mL(menuRow);
  menu[1].mL(menuRow);
}

void loop(){  
menuControl();
}
/*
 * Pääfunktio, joka määrittelee painikkeiden arvojen mukaan tapahtuman
 */
void menuControl(){
switch(buttons()){
  
  case 1: // laskee rivin arvoa jos menuRow suurempi kuin nolla jotta ei laske alle nollan
  if(cursorPosition > 0)
  {
  cursorPosition--;
  }
  if(menuRow > 0)
  {
  menuRow--;
  }
  break;
  case 2: // Valitsee valikon kursorin osoittaman rivin mukaan, putsaa näytön ja piirtää valitusta seuraavan valikon
  lcd.clear();          // pyyhkii näytön
  menu=menu[menuRow].t; // Valikkorakenne toisesta taulukosta
  menu[0].mL(menuRow);  // piirtää uuden rivin paikalle rivi 0
  menu[1].mL(menuRow);  // piirtää uuden rivin paikalle rivi 1
  menuRow = 0;          // palauttaa menuRow arvon nollille
  cursorPosition = 0;   // palauttaa kursorin arvon
  break;
  case 3: // kasvattaa rivin arvoa
  if(cursorPosition < 1)
  {
  cursorPosition++;
  }
  menuRow++;
  break;
  case 4: // varaus käytettäväksi jos painiketta S1 painettu pitkään tapahtuu jotain hienoa
  break;
  case 5: // varaus käytettäväksi jos painiketta S3 painettu pitkään tapahtuu jotain hienoa
  break;
  case 6: // jos valintapainiketta painettu pitkään, tyhjentää näytön ja palaa ensimmäiseen valikkoon
  lcd.clear();   
  menuRow=0;
  cursorPosition = 0;           
  menu=Menu1;
  menu[0].mL(menuRow);
  menu[1].mL(menuRow);
  break;
} drawCursor(); // kutsuu funktiota joka piirtää kursorin
}

/*
 * muuttuja funktio joka painikkeiden mukaan palauttaa halutun arvon käytettäväksi menuControl funktiossa
 */
int buttons(){
int ret=0; //vakioarvo on nolla
  if (S1.pressed()){ ret = 1; } // jos painiketta S1 painettu ja valikkorivi on yksi, palauttaa arvon 1 menuControl funktioon
  if (S1.pressedLong()){ ret = 4; } // varaus käytettäväksi jos painiketta S1 painettu pitkään tapahtuu jotain hienoa
  if (S3.pressed()){ ret = 3; } // jos painiketta S3 painettu ja valikkorivi on nolla, palauttaa arvon 3 menuControl funktioon
  if (S3.pressedLong()){ ret = 5; } // varaus käytettäväksi jos painiketta S3 painettu pitkään tapahtuu jotain hienoa
  if (S2.pressed()){ ret = 2; } // jos painiketta S2 painetaan palauttaa arvon kaksi menuControl funktioon
  if (S2.pressedLong()){ ret = 6; } // jos paineketta S2 painetaan pitkään palauttaa arvon kuusi menuControl funktioon
 return ret;  // palauttaa vakioarvon
} 
/*
 * funktio joka piirtää kursorin
 */
void drawCursor() {
    if (cursorPosition == 0) { //jos valikkorivi on yhtäkuin nolla,
      lcd.setCursor(0, 0);
      lcd.write(byte(0)); //piirtää kursorin riville nolla
      lcd.setCursor(0,1);
      lcd.print(" "); //ja pyyhkii rivin yksi
    }
    if (cursorPosition == 1) {  //jos valikkorivi on yhtäkuin yksi, 
      lcd.setCursor(0,0);
      lcd.print(" "); //  pyyhkii kursorin riviltä nolla
      lcd.setCursor(0, 1);
      lcd.write(byte(0)); // ja piirtää kursorin riville yksi
    }
}
//Tehnyt Marko Saari 2018
