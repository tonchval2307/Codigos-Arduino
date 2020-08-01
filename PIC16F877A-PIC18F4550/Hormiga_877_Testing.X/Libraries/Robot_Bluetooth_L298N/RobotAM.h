/* 
 * File:   RobotAM.h
 * Author: c4810
 *
 * Created on November 13, 2019, 1:43 PM
 */

#ifndef ROBOTAM_H
#define	ROBOTAM_H

#include "system.h"

void AdelanteMotorIzquierdo(void);
void AtrasMotorIzquierdo(void);
void AdelanteMotorDerecho(void);
void AtrasMotorDerecho(void);
void Adelante(uint16_t Velocidad);
void Atras(uint16_t Velocidad);
void Izquierda(uint16_t Velocidad);
void Derecha(uint16_t Velocidad);
void Detener(void);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ROBOTAM_H */

