#include <stdio.h>
#include <stdlib.h>
#include "exercice23.h"
#include "exercice24.h"

/*
La procédure main permettra simplement de naviguer entre les différents exercices grâce à un menu. Chaque exos possédant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on améliore la lisibilité du code source.
Pour déclarer l'ensemble des fonctions/procédures, il suffit d'indiquer les headers des différentes parties.
*/
int main(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
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
