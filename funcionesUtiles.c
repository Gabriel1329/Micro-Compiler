#include "funcionesUtiles.h"




int prueba(char* buffer, char* token, int pLargo)
{
    int resultado = 0;
    int i = 0;
    for (i ; i < pLargo; i++)
    {
        if(tolower(buffer[i]) != token[i])
        {
            resultado = -1;
            break;
        } 
    }
    return resultado;    
}