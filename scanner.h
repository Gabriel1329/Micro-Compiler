/* 
 * File:   scanner.h
 * Author: soto
 *
 * Created on 17 de febrero de 2016, 10:39 AM
 */



#ifndef SCANNER_H
#define	SCANNER_H

#include "variables.h" 
#include "funcionesUtiles.h"
#include <string.h>


#ifdef	__cplusplus



extern "C" {
#endif

extern void clear_buffer(void);
extern void buffer_char(int c);
extern token check_reserved(void);
extern void lexical_error(int c);
extern token scanner(void);
extern token next_token(void);



#ifdef	__cplusplus
}
#endif

#endif	/* SCANNER_H */

