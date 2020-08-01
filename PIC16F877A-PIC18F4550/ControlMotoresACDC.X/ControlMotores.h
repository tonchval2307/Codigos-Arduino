/* 
 * File:   ControlMotores.h
 * Author: c4810
 *
 * Created on February 10, 2020, 9:18 AM
 */

#ifndef CONTROLMOTORES_H
#define	CONTROLMOTORES_H

#include <xc.h>

unsigned int Contador(unsigned int mode);
void MotorDC(unsigned int Mode);
void ModoApagado(void);
void ModoEncendido(void);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONTROLMOTORES_H */

