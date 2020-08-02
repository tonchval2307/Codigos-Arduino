#define split_mode 1
#define join_mode 2
 unsigned int count = 0;

void setup() {
  // put your setup code here, to run once:
  fresnell_init();
  alarm_init(split_mode);
  ventanas_init();
  bluetooth_init();
  pinMode(6,INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
    delay(100);
    if(data_bt_rx() == true)
    {
      count++;
      if(count >= 2)
      {
        count = 0;
      }
  }
  if(count == 0)
  {
  if ((fressnel_sensor() == true) && (temperature_read(0,512) == true))
  {
    alarm_mode(split_mode);
    ventanas_abajo();
  }
  else
  {
    ventanas_arriba();
  }
  }
}

void fresnell_init(void)
{
  pinMode(13,INPUT);
}

bool fressnel_sensor(void)
{
  if (digitalRead(13) == HIGH)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

bool temperature_read(unsigned int ch_an,unsigned int temp)
{
  unsigned int a;
  a = analogRead(ch_an);
  if (a >= temp)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

void alarm_init(int mode)
{
  switch (mode)
  {
    case 1:
        pinMode(2,OUTPUT);  //Pin usado para encender luz izquierda delantera
        pinMode(3,OUTPUT);  //Pin Usado para encender luz derecha delantera
        pinMode(4,OUTPUT);  //Pin Usado para encender la luz izquierda trasera.
        pinMode(5,OUTPUT);  //Pin Usado para encender la luz derecha trasera.
        pinMode(6,OUTPUT);  //PIn usado para encender bocina.
        for(int i=2;i<=6;i++)
        {
          digitalWrite(i,LOW);
        }
    break;
    case 2:
        pinMode(2,OUTPUT);  //Pin para luces delanteras
        pinMode(3,OUTPUT);  //Pin para luces traseras.
        pinMode(4,OUTPUT);  //Pin Para bocina de alarma.
        for(int i=2;i<=4;i++)
        {
          digitalWrite(i,LOW);
        }
    break;
    default:
        pinMode(2,OUTPUT);  //Pin usado para encender luz izquierda delantera
        pinMode(3,OUTPUT);  //Pin Usado para encender luz derecha delantera
        pinMode(4,OUTPUT);  //Pin Usado para encender la luz izquierda trasera.
        pinMode(5,OUTPUT);  //Pin Usado para encender la luz derecha trasera.
        pinMode(6,OUTPUT);  //PIn usado para encender bocina.
        for(int i=2;i<=6;i++)
        {
          digitalWrite(i,LOW);
        }
    break;
  }
}

void alarm_mode(unsigned int mode)
{
  switch(mode)
  {
    case 1:
      for(int i=2;i<=6;i++)
      {
        digitalWrite(i,HIGH);
      }
      delay(250);
      for(int i=2;i<=6;i++)
      {
        digitalWrite(i,LOW);
      }
      delay(250);
    break;
    case 2:
      for(int i=2;i<=4;i++)
      {
        digitalWrite(i,HIGH);
      }
      delay(250);
      for(int i=2;i<=4;i++)
      {
        digitalWrite(i,LOW);
      }
      delay(250);
    break;
    default:
      for(int i=2;i<=6;i++)
      {
        digitalWrite(i,HIGH);
      }
      delay(250);
      for(int i=2;i<=6;i++)
      {
        digitalWrite(i,LOW);
      }
      delay(250);
    break;
  }
}

void ventanas_init(void)
{
  pinMode(7,OUTPUT);
}

void ventanas_abajo(void)
{
  digitalWrite(7,HIGH);
}
void ventanas_arriba(void)
{
  digitalWrite(7,LOW);
}

void bluetooth_init(void)
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

bool data_bt_rx(void)
{
  char data;
  if(Serial.available()>0)
  {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if(data == '1')
    {
      digitalWrite(13,HIGH);
      return true;
    }
    else if(data == '0')
    {
      digitalWrite(13,LOW);
      return false;
    }
  }
}

