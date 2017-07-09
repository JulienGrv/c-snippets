#include <stdio.h>
#include <stdlib.h>
#include "exercice15.h"
#include "exercice16.h"
#include "exercice17.h"
#include "exercice18.h"

/*
La proc�dure main permettra simplement de naviguer entre les diff�rents exercices gr�ce � un menu. Chaque exos poss�dant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on am�liore la lisibilit� du code source.
Pour d�clarer l'ensemble des fonctions/proc�dures, il suffit d'indiquer les headers des diff�rentes parties.
*/

int main(void)
{
    system("cls"); // On efface ce qui �tait auparavant �crit sur la fen�tre DOS
    int choixExercice=0;
    printf("---- Menu du TP 14 ----\n\n1: Exercice 15\n2: Exercice 16\n3: Exercice 17\n4: Exercice 18\n");
    scanf("%d",&choixExercice);
    system("cls");
    switch(choixExercice)
    {
    case 1:
        exercice15();
        break;
    case 2:
        exercice16();
        break;
    case 3:
        exercice17();
        break;
    case 4:
        exercice18();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return main();
}
