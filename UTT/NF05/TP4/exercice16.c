#include <stdio.h>
#include <stdlib.h>
#include "exercice16.h"

void exercice16(void)
{
    int nombreDElements=0;
    float* tableauATrier=saisieElements(&nombreDElements); // On réutilise notre fonction saisieElements de l'exo 15 afin de saisir un tableau
    int nombreDEchanges=triBulle(nombreDElements,tableauATrier); // On appelle la fonction triBulle qui va trier notre tableau grâce au tri bulle et nous retourner le nombre d'échanges effectué
    printf("Le nombre d'operations d'echange effectuees lors du tri est %d\n",nombreDEchanges);
}


// La méthode de tri du tableau est celle du tri bulle. Cette méthode est la plus intuitive et classique bien que très complexe et donc très lente pour des tableaux de grande taille.
int triBulle(int nombreDElements, float* tableauATrier)
{
    int i=0, j=0, nombreDEchanges=0;
    float temp=0;
    for(i=0; i<nombreDElements-1; i++)
    {
        for(j=i+1; j<nombreDElements; j++)
        {
            if(tableauATrier[i]>tableauATrier[j])
            {
                temp=tableauATrier[i];
                tableauATrier[i]=tableauATrier[j];
                tableauATrier[j]=temp;
                nombreDEchanges++;
            }
        }
    }
    return nombreDEchanges;
}
