#include "funcionesUtiles.h"


char* lowerCaseWord(char* a)
{
    char b[strlen(a)];
    int i = 0;
    for (i ; i < strlen(a); i++)
    {
        b[i] = tolower(a[i]);
        //printf("%c",b[i]);
    }
    //printf("%s","\n");
    return b;
}

int strcmpInsensitive(char* a, char* b)
{
    //char *tem = lowerCaseWord(a);
    //char *tem2 = lowerCaseWord(b);
   // printf("%s",a);
   // printf("%s"," Lo paso a ");
    //printf("%s",tem);
   // printf("%s","\n");
   // printf("%s",b);
//    printf("%s"," Lo paso a ");
//    printf("%s",tem2);
 //   printf("%s","\n");
    int i = strcmp(lowerCaseWord(a), b);
    return i;
}