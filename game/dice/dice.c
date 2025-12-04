#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../utils/utils.h"

//Print the dice value with it's ASCII art
void printDice(int value)
{
    const char *dice[] = {
        "",
        "-----\n"
        "|   |\n"
        "| o |\n"
        "|   |\n"
        "-----\n",

        "-----\n"
        "|o  |\n"
        "|   |\n"
        "|  o|\n"
        "-----\n",

        "-----\n"
        "|o  |\n"
        "| o |\n"
        "|  o|\n"
        "-----\n",

        "-----\n"
        "|o o|\n"
        "|   |\n"
        "|o o|\n"
        "-----\n",

        "-----\n"
        "|o o|\n"
        "| o |\n"
        "|o o|\n"
        "-----\n",

        "-----\n"
        "|o o|\n"
        "|o o|\n"
        "|o o|\n"
        "-----\n"
    };

    if (value < 1 || value > 6) {
        printf("Valeur invalide : %d\n", value);
        return;
    }

    printf("%s", dice[value]);
}

//Print the three dices
void printPlayerDice(const char *player, int t[3])
{
    for(int i=0; i<strlen(player); i++)
    {
        if(player[i]=='1')
        {
            printf(BOLD BRIGHT_BLUE);
            break;
        }
        else if(player[i]=='2')
        {
            printf(BOLD BRIGHT_RED);
            break;
        }
        printf(RESET);
    }
    printf("====== %s ======\n\n", player);

    for (int i = 0; i < 3; i++) {
        printDice(t[i]);
        printf("\n");
    }
}

//return a random value beetween 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}
