/* 
 * File:   parser.h
 * Author: soto
 *
 * Created on 17 de febrero de 2016, 07:42 PM
 */

#ifndef PARSER_H
#define	PARSER_H

#include "scanner.h"


#ifdef	__cplusplus
extern "C" {
#endif

extern void system_goal(void);
extern void program(void);
extern void statement_list(void);
extern void statement(void);
extern void id_list(void);
extern void expression (void);
extern void expr_list(void);
extern void add_op(void);
extern void primary(void);
extern void match(token pToken);
extern void syntax_error(token pToken);
extern char * getTokenText(token pToken);
    


#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_H */

