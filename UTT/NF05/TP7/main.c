#include <stdio.h>
#include <stdlib.h>
#include "exercice23.h"
#include "exercice24.h"

/*
La proc�dure main permettra simplement de naviguer entre les diff�rents exercices gr�ce � un menu. Chaque exos poss�dant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on am�liore la lisibilit� du code source.
Pour d�clarer l'ensemble des fonctions/proc�dures, il suffit d'indiquer les headers des diff�rentes parties.
*/
int main(void)
{
    system("cls"); // On efface ce qui �tait auparavant �crit sur la fen�tre DOS
    int choixExercice=0;
    printf("---- Menu du TP 7 ----\n\n1: Exercice 23\n2: Exercice 24\n");
    scanf("%d",&choixExercice);
    system("cls");
    switch(choixExercice)
    {
    case 1:
        exercice23();
        break;
    case 2:
        exercice24();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return main();
}
