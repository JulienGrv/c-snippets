#include <stdio.h>
#include <stdlib.h>
#include "exercice25.h"

int exercice25(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
    int i=0, info=0, nbElements=0;
    printf("Valeur du premier element = ");
    scanf("%d",&info);
    Cellule *liste = initialisationListe(info); // On initialise la liste en créant le premier élément
    printf("Combien d'elements doivent etre ajoutes ?\n");
    scanf("%d",&nbElements);
    for (i=2; i<nbElements; i++) // On saisie tous les éléments
    {
        printf("Valeur de l'element %d = ", i);
        scanf("%d",&info);
        liste = add_first(info, liste);
    }
    printf("\nAffichage de la liste chainee :\n");
    affichage(*liste); // On affiche la liste
    liberationMemoire(liste); // On libère la mémoire
    return EXIT_SUCCESS;
}

// Fonction qui retourne l'initialisation de la liste avec la saisie du premier élément
Cellule *initialisationListe(int info)
{
    Cellule *liste = (Cellule*)malloc(sizeof(Cellule)); // On alloue dynamiquement les cellules de la liste
    if(liste==NULL) // En cas d'erreur
    {
        printf("Impossible d'initialiser la liste chainee : memoire vive insuffisante !\n");
        exit(EXIT_FAILURE);
    }
    liste->precedent = NULL; // On initialise l'élément précédent et suivant
    liste->info = info; // On enregistre la première info
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
    liste->precedent = aux; // On l'ajoute au début juste avant l'élément précédent
    aux->precedent = NULL;
    aux->info = info;
    aux->suivant = liste;
    return aux ;
}

// Procédure d'affichage de la liste
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

// Procédure qui libère chacun des cellules allouées dynamiquement
void liberationMemoire(Cellule *liste)
{
    while(liste->suivant!=NULL)
    {
        liste = liste->suivant;
        free(liste->precedent);
    }
    free(liste);
}
