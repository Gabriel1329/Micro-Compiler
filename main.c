/* 
 * File:   main.c
 * Author: soto
 */

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "scanner.h"

/* 
void system_goal(void)
{
   <system goal> ::= <program> SCANEOF 
    program();
    match(SCANEOF);
}
*/

/*
void program(void)
{
     <program> ::= BEGIN <statement list> END
    match(BEGIN);
    statement_list();
    match(END);
}
*/

/*
void statement_list(void)
{
    
     *<statement list> ::= <statement>
     *                     { <statement>}   
     
    
    statement();
    while (true){
        switch (next_token()){
            case ID:
            case READ:
            case WRITE:
                statement();
                break;
            default:
                return;
        }
    }
}
*/


/*
void statement(void)
{
    token tok = next_token();
    
    switch (tok) 
    {
        case ID:
 */
            /* <statement> ::= ID := <expression> ;*/
/*            match(ID); 
            match(ASSIGNOP);
            expression(); 
            match(SEMICOLON);
            break;
            
        case READ:
 */
            /* <statement> ::= READ (<id list>);*/
/*            match(READ);
            match(LPAREN);
            id_list();
            match(RPAREN);
            match(SEMICOLON);
            break;
        
        case WRITE:
 */
            /*<statement> ::= WRITE (<expr list>) ;*/
/*            match(WRITE); 
            match(LPAREN);
            expr_list();
            match(RPAREN);
            match(SEMICOLON);
            break;
            
        default:
            syntax_error(tok);
            break;
            
    }
}
 */
 /*
void id_list(void)
{
    <id list> ::= ID { , ID}
    match(ID);
    
    while (next_token() == COMMA)
    {
        match(COMMA);
        match(ID);
    }
}
*/


/*
void expression (void)
{
    token t;
    
    
     * <expression> ::= <primary> 
     *                  { <add op> <primary>}
     
    primary();
    for (t= next_token(); t==PLUSOP || t== MINUSOP ; t = next_token())
    {
        add_op();
        primary();
    } 
}
*/

/*
void expr_list(void)
{
     <expr list> ::= <expression> { , <expression>}
    expression();
    
    while (next_token() == COMMA)
    {
        match(COMMA);
//        expression(exp);
    }
}
*/

/*
void add_op(void)
{
    token tok = next_token();
     <addop> ::= PLUSOP | MINUSOP
    if(tok == PLUSOP || tok == MINUSOP)
        match(tok);
    else
        syntax_error(tok);
}
*/

/*
void primary(void)
{
    token tok = next_token();
    
    switch(tok)
    {
        case LPAREN:
 */
            /* <primary> ::= (<expression>)*/
/*           
            match(LPAREN); 
            expression();
            match(RPAREN);
            break;
            
        case ID:
 */
            /* <primary> ::= ID*/
/*            match(ID);
            break;
            
        case INTLITERAL:
 */
            /* <primary> ::= INTLITERAL*/
 /*           match(INTLITERAL);
            break;
            
        default:
            syntax_error(tok);
            break;
            
            
    }
}

*/


/* Is s in the symbol table?
extern int lookup(string s);
*/
/* Put s unconditionally into simbol table
extern void enter(string s);
*/
/*

void check_id(string s)
{
  if(! lookup(s)){
      enter(s);
//      generate("Declare",s,"Integer","");
  }
}
*/

/*
char *get_temp(void)
{
    max temporary allocated so far
    static int max_temp = 0;
    static char tempname[MAXIDLEN]; //En realidad el tamaño es MAXIDLEN ;
    
    max_temp++;
    sprintf(tempname,"Temp&%d",max_temp);
    check_id(tempname);
    return tempname;
}
*/

/*
void start(void)
{
     Semantc initializations, none needed
}
*/

/*
void finish(void)
{
     Generate code to finish program.
//    generate("Halt","","","");
}
*/

/*
void assign(expr_rec target, expr_rec source)
{
     Generate code for assignment.
//    generate("Store", extract(source), target.name,"");
}
*/
 /*
op_rec process_op(void)
{
   Produce operator descriptor.
    op_rec o;
    
    if(current_token == PLUSOP)
        o.operators = PLUS;
    else
        o.operators = MINUS;
    return o;
}
*/


//expr_rec gen_infix(expr_rec e1,op_rec op, expr_rec e2)
//{
//    expr_rec e_rec;
    /* An expr_rec with temp variant set.*/
    
//    e_rec.kind = TEMPEXPR;
    /*
     * Generate code for infix operatin.
     * Get result temp and set up semantic record  
     * for result
     */
//    strcpy(e_rec.name, get_temp());

//    generate(extract(op),extract(e1),extract(e2),e_rec.name);

//    return e_rec;
//}


/*
 * 
 * 
void read_id(expr_rec in_var)
{
    Generate code for read.
//    generate("READ",in_var.name,"INTEGER","");
}
*/

/*
expr_rec process_id(void)
{
    expr_rec t;
    
     * Declare ID and build a
     * corresponding semantic record
     
    check_id(token_buffer);
    t.kind = IDEXPR;
    strcpy(t.name, token_buffer);
    return t;
}
*/

/*
expr_rec process_literal(void)
{
    expr_rec t;
    
     * Convert literal to a numeric representation
     * and build semantic record.
     
    t.kind = LITERALEXPR;
    (void) sscanf(token_buffer, "%d", & t.val);
    return t;
}
*/

/*
void writer_expr(expr_rec out_expr)
{
//    generate("Write",extract(out_expr),"Integer","");
}
*/

/*
void expression (expr_rec *result)
{
    expr_rec left_operand, right_operand;
    op_rec op;
    
    primary(& left_operand);
    while(next_token() == PLUSOP ||
          next_token() == MINUSOP)
    {
        add_op(& op);
        primary(& right_operand);
        left_operand = gen_infix(left_operand,op,right_operand);
    }
    *result = left_operand;
}
*/


/*EL CODIGO DE AQUI EN ADELANTE LO PUSE SOLO PARA QUE NO DE ERRORES, EN RESUMEN 
 * SOLO TENEMOS EL CODIGO DEL LIBRO DIGITADO
 -) Hay que implemnetar generate
 -) ver cual funcion expresion utilizar, xq hay una con parametro y otra sin parametro
 -) Cree la variable current_token 
 -) TUVE QUE PONERLE VALOR A MAXIDLEN PARA QUE NO DIERA ERROR
 */ 
//extern token next_token();

/*
token next_token()
{
    return current_token;
}

extern void match(token pToken);
extern void syntax_error(token pToken);
*/



int main(int argc, char** argv) 
{
//Se pone el path de la siguiente manera    
//home/soto/NetBeansProjects/Micro-Compiler/Texto.txt ó Texto.txt
//se puede poner solo Texto.txt por que el archivo esta en la carpeta del proyecto
    
    char direccionArchivo[150];
    printf( "Bienvenido a Micro-Compiler, Ingrese la ruta del archivo: " );
    scanf( "%s", direccionArchivo );
  
    
    
    archivoEntrada = freopen( direccionArchivo, "r", stdin );
    
    if (!archivoEntrada)
    {
        printf( "El archivo no existe" );
        return EXIT_FAILURE;
    }
    
    
    while(current_token != SCANEOF)
    {
        current_token = scanner();
    }
    
    fclose( archivoEntrada );
    
    return EXIT_SUCCESS;    
}

