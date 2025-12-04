#include <stdio.h>
#include <stdlib.h>

//sort th dice in ascending order
void sort3(int t[3]) {
    for (int i = 0; i < 2; i++)
        for (int j = i + 1; j < 3; j++)
            if (t[i] > t[j]) {
                int tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
}

//sum of the 3 dice
int sum(int t[3]) {
    return t[0] + t[1] + t[2];
}

//Player game force, the smaller the value, the stronger it is.s
int power(int t_in[3]) {
    int t[3] = {t_in[0], t_in[1], t_in[2]};
    sort3(t);

    if (t[0]==1 && t[1]==2 && t[2]==4) return 1;  // 421
    if (t[0]==1 && t[1]==1 && t[2]==1) return 2;
    if (t[0]==1 && t[1]==1 && t[2]==6) return 3;
    if (t[0]==6 && t[1]==6 && t[2]==6) return 4;
    if (t[0]==1 && t[1]==1 && t[2]==5) return 5;
    if (t[0]==5 && t[1]==5 && t[2]==5) return 6;
    if (t[0]==1 && t[1]==1 && t[2]==4) return 7;
    if (t[0]==4 && t[1]==4 && t[2]==4) return 8;
    if (t[0]==1 && t[1]==1 && t[2]==3) return 9;
    if (t[0]==3 && t[1]==3 && t[2]==3) return 10;
    if (t[0]==1 && t[1]==1 && t[2]==2) return 11;
    if (t[0]==2 && t[1]==2 && t[2]==2) return 12;

    if (t[0]==4 && t[1]==5 && t[2]==6) return 13; // 654
    if (t[0]==3 && t[1]==4 && t[2]==5) return 14;
    if (t[0]==2 && t[1]==3 && t[2]==4) return 15;
    if (t[0]==1 && t[1]==2 && t[2]==3) return 16;

    if (t[0]==1 && t[1]==2 && t[2]==2) return 17;

    return 18;
}

// How much token win for this power
int token(int p) {
    if (p == 1) return 10;
    if (p == 2) return 7;
    if (p == 3 || p == 4) return 6;
    if (p == 5 || p == 6) return 5;
    if (p == 7 || p == 8) return 4;
    if (p == 9 || p == 10) return 3;
    if (p >= 11 && p <= 17) return 2;
    return 1;
}

//Determine the winner
int winner(int p1[3], int p2[3]) {
    int pw1 = power(p1);
    int pw2 = power(p2);

    if (pw1 == 17) return 1;
    if (pw2 == 17) return 2;

    if (pw1 < pw2) return 1;
    if (pw1 > pw2) return 2;

    if (pw1 == 18 && pw2 == 18) {
        int s1 = sum(p1);
        int s2 = sum(p2);
        return (s1 > s2) ? 1 : 2;
    }

    return 0;
}
