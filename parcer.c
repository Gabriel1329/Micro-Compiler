#include "parser.h"
#include "variables.h"


void system_goal(void)
{
  /* <system goal> ::= <program> SCANEOF */ 
    program();
    match(SCANEOF);
    finish();
}

void program(void)
{
  /*   <program> ::= BEGIN <statement list> END*/
    // Probando si con esto se corrige el error
    matched = true;
    fprintf(stderr, "        .text\n");
    fprintf(stderr, "        .globl main\n");
    fprintf(stderr, "main:\n");
    match(BEGIN);
    statement_list();
    match(END);
}

void statement_list(void)
{
    /*
     *<statement list> ::= <statement>
     *                     { <statement>}   
     */
    statement();
    
    while (true)
    {
        next_token();
        matched = false;
        switch (current_token)
        {
            case ID:
                statement();
                break;
            case READ:
                statement();
                break;
            case WRITE:
                statement();
                break;
            case CONS:
                statement();
                break;
            default:
                return;
        }
    }
    
}

void statement(void)
{   
    if (matched)
    {
        next_token();
    }
    
    switch (current_token) 
    {
        case ID:

            /* <statement> ::= ID := <expression> ;*/
            matched = false;
            match(ID); 
            match(ASSIGNOP);
            restriccionConstante(identificador);
            enterOP(identificador);
            posTable = symbolTable.freepointer;
            expresion = true;
            expression();
            matched = false;
            match(SEMICOLON);
            symbolTable.freepointer = posTable;
            expresion = false;
            codigoOperacion("asignacion");
            limpiarTabla(opTable);
            break;
            
        case READ:
            /* <statement> ::= READ (<id list>);*/
            matched = false;
            match(READ);
            match(LPAREN);
            id_list();
            matched = false;
            match(RPAREN);
            match(SEMICOLON);
            break;
        
        case WRITE:
 
            /*<statement> ::= WRITE (<expr list>) ;*/
            matched = false;
            match(WRITE); 
            match(LPAREN);
            posTable = symbolTable.freepointer;
            expresion = true;
            expr_list();
            expresion = false;
            symbolTable.freepointer = posTable;
            matched = false;
            match(RPAREN);
            match(SEMICOLON);
            break;
        
        case CONS:
            matched = true;
            match(ID);
            match(INTLITERAL);
            cambiarPorConstante(symbolTable, identificador, token_buffer);
            match(SEMICOLON);
            break;
            
        default:
            syntax_error(current_token);
            break;
            
    }
}
 
void id_list(void)
{
    /*<id list> ::= ID { , ID}*/
    match(ID);
    read_id();
    while (next_token() == COMMA)
    {
        
        matched = false;
        match(COMMA);
        match(ID);
        read_id();
    }
}


void expression (void)
{
    token t;
    
    /*
     * <expression> ::= <primary> 
     *                  { <add op> <primary>}
     */
    primary();
    for (t= next_token(); t==PLUSOP || t== MINUSOP ; t = next_token())
    {
        add_op();
        primary();
    }
}

void expr_list(void)
{
   /*  <expr list> ::= <expression> { , <expression>}*/
    expression();
    writer_expr();
    while (current_token == COMMA)
    {
        matched = false;
        match(COMMA);
        expression();
        writer_expr();
    }
}

void add_op(void)
{
    //token tok = next_token();
    /* <addop> ::= PLUSOP | MINUSOP*/
    if(current_token == PLUSOP || current_token == MINUSOP)
    {
        operando(current_token);
        matched = false;
        match(current_token);
    }
    else
        syntax_error(current_token);
}

void primary(void)
{
    next_token();
    
    switch(current_token)
    {
        case LPAREN:
 
            /* <primary> ::= (<expression>)*/
            matched = false;            
            match(LPAREN); 
            expression();
            matched = false;
            match(RPAREN);
            break;
            
        case ID:

            /* <primary> ::= ID*/
            matched = false;
            match(ID);
            break;
            
        case INTLITERAL:

            /* <primary> ::= INTLITERAL*/
           matched = false;
           match(INTLITERAL);
            break;
            
        default:
            syntax_error(current_token);
            break;
            
            
    }
}

void match(token pToken) 
{   
    if( matched ) 
    {   
        current_token = next_token();
    }   
    if( current_token != pToken ) 
    {   
        syntax_error(pToken);   
    }   
    if( DEBUG ) 
    {   
        matched = true;
    }   
} 


 
void syntax_error(token pToken) 
{   
    fprintf(stdout, "Error sintactico en  %s  token. Token esperado %s", token_buffer, getTokenText(pToken));   
    exit(4);   
}


char * getTokenText(token pToken) {   
    switch(pToken) {   
    case BEGIN:   
        return "begin";   
    case END:   
        return "end";   
    case READ:   
        return "read";   
    case WRITE:   
        return "write";  
    case CONS:   
        return "cons"; 
    case ID:   
        return "id";   
    case INTLITERAL:   
        return "INTLITERAL";   
    case LPAREN:   
        return "(";   
    case RPAREN:   
        return ")";   
    case SEMICOLON:   
        return ";";   
    case COMMA:   
        return ",";   
    case ASSIGNOP:   
        return ":=";   
    case PLUSOP:   
        return "+";   
    case MINUSOP:   
        return "-";   
    case SCANEOF:   
        return "SCANEOF";   
    default:   
        return "error token";   
    }   
}

