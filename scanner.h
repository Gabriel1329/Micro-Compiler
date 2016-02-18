/* 
 * File:   scanner.h
 * Author: soto
 *
 * Created on 17 de febrero de 2016, 10:39 AM
 */



#ifndef SCANNER_H
#define	SCANNER_H

#include "variables.h" 
#include <string.h>


#ifdef	__cplusplus



extern "C" {
#endif

extern void clear_buffer();
extern void buffer_char(int c);
extern token check_reserved();
extern void lexical_error(int c);
extern token scanner();



#ifdef	__cplusplus
}
#endif

#endif	/* SCANNER_H */

