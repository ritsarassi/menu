/*
Button.h - library for buttons
*/

#ifndef Button_h
#define Button_h
#include "Arduino.h"

const int BUTTONPRESSED=LOW;
const int BOUNCE=50;

/*
Luodaan luokka joka muodostuu metodeista painikkeen käsittelyä varten,
sekä muuttujuat joita tarvitaan
*/
class Button
{
  public:
    //Konstruktori joka liittää metodit valitulle tulolle
    Button(int pin);
    //Metodi joka kertoo painkkeen painalluksesta
    bool pressed();
    bool pressedLong();
  private:
    //Mihin tuloon painike liitetään
    int _pin;
    //Tilatieto vanhasta painikkeen tilasta
    int _prevState;
    //Aikaleima
    unsigned long _timeStamp;
    unsigned long _keepTime; 
};

#endif
