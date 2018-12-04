/*
Button.cpp - library for button
*/

#include "Arduino.h"
#include "Button.h"

/*
Konstruktori - Funktio joka luo uuden ilmentymän Button-luokasta. 
Täällä alustetaan kaikki painkeen toiminnot
*/
Button::Button(int pin)
{
  pinMode(pin, INPUT_PULLUP); //määritetään pinni lähdöksi
  _pin=pin; //Tallennetaan omaksi tiedoksi mihin pinnin liityttiin
  _prevState=digitalRead(pin); //Luetaan painikkeen tila ensimmäistä vertailua varten
  //Aikaleiman nollaus
  _timeStamp = 0;
  _keepTime = 2000;
}


//Funktio joka kertoo jos painike on painettu.
bool Button::pressed()
{
  bool ret=0;
  int x=digitalRead(_pin);
  if(x!=_prevState && x==BUTTONPRESSED)
  {
    ret=1;
    delay(BOUNCE);
  }
  _prevState=x;
  return ret;
} 
/* Funktio kertoo kahden sekunnin välein painikkeen
 * pohjassapidosta
 */
bool Button::pressedLong(){
  bool ret=0;
  int x=digitalRead(_pin);
  if(x == BUTTONPRESSED){
      if(_timeStamp == 0){//uusi painallus
        _timeStamp = millis();//Eli otetaan uusi aikaleima
      }else if(millis()-_timeStamp > _keepTime){
        ret = 1;
        _timeStamp += _keepTime;        
      }
  }else{
    _timeStamp=0;
  }
  return ret;
}
