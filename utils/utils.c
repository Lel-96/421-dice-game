#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void printTitle()
{
    printf(BOLD BRIGHT_WHITE);
    printf("=====================================\n");
    printf("             JEU DU 421            \n");
    printf("=====================================\n\n" RESET);
}


//Game pause, wait an input
void waitEnter()
{
    printf(BOLD BRIGHT_WHITE"\nAppuyez sur ENTREE pour continuer..."RESET);
    getchar();
}

//Func to enter a string
void inputc(char* input)
{
    int i =0;
    char c;

    while((c=getchar()) != '\n' && c!=EOF)
    {
        input[i] = c;
        i++;
    }
    input[i]='\0';
}
