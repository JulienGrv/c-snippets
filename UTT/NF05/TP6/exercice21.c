#include <stdio.h>
#include <stdlib.h>
#include "exercice21.h"

void exercice21(void)
{
    system("cls"); // On efface ce qui �tait auparavant �crit sur la fen�tre DOS
    int choixQuestion=0;
    printf("---- Menu Exercice 21 ----\n\n1: Saisir un vecteur\n2: Somme, soustraction et produit scalaire de 2 vecteurs\n");
    scanf("%d",&choixQuestion);
    system("cls");
    switch(choixQuestion)
    {
    case 1:
        question1();
        break;
    case 2:
        question2();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return exercice21();
}

// Proc�dure de saisie d'un vecteur
void question1(void)
{
    float *vecteur = NULL; // pointeur vers float qui contiendra les �l�ments du vecteur
    int nbDElements = 0;
    printf("Qu'elle est le nombre d'elements a saisir ?\n");
    scanf("%d",&nbDElements); // On demande le nombre d'�l�ments contenus dans le vecteur
    saisieVecteur(&vecteur, nbDElements);
    free(vecteur); // On lib�re la m�moire

}

// Proc�dure d'allocation dynamique du tableau des �l�ments d'un vecteur, ainsi que la saisie des �l�ments
void saisieVecteur(float **vecteur, int nbDElements)
{
    int i=0;

    if(nbDElements<=0)
    {
        printf("Veuillez entrer un nombre d'elements strictement superieur a zero.");
    }
    else
    {
        *vecteur = (float*)malloc(nbDElements * sizeof(float)); // On alloue de la m�moire pour le tableau gr�ce � la fonction malloc. Celle-ci retourne un pointeur pointant sur notre tableau.

        if(!(*vecteur)) // On v�rifie si l'allocation a fonctionn� ou non
        {
            printf("L'allocation de la fonction malloc a echouee: memoire vive insuffisante !");
            exit(EXIT_FAILURE); // On arr�te tout en cas d'erreur d'allocation. Ce genre d'erreur n'arrive plus sur les nouveaus ordinateurs puisque la capacit� de la m�moire vive est dans la plupart des cas largement suffisante.
        }
        printf("Saisir les elements du vecteur (reels positifs)\n");
        for(i=0; i<nbDElements; i++)
        {
            printf("Element %d: ",i+1);
            scanf("%f",&((*vecteur)[i])); // On peut maintenant remplir notre tableau qui a exactement la taille que l'on d�sire.
            if((*vecteur)[i]<0)
            {
                printf("Vous devez saisir des reels positifs ! Recommencez :\n");
                i--;
            }
        }
    }
}

// Proc�dure permettant de saisir 2 vecteurs et d'en faire la somme, la soustraction et le produit scalaire.
void question2(void)
{
    int nbDElements=0;
    printf("Veuillez indiquer le nombre d'elements des 2 vecteurs a saisir :\n");
    scanf("%d",&nbDElements); // On demande le nombre d'�l�ments contenus dans les vecteurs
    float *vecteur1 = NULL, *vecteur2 = NULL;
    printf("Veuillez saisir le vecteur 1.\n");
    saisieVecteur(&vecteur1, nbDElements);
    printf("Veuillez saisir le vecteur 2.\n");
    saisieVecteur(&vecteur2, nbDElements);
    float *somme = sommeVecteurs(vecteur1, vecteur2, nbDElements);
    float *soustraction = soustractionVecteurs(vecteur1, vecteur2, nbDElements);
    float produit = produitScalaire(vecteur1, vecteur2, nbDElements);
    printf("Vecteur somme : \n");
    affichage(somme, nbDElements);
    printf("Vecteur soustraction : \n");
    affichage(soustraction, nbDElements);
    printf("Le produit scalaire vaut : %f\n",produit);
}

// Fonction qui retourne la somme de 2 vecteurs
float* sommeVecteurs(float *vecteur1, float *vecteur2, int nbDElements)
{
    float *somme = NULL;
    somme = (float*)malloc(nbDElements * sizeof(float));
    int i = 0;
    for (i=0; i<nbDElements; i++)
    {
        somme[i] = vecteur1[i] + vecteur2[i];
    }
    return somme;
}

// Fonction qui retourne la soustraction de 2 vecteurs
float* soustractionVecteurs(float *vecteur1, float *vecteur2, int nbDElements)
{
    float *soustraction = NULL;
    soustraction = (float*)malloc(nbDElements * sizeof(float));
    int i = 0;
    for (i=0; i<nbDElements; i++)
    {
        soustraction[i] = vecteur1[i] - vecteur2[i];
    }
    return soustraction;
}

// Fonction qui retourne le produit scalaire
float produitScalaire(float *vecteur1, float *vecteur2, int nbDElements)
{
    float produit = 0;
    int i = 0;
    for (i=0; i<nbDElements; i++)
    {
        produit = produit + vecteur1[i] * vecteur2[i];
    }
    return produit;
}

// Proc�dure d'affichage d'un vecteur
void affichage(float *vecteurAffiche, int nbDElements)
{
    int i=0;
    for(i=0;i<nbDElements;i++)
    {
        printf("Element %d: %f\n",i,vecteurAffiche[i]);
    }
}
