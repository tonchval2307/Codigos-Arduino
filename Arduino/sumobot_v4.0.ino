/*
 * Sumobot Firmware v4.0
 * Escrito Por: Carlos Edruado Tonche Vazquez
 * Escrito en : Octubre 2017
 */
 
/*
 * assignacion de comportamientos del sumobot.
 * Comportamiento Inicio:
 *  EL robot espera a que se de la senal de activacion para empezar la demora
 *  de 10 segundos para iniciar la rutina de modo busqueda.
 * 
 * El comportamiento de Busqueda:
 *  tiene dos modos:
 *    deteccion de linea:
 *      si tiene detctada que una linea blanca esta presente avanza un periodo de tiempo
 *      n e inicia el modo ataque.
 *    Sin Deteccion de Linea:
 *      Avanza Hasta que detecta una linea y retorna para iniciar el modo ataque.
 * comportamiento de Ataque:
 *  tiene tres modos de ataque:
 *    CW:
 *      El robot Gira en le sentido de las manecillas del reloj.
 *    CCW:
 *      El Robot Gira en contra de las manecillas del reloj.
 *    FWD_REW:
 *      EL Robot Realiza Embestidas constantes contra el c ontrincante.
 *      con mivimientos incrementales.
 *    
 */

//Standar Includes.
#include <NewPing.h>
#define MAX_DISTANCE 50 //Maxima Distancia para detectar medida en centimetros.
//Enumeradores de maquina de estados.
enum comportamiento {arranque,inicio,busqueda,ataque};
enum busqueda{line_sense,no_line_sense,busqueda_combate};
enum ataques{CW,CCW,fwd_rew};
//Varialbes de estado
int estado_comportamiento;
int estado_busqueda;
int estado_ataque;
/*
 * Variables del motor de Pasos 1.
 */
 byte dir_mot_1 = 0;
 byte step_mot_1 = 1;
/*
 * Variables del Motor de pasos 2.
 */
 byte dir_mot_2 = 2;
 byte step_mot_2 = 3;
//Variables para sensor Ultrasonico Frontal.
 byte trigger = 4;
 byte echo = 5;
//Variables para sensor ultrasonico Anterior.
 byte trigger2 = 6;
 byte echo2 = 7;
//Variables de Interruptores de contacto lateral .
 byte sw_left = 8;
 byte sw_right = 9;
//Variables de Entrada analogica para sensores (4 Sensores TCRT5000)
 byte LF = 2; //Sensor Left Front del sumobot.
 byte RF = 3; //Sensor Rgith Front del SumoBot.
 byte LB = 4; //Sensor Left Back del sumobot.
 byte RB = 5;  //Sensor Right Back del sumobot.
 //Variable de Switch de inicio;
 byte start = 10;
 int retardo_s = 5;
//Declaracion de Objetos para sensores ultrasonicos.
//Sensor Frontal
NewPing frontal(trigger,echo,MAX_DISTANCE);
//Sensor Trasero
NewPing trasero(trigger2,echo2,MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
  motores_init(step_mot_1,dir_mot_1,step_mot_2,dir_mot_1);
  sensores_embestida_init(sw_left,sw_right);
  start_switch_init(start);
  estado_comportamiento = arranque;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(estado_comportamiento)
  {
    case arranque:
      if(digitalRead(start) == LOW)
      {
        delay(50);
        if(digitalRead(start) == LOW)
        {
          start_sequence(retardo_s);
          estado_comportamiento = inicio;
        }
      }
    break;
    case inicio:
      if(deteccion_atras() == true)
      {
        estado_comportamiento = busqueda;
        estado_busqueda = line_sense;
      }
      else
      {
        estado_comportamiento = busqueda;
        estado_busqueda = no_line_sense;
      }
    break;
    case busqueda:
      switch(estado_busqueda)
      {
        case line_sense:
          move_forward_inf(true,50);
          delay(2000);
          move_forward_inf(false,50);
          if(frontal.ping_cm() <= 10)
          {
            estado_comportamiento = ataque;
            estado_ataque = fwd_rew;
          }
          else if(embestida_izquierda(sw_left)== true)
          {
            estado_comportamiento = ataque;
            estado_ataque = CCW;
          }
          else if(embestida_derecha(sw_right) == true)
          {
            estado_comportamiento = ataque;
            estado_ataque = CW;
          }
        break;
        case no_line_sense:
          move_forward_inf(true,50);
          if(deteccion_adelante() == true)
          {
            move_forward_inf(false,50);
            if(sensor_linea_RF()==true)
            {
              CCW_attack(10,20);
              move_forward(10,10);
              estado_comportamiento = busqueda;
              estado_busqueda = line_sense;
            }
            else if(sensor_linea_LF() == true)
            {
              CW_attack(10,20);
              move_forward(10,10);
              estado_comportamiento = busqueda;
              estado_busqueda = line_sense;
            }
          }
        break;
        busqueda_combate:
          if(frontal.ping_cm() <= 10)
          {
            move_forward(30,5);
            estado_comportamiento = ataque;
            estado_ataque = fwd_rew;
          }
          else if(trasero.ping_cm() <= 10)
          {
            move_backward(30,5);
            estado_comportamiento = ataque;
            estado_ataque = fwd_rew;
          }
          else
          {
            CW_attack(15,20);
            CCW_attack(15,20);
          }
        break;
      }
    break;
    case ataque:
      switch(estado_ataque)
      {
        case CW:
          CW_attack(15,20);
          move_forward(15,20);
          estado_comportamiento = busqueda;
          estado_busqueda = busqueda_combate;
        break;
        case CCW:
          CCW_attack(15,20);
          move_forward(15,20);
          estado_comportamiento = busqueda;
          estado_busqueda = busqueda_combate;
        break;
        case fwd_rew:
          move_forward(5,10);
          move_backward(5,10);
          move_forward(7,10);
          move_backward(7,10);
          estado_comportamiento = busqueda;
          estado_busqueda = busqueda_combate;
        break;
      }
      
    break;
  }
}

/*
 * Funciones Basicas de Manejo de Motores de Pasos Usando el Driver de Pololu para
 * motores de pasos A4988.
 */
 /*
  * Prototype : motores_init()
  * Data In : 
  *   motor_1 : Senal de salida de pulsos para el driver.
  *   direccion_1 : Senal de salda de direccion para el driver.
  *   motor_2 : Senal de salida de Pulsos para el motor 2.
  *   direccion_2 :  Senal de Salida de Direccion para el motor 2.
  *  Data Out:
  *   None.
  *  Description:
  *   funcion de Inicializacion de los motores, configura las respectivas entradas y 
  *   salidas necesarias para mover ambos motores.
  */
void motores_init(byte motor_1, byte direccion_1, byte motor_2,byte direccion_2)
{
  //Modo de operacion de Motor
  pinMode(motor_1,OUTPUT);
  pinMode(motor_2,OUTPUT);
  pinMode(direccion_1,OUTPUT);
  pinMode(direccion_2,OUTPUT);
}
/*
 * Prototype : forwardM1().
 * Data In:
 *  pasos : cantidad de pasos que el motor de pasos debe de dar.
 *  retraso : cantidad de tiempor entre un paso y  el siguiente.
 * Data Out :
 *  none.
 * Description:
 *  Mueve hacia adelante el motor 1 de pasos.
 */
void forwardM1(int pasos,int retraso)
{
  unsigned int cnt = 0;
  digitalWrite(dir_mot_1,HIGH);
  do
  {
    digitalWrite(step_mot_1,HIGH);
    delay(retraso);
    digitalWrite(step_mot_1,LOW);
    delay(retraso);
    cnt++;
  }while(cnt <=pasos);
}
/*
 * Prototype : backwardM1().
 * Data In:
 *  paso : cantidad de pasos que el motor de pasos debe de dar.
 *  retrasos : cantidad de tiempor entre un paso y  el siguiente.
 * Data Out :
 *  none.
 * Description:
 *  Mueve hacia atrasel motor 1 de pasos.
 */
void backwardM1(int paso, int retrasos)
{
  unsigned int cnt = 0;
  digitalWrite(dir_mot_1,LOW);
  do{
      digitalWrite(step_mot_1,HIGH);
      delay(retrasos);
      digitalWrite(step_mot_1,LOW);
      delay(retrasos);
      cnt++;
  }while(cnt <=paso);
}
/*
 * Prototype : forwardM2().
 * Data In:
 *  pasos : cantidad de pasos que el motor de pasos debe de dar.
 *  retraso : cantidad de tiempor entre un paso y  el siguiente.
 * Data Out :
 *  none.
 * Description:
 *  Mueve hacia adelante el motor 2 de pasos.
 */
void forwardM2(int pasos,int retraso)
{
  unsigned int cnt = 0;
  digitalWrite(dir_mot_2,HIGH);
  do
  {
    digitalWrite(step_mot_2,HIGH);
    delay(retraso);
    digitalWrite(step_mot_2,LOW);
    delay(retraso);
    cnt++;
  }while(cnt <=pasos);
}
/*
 * Prototype : backwardM2().
 * Data In:
 *  pasos : cantidad de pasos que el motor de pasos debe de dar.
 *  retraso : cantidad de tiempor entre un paso y  el siguiente.
 * Data Out :
 *  none.
 * Description:
 *  Mueve hacia atras el motor 2 de pasos.
 */
void backwardM2(int paso, int retrasos)
{
  unsigned int cnt = 0;
  digitalWrite(dir_mot_2,LOW);
  do{
      digitalWrite(step_mot_2,HIGH);
      delay(retrasos);
      digitalWrite(step_mot_2,LOW);
      delay(retrasos);
      cnt++;
  }while(cnt <=paso);
}
/*
 * Prototype : sensor_linea_LF()
 * Data In:
 *  None.
 * Data Out:
 *  true / false
 * Description:
 *  Devuelve un valor de Cierto o Falso (True / False) en funcion de si detecto una linea
 *  o no. LF es por Frontal Izquierdo.
 */
bool sensor_linea_LF(void)
{
  int analog = 0;
  analog = analogRead(LF);
  if(analog >= 600)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/*
 * Prototype : sensor_linea_RF()
 * Data In:
 *  None.
 * Data Out:
 *  true / false
 * Description:
 *  Devuelve un valor de Cierto o Falso (True / False) en funcion de si detecto una linea
 *  o no. RF es por Frontal Derecho.
 */
bool sensor_linea_RF(void)
{
  int analog = 0;
  analog = analogRead(RF);
  if(analog >= 600)
  {
    return true;
  }
  else
  {
    return false;
  };
}
/*
 * Prototype : sensor_linea_LB()
 * Data In:
 *  None.
 * Data Out:
 *  true / false
 * Description:
 *  Devuelve un valor de Cierto o Falso (True / False) en funcion de si detecto una linea
 *  o no. LB es por Anterior Izquiedro.
 */
bool sensor_linea_LB(void)
{
  int analog = 0;
  analog = analogRead(LB);
  if(analog >= 600)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/*
 * Prototype : sensor_linea_LB()
 * Data In:
 *  None.
 * Data Out:
 *  true / false
 * Description:
 *  Devuelve un valor de Cierto o Falso (True / False) en funcion de si detecto una linea
 *  o no. RB es por Anterior Derecho.
 */
bool sensor_linea_RB(void)
{
  int analog = 0;
  analog = analogRead(RB);
  if(analog >= 600)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/*
 *  Prototype: sensores_embestida_init()
 *  Data In:
 *    byte sensor1
 *    `Numero de Pin del sensor de embetida 1.
 *    byte sensor2
 *    `Numero de pin del sensor de embestida 2.
 *   Data Out:
 *    None.
 */
void sensores_embestida_init(byte sensor1,byte sensor2)
{
  pinMode(sensor1,INPUT_PULLUP);
  pinMode(sensor2,INPUT_PULLUP);
}
/*
 *    Prototype:
 *      embestida_izquierda()
 *    Data In;
 *      byte "sensor"
 *        Numero de Pin en donde esta conectado el sensor de embestida.
 *    Data Out:
 *      TRUE/FALSE
 *    
 *    Description:
 *      Detecta si existe un emuje de un robot por el lado izquierdo del robot.
 * 
 */
bool embestida_izquierda(byte sensor)
{
  if(digitalRead(sensor) == LOW)
  {
    return false;
  }
  else
  {
    return true;
  }
}
/*
 * Prototype:
 *  embestida_derecha()
 *  Data In:
 *    byte "sensor"
 *  Data Out:
 *    TRUE/FALSE
 *  Description:
 *    Detecta si se ha presentado una embetida por el lado derecho del robot.
 */
bool embestida_derecha(byte sensor)
{
  if(digitalRead(sensor) == LOW)
  {
    return false;
  }
  else
  {
    return true;
  }
}
/*
 * Prototype: deteccion_atras()
 * Data In:
 *  None.
 * Data Out:
 *  TRUE/FALSE
 * Description:
 *  Devuleve un cierto o falso segun se presente una linea blanca
 *  en cualesquiera de los dos sensores de linea.
 */
bool deteccion_atras(void)
{
  if(sensor_linea_RB()||sensor_linea_LB())
  {
    return true;
  }
  else
  {
    return false;
  }
}
/*
 * Prototype: deteccion_adelante()
 * Data In:
 *  None.
 * Data Out:
 *  TRUE/FALSE
 * Description:
 *  Devuelve un Valor cierto o falso acorde a los dos sensores frontales TCRT5000
 *  de que si se detecta linea o no.
 */
bool deteccion_adelante(void)
{
  if(sensor_linea_RF()||sensor_linea_LF())
  {
    return true;
  }
  else
  {
    return false;
  }
}
/*
 * Prototype: start_switch_init()
 * Data In:
 *  byte "sw"
 * Data Out:
 *  None.
 * Descrprtion:
 *  Permite declarar el pin "sw" como entrada para la senal de arranque.
 */
void start_switch_init(byte sw)
{
  pinMode(sw,INPUT_PULLUP);
}
/*
 * Prototype: start_sequence()
 * Data In:
 *  int "Segundos"
 * Data Out: 
 *  None.
 * Description:
 *  Permite un retrao de 5 segudos entre la senal de arranque y el inicio de busqueda de
 *  linea y contrincante.
 */
void start_sequence(int segundos)
{
  for(int i=0;i<=segundos-1;i++)
  {
    delay(1000);
  }
}
/*
 * Prototype : move_forward_inf()
 * Data In :
 *  bool "control": 
 *    senal de control para mantener activo el motor de pasos.
 *  int "retraso":
 *    senal de tiempo entre paso y paso en el giro del motor de pasos.
 *  Data Out:
 *    None.
 *  Description:
 *    MAntiene en movimiento continuo el robot hacia adelante.
 */
void move_forward_inf(bool control,int retraso)
{
  digitalWrite(dir_mot_1,HIGH);
  digitalWrite(dir_mot_2,HIGH);
  while(control == true)
  {
    digitalWrite(step_mot_1,HIGH);
    digitalWrite(step_mot_2,HIGH);
    delay(retraso);
    digitalWrite(step_mot_1,LOW);
    digitalWrite(step_mot_2,LOW);
    delay(retraso);
  }
}
/*
 * Prototye : CCW_attack()
 * Data In:
 *  integer "steps":
 *    cantidad de pasos de desplazamiento angular.
 *  integer "retraso":
 *    cantidad de tiempo entre pulso y pulso para que avance el motor de pasos.
 *  Data Out:
 *     none.
 *  Description:
 *    produce un movimiento angular sobre el propio eje del robot, en el sentido en contra  de las
 *    de las manecillas del reloj.
 */
void CCW_attack(int steps,int retraso)
{
  int cnt = 0;
  digitalWrite(dir_mot_1,LOW);
  digitalWrite(dir_mot_2,HIGH);
  do{
    digitalWrite(step_mot_1,HIGH);
    digitalWrite(step_mot_2,HIGH);
    delay(retraso);
    digitalWrite(step_mot_1,LOW);
    digitalWrite(step_mot_2,LOW);
    delay(retraso);
  }while(cnt <= steps);
}
/*
 * Prototye : CW_attack()
 * Data In:
 *  integer "steps":
 *    cantidad de pasos de desplazamiento angular.
 *  integer "retraso":
 *    cantidad de tiempo entre pulso y pulso para que avance el motor de pasos.
 *  Data Out:
 *     none.
 *  Description:
 *    produce un movimiento angular sobre el propio eje del robot, en el sentido de las
 *    manecillas del reloj.
 */
void CW_attack(int steps,int retraso)
{
  int cnt = 0;
  digitalWrite(dir_mot_1,HIGH);
  digitalWrite(dir_mot_2,LOW);
  do{
    digitalWrite(step_mot_1,HIGH);
    digitalWrite(step_mot_2,HIGH);
    delay(retraso);
    digitalWrite(step_mot_1,LOW);
    digitalWrite(step_mot_2,LOW);
    delay(retraso);
  }while(cnt <= steps);
}
/*
 * Prototye : move_forward()
 * Data In:
 *  integer "pasos":
 *    cantidad de pasos de desplazamiento angular.
 *  integer "retraso":
 *    cantidad de tiempo entre pulso y pulso para que avance el motor de pasos.
 *  Data Out:
 *     none.
 *  Description:
 *    avanza una catidad de pasos estipulada y detiene la operaciopn de los pulsos.
 */
void move_forward(int pasos, int retraso)
{
  int cnt =0;
  digitalWrite(dir_mot_1,HIGH);
  digitalWrite(dir_mot_2,HIGH);
  
  do{
    digitalWrite(step_mot_1,HIGH);
    digitalWrite(step_mot_2,HIGH);
    delay(retraso);
    digitalWrite(step_mot_1,LOW);
    digitalWrite(step_mot_2,LOW);
    delay(retraso);
    cnt++;
  }while(cnt <=pasos);
}

/*
 * Prototye : move_backward()
 * Data In:
 *  integer "pasos":
 *    cantidad de pasos de desplazamiento angular.
 *  integer "retraso":
 *    cantidad de tiempo entre pulso y pulso para que avance el motor de pasos.
 *  Data Out:
 *     none.
 *  Description:
 *    avanza una catidad de pasos estipulada y detiene la operaciopn de los pulsos.
 */
void move_backward(int pasos, int retraso)
{
  int cnt =0;
  digitalWrite(dir_mot_1,LOW);
  digitalWrite(dir_mot_2,LOW);
  
  do{
    digitalWrite(step_mot_1,HIGH);
    digitalWrite(step_mot_2,HIGH);
    delay(retraso);
    digitalWrite(step_mot_1,LOW);
    digitalWrite(step_mot_2,LOW);
    delay(retraso);
    cnt++;
  }while(cnt <=pasos);
}
