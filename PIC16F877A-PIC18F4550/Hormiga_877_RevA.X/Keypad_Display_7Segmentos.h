#include "system.h"
#include "Keypad4x4.h"
#include <stdio.h>

#define A 7
#define B 8
#define C 9
#define D 10
#define E 11
#define F 12
#define G 13

// teclado Matricial
char Teclas[4][4] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'},
};
char Tecla = 'n';
const int ROWS[4] = {14,15,16,17};
const int COLS[4] = {18,19,20,21};

// display de 7 Segmentos;
//-------------------{a,b,c,d, e, f ,g }
char Terminales[7] = {7,8,9,10,11,12,13};

void setup()
{
    KeypadBegin(ROWS,COLS,Teclas);
    for(int i=0;i<7;i++)
    {
        pinMode(Terminales[i],OUTPUT);
    }
}


void loop()
{
    Tecla = KeypadRead();
    if(Tecla != NO_KEY)
    {
        switch(Tecla)
        {
            case '0':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '1':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '2':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '3':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '4':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '5':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '6':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '7':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '8':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '9':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case 'A':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case 'B':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case 'C':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case 'D':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '*':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
            case '#':
                digitalWrite(A,LOW);
                digitalWrite(B,LOW);
                digitalWrite(C,LOW);
                digitalWrite(D,LOW);
                digitalWrite(E,LOW);
                digitalWrite(F,LOW);
                digitalWrite(G,LOW);
                break;
        }
    }
}