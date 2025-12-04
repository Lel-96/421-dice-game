#include <stdio.h>
#include <stdlib.h>
#include"../dice/dice.h"



void AIReroll(int dice[3], int power, int power_adv)
{
    if (power == 18) {
        dice[0] = rollDice();
        dice[1] = rollDice();
        dice[2] = rollDice();
        return;
    }
    if (power_adv != 0 && power > power_adv)
    {
        for (int i = 0; i < 3; i++)
            if (dice[i] > 4)
                dice[i] = rollDice();
    }

}
