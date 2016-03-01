#include "scanner.h"
#include <stdio.h>
#include "traductor.h"


void clear_buffer(void)
{ 
    int i;
    for(i = strlen(token_buffer); i >= 0; i--)
    {
        token_buffer[i] = 0;
    }
} 


void buffer_char(int c) 
{   
    token_buffer[strlen(token_buffer)] = c;
}

/*
token check_reserved(void){   
    // read  write  begin  end  function   
    char * read     = "Read";   
    char * write    = "Write";   
    char * begin    = "Begin";   
    char * end      = "End"; 
    
    //printf("%s",token_buffer);
    if( token_buffer[0] == 'R' ) {   
        if( strlen(token_buffer) != strlen(read) ) 
        {
            printf("%s","ID\n");
            return ID;   
        }   
        if( strncmp(read, token_buffer, strlen(read) ) == 0 ) 
        {
            printf("%s","READ\n");
            return READ;   
        }   
    }   
    else if( token_buffer[0] == 'W' ) {   
        if( strlen(token_buffer) != strlen(write) ) 
        {   
            printf("%s","ID\n");
            return ID;   
        }   
        if( strncmp(write, token_buffer, strlen(write) ) == 0 ) 
        {
            printf("%s","WRITE\n");
            return WRITE;   
        }   
    }   
    else if( token_buffer[0] == 'B' ) {   
        if( strlen(token_buffer) != strlen(begin) ) 
        {
            printf("%s","ID\n");
            return ID;   
        }   
        if( strncmp(begin, token_buffer, strlen(begin)) == 0 ) 
        {
            printf("%s","BEGIN\n");
            return BEGIN;   
        }   
    }   
    else if( token_buffer[0] == 'E' ) {   
        if( strlen(token_buffer) != strlen(end) ) 
        {
            printf("%s","ID\n");
            return ID;   
        }   
        if( strncmp(end, token_buffer, strlen(end) ) == 0 ) 
        {
            printf("%s","END\n");
            return END;   
        }   
    } 
    printf("%s","ID\n");
    return ID;   
} 
*/

token check_reserved(void)
{   
    // read  write  begin  end  function   
    char * read     = "read";   
    char * write    = "write";   
    char * begin    = "begin";   
    char * end      = "end";
    char * temp     =  token_buffer;
    
    
    //printf("%s <---> ",temp);
    //printf(" <-----> ");
    //sprintf(temp, "%s", temp);
    // metodo que sirve con el print strcmpInsensitive(temp, read)
    //prueba(char* buffer, char* token, int pLargo)
    if(comparacionCadenas(temp, read, 4) == 0) 
    {
        //printf("%s","READ\n");
        return READ;   
    }   
    else if(comparacionCadenas(temp, write, 5) == 0) 
    {   
        //printf("%s","WRITE\n");
        return WRITE;   
    }   
    else if(comparacionCadenas(temp, begin, 5) == 0) 
    {   
        //printf("%s","BEGIN\n");
        return BEGIN;   
    }   
    else if(comparacionCadenas(temp, end, 3) == 0) 
    {   
        //printf("%s","END\n");
        return END;   
    } 
    //printf("%s","ID\n");
    return ID;   
} 

void lexical_error(int c) 
{   
    fprintf(stderr, "Error lexico en  %c \n", c);   
    exit(1);   
} 


token scanner(void) 
{   
    int in_char, c;   
    clear_buffer();   
    if( feof(stdin) ) 
    {   
        printf("%s","SCANEOF\n");
        return SCANEOF;   
    }   
    while( (in_char = getchar()) != EOF ) 
    { 
        if( isspace(in_char) ) {   
            continue; /*do nothing */  
        }   
        else if( isalpha(in_char) ) 
        {   
            /*  ID ::= LETTER | ID LETTER | ID DIGIT | ID UNDERSCORE  */   
            buffer_char(in_char);   
            for( c = getchar(); isalnum(c) || c == '_'; c = getchar() ) {   
                buffer_char(c);   
            }
            revisarAsignacion(token_buffer);
            
            if(expresion){
                enterOP(identificador);
            }else{
                check_id(identificador);
            }
            
            ungetc(c, stdin);   
            return  check_reserved();   
        }   
        else if( isdigit(in_char) ) 
        {  
          /*  INTLITERAL ::= DIGIT | INTLITERAL DIGIT  */   
            buffer_char(in_char);   
            for(c = getchar(); isdigit(c); c = getchar() ) {   
                buffer_char(c);   
            }   
            ungetc(c, stdin);
            //printf("%s","INTLITERAL\n");
             if(expresion)
                 enterOP(token_buffer);
            
            return INTLITERAL;   
        }   
        else if( in_char == '(' ) 
        {   
            //printf("%s","LPAREN\n");
            return LPAREN;   
        }   
        else if( in_char == ')' ) 
        {   
            //printf("%s","RPAREN\n");
            return RPAREN;   
        }   
        else if( in_char == ';' ) 
        {
            //printf("%s","SEMICOLON\n");
            return SEMICOLON;   
        }   
        else if( in_char == ',' ) 
        {
            //printf("%s","COMMA\n");
            return COMMA;   
        }   
        else if( in_char == '+' ) 
        {
            //printf("%s","PLUSOP\n");
            return PLUSOP;   
        }   

        else if( in_char == ':' ) { 
  
            /*  looking for ":="  */   
            c = getchar();   
            if( c == '=' ) 
            {
                //printf("%s","ASSIGNOP\n");
                return ASSIGNOP;   
            } else 
            {   
                ungetc(c, stdin);   
                lexical_error(in_char);   
             }   
        }   
        else if( in_char == '-' ) {   
            /* is it --, comment start  */   
            c = getchar();   
            if( c == '-' ) {   
                do {   
                    in_char = getchar();   
                } while( in_char != '\n' && in_char != EOF );   
            }   
            else {   
                ungetc(c, stdin);
                //printf("%s","MINUSOP\n");
                return  MINUSOP;   
            }   
            //printf("%s","COMENTARIO\n");
            //return LPAREN;   
        }   
        else  {    
            lexical_error(in_char);   
        }   
    }   
    //printf("%s","SCANEOF\n");
    return SCANEOF;   
} 

token next_token()
{
    current_token = scanner();
    
    return current_token;
}



