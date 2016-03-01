/* 
 * File:   main.c
 * Author: soto
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser.h"
#include "traductor.h"
#include "variables.h"
#include <string.h>


int main(int argc, char** argv) 
{
//Se pone el path de la siguiente manera    
//home/soto/NetBeansProjects/Micro-Compiler/Texto.txt ó Texto.txt
//se puede poner solo Texto.txt por que el archivo esta en la carpeta del proyecto
    
    //char direccionArchivo[150];
    //printf( "Bienvenido a Micro-Compiler, Ingrese la ruta del archivo: " );
    //scanf( "%s", direccionArchivo );
  
    
    
    //archivoEntrada = freopen( direccionArchivo, "r", stdin );
    archivoEntrada = freopen( "Texto.txt", "r", stdin );
    archivoSalida = freopen( "ensambler.s", "w", stderr);
    if (!archivoEntrada)
    {
        printf( "El archivo no existe" );
        return EXIT_FAILURE;
    }
    
    system_goal();
    //printf("identificador: %s\n", identificador);
    //printf("identificador LEN: %d\n", strlen(identificador));


    
    printf("tabla sin ser limpiada!!!\n");
    mostrarTabla(opTable);
    limpiarTabla(opTable);
    printf("tabla limpia!!!\n");
    mostrarTabla(opTable);
/*
    int i = opTable.smb[1].name[0];
    printf("%d", '9');
*/

    


/*
    if(1){
        printf("1 = TRUE, 0 = FALSE");
    }
*/
/*  
    while(current_token != SCANEOF)
    {
        next_token();
    }
*/
 
    fclose( archivoEntrada );
    
    return EXIT_SUCCESS;    
}

