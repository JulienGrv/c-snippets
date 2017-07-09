#include <stdio.h>
#include <stdlib.h>
#include "exercice22.h"

void exercice22(void)
{
    system("cls"); // On efface ce qui �tait auparavant �crit sur la fen�tre DOS
    int choixQuestion=0;
    printf("---- Menu Exercice 22 ----\n\n1: Saisie d'une phrase\n2: Saisie d'une liste d'etudiants\n");
    fflush(stdin);
    scanf("%d",&choixQuestion);
    system("cls");
    switch(choixQuestion)
    {
    case 1:
        question221();
        break;
    case 2:
        question222();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return exercice22();
}

// Proc�dure de saisie s�curis�e d'une phrase puis affichage
void question221(void)
{
    printf("Saisir votre texte :\n");
    char phrase[100] = {0};
    saisiePhrase(phrase);
    printf("Votre phrase :\n%s\n",phrase);
}

// Proc�dure de saisie s�curis�e d'une phrase
void saisiePhrase(char phrase[100])
{
    fflush(stdin);
    fgets(phrase, 100, stdin);
    clean(phrase);
}
 // Proc�dure qui supprime le retour � la ligne � la fin de la phrase
void clean(char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }
    else
    {
        purger(); // Si on ne trouve pas le dernier caract�re \n alors la chaine saisie �tait trop longue donc on vide le flux stdin
    }
}

// Proc�dure qui vide le flux stdin
void purger(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) // On avale les caract�res � l'aide de la fonction getchar jusqu'� ce que le flux stdin soit vid�
        {}
}

// Proc�dure de saisie d'une liste d'�tudiants, ainsi que les fonctionnalit�es de trie par nom pr�nom ou moyenne
void question222(void)
{
    int nombreDEtudiants=0, i=0, choix=0;
    printf("Combien d'etudiants a lister ?");
    scanf("%d",&nombreDEtudiants);
    etudiant* listeEtudiants = allocationDynamique(nombreDEtudiants); // On alloue la liste des �tudiants en fonction du nombre saisie par l'utilisateur
    for(i=0; i<nombreDEtudiants; i++)
    {
        saisieEtudiant(i, listeEtudiants); // On saisie un � un les �tudiants gr�ce � la saisie s�curis�e
    }
    printf("Voulez-vous trier la liste par ordre croissant des noms et prenoms ? (0=non/1=oui)\n");
    scanf("%d",&choix);
    if(choix==1)
    {
        triageListeEtudiants(nombreDEtudiants, listeEtudiants); // Triage de la liste des �tudiants par nom et pr�nom
    }
    else
    {
        printf("Voulez-vous trier la liste par ordre croissant des moyennes ? (0=non/1=oui)\n");
        scanf("%d",&choix);
        if(choix==1)
        {
            triageParMoyenne(nombreDEtudiants, listeEtudiants); // Triage par moyenne
        }
    }
    printf("Voulez-vous afficher la liste des etudiants ? (0=non/1=oui)\n");
    scanf("%d",&choix);
    if(choix==1)
    {
        // Affichage de la liste des �tudiants
        for(i=0; i<nombreDEtudiants; i++)
        {
            printf("Nom : %s | Prenom : %s | Date de naissance : %d/%d/%d | Note median = %f | Note final = %f | Moyenne = %f\n",listeEtudiants[i].nom,listeEtudiants[i].prenom,listeEtudiants[i].dateDeNaissance[0],listeEtudiants[i].dateDeNaissance[1],listeEtudiants[i].dateDeNaissance[2],listeEtudiants[i].noteMedian,listeEtudiants[i].noteFinal,listeEtudiants[i].moyenne);
        }
    }
    free(listeEtudiants); // lib�ration de la m�moire
}

// Fonction qui retourne un tableau d'�tudiants
etudiant* allocationDynamique(int nombreDEtudiants)
{
    if(nombreDEtudiants<=0)
    {
        printf("Veuillez entrer un nombre d'elements strictement superieur a zero.");
        exit(0);
    }
    else
    {
        etudiant *listeEtudiants = NULL;
        listeEtudiants = malloc(nombreDEtudiants * sizeof(etudiant)); // On alloue de la m�moire pour le tableau gr�ce � la fonction malloc. Celle-ci retourne un pointeur pointant sur notre tableau. (plus pr�cis�ment le premier �l�ment du tableau, il est a not� que le tableau se comporte comme un pointeur donc on retourne tout simplement un tableau)

        if(listeEtudiants==NULL) // On v�rifie si l'allocation a fonctionn� ou non
        {
            printf("L'allocation de la fonction malloc a echouee : memoire vive insuffisante !");
            exit(0); // On arr�te tout en cas d'erreur d'allocation. Ce genre d'erreur n'arrive plus sur les nouveaus ordinateurs puisque la capacit� de la m�moire vive est dans la plupart des cas largement suffisante.
        }
        else
        {
            return listeEtudiants;
        }
    }
}

// Proc�dure de saisie d'un �tudiant
void saisieEtudiant(int IDEtudiant, etudiant *listeEtudiants)
{
    printf("Etudiant %d :\n",IDEtudiant+1);
    printf("Nom : ");
    saisiePhrase(listeEtudiants[IDEtudiant].nom);
    printf("Prenom : ");
    saisiePhrase(listeEtudiants[IDEtudiant].prenom);
    printf("Date de naissance (jj/mm/annee) : ");
    scanf("%d/%d/%d",&(listeEtudiants[IDEtudiant].dateDeNaissance)[0],&(listeEtudiants[IDEtudiant].dateDeNaissance)[1],&(listeEtudiants[IDEtudiant].dateDeNaissance)[2]);
    printf("Note median = ");
    scanf("%f",&listeEtudiants[IDEtudiant].noteMedian);
    printf("Note final = ");
    scanf("%f",&listeEtudiants[IDEtudiant].noteFinal);
    listeEtudiants[IDEtudiant].moyenne=(float)0.4*listeEtudiants[IDEtudiant].noteMedian+(float)0.6*listeEtudiants[IDEtudiant].noteFinal;
}

// Trie bulle de la liste des �tudiants
void triageListeEtudiants(int  nombreDEtudiants, etudiant *listeEtudiants)
{
    int i=0, j=0, fixe=0;
    etudiant temp = {"","",{0},0,0,0};
    for(fixe=0; fixe<nombreDEtudiants-1; fixe++)
    {
        for(i=fixe+1; i<nombreDEtudiants; i++)
        {
            j=0;
            // On trie par nom
            while(listeEtudiants[fixe].nom[j]==listeEtudiants[i].nom[j]&&listeEtudiants[fixe].nom[j]!='\0'&&listeEtudiants[i].nom[j]!='\0'&&j!=100)
            {
                j++;
            }
            if(listeEtudiants[fixe].nom[j]>listeEtudiants[i].nom[j])
            {
                temp=listeEtudiants[fixe];
                listeEtudiants[fixe]=listeEtudiants[i];
                listeEtudiants[i]=temp;
            }
            else // Si le nom des �tudiants est le m�me alors on trie par pr�nom
            {
                j=0;
                while(listeEtudiants[fixe].prenom[j]==listeEtudiants[i].prenom[j]&&listeEtudiants[fixe].prenom[j]!='\0'&&listeEtudiants[i].prenom[j]!='\0'&&j!=100)
                {
                    j++;
                }
                if(listeEtudiants[fixe].prenom[j]>listeEtudiants[i].prenom[j])
                {
                    temp=listeEtudiants[fixe];
                    listeEtudiants[fixe]=listeEtudiants[i];
                    listeEtudiants[i]=temp;
                }
            }
        }
    }
}

// Proc�dure de triage par moyenne des �tudiants
void triageParMoyenne(int nombreDEtudiants, etudiant *listeEtudiants)
{
    int i=0, j=0;
    etudiant temp = {"","",{0},0,0,0};
    for(i=0; i<nombreDEtudiants-1; i++)
    {
        for(j=i+1; j<nombreDEtudiants; j++)
        {
            if(listeEtudiants[i].moyenne>listeEtudiants[j].moyenne)
            {
                temp=listeEtudiants[i];
                listeEtudiants[i]=listeEtudiants[j];
                listeEtudiants[j]=temp;
            }
        }
    }
}
