/* 
 * File:   funcionesUtiles.h
 * Author: soto
 *
 * Created on 18 de febrero de 2016, 08:35 AM
 */

#ifndef FUNCIONESUTILES_H
#define	FUNCIONESUTILES_H

#include <string.h>

#ifdef	__cplusplus
extern "C" {
#endif

extern int comparacionCadenas(char* buffer, char* token, int pLargo);
extern void reverse(char s[]);
extern void itoa(int n, char s[]);

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCIONESUTILES_H */

