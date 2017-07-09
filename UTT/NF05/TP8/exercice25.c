#include <stdio.h>
#include <stdlib.h>
#include "exercice25.h"

int exercice25(void)
{
    system("cls"); // On efface ce qui �tait auparavant �crit sur la fen�tre DOS
    int i=0, info=0, nbElements=0;
    printf("Valeur du premier element = ");
    scanf("%d",&info);
    Cellule *liste = initialisationListe(info); // On initialise la liste en cr�ant le premier �l�ment
    printf("Combien d'elements doivent etre ajoutes ?\n");
    scanf("%d",&nbElements);
    for (i=2; i<nbElements; i++) // On saisie tous les �l�ments
    {
        printf("Valeur de l'element %d = ", i);
        scanf("%d",&info);
        liste = add_first(info, liste);
    }
    printf("\nAffichage de la liste chainee :\n");
    affichage(*liste); // On affiche la liste
    liberationMemoire(liste); // On lib�re la m�moire
    return EXIT_SUCCESS;
}

// Fonction qui retourne l'initialisation de la liste avec la saisie du premier �l�ment
Cellule *initialisationListe(int info)
{
    Cellule *liste = (Cellule*)malloc(sizeof(Cellule)); // On alloue dynamiquement les cellules de la liste
    if(liste==NULL) // En cas d'erreur
    {
        printf("Impossible d'initialiser la liste chainee : memoire vive insuffisante !\n");
        exit(EXIT_FAILURE);
    }
    liste->precedent = NULL; // On initialise l'�l�ment pr�c�dent et suivant
    liste->info = info; // On enregistre la premi�re info
    liste->suivant = NULL;
    return liste;
}

// Fonction qui ajoute une cellule
Cellule *add_first(int info, Cellule *liste)
{
    Cellule *aux = (Cellule*)malloc(sizeof(Cellule)); // On alloue dynamiquement la nouvelle cellule
    if(aux==NULL)
    {
        printf("Erreur d'allocation dynamique : memoire vive insuffisante !\n");
        exit(EXIT_FAILURE);
    }
    liste->precedent = aux; // On l'ajoute au d�but juste avant l'�l�ment pr�c�dent
    aux->precedent = NULL;
    aux->info = info;
    aux->suivant = liste;
    return aux ;
}

// Proc�dure d'affichage de la liste
void affichage(Cellule liste)
{
    int i=0;
    Cellule *aux = &liste;
    while(aux!=NULL) // Tant qu'il y a une cellule on affiche
    {
        printf("Valeur %d = %d\n",i+1,aux->info);
        aux = aux->suivant;
        i++;
    }
}

// Proc�dure qui lib�re chacun des cellules allou�es dynamiquement
void liberationMemoire(Cellule *liste)
{
    while(liste->suivant!=NULL)
    {
        liste = liste->suivant;
        free(liste->precedent);
    }
    free(liste);
}
