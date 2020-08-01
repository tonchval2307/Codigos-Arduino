/*
 * Estructura Basica de un Programa -sketch- en arduino:
 *  void setup(){
 *  }
 *  El "void setup" solamente se ejecuta una sola ocasion en el programa.
 *  funciona para realizar configuraciones previas a la realizacion del 
 *  programa principal.
 *  funciones comunes:
 *    pinMode(<Numero_de_Pin>,<Modo_Operacion>)
 *    <Numero_de_Pin>
 *     Es un numero entero de 8 bits de tamano que indica que pin de arduino (fisicamente)
 *     puede ser desde el valor 1 hasta el 13. 
 *    <Modo_Operacion>
 *    Es el Modo en el que se puede hacer funcionar un pin digital de la placa Arduino.
 *    puede ser las siguientes configuraciones:
 *    Las Declaraciones deben de ser escritas en Mayusculas.
 *    INPUT
 *      Habilita el Pin Digital de la Placa de Arduino para revisar valores logicos del 
 *      exterior (Interrputores, Sensores con Salida Digital, Etc.).
 *    OUTPUT
 *      Habilita el Pin Digital del Arduino para Generar hacia el Exterior Voltage de
 *      encendido o apagado (encender o apagar dispositivos).
 *    INPUT_PULLUP
 *      Habilita una resistencia interna en la entrada digital del arduino que ingresa
 *      un valor por defecto de "1" Logico en la entrada digital del arduino.
 *      Ideal para conectar push buttons o sensores de salida digital.
 *    Serial.Begin(<Velocidad_Bauidos>)
 *      Permite la comunicacion entre el arduino y la computadora para el intercambio de 
 *      datos.
 *      <Velocidad_Baudios>
 *      es la valocidad en que se intercambian los datos entre la computadora y el arduino
 *  void loop(){
 *  }
 *  El "void loop()" es la parte del programa que se repite continuamente; aqui se coloca
 *  el algoritmo de trabajo del Arduino, donde se gestionan el estado de las entradas
 *  y salidas configuradas previamente en el "void setup()".
 */
unsigned int led = 8;  //Valor sin signo que funionara para configurar una

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);//Se declara el Pin 8 como salida.

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  /*
   * digitalWrite(<Numero_Pin>,<Estado>)
   * <Numero_Pin>
   *  Se ingresa el valor de pin en donde se quiere escribir el dato digital.
   * <Estado>
   *  Se ingresa uno de dos valores digitales:
   *  HIGH
   *    Es un Valor digital en la salida del arduino de aproximadamente 5V.
   *  LOW
   *    Es un Valor digital en la salida del arduino aproximandamente 0v.
   */
   delay(500);
   /*
    * delay(<milisegundos>)
    * Es un retardo de tiempo el cual esta en unidades de milisegundos.
    * delayMicroseconds(<microsegundos>)
    * Es un retrdo de tiempo en microsegundos.
    */
    digitalWrite(led,LOW);
    delay(500);

}
