#include <stdio.h>
#include <stdlib.h>
#include "exercice25.h"
#include "exercice26.h"

/*
La procédure main permettra simplement de naviguer entre les différents exercices grâce à un menu. Chaque exos possédant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on améliore la lisibilité du code source.
Pour déclarer l'ensemble des fonctions/procédures, il suffit d'indiquer les headers des différentes parties.
*/
int main(int argc, char *argv[])
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
    int choixExercice=0;
    printf("---- Menu du TP 8 ----\n\n1: Exercice 25\n2: Exercice 26\n");
    scanf("%d",&choixExercice);
    system("cls");
    switch(choixExercice)
    {
    case 1:
        exercice25();
        break;
            case 2:
        exercice26();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
