#define _XTAL_FREQ 20000000
#include "Tonche_16F877.h"
#define true 1
#define false 0

volatile int data;
void setup()
{
    TRISDbits.TRISD2 = 0;
    TRISEbits.PSPMODE = 0;
    GlobalInterruptEnable(true);
    PeripheralIntEnable(true);
    PortBChangeIntEnable(false);
    SSPInterruptEnable();
    spiSlavebegin();
    portdMode(2,OUTPUT);
    digitalWrite(2,PD,LOW);
    spiCLKpolarity(LOW);
    for( int i=0;i<=7;i++)
    {
        portbMode(i,OUTPUT);
    }

}
void loop()
{
    if(spiBufferfull() == 1)
    {
        PORTB = spiRead();
        PORTDbits.RD2 = 1;
    }
    else
    {
        //PORTB = 0x00;
        PORTDbits.RD2 = 0;
    }
}


/*
 * V1.0 La versio 1.0 de la conexion de Arduino y pic
 * usa una interrupcion.
 * a continuacion descrita.
 */
/*
void interrupt isr(void)
{
    if(SSPIFinterrupt() == 1)
    {
        PORTB = SSPBUF;
        SSPBUF = 0;
        TxRxOcurredReset();
    }
}
 *
 * */
