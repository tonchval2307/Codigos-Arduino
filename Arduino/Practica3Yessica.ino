#include<Keypad.h>
#include <LiquidCrystal.h>
/*
 *  Practica 3. Medir la temperatura de un equipo y cuando suba la temperatura
 *   al punto de control se encienda un abanico, que refrescara al LM35 y cuando 
 *   llegue a la temperatura inferior se apague.
 */
const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte rowPins[rows] = {23, 25, 27, 29}; //connect to the row pinouts of the keypad
byte colPins[cols] = {22, 24, 26, 28}; //connect to the column pinouts of the keypad

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad Teclado = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

enum Comportamiento{Configuracion, Runing};
enum Comportamiento Estado;

int Abanico = 46;
int Temperatura = 0;
int Horno = 47;
char StatusLamp = '0';
char key;
int counter = 0;
double Celcius = 0;

int TempMax[2];
int TempMin[2];

int Maximo = 0;
int Minimo = 0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Estado = Configuracion;
  lcd.setCursor(0,0);
  lcd.print("P-3 : Cntrl Temp");
  lcd.setCursor(0,1);
  for(int i=0;i<16;i++)
  {
    lcd.print(".");
    delay(250);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ingresr Valores:");
  delay(2000);
  lcd.clear();
}

void loop() {

    switch(Estado)
    {
      case Configuracion:
        lcd.setCursor(0,0);
        lcd.print("Ingrsr Valor Min");
        while(counter < 2)
        {
          key = Teclado.getKey();
          if(key != NO_KEY)
          {
            if(key != 'A')
            {
              TempMin[counter] = key - 48;
              lcd.setCursor(counter + 2,1);
              lcd.print(TempMin[counter]);
            }
            else
            {
              counter++;
            }
          }
        }
        counter = 0;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ingrsr Valor Max");
        while(counter < 2)
        {
          key = Teclado.getKey();
          if(key != NO_KEY)
          {
            if(key != 'A')
            {
              TempMax[counter] = key - 48;
              lcd.setCursor(counter + 2,1);
              lcd.print(TempMax[counter]);
            }
            else
            {
              counter++;
            }
          }
        }
        lcd.clear();
        delay(1000);
        lcd.setCursor(0,0);
        lcd.print("- Max ---- Min -");
        lcd.setCursor(2,1);
        Maximo = (TempMax[0] * 10) + TempMax[1];
        Minimo = (TempMin[0] * 10) + TempMin[1];
        lcd.print(Maximo);
        lcd.setCursor(11,1);
        lcd.print(Minimo);
        delay(3000);
        lcd.clear();
        Estado = Runing;
      break;
      case Runing:
        //for(int i=0;i<20;i++)
        //{       
        //  Temperatura += analogRead(2) * 0.0048;
        //  delay(50);
       // }
        //Celcius = Temperatura / 20;
        Celcius = map(analogRead(2),330,806,25,92);
        //Temperatura = 0;
        if((Celcius <= Maximo) && (Celcius >= Minimo))
        {
          digitalWrite(Horno,HIGH);
          StatusLamp = 'I';
        }
        else
        {
          digitalWrite(Horno,LOW);
          StatusLamp = 'O';
        }
        lcd.setCursor(0,0);
        lcd.print("M:");
        lcd.setCursor(3,0);
        lcd.print(Maximo);
        lcd.setCursor(5,0);
        lcd.print ("m :");
        lcd.print(Minimo);
        lcd.setCursor(0,1);
        lcd.print("H=");
        lcd.print(StatusLamp);
        lcd.setCursor(4,1);
        lcd.print("Temp:");
        lcd.print(Celcius);
        delay(500);
        key = Teclado.getKey();
        if((key != NO_KEY) && (key == 'A'))
        {
          Estado = Configuracion;
          counter = 0;
          lcd.clear();
          digitalWrite(Horno,LOW);
        }
      break;
    }

}
