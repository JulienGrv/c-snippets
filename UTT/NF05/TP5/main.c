#include <stdio.h>
#include <stdlib.h>
#include "exercice19.h"
#include "exercice20.h"

/*
La procédure main permettra simplement de naviguer entre les différents exercices grâce à un menu. Chaque exos possédant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on améliore la lisibilité du code source.
Pour déclarer l'ensemble des fonctions/procédures, il suffit d'indiquer les headers des différentes parties.
*/

int main(int argc, char *argv[])
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
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
