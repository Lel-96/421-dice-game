#include <stdio.h>
#include <stdlib.h>


void printTitle()
{
    printf("=====================================\n");
    printf("             JEU DU 421            \n");
    printf("=====================================\n\n");
}

void waitEnter()
{
    printf("\nAppuyez sur ENTREE pour continuer...");
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
