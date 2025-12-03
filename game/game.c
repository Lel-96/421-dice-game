#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dice/dice.h"
#include "rules/rules.h"
#include "ai/ai.h"
#include "../utils/utils.h"

#ifdef _WIN32
#define CLEAR() system("cls")
#else
#define CLEAR() system("clear")
#endif




int askReroll(int dice[3], int *attempt)
{
    char choice[16] = {0};
    printf("\nVoulez-vous relancer certains dés ? (y/n) : ");
    //fgets(choice, sizeof(choice), stdin);
    inputc(choice);
    if (choice[0] != 'y' && choice[0] != 'Y')
    {
        return 0;
    }


    printf("Entrez les numéros des dés à relancer (ex : 13 = relance 1 et 3) : ");
    //fgets(choice, sizeof(choice), stdin);
    inputc(choice);
    int i = 0;
    while (choice[i] != '\0') {
        if (choice[i] >= '1' && choice[i] <= '3') {
            int d = choice[i] - '1';
            dice[d] = rollDice();
        }
        i++;
    }
    (*attempt)++;
    return 1;
}


void playTurn(const char *name, int dice[3], int isAI,int* max_attempt, int power_p1)
{
    int attempt = 1;
    while (attempt <= 3 && *max_attempt ==0 || attempt <= *max_attempt)
    {
        CLEAR();
        printTitle();

        printf("LANCER %d - %s\n\n", attempt, name);
        if (attempt == 1) {
            for (int i = 0; i < 3; i++)
                dice[i] = rollDice();
        }

        printPlayerDice(name, dice);
        printf("Puissance actuelle : %d\n", power(dice));

        if (attempt == 3 && *max_attempt ==0 || attempt == *max_attempt)
            break;

        if (isAI) {
            AIReroll(dice, power(dice), power_p1);
            printf("\nL'IA relance automatiquement...\n");
            waitEnter();
            attempt++;
        } else {
            if (!askReroll(dice, &attempt))
            {
                break;
            }else {
                waitEnter();
            }
        }

    }
    *max_attempt = attempt;
}

int tokenBank(int* bank, int tokens, char* round)
{
    int r = *bank - tokens;
    if(r <= 0)
    {
        *round = 'D';
        int swap = *bank;
        *bank = 0;
        return swap;
    }
    else
    {
        *bank -= tokens;
        return tokens;
    }
}

int tokenPlayer(int tokens1, int tokens2)
{
    int r = tokens1 - tokens2;
    if(r < 0)
    {
        return tokens1;
    }
    else
    {
        return tokens2;
    }
}

int round0(int p1[3], int p2[3], int mode)
{
    int can_start =0;
    int max_attempt = 1;
    while(1)
    {
        printTitle();
        printf("Premier tour\n");
        printf("→ Joueur 1 joue.\n");
        waitEnter();
        playTurn("Joueur 1", p1, 0, &max_attempt, 0);

        printf("→ Joueur 2 joue.\n");
        waitEnter();
        playTurn("Joueur 2", p2, (mode == 2 ? 1 : 0), &max_attempt, power(p1));
        waitEnter();
        int pw1 = power(p1);
        int pw2 = power(p2);
        int win = winner(p1, p2);
        CLEAR();
        printTitle();

        printf("Résultats de la manche :\n");
        printf(" - Joueur 1 : puissance %d\n", pw1);
        printf(" - Joueur 2 : puissance %d\n\n", pw2);
        if (win == 1) {
            can_start =1;
            printf("Joueur 1 commence la partie !\n");
        }
        else if (win == 2) {
            can_start =1;
            printf("Joueur 2 commence la partie!\n");
        }
        else printf("Égalité parfaite ! Recommecer.\n");

        waitEnter();
        if(can_start) return win;
    }

}

int game()
{
    srand(time(NULL));

    int mode = 1;
    int jetons_p1 = 0;
    int jetons_p2 = 0;
    int bank = 21;

    int p1[3], p2[3];
    int beginner, max_attempt =0;

    char round = 'C';

    CLEAR();
    printTitle();
    printf("Mode de jeu :\n");
    printf(" 1 - 2 Joueurs humains\n");
    printf(" 2 - Joueur vs IA\n\n");
    printf("Votre choix : ");
    scanf("%d", &mode);
    getchar();
    CLEAR();
    beginner = round0(p1, p2, mode);

    while ((jetons_p1 >= 0 && jetons_p2 >= 0 && round != 'D')
           ||
           (jetons_p1 > 0  && jetons_p2 > 0 && round != 'C'))
    {
        CLEAR();
        printTitle();

        printf("====== %c ======\n", round);
        printf("JETONS :\n");
        printf("Joueur 1 : %d\n", jetons_p1);
        printf("Joueur 2 : %d\n", jetons_p2);
        printf("Pot : %d\n\n", bank);

        if (beginner ==1)
        {
            max_attempt =0;
            printf("→ Joueur 1 joue.\n");
            waitEnter();
            playTurn("Joueur 1", p1, 0, &max_attempt, 0);

            printf("→ Joueur 2 joue.\n");
            waitEnter();
            playTurn("Joueur 2", p2, (mode == 2 ? 1 : 0), &max_attempt, power(p1));
            waitEnter();
        }
        else
        {
            max_attempt = 0;
            printf("→ Joueur 2 joue.\n");
            waitEnter();
            playTurn("Joueur 2", p2, (mode == 2 ? 1 : 0), &max_attempt, 0);

            printf("→ Joueur 1 joue.\n");
            waitEnter();
            playTurn("Joueur 1", p1, 0, &max_attempt, 0);
        }


        int pw1 = power(p1);
        int pw2 = power(p2);
        int win = winner(p1, p2);

        CLEAR();
        printTitle();

        printf("Résultats de la manche :\n");
        printf(" - Joueur 1 : puissance %d\n", pw1);
        printf(" - Joueur 2 : puissance %d\n\n", pw2);

        int t = 0;

        if(round == 'C')
        {
            if (win == 1) {
                t = token(pw1);
                t = tokenBank(&bank, t, &round);
                jetons_p2 += t;
                printf("Joueur 1 gagne, joueur 2 prend %d jetons !\n", t);
            }
            else if (win == 2) {
                t = token(pw2);
                t = tokenBank(&bank, t, &round);
                jetons_p1 += t;
                printf("Joueur 2 gagne, joueur 1 prend %d jetons ! !\n", t);
            }
            else {
                printf("Égalité parfaite ! Pas d'échange de jetons.\n");
            }
        }
        else
        {
            if (win == 1) {
                t = token(pw1);
                t =tokenPlayer(jetons_p1, t);
                jetons_p2 += t;
                jetons_p1 -= t;
                printf("Joueur 1 gagne, joueur 2 prend %d jetons !\n", t);
            }
            else if (win == 2) {
                t = token(pw2);
                t =tokenPlayer(jetons_p2, t);
                jetons_p1 += t;
                jetons_p2 -= t;
                printf("Joueur 2 gagne, joueur 1 prend %d jetons ! !\n", t);
            }
            else {
                printf("Égalité parfaite ! Pas d'échange de jetons.\n");
            }
        }


        waitEnter();
    }

    CLEAR();
    printTitle();

    if (jetons_p1 <= 0)
        printf("Joueur 1 remporte la partie !\n");
    else
        printf("Joueur 2 remporte la partie !\n");

    printf("\nMerci d'avoir joué !\n\n");

    return 0;
}
