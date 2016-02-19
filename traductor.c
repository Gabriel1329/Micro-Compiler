#include <string.h>
#include "traductor.h"


int lookup(string s)
{
    return 1;
}

void enter(string s)
{
    
}

void check_id(string s)
{
  if(! lookup(s)){
      enter(s);
      generate("Declare",s,"Integer","");
  }
}

char *get_temp(void)
{
   /* max temporary allocated so far*/
    static int max_temp = 0;
    static char tempname[MAXIDLEN]; //En realidad el tamaño es MAXIDLEN ;
    
    max_temp++;
    sprintf(tempname,"Temp&%d",max_temp);
    check_id(tempname);
    return tempname;
}


void start(void)
{
    /* Semantc initializations, none needed */
}



void finish(void)
{
    /* Generate code to finish program.*/
    generate("Halt","","","");
}


void assign(expr_rec target, expr_rec source)
{
    /* Generate code for assignment.*/
    generate("Store", extract(source), target.name,"");
}


op_rec process_op(void)
{
    /*Produce operator descriptor.*/
    op_rec o;
    
    if(current_token == PLUSOP)
        o.operators = PLUSOP;
    else
        o.operators = MINUSOP;
    return o;
}


expr_rec gen_infix(expr_rec e1,op_rec op, expr_rec e2)
{
    expr_rec e_rec;
    /* An expr_rec with temp variant set.*/
    
    e_rec.kind = TEMPEXPR;
    /*
     * Generate code for infix operatin.
     * Get result temp and set up semantic record  
     * for result
     */
    strcpy(e_rec.name, get_temp());

 //   generate(extract(op),extract(e1),extract(e2),e_rec.name);

    return e_rec;
}



 
void read_id(expr_rec in_var)
{
   /* Generate code for read.*/
    generate("READ",in_var.name,"INTEGER","");
}


expr_rec process_id(void)
{
    expr_rec t;
    /*
     * Declare ID and build a
     * corresponding semantic record
     */
    check_id(token_buffer);
    t.kind = IDEXPR;
    strcpy(t.name, token_buffer);
    return t;
}


expr_rec process_literal(void)
{
    expr_rec t;
    /*
     * Convert literal to a numeric representation
     * and build semantic record.
     */
    t.kind = LITERALEXPR;
    (void) sscanf(token_buffer, "%d", & t.val);
    return t;
}


void writer_expr(expr_rec out_expr)
{
 //   generate("Write",extract(out_expr),"Integer","");
}


void   generate(char * op, char * A, char * B, char * C) 
{   
    if(strlen(C) > 0) {   
        printf("%s\t%s,\t%s,\t%s\n", op, A, B, C);   
        if( archivoSalida )   
            fprintf(stderr, "[ Gen ] %s\t%s,\t%s,\t%s\n", op, A, B, C);   
    }   
    else {   
        if( strlen(B) > 0) {   
            printf("%s\t%s,\t%s\n", op, A, B);   
            if( archivoSalida )   
                fprintf(stderr, "[ Gen ] %s\t%s,\t%s\n", op, A, B);   
        }   
        else {   
            printf("%s\t%s\n", op, A);   
            if( archivoSalida )   
                fprintf(stderr, "[ Gen ] %s\n", op, A, B);   
        }   
    }   
}   














