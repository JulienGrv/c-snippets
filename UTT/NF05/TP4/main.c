#include <stdio.h>
#include <stdlib.h>
#include "exercice15.h"
#include "exercice16.h"
#include "exercice17.h"
#include "exercice18.h"

/*
La procédure main permettra simplement de naviguer entre les différents exercices grâce à un menu. Chaque exos possédant son propre code source.
L'avantage est qu'en organisant l'ensemble du TP sous forme de projet on améliore la lisibilité du code source.
Pour déclarer l'ensemble des fonctions/procédures, il suffit d'indiquer les headers des différentes parties.
*/

int main(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
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
