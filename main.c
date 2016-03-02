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

 
    fclose( archivoEntrada );
    fclose( archivoSalida );
    
    return EXIT_SUCCESS;    
}

