#include <stdio.h>
#include <stdlib.h>
#include "exercice15.h"

void exercice15(void)
{
    system("cls");
    int nombreDElements=0;
    float* tableauDElements=saisieElements(&nombreDElements); // Ce pointeur pointera sur notre tableau dimensionné à la taille voulu retourné par la fonction saisieElements.
    affichage(nombreDElements,tableauDElements); // On affiche un à un les élements du tableau
    float moyenne=calculMoyenne(nombreDElements,tableauDElements); // On appelle la fonction calculMoyenne afin de connaître la moyenne des éléments de notre tableau
    printf("La moyenne des elements est : %f\n",moyenne);
    float variance=calculVariance(nombreDElements,tableauDElements,moyenne); // On appelle la fonction calculVariance afin de connaître la variance des éléments de notre tableau
    printf("La variance des elements est : %f\n",variance);
    int positionDuMinimum=positionMinimum(nombreDElements,tableauDElements); // On appelle la fonction positionMinimum afin de connaître la position du minimum de notre tableau. NB: si le tableau contient plusieurs minimum seul la position du premier sera retourné
    printf("Le minimum est l'element %d = %f\n",positionDuMinimum+1,tableauDElements[positionDuMinimum]);
    system("cls");
}

// Cette fonction permet d'allouer dynamiquement la taille de notre tableau et de le remplir.
float* saisieElements(int* nbDElements)
{
    int i=0;
    float* tabDElements=NULL; // On déclare un pointeur qui servira à contenir l'adresse de notre futur tableau.
    printf("Qu'elle est le nombre d'elements a saisir ?\n");
    scanf("%d",nbDElements); // On demande le nombre d'éléments contenus dans le tableau

    if(nbDElements<=0)
    {
        printf("Veuillez entrer un nombre d'elements strictement superieur a zero.");
        exit(0); // On arrête tout en cas d'erreur d'allocation. Ce genre n'arrive plus sur les nouveau ordinateur puisque la capacité de la mémoire vive est dans la plupart des cas largement suffisante.
    }
    else
    {
        tabDElements = (float*)malloc(*nbDElements * sizeof(float)); // On alloue de la mémoire pour le tableau grâce à la fonction malloc. Celle-ci retourne un pointeur pointant sur notre tableau. (plus précisément le premier élément du tableau, il est a noté que le tableau se comporte comme un pointeur donc on retourne tout simplement un tableau)

        if(tabDElements == NULL) // On vérifie si l'allocation a fonctionné ou non
        {
            printf("L'allocation de la fonction malloc a echouee: mémoire vive insuffisante !");
            exit(0); // On arrête tout
        }

        for(i=0; i<*nbDElements; i++)
        {
            printf("Valeur %d: ",i+1);
            scanf("%f",&tabDElements[i]); // On peut maintenant remplir notre tableau qui a exactement la taille que l'on désire.
        }
    }
    return tabDElements;
}

// Cette procédure va afficher un à un les éléments du tableau au moyen du boucle for.
void affichage(int nbDElements, float* tabAffiche)
{
    int i=0;
    for(i=0; i<nbDElements; i++)
    {
        printf("Element %d = %f\n",i+1,tabAffiche[i]);
    }
}

// Cette fonction permet de calculer la moyenne d'un tableau dont on connait le nombre d'élements
float calculMoyenne(int nbDElements, float* tableauMoyenne)
{
    int i=0;
    float sommeMoyenne=0;
    for(i=0; i<nbDElements; i++)
    {
        sommeMoyenne+=tableauMoyenne[i];
    }
    return sommeMoyenne/((float)i);
}

// Cette fonction permet de calculer la variance d'un tableau dont on connait le nombre d'élements
float calculVariance(int nbDElements, float* tableauVariance, float moyenne)
{
    float sommeVariance=0;
    int i=0;
    for(i=0; i<nbDElements; i++)
    {
        sommeVariance+=tableauVariance[i]*tableauVariance[i];
    }
    return (sommeVariance/((float)nbDElements)-moyenne*moyenne);
}

// Cette fonction permet de trouver la position du minimum d'un tableau dont on connait le nombre d'élements
int positionMinimum(int nbDElements, float* tableauMinimum)
{
    int i=0;
    int positionDuMinimum=0;
    for(i=1; i<nbDElements; i++)
    {
        if(tableauMinimum[i]<tableauMinimum[i-1])
        {
            positionDuMinimum=i;
        }
    }
    return positionDuMinimum;
}
