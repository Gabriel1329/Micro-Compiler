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
extern void enter(char* variable);
extern void enterOP(char* variable);
extern void check_id(char* s);
extern char* gen_reg(void);
extern void start(void);
extern void finish(void);
extern void assign(expr_rec target, expr_rec source);
extern op_rec process_op(void);
extern void gen_infix(char* e1, char* op, char* e2);
//extern void read_id(expr_rec in_var);
extern void read_id();
extern expr_rec process_id(void);
extern expr_rec process_literal(void);
extern void writer_expr(expr_rec out_expr);
extern void generate(char *op, char * A, char * B, char * C);
extern void revisarAsignacion(char *s);
extern void mostrarTabla(SymbolTable t);
extern void operando(char* o);
extern char* get_reg(char* s);
void codigoOperacion(void);
int verificarNumero(char* n);


    



#ifdef	__cplusplus
}
#endif

#endif	/* TRADUCTOR_H */

