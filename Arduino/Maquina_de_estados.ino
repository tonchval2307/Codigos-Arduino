enum estados{inicio,incrementar,disminuir};
int estado;
int i;
int data = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  estado = inicio;
  Serial.print("Practica #5");
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() >= 0 )
  {
    switch(estado)
    {
      case inicio:
        //Serial.println("inicio");
        data = Serial.read();
        analogWrite(11,0);
        if(data == 49)
        {
          estado = incrementar;
        }
        else
        {
          estado = inicio;
        }
      break;
      case incrementar:
        //Serial.println("incrementar");
        analogWrite(11,i);
        if(Serial.read() == 2)
        {
          i = i + 10;
          estado = incrementar;
        }
        else if(Serial.read() == 3)
        {
          estado = disminuir;
        }
        else if(Serial.read() == 4)
        {
          estado = inicio;
        }
        
      break;
      case disminuir:
       // Serial.println("disminuir");
        analogWrite(6,i);
        if(Serial.read() == 3)
        {
          i = i - 10;
          estado = disminuir;
        }
        else if(Serial.read() == 2)
        {
          estado = incrementar;
        }
        else if(Serial.read() == 4)
        {
          estado = inicio;
        }
      break;
    }
  }
}
