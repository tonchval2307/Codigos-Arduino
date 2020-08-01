String pwm = "0";
int analog_pin = 0;
int estado;
int duty;
enum estados{inicio,enviar,recibir};
char comando;

///Command variables

int comand;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >= 1)
  {
    comando = Serial.read();
    Serial.print("sync");
  }
}

int checkForCommand(void)
{
  char command;
  int bufferBytes = Serial.available();
  if(bufferBytes >= 4)
  {
    command   = Serial.read();
    procesCommand(command);
    return 1;
  }
  else
  {
    return 0;
  }
}

void procesCommand(unsigned char command)
{
  switch(command)
  {
    case 0:
      Serial.print("sync");
      Serial.print("Ok");
      Serial.flush();
    break;
    case 1:
      Serial.flush();
    break;
    case 2:
      Serial.print("option 2");
    break;
  }
}


