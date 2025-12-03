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

void waitEnter()
{
    printf(BOLD BRIGHT_WHITE"\nAppuyez sur ENTREE pour continuer..."RESET);
    getchar();
}

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
