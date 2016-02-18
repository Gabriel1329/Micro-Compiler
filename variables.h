/* 
 * File:   variables.h
 * Author: soto
 *
 * Created on 17 de febrero de 2016, 03:58 PM
 */

#ifndef VARIABLES_H
#define	VARIABLES_H

#include "estructuturas.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif


char token_buffer[];
token current_token;


FILE *archivoEntrada;
FILE *archivoSalida;

bool matched; 
    


#ifdef	__cplusplus
}
#endif

#endif	/* VARIABLES_H */

