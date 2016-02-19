/* 
 * File:   estructuturas.h
 * Author: soto
 *
 * Created on 17 de febrero de 2016, 10:47 AM
 */

#ifndef ESTRUCTUTURAS_H
#define	ESTRUCTUTURAS_H

#ifdef	__cplusplus
extern "C" {
#endif

//DEFINE

    
#define  DEBUG  true
#define MAXIDLEN 100
    
    
typedef char string[MAXIDLEN];    

    
typedef enum token_types {
    BEGIN, END, READ, WRITE, ID, INTLITERAL,
    LPAREN, RPAREN, SEMICOLON, COMMA, ASSIGNOP,
    PLUSOP, MINUSOP, SCANEOF
}token;

typedef struct operator 
{ /* for operators*/
    enum op { PLUS, MINUS} operators;
}op_rec;

/* expression types*/
enum expr {IDEXPR, LITERALEXPR, TEMPEXPR};

/* for <primary> and <expression>*/
typedef struct expression
{
    enum expr kind;
    union
    {
        string name; /* for IDEXPR, TEMPEXPR*/
        int val;     /* for LITERALEXPR*/
    };
}expr_rec;








#ifdef	__cplusplus
}
#endif

#endif	/* ESTRUCTUTURAS_H */

