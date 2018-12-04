#include "menuElement.h" //liitetty menuElement kirjasto
#include <LiquidCrystal.h> //liitetty LCD kirjasto
#include "Button.h" //liitetty painike kirjasto
/*
 * LCD näytön pinnimääritelmät
 */
#define rs 12
#define en 11
#define d4 10
#define d5 9
#define d6 8
#define d7 7
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
byte downArrow[8] = { //TODO käytettäväksi myöhemmin
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b10101, // * * *
  0b01110, //  ***
  0b00100  //   *
};
byte upArrow[8] = { //TODO käytettäväksi myöhemmin
  0b00100, //   *
  0b01110, //  ***
  0b10101, // * * *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100  //   *
};
int cursorPosition = 0;
int menuRow = 0; // valikkorivimuuttuja
menuElement *menu=Menu1;

void setup(){
int VIIVE=20;
for(int i=0; i<5; i++){
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
          lcd.setCursor(1,1);
          lcd.print("DELAY!!! ");
}
  lcd.clear();
  lcd.begin(16, 2);
  lcd.createChar(0, menuCursor);
  lcd.createChar(1, downArrow);
  lcd.createChar(2, upArrow);
  menu[menuRow+0].mL(0);
  menu[menuRow+1].mL(1);
}

void loop(){  
menuControl();
}
/*
 * Pääfunktio, joka määrittelee painikkeiden arvojen mukaan tapahtuman
 * TODO jos valikossa enemmän kuin kaksi riviä, siirtää rivejä tai vain kursoria
 */
void menuControl(){
switch(buttons()){
  
  case 1: // laskee arvoa
if(cursorPosition > 0){
  cursorPosition--;
  menuRow--;
  }
  
  if(menuRow > 0){
  menuRow--;}
  lcd.clear();
  menu[menuRow+0].mL(0);
  menu[menuRow+1].mL(1);
  break;
  
  case 2: // Valitsee valikon kursorin osoittaman rivin mukaan, putsaa näytön ja piirtää valitusta seuraavan valikon
  
  lcd.clear();
  menu=menu[menuRow].t; //Valikkorakenne toisesta taulukosta
  menu[menuRow+0].mL(0);
  menu[menuRow+1].mL(1);
  cursorPosition = 0;
  menuRow = 0;
  
  break;
  
  case 3: // kasvattaa arvoa
  cursorPosition++;
  if(cursorPosition > 1){
  menuRow++;
  cursorPosition = 0;
  lcd.clear();
  if(menu[menuRow].t != NULL){
    menu[menuRow+0].mL(0);
  }else{
    menuRow=0;
  }
  if(menu[menuRow+1].t != NULL){
    menu[menuRow+1].mL(1);
  }else{
    menu[menuRow=0].mL(1);
  }
  }
  break;
  
  case 4: // TODO jos painiketta S1 painettu pitkään tapahtuu jotain hienoa
  
  break;
  case 5: // TODO jos painiketta S3 painettu pitkään tapahtuu jotain hienoa
  
  break;
  
  case 6: // jos valintapainiketta painettu pitkään, palaa ensimmäiseen valikkoon
  lcd.clear();
  menuRow = 0;
  cursorPosition=0;
  menu=Menu1;
  menu[menuRow+0].mL(0);
  menu[menuRow+1].mL(1);
  break;
}
drawCursor();
}
/*
 * muuttuja funktio joka painikkeiden mukaan palauttaa halutun arvon käytettäväksi menuControl funktiossa
 */
int buttons(){
int ret=0;
  if (S1.pressed() ){ ret = 1; } // jos painiketta S1 painettu ja valikkorivi on yksi, palauttaa arvon 1 menuControl funktioon
  if (S1.pressedLong()){ ret = 4; } // TODO jos painiketta S1 painettu pitkään tapahtuu jotain hienoa
  if (S3.pressed() ){ ret = 3; } // jos painiketta S3 painettu ja valikkorivi on nolla, palauttaa arvon 3 menuControl funktioon
  if (S3.pressedLong()){ ret = 5; } // TODO jos painiketta S3 painettu pitkään tapahtuu jotain hienoa
  if (S2.pressed()){ ret = 2; } // jos painiketta S2 painetaan palauttaa arvon kaksi menuControl funktioon
  if (S2.pressedLong()){ ret = 6; } // jos paineketta S2 painetaan pitkään palauttaa arvon kuusi menuControl funktioon
 return ret;  
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
