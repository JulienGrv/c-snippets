#include <stdio.h>
#include <stdlib.h>
#include "exercice19.h"
#include "exercice20.h"

/*
La proc�dure main permettra simplement de naviguer entre les diff�rents exercices gr�ce � un menu. Chaque exos poss�dant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on am�liore la lisibilit� du code source.
Pour d�clarer l'ensemble des fonctions/proc�dures, il suffit d'indiquer les headers des diff�rentes parties.
*/

int main(int argc, char *argv[])
{
    system("cls"); // On efface ce qui �tait auparavant �crit sur la fen�tre DOS
    int choixExercice=0;
    printf("---- Menu du TP 14 ----\n\n1: Exercice 19\n2: Exercice 20\n");
    scanf("%d",&choixExercice);
    system("cls");
    switch(choixExercice)
    {
    case 1:
        exercice19();
        break;
    case 2:
        exercice20();
        break;
    default:
        printf("Veuillez recommencer.\n");
        break;
    }
    system("PAUSE");
    return 0;
}
