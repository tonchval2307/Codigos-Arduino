
// Dimensiones del robot.
double A = 1; //Ubicacion de Sensor 1 y 8
double B = 2; //Ubicacion de sensor 2 y 7
double C = 3; //ubicacion de sensor 3 y 6
double D = 4; //Ubicacion de sensor 4 y 5
double F = 3; //Altura del array de sensores respecto a la base del robot.

const int S1 = 0;
const int S2 = 1;
const int S3 = 2;
const int S4 = 3;
const int S5 = 4;
const int S6 = 5;
const int S7 = 6;
const int S8 = 7;

double angulos1;
double angulos2;
double angulos3;
double angulos4;
double angulos5;
double angulos6;
double angulos7;
double angulos8;
const int array_sensores[8] = {S1,S2,S3,S4,S5,S6,S7,S8}
double medicion[8];
double angulo_array[8];

double sensores_y[8];
double sensores_x[8];

double suma_x;
double suma_y;
double direccion;
double accion_control;
double pi = 3.14162859;
void setup(void)
{
	
	angulos1 = angulo(F,D);
	angulos2 = angulo(F,C);
	angulos3 = angulo(F,B);
	angulos4 = angulo(F,A);
	angulos5 = angulo(F,-A);
	angulos6 = angulo(F,-B);
	angulos7 = angulo(F,-C);
	angulos8 = angluo(F,-D);
	angulo_array[0] = angulos1;
	angulo_array[1] = angulos2;
	angulo_array[2] = angulos3;
	angulo_array[3] = angulos4;
	angulo_array[4] = angulos5;
	angulo_array[5] = angulos6;
	angulo_array[6] = angulos7;
	angulo_array[7] = angulos8;
}

void loop(void)
{
	for(int i=0;i<8;i++)
	{
		medicion[i] = analogRead(array_sensores[i]);
		sensores_y[i] = medicion[i] * sin(angulo_array[i]);
		sensores_x[i] = medicion[i] * cos(angulo_array[i]);
		
	}
	for(int i=0;i<8;i++)
	{
		suma_x += sensores_x[i];
		suma_y += sensores_y[i];
	}
	direccion = atan(suma_y / suma_x);
	accion_control = pid(pi / 2 ,direccion);
	mover_motores(accion_control);
}

double angulo(double vert, double hori)
{
	double temp1 = vert / hori;
	return atan(temp1);
}

double pid(double setpoint, double var_control)
{
	
}

void mover_motores(double control_signal)
{
	
}
