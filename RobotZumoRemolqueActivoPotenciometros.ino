/*
   Remolque activo con robot Zumo
   Se necesita conectar un potenciómetro lineal en el pin A2 para detectar la distancia al robot tractor
   y otro potenciómetro giratorio al pin A2 para detectar la distancia.
*/

#include <Wire.h>
#include <ZumoShield.h>

const int PinPotenciometroGiro = A0;
const int PinPotenciometroLineal = A2;

int ValorPotGiro = 0;
int ValorPotDistancia = 0;
int mixIzquierdo = 0;
int mixDerecho = 0;

ZumoMotors motors;

void setup()
{
  //Serial.begin(115200);
}

void loop()
{
  ValorPotGiro = map(analogRead(PinPotenciometroGiro), 0, 1023, -100, 100);
  ValorPotDistancia = map(analogRead(PinPotenciometroLineal), 0, 1023, 100, -100);

  mixIzquierdo = ValorPotDistancia  * 4;
  mixIzquierdo = mixIzquierdo - ValorPotGiro * 10;
  mixIzquierdo = mixIzquierdo * 2;
  motors.setLeftSpeed(mixIzquierdo); // speed de -400 a 400 en el ejemplo

  mixDerecho = ValorPotDistancia  * 4;
  mixDerecho = mixDerecho + ValorPotGiro * 10;
  mixDerecho = mixDerecho * 2;
  motors.setRightSpeed(mixDerecho);// speed de -400 a 400 en el ejemplo
}
