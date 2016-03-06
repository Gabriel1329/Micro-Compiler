#include <string.h>
#include "traductor.h"
#include "funcionesUtiles.h"
#include "variables.h"


int lookup(char* s)
{
    int i, resultado = 0;
    for(i = 0 ; i < symbolTable.freepointer; i++){
        if(comparacionCadenas(symbolTable.smb[i].name, s, strlen(s)) == 0)
            resultado = 1;
    }
    return resultado;
}

// se utiliza para saber si un elemento está en la tabla, sino, lo agrega
void check_id(char* s)
{
    if(!lookup(s) && strlen(s)!=0){ //el identificador la primera vez viene vacío
      enter(s);
      //generate("Declare",s,"Integer","");
  }
}

void enter(char* variable)
{
    if(symbolTable.freepointer < 200 ) {     

        strcpy(symbolTable.smb[symbolTable.freepointer].name, variable);
        strcpy(symbolTable.smb[symbolTable.freepointer].registro, gen_reg()); 

        symbolTable.freepointer++;   
    } else {   
        printf("Exceed the max symbol table size");   
    }   
}


void enterOP(char* variable)
{
    if(opTable.freepointer < 200 ) {     

        strcpy(opTable.smb[opTable.freepointer].name, variable);
        strcpy(opTable.smb[opTable.freepointer].registro, gen_reg()); 
        
        opTable.freepointer++;  
        symbolTable.freepointer++;   
    } else {   
        printf("Exceed the max symbol table size");   
    }   
}

char* gen_reg(void)
{
    char *numRegistro[10];
    char *registro = (char *) malloc(sizeof(char) * 3);
    registro[0] = '$';
    registro[3] = '\0';
    
    if(symbolTable.freepointer <= 9){ //los registros $t llegan hasta 9, luego se usan los $s
        registro[1] = 't';
        itoa(symbolTable.freepointer,numRegistro);
    }else{
        registro[1] = 's';
        itoa(symbolTable.freepointer - 10,numRegistro);
    }
    registro[2] = numRegistro[0];
    return registro;
    
}


void start(void)
{
    /* Semantc initializations, none needed */
}



void finish(void)
{
    /* Generate code to finish program.*/
    generate("finish","jr","$ra","");
}


void assign(expr_rec target, expr_rec source)
{
    /* Generate code for assignment.*/
//    generate("Store", extract(source), target.name,"");
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


void gen_infix(char* e1,char* op, char* e2)
{
    generate(op, e2, e1, "$a3");
    //expr_rec e_rec;
    /* An expr_rec with temp variant set.*/
    
    //e_rec.kind = TEMPEXPR;
    /*
     * Generate code for infix operatin.
     * Get result temp and set up semantic record  
     * for result
     */
    //strcpy(e_rec.name, gen_reg());

 //   generate(extract(op),extract(e1),extract(e2),e_rec.name);

}



 
/*
void read_id(expr_rec in_var)
{
    Generate code for read.
    generate("READ",in_var.name,"INTEGER","");
}
*/

void read_id()
{
    //generate("read",gen_reg(),"5"," "); //en el segundo parametro va el registro que sigue 
    generate("read",symbolTable.smb[symbolTable.freepointer - 1].registro,"5"," ");
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


void writer_expr()
{   
    acomodarOPtable();
    //mostrarTabla(opTable);
    if(opTable.freepointer == 1){
        generate("write",opTable.smb[0].registro,"1","");
    }else{
        codigoOperacion("write");
        generate("write","$a3","1","");
    }
    limpiarTabla();
 //   generate("Write",extract(out_expr),"Integer","");
    
}


void   generate(char *op, char * A, char * B, char * C) 
{  
    if (comparacionCadenas(op,"read",4) == 0)
    {
        fprintf(stderr, "	li $v0, %s\n", B);
        fprintf(stderr, "	syscall\n");
        fprintf(stderr, "	add %s, $v0, $zero\n\n", A);
    }
    
    else if(comparacionCadenas(op,"add",3) == 0 || 
            comparacionCadenas(op,"sub",3) == 0){
        if(verificarNumero(A[0]) && verificarNumero(B[0])){
            fprintf(stderr, "	li $a2, %s\n", A);
            fprintf(stderr, "	%s %s, $a2, %s\n", op, C, B);
        }
        else if(verificarNumero(A[0])){
            fprintf(stderr, "	%s %s, %s, %s\n", op, C, B, A);
        }else {
            fprintf(stderr, "	%s %s, %s, %s\n", op, C, A, B);
        }
    }
    
    else if(comparacionCadenas(op,"write",5) == 0){
        fprintf(stderr, "	li $v0, %s\n", B);
        fprintf(stderr, "	add $a0, %s, $zero\n", A);
        fprintf(stderr, "	syscall\n\n");
    }
    else if(comparacionCadenas(op,"finish",6) == 0){
        fprintf(stderr, "	%s %s", A, B);
    }

}   

void revisarAsignacion(char *s){
    if(comparacionCadenas(s,"begin",5) != 0 
       && comparacionCadenas(s,"read",4) != 0
       && comparacionCadenas(s,"write",5) != 0
       && comparacionCadenas(s,"end",3) != 0
       && comparacionCadenas(s,"cons",4) != 0){
        strcpy(identificador,s);
    }
}


void mostrarTabla(SymbolTable t){
    printf("Variable | Registro\n");
    int i;
    printf("Freepointer: %d\n", t.freepointer);
    for(i = 0; i < t.freepointer; i++){
        printf("%s        | %s\n",t.smb[i].name, t.smb[i].registro);
    }
}


// agrega a la tabla2 (la tabla de la operación), el operando correspondiente
void operando(char* o)
{
    if(o == PLUSOP && expresion == true){ enterOP("add");}
    if(o == MINUSOP && expresion == true){ enterOP("sub");}
}


char* get_reg(char* s)
{
    char* registro[10];
    int i;
    for(i = 0; i < symbolTable.freepointer; i++){
        if(comparacionCadenas(symbolTable.smb[i].name, s, strlen(s)) == 0){
            strcpy(registro, symbolTable.smb[i].registro);
            //strcpy(opTable.smb[opTable.freepointer].name, variable);
        }
    }
    return registro;
}

void acomodarOPtable()
{
    int i;
    
    for(i = 0; i < opTable.freepointer; i++){
        if(lookup(opTable.smb[i].name)){
            strcpy(opTable.smb[i].registro, get_reg(opTable.smb[i].name));
        }
        else if(comparacionCadenas(opTable.smb[i].name, "add", 3) == 0
           || comparacionCadenas(opTable.smb[i].name, "sub", 3) == 0){
            strcpy(opTable.smb[i].registro, opTable.smb[i].name);
        }
        else if(esConstante(opTable.smb[i].name)){
            strcpy(opTable.smb[i].registro, get_reg(opTable.smb[i].name));
        }
        else if(!lookup(opTable.smb[i].name) && !verificarNumero(opTable.smb[i].name[0])){
            printf("La variable %s no está definida\n", opTable.smb[i].name); //arrglar esto
            exit(3); 
        }
    }
}

void codigoOperacion(char* instruccion)
{/*
    opTable.smb[opTable.freepointer - 1].registro; //primer operando
    opTable.smb[opTable.freepointer - 2].registro; // operador
    opTable.smb[opTable.freepointer - 3].registro; //segundo operando
*/
    acomodarOPtable();
    
    int i = 0, pos = opTable.freepointer;
    while(pos >= 0){
/*
        printf("");
        printf("");
        mostrarTabla(opTable);
        printf("");
        printf("");
        
*/
        agregarNumeros(opTable.smb[pos - 1], opTable.smb[pos - 2], opTable.smb[pos - 3]);
        
        if(pos == 2){
            if(comparacionCadenas(instruccion, "asignacion", 10) == 0){
                generate("add",opTable.smb[1].registro, "$zero",opTable.smb[0].registro); 
            }
            else if(comparacionCadenas(instruccion, "write", 5) == 0){
                generate(opTable.smb[1].registro, opTable.smb[0].registro, "$a3", "$a3" );
            }
           pos = -1;
           
        }
        else if(pos == 1){
            generate("add","$a3", "$zero",opTable.smb[0].registro);
            pos = -1;
        }
        else if(i == 0){
            generate(opTable.smb[pos - 2].registro,
                    opTable.smb[pos - 3].registro,
                    opTable.smb[pos - 1].registro,
                    "$a3");
            pos = pos - 3;
            i = 1;
        }else{
            generate(opTable.smb[pos - 1].registro,
                    opTable.smb[pos - 2].registro,
                    "$a3", "$a3");
            pos = pos - 2;
        }
    }
    fprintf(stderr, "\n");

}

int verificarNumero(char n)
{
    int resultado = 0, i = n;
    if(i <= 57 && i >= 48){ resultado = 1; }
    return resultado;
}

void limpiarTabla(void){ opTable.freepointer = 0;}

// cambia el registro de una entrada en la tabla de simbolos, por su valor de constante
int cambiarPorConstante(char* cons, char* valor)
{
    int i, resultado = 0;
    
    for(i = 0; i < symbolTable.freepointer; i++){
        if(comparacionCadenas(symbolTable.smb[i].name, cons, strlen(cons)) == 0){
            strcpy(symbolTable.smb[i].registro, valor);
            resultado = 1;
        }
    }
    return resultado;
}

int esConstante(char* nombre)
{
    int resultado = 0;
    if(verificarNumero(get_reg(nombre)[0])){
        resultado = 1;
    }
    return resultado;
}

void agregarNumeros(Symbol A, Symbol B, Symbol C)
{
    generarCodigoNumeros(A);
    generarCodigoNumeros(B);
    generarCodigoNumeros(C);
}

void generarCodigoNumeros(Symbol s)
{
    if(verificarNumero(s.name[0])){fprintf(stderr, "	la %s, %s\n", s.registro, s.name);}
}

void restriccionConstante(char* nombre){
    if(esConstante(nombre)){
        printf("Error, no se puede reasignar la constante %s", nombre);
    }
}