/*
 * Sumobot Firmware v5.0
 * Escrito por: Ing. Carlos Eduardo Tonche Vazquez.
 * Escrito en : 3 Diciembre 2017.
 * 
 * Caracteristicas:
 *  1. Empleo del Motor Driver L298N.
 *  2. Uso de Motorreductores.
 *  3. 2 Sensores Ultrasonicos.
 *  4. Uso de Interupciones en TIMER_1.
 *  5. Uso de Interrupciones para detectar Linea Blanca.
 *  6. Mejora en el Comportamiento agresivo del robot.
 *  
 *  Modos de comportamiento general del robot de sumo:
 *  Modo Inicio:
 *                El robot espera a que se de la senal de arranque para realizar 
 *                una espera de 10 SEgundos previo a el comienzo del combate.
 *                permite colocar adecuadamente el robot en su debida posicion.
 *  Modo busqueda_combate:  
 *                Procede con la buscqueda de oponente, se mejora el comportamiento
 *                agresivo del robot en este modo, no solo busca, tambien agrede
 *                sin esperar un ataque previo como en la version v4.0.
 *  Modo Combate:
 *                Posee tres modos de combate:
 *                1. CW: El robot gira en sentido de las manecillas del reloj.
 *                2. CCW: El robot gira en contra de las manecillas del reloj.
 *                3. FWD_REW: EL robot realiza una embestida continua.
 */

  //Asignacion de termianles para el funcionamiento del Driver L298N
const byte enableA = 5;  //Terminal enA
const byte enableB = 6;  //Terminal enB
const byte Input1 = 4;   //Terminal in1
const byte Input2 = 7;    //Terminal in2
const byte Input3 = 8;   //Terminal in3
const byte Input4 = 9;   //Terminal in4

  //Asignacion de Termianles para los dos sensores ultrasonicos.
  //Sensor Ultrasonico Frontal
const byte trigger = 10;
const byte echo = 11;
  //Sensor ultrasonico trasero
const byte trigger_b = 12;
const byte echo_b = 13;

  //Asignacion de terminales para la deteccion de linea blanca
  //Frontal
const byte trasero1 = 2;
const byte trasero2 = 3;

  //Definicion de la maquina de estados del robot.
enum estados{arranque,izquierda,derecha,giro,combate};
volatile int estado;

  //Variables de almacenamiento de datos temporales
volatile double Ufront = 0;
volatile double Uback = 0;
volatile bool start;
volatile int velocidad = 100;
void setup() {
  Serial.begin(9600);
  configuracion_detectores(trasero1,trasero2);
  configuracion_ultrasonicos(trigger,echo,trigger_b,echo_b);
  motor_drive_init(enableA,Input1,Input2,Input3,Input4,enableB);
  timer_configuration();
  estado = arranque;
  start = false;
  
}

void loop() {
  switch(estado)
  {
    case arranque:
      for(int j=0;j<=10;j++)
      {
        Serial.println(j);
        delay(1000);
      }
      start = true;
      estado = combate;
    break;
  }
}

void prueba_motores(char dato)
{
  switch(dato)
  {
    case 'w':
      adelanteM1(enableA,Input1,Input2,128);
      adelanteM2(enableB,Input3,Input4,128);
    break;
    case 's':
      atrasM1(enableA,Input1,Input2,128);
      atrasM2(enableB,Input3,Input4,128);
    break;
    case 'd':
      adelanteM1(enableA,Input1,Input2,128);
      atrasM2(enableB,Input3,Input4,128);
    break;
    case 'a':
      atrasM1(enableA,Input1,Input2,128);
      adelanteM2(enableB,Input3,Input4,128);
    break;
    case 'q':
      adelanteM1(enableA,Input1,Input2,0);
      adelanteM2(enableB,Input3,Input4,0);
    break;
  }
}
void timer_configuration(void)
{ //Configuracion del TIMER 1 para que el Prescaler sea de 64 y se sature cada 200ms
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1<<CS12);
  //| (1<<CS10);    //prescaler 1
  TIMSK1 |= (1<<TOIE1); //Enable timer overflow
}

ISR(TIMER1_OVF_vect)
{
  if(start == true)
  {
    Uback = measure_distance(trigger,echo);
    Ufront = measure_distance(trigger_b,echo_b);
    if(Uback > Ufront)
    {
      Serial.println("derecha");
      adelanteM1(enableA,Input1,Input2,velocidad);
      atrasM2(enableB,Input3,Input4,velocidad);
    }
    else if(Uback < Ufront)
    {
      Serial.println("Izquierda");
      atrasM1(enableA,Input1,Input2,velocidad);
      adelanteM2(enableB,Input3,Input4,velocidad);
    }
    else if( (Uback >= 100) || (Ufront >= 100))
    {
      Serial.println("giro");
      atrasM1(enableA,Input1,Input2,velocidad);
      adelanteM2(enableB,Input3,Input4,velocidad );
    }
    else
    {
      Serial.println("combate");
      adelanteM1(enableA,Input1,Input2,velocidad);
      adelanteM2(enableB,Input3,Input4,velocidad);
    }
  }
  /*
    Serial.print("izquierdo : ");
    Serial.print(measure_distance(trigger,echo));
    Serial.print(" , Derecho :  ");
    Serial.println(measure_distance(trigger_b,echo_b));
   */
}

double measure_distance(byte trigger,byte echo)
{
  int duration;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration = pulseIn(echo,HIGH);
  return (duration * 0.034)/2;
}

void motor_drive_init(byte enA,byte in1,byte in2,byte in3,byte in4,byte enB)
{
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);
}
void adelanteM1(byte pwm,byte dir1,byte dir2,int vel)
{
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,vel);
}

void adelanteM2(byte pwm,byte dir1,byte dir2,int vel)
{
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(pwm,vel);
}

void atrasM1(byte pwm,byte dir1,byte dir2,int vel)
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm,vel);
}

void atrasM2(byte pwm,byte dir1,byte dir2,int vel)
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm,vel);
}

void configuracion_detectores(byte adelante, byte atras)
{
  pinMode(trasero1,INPUT_PULLUP);
  pinMode(trasero2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(trasero1),deteccion_adelante,CHANGE);
  attachInterrupt(digitalPinToInterrupt(trasero2),deteccion_atras,CHANGE);
}
void deteccion_atras(void)
{
  Serial.println("int atras");
   adelanteM1(enableA,Input1,Input2,128);
   adelanteM2(enableB,Input3,Input4,128);
}

void deteccion_adelante(void)
{
  Serial.println("Interrupcion adelante");
  adelanteM1(enableA,Input1,Input2,128);
  adelanteM2(enableB,Input3,Input4,128);
}

void configuracion_ultrasonicos(byte trigger1, byte echo1, byte trigger2, byte echo2)
{
  pinMode(trigger1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trigger2,OUTPUT);
  pinMode(echo2,INPUT);
}

