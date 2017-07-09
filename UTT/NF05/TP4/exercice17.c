#include <stdio.h>
#include <stdlib.h>
#include "exercice17.h"


void exercice17(void)
{
    int petitEntier=0, grandEntier=0, temp=0, PGCD=0;
    printf("Saisir 2 entiers :\nEntier 1 = ");
    scanf("%d",&petitEntier);
    printf("Entier 2 = ");
    scanf("%d",&grandEntier);
    // La condition suivante permet de s'assurer que c'est bien le plus grand entier qui est dans la variable grandEntier et inversement pour petitEntier
    if(petitEntier>grandEntier)
    {
        temp=grandEntier;
        grandEntier=petitEntier;
        petitEntier=temp;
    }
    if(petitEntier==0&&grandEntier==0) // Si les deux entiers sont nuls on ne peut déterminer de PGCD
    {
        printf("Un des deux entiers doit etre non-nul ! Veuillez Recommencer.\n");
        return exercice17();

    }
    else if(petitEntier==0) // Si seule petitEntier est nul alors on sait déjà que valeur absolue de grandEntier est le PGCD
    {
        PGCD=abs(grandEntier);
    }
    else if(grandEntier==0) // Si seule grandEntier est nul alors on sait déjà que valeur absolue de petitEntier est le PGCD
    {
        PGCD=abs(petitEntier);
    }
    else // Sinon on détermine le PGCD à l'aide de l'algorithme d'Euclide
    {
        PGCD=calculPGCD(petitEntier, grandEntier);
    }
    printf("Le Plus Grand Diviseur Commun (PGCD) de %d et de %d vaut %d\n",grandEntier,petitEntier,PGCD);
}


// Cette fonction permet de calculer le PGCD de deux entiers relatifs
int calculPGCD(int petitEntier, int grandEntier)
{
    petitEntier=abs(petitEntier); // Pour étendre la fonction aux entiers relatifs, il suffit de considérer les valeurs absolues de petitEntier et grandEntier.
    grandEntier=abs(grandEntier);
    int reste=1;
    while(reste!=0)
    {
        reste=grandEntier%petitEntier;
        grandEntier=petitEntier;
        petitEntier=reste;
    }
    return grandEntier;
}
