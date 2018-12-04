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
byte rightArrow[8] = { //kursori oikea
  B01000, //  *
  B00100, //   *
  B00010, //    *
  B00001, //     *
  B00010, //    *
  B00100, //   *
  B01000, //  *
  B00000  //
};
byte downArrow[8] = { //kursori alas
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b00100, //   *
  0b10101, // * * *
  0b01110, //  ***
  0b00100  //   *
};
byte upArrow[8] = { // kursori ylös
  0b00100, //   *
  0b01110, //  ***
  0b11111, // *****
  0b00100, //   *
  0b00100, //   *
  0b00100, //   * 
  0b00100, //   *
  0b00100  //   *
};
byte leftArrow[8] = { // kursori vasen
  0b00010, //    *
  0b00100, //   *
  0b01000, //  *
  0b10000, // *
  0b01000, //  *
  0b00100, //   *
  0b00010, //    *
  0b00000  //
};

int menuRow = 0; // valikkorivimuuttuja
menuElement *menu=Menu1; 

void setup(){
  pinMode(LCDLight, OUTPUT); // asettaa pinnin LCDLight output
  digitalWrite(LCDLight, HIGH); // asettaa pinnille virran
  lcd.begin(16, 2); // käynnistää näytön, merkki paikkojen määrät 16 ja rivit 2
  lcd.createChar(0, rightArrow); // Luo merkin paikalle 0, nuoli oikealle
  lcd.createChar(1, downArrow); // Luo merkin paikalle 1, nuoli alas
  lcd.createChar(2, upArrow); // Luo merkin paikalle 2, nuoli ylös
  lcd.createChar(3, leftArrow); // Luo merkin paikalle 3, nuoli vasemmalle
  // piirtää ensimmäisen valikon
  menu[menuRow+0].mL(0);
  menu[menuRow+1].mL(1);
}

void loop(){  
menuControl();
}

/*
 * Pääfunktio, joka määrittelee painikkeiden arvojen mukaan tapahtuman
 */
void menuControl(){
  switch(buttons()){
  case 1: 
  lcd.clear(); // pyyhkii näytön
  if(menuRow > 0){ //jos suurempi kuin nolla,
  menuRow--; // laskee arvoa
  }
  //piirtää uudet rivit
  menu[menuRow+0].mL(0); 
  menu[menuRow+1].mL(1);
  break;
  case 2: // Valitsee valikon kursorin osoittaman rivin mukaan, putsaa näytön ja piirtää valitusta seuraavan valikon
  menu=menu[menuRow].t; //Valikkorakenne toisesta taulukosta
  lcd.clear(); // pyyhkii näytön
  menuRow=0;  //nollaa rivit
  //piirtää uudet rivit
  menu[menuRow+0].mL(0); 
  menu[menuRow+1].mL(1);
  
  break;
  case 3: 
  lcd.clear(); // pyyhkii näytön
  menuRow++; // kasvattaa arvoa
  if(menu[menuRow].t != NULL){ //jos ei ole tyhjä 
    menu[menuRow+0].mL(0); //ei kasvata arvoa riville 0
  }else{ // muutoin laskee arvoa
    menuRow--; // jos halutaan pyörähtämään ympäri, vaihdetaan kasvattamaan arvoa
  }
  if(menu[menuRow+1].t != NULL){ //jos seuraava rivi ei ole tyhjä,
    menu[menuRow+1].mL(1); // kasvattaa rivien arvoa ja piirtää seuraavaan
  }else{ // muutoin ei kasvata arvoa, pysähtyy tyhjään riviin, alanuoli katoaa
    menu[menuRow+0].mL(0);
}
  break;
  case 4: // TODO tarvittaessa, painiketta S1 painettu pitkään tapahtuu jotain hienoa
  break;
  case 5: // TODO tarvittaessa, painiketta S3 painettu pitkään tapahtuu jotain hienoa 
  break;
  case 6: // jos valintapainiketta painettu pitkään, palaa ensimmäiseen valikkoon
  lcd.clear(); // pyyhkii näytön
  menu=Menu1; // asettaa menun vastaamaan Menu1:sta
  menuRow=0; //nollaa rivit
  //piirtää uudet rivit
  menu[menuRow+0].mL(0);
  menu[menuRow+1].mL(1);
  break;
} 
drawCursor(); //piirtää kursorin
}
/*
 * muuttuja funktio joka painikkeiden mukaan palauttaa halutun arvon käytettäväksi menuControl funktiossa
 */
int buttons(){
int ret=0; // oletusarvo nolla
  if (S1.pressed() ){ ret = 1; } // jos painiketta S1 painettu ja valikkorivi on yksi, palauttaa arvon 1 menuControl funktioon
  if (S1.pressedLong()){ ret = 4; } // TODO jos painiketta S1 painettu pitkään tapahtuu jotain hienoa
  if (S3.pressed() ){ ret = 3; } // jos painiketta S3 painettu ja valikkorivi on nolla, palauttaa arvon 3 menuControl funktioon
  if (S3.pressedLong()){ ret = 5; } // TODO jos painiketta S3 painettu pitkään tapahtuu jotain hienoa
  if (S2.pressed()){ ret = 2; } // jos painiketta S2 painetaan palauttaa arvon kaksi menuControl funktioon
  if (S2.pressedLong()){ ret = 6; } // jos paineketta S2 painetaan pitkään palauttaa arvon kuusi menuControl funktioon
 return ret;  // palauttaa oletusarvon
} 
/*
 * funktio joka piirtää kursorin
 */
void drawCursor() {
      lcd.setCursor(0, 0);
      lcd.write(byte(0)); //piirtää kursorin oikea nuoli
      lcd.setCursor(15,0);
      lcd.write(byte(3)); //piirtää kursorin vasen nuoli
      lcd.setCursor(15,1); 
      lcd.write(byte(1)); //piirtää kursorin nuoli alas
      if(menu[menuRow+1].t == NULL){ //jos tuleva rivi on tyhjä,
      lcd.setCursor(15,1);
      lcd.write(" ");} // pyyhkii nuolen  alas
      if(menuRow > 0){ // jos suurempi kuin nolla, 
        lcd.setCursor(0,1);
        lcd.write(byte(2)); // piirtää nuolen ylös
      }
}
