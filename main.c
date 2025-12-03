#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game/game.h"
#include "utils/utils.h"



int main()
{
    char loop[10];
    loop[0] = 'y';
    while(loop != 'n' && loop != 'N')
    {
        game();
        waitEnter();
        printf("Voulez vous recommencer? ");
        fgets(loop, sizeof(loop), stdin);
    }
    return 0;
}
