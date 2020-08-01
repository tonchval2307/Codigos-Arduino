#Include <18f4550.h>       //Archivo libreria del pic 18f4550
#Device ADC = 10

// Configuracion para USB con cristal oscilador de 4MHz
#Fuses XTPLL //Se habilita le Demux para dividir la frecuencia de salida del PLL de 96MHz como Salida
#fuses PLL1 //Se divide la frecuencia del PLL entre 1 comno es de 4 MHz la entrada del PLL para generar 96 MHz no es necesario dividirla
#Fuses USBDIV //Se selecciona la salida de 48Mhz para la operacion de USB transceiver
#Fuses CPUDIV1 //Se selecciona la division de la frecuencia /2 del PLLUSB que da 48MHz
#Fuses VREGEN  //Se Habilita el regulador de 3.3v interno del PIC
#Fuses MCLR    //Se habilita el MCLR
#Fuses NOWDT   //Se dehabilita el watchdog timer
#Fuses NOPROTECT     //Se dehabilita la porteccion de codigo
#Fuses NOLVP         //Se dehabilita la programacion por bajo voltaje
#Fuses NODEBUG       //Se habilita le modo debug
#Fuses NOPBADEN      //Se deshabilitan los canales analogicos del puerto B

#Use delay(clock = 48000000)     //freucencia de oscilador declarada en el compilador

//#Include <usb_cdc.h>             //Libreria de la comunicacion CDC
//#Include <usb_desc_cdc.h>        //Librerias de descriptores para la conexion Cdc
/* Designacion de etiquetas */

#Define ledgrn PIN_D0
#Define ledred PIN_D1
#Define off output_low
#Define on output_high

/* Declaracion de variables globales del programa   */


/* Inicion del programa   */
void main(void)
{
   int16 valor,control; //Variables para la lectura de ADC y la senal de control a modulo CCP
   FLOAT a,b,c;         //Constantes para parametros de controlador PID
   Float limite_temperatura;  //Referencia de temperatura
   Float rt,et,it,dt,yt,ut,it0,et0; //Variables de controlador PID
   Float max,min;       //Variables para anti-Windup
   
   min = 0.0;
   max = 1000.0;
   it0 = 0.0;
   et0 = 0.0;
   a = 0.1243;
   b = 0.0062;
   c = 0.6215;
   limite_temperatura = 1200.0;   //Set-point r(kt) = 120c
   
   setup_timer_2(t2_div_by_4,249,1);  //Configuracion de Timer 2 para establecer Frec. PWM a 1KHz
   setup_ccp1(ccp_pwm); //COnfigurar modulo CCP1 en modo PWM
   setup_adc(all_analog);  //Configurar ADC
   set_adc_channel(0);     //Seleccionar Canal 0 para sensor de temperatura
  
   while(TRUE)
   {
      valor = read_adc();
      yt = 5000 * (valor/1024);  //Escalado de la senal de error.
      rt = limite_temperatura;
      et = rt - yt;  //Calculo de la senal de error.
      it = (b * et)+it0;
      dt = c * (et - et0);
      ut = it + (a*et) + dt;
      
      if(ut > max)
      {
         ut = max;
      }
      else
      {
         if(ut < min)
         {
            ut = min;
         }
      }
      
      control = ut;
      set_pwm1_duty(control);
      it0 = it;
      et0 = et;
      delay_ms(100);
      
   }
   
}



