char data = 0;
int NumberX = 0;
int NumberY = 0;
int counter = 0;
int Value[4];
enum Modos{IngresarCoordenadaX, IngresarCoordenadaY,Ejecutar,Calcular};
enum Modos Estado;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ingrese Cuatro Numeros");
  Estado = IngresarCoordenadaX;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >= 0)
  {
    switch(Estado)
    {
      case IngresarCoordenadaX:
        Serial.println("Ingrese Coordenada X:");
        while(counter < 4)
        {
          data = Serial.read();
          switch(data)
          {
            case '0':
              Value[counter] = 0;
              Serial.print('0');
              counter++;
            break;
            case '1':
              Value[counter] = 1;
              Serial.print('1');
              counter++;
            break;
            case '2':
              Value[counter] = 2;
              Serial.print('2');
              counter++;
            break;
            case '3':
              Value[counter] = 3;
              Serial.print('3');
              counter++;
            break;
            case '4':
              Value[counter] = 4;
              Serial.print('4');
              counter++;
            break;
            case '5':
              Value[counter] = 5;
              Serial.print('5');
              counter++;
            break;
            case '6':
              Value[counter] = 6;
              Serial.print('6');
              counter++;
            break;
            case '7':
              Value[counter] = 7;
              Serial.print('7');
              counter++;
            break;
            case'8':
              Value[counter] = 8;
              Serial.print('8');
              counter++;
            break;
            case '9':
              Value[counter] = 9;
              Serial.print('9');
              counter++;
            break;
          }
        }
        NumberX = Value[3] + (10*Value[2]) + (100*Value[1]) + (1000*Value[0]);
        Serial.println();
        Serial.println(NumberX);
        counter = 0;
        Estado = IngresarCoordenadaY;
      break;
      case IngresarCoordenadaY:
        Serial.println("Ingrese Coordenada Y:");
        while(counter < 4)
        {
          data = Serial.read();
          switch(data)
          {
            case '0':
              Value[counter] = 0;
              Serial.print('0');
              counter++;
            break;
            case '1':
              Value[counter] = 1;
              Serial.print('1');
              counter++;
            break;
            case '2':
              Value[counter] = 2;
              Serial.print('2');
              counter++;
            break;
            case '3':
              Value[counter] = 3;
              Serial.print('3');
              counter++;
            break;
            case '4':
              Value[counter] = 4;
              Serial.print('4');
              counter++;
            break;
            case '5':
              Value[counter] = 5;
              Serial.print('5');
              counter++;
            break;
            case '6':
              Value[counter] = 6;
              Serial.print('6');
              counter++;
            break;
            case '7':
              Value[counter] = 7;
              Serial.print('7');
              counter++;
            break;
            case'8':
              Value[counter] = 8;
              Serial.print('8');
              counter++;
            break;
            case '9':
              Value[counter] = 9;
              Serial.print('9');
              counter++;
            break;
          }
        }
        NumberY = Value[3] + (10*Value[2]) + (100*Value[1]) + (1000*Value[0]);
        Serial.println();
        Serial.println(NumberY);
        counter = 0;
        Estado =Calcular;
      break;
      case Calcular:
        Serial.print("Coordenada X:");
        Serial.println(NumberX);
        Serial.print("Coordenada Y:");
        Serial.println(NumberY);
        Estado = Ejecutar;
      break;
      case Ejecutar:
        
        Estado = IngresarCoordenadaX;
      break;
    }
  }
}
