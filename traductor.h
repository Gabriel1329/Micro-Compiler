/* 
 * File:   traductor.h
 * Author: soto
 *
 * Created on 19 de febrero de 2016, 10:01 AM
 */

#ifndef TRADUCTOR_H
#define	TRADUCTOR_H

#include "variables.h"

#ifdef	__cplusplus
extern "C" {
#endif

/* Is s in the symbol table?*/
extern int lookup(string s);

/* Put s unconditionally into simbol table*/
extern void enter(string s);
extern void check_id(string s);
extern char *get_temp(void);
extern void start(void);
extern void finish(void);
extern void assign(expr_rec target, expr_rec source);
extern op_rec process_op(void);
extern expr_rec gen_infix(expr_rec e1,op_rec op, expr_rec e2);
extern void read_id(expr_rec in_var);
extern expr_rec process_id(void);
extern expr_rec process_literal(void);
extern void writer_expr(expr_rec out_expr);
extern void   generate(char * op, char * A, char * B, char * C);



    



#ifdef	__cplusplus
}
#endif

#endif	/* TRADUCTOR_H */

