#include <stdio.h>
#include <stdlib.h>
#include "exercice23.h"

void exercice23(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
    int choixQuestion=0;
    printf("---- Menu Exercice 23 ----\n\n1: Stocker M vecteurs de taille N et faire une somme\n2: Afficher le contenu d'un fichier\n");
    scanf("%d",&choixQuestion);
    system("cls");
    switch(choixQuestion)
    {
    case 1:
        question231();
        break;
    case 2:
        question232();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return exercice23();
}

// Procédure de création d'une liste de M vecteurs réels de taille N et d'enregistrement de la liste dans un fichier
void question231(void)
{
    int nombreDeVecteurs=0, tailleVecteur=0, choix=0;
    char nomDuFichier[100]="";
    printf("Combien de vecteurs ?\n");
    scanf("%d",&nombreDeVecteurs);
    printf("Taille des vecteurs ?\n");
    scanf("%d",&tailleVecteur);
    float **listeDeVecteurs = saisieVecteurs(nombreDeVecteurs, tailleVecteur); // On créer la liste de M vecteurs de taille N
    fflush(stdin);
    printf("Nom du fichier de sauvegarde de la liste des vecteurs ?\n");
    fgets(nomDuFichier, 100, stdin);
    clean(nomDuFichier);
    sauvegardeFichier(nombreDeVecteurs, tailleVecteur, listeDeVecteurs, nomDuFichier); // On enregistre la liste des M vecteurs
    printf("Voulez-vous effectuer la somme de 2 vecteurs ? (0=Non/1=Oui)\n");
    scanf("%d",&choix);
    if(choix==1)
    {
        system("cls");
        question233(nomDuFichier, tailleVecteur); // On effectue la somme de deux vecteurs choisis par l'utilisateur
    }
    free(listeDeVecteurs[0]);
	free(listeDeVecteurs);
}

// Fonction qui retourne une liste de M vecteurs de taille N
float** saisieVecteurs(int nombreDeVecteurs, int tailleVecteur)
{
    if(nombreDeVecteurs<=0)
    {
        printf("Veuillez entrer un nombre de vecteurs strictement superieur a zero.");
        exit(0);
    }
    else
    {
        float **listeDeVecteurs = NULL;
        listeDeVecteurs = (float**)malloc(nombreDeVecteurs*sizeof(float*)); // On alloue dynamiquement la liste de M vecteurs
        if(listeDeVecteurs==NULL) // On vérifie si l'allocation a fonctionné ou non
        {
            printf("L'allocation de la fonction malloc a echouee : memoire vive insuffisante !");
            exit(EXIT_FAILURE); // On arrête tout en cas d'erreur d'allocation. Ce genre d'erreur n'arrive plus sur les nouveaus ordinateurs puisque la capacité de la mémoire vive est dans la plupart des cas largement suffisante.
        }
        else
        {
            float *tableauDesElements = NULL;
            tableauDesElements = (float*)malloc(nombreDeVecteurs*tailleVecteur*sizeof(float)); // On alloue dynamiquement les M*N éléments des vecteurs
            if(tableauDesElements==NULL) // On vérifie si l'allocation a fonctionné ou non
            {
                printf("L'allocation de la fonction malloc a echouee : memoire vive insuffisante !");
                exit(EXIT_FAILURE); // On arrête tout en cas d'erreur d'allocation. Ce genre d'erreur n'arrive plus sur les nouveaus ordinateurs puisque la capacité de la mémoire vive est dans la plupart des cas largement suffisante.
            }
            else
            {
                int i=0, j=0;
                for(i=0; i<nombreDeVecteurs; i++)
                {
                    listeDeVecteurs[i] = &tableauDesElements[i*tailleVecteur]; // On place N éléments à chaque vecteur de la liste des M vecteurs
                    printf("Saisir vecteur %d :\n",i+1);
                    for(j=0; j<tailleVecteur; j++)
                    {
                        scanf("%f",&listeDeVecteurs[i][j]); // On effectue la saisie des vecteurs
                    }
                }
                return listeDeVecteurs;
            }
        }
    }
}

// Procédure qui retire le \n à la fin d'une saisie ou qui vide le flux stdin
void clean(char *chaine)
{
    char *p = strchr(chaine, '\n');
    if (p)
    {
        *p = 0;
    }
    else
    {
        purger();
    }
}

// Procédure qui vide le flux stdin
void purger(void)
{
    int c;
    while ((c = getchar())!='\n'&&(c!=EOF))
        {}
}

// Procédure qui permet d'enregistrer dans un fichier une liste de M vecteurs de taille N
void sauvegardeFichier(int nombreDeVecteurs, int tailleVecteur, float **listeDeVecteurs, char *nomDuFichier)
{
    FILE* fichier = NULL;
    strcat(nomDuFichier,".txt"); // Pour s'assurer que l'on enregistre bien le fichier sous le format .txt
    fichier = fopen(nomDuFichier, "w"); // On ouvre le fichier en mode écriture
    if (fichier != NULL)
    {
        int i=0, j=0;
        for(i=0; i<nombreDeVecteurs; i++)
        {
            fprintf(fichier, "Vecteur %d = (", i+1);
            for(j=0; j<tailleVecteur; j++)
            {
                fprintf(fichier, "%f,", listeDeVecteurs[i][j]); // On écrit dans le fichier sous une forme esthétique
            }
            fseek(fichier, -1, SEEK_CUR);
            fputs(")\n", fichier);
        }
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s",nomDuFichier); // Si erreur d'ouverture du fichier
    }
    fclose(fichier);
}

// Procédure d'affichage du contenu d'un fichier
void question232(void)
{
    char nomDuFichier[100] = "";
    printf("Quel est le nom du fichier a ouvrir ?\n");
    fflush(stdin);
    fgets(nomDuFichier, 100, stdin);
    clean(nomDuFichier);
    affichageFichier(nomDuFichier);
}
 // Fonction qui permet de lire le contenu d'un fichier et de l'afficher
void affichageFichier(char nomDuFichier[100])
{
    FILE *fichier = NULL;
    fichier = fopen(nomDuFichier, "r"); // On ouvre le fichier en mode lecture
    if(fichier!=NULL) // Si pas d'erreur :
    {
        char caractereActuel = 0;
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        }
        while (caractereActuel != EOF);   // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        printf("\n");
        fclose(fichier); // On referme le fichier
    }
    else
    {
        printf("Erreur de lecture du fichier !\n");
    }
}

void question233(char nomDuFichier[100], int tailleVecteur)
{
    float *vecteur1 = creationVecteur(tailleVecteur); // On créer 2 vecteurs qui serviront à l'addition
    float *vecteur2 = creationVecteur(tailleVecteur);
    FILE *fichier = NULL;
    fichier = fopen(nomDuFichier, "r+"); // On ouvre le fichier en mode lecture et écriture
    if(fichier!=NULL)
    {
        affichageFichier(nomDuFichier); // Dans un premier temps on affiche le contenu du fichier
        int numero1 = 0, numero2 = 0, i = 0;
        printf("Quels sont les numeros des vecteurs que vous souhaitez additionner ?\nNumero 1 = "); // on demande à l'utilisateur le numéro des vecteurs à additionner
        scanf("%d",&numero1);
        printf("Numero 2 = ");
        scanf("%d",&numero2);
        fseek(fichier, 0, SEEK_SET);
        for(i=1; i<numero1; i++) // On se déplace dans le fichier jusqu'à la ligne du vecteur recherché
        {
            while(fgetc(fichier)!='\n')
                {}
        }
        while(fgetc(fichier)!='(')
            {}
        for(i=0; i<tailleVecteur; i++) // on lit les composantes du vecteur
        {
            fscanf(fichier, "%f,", &vecteur1[i]);
        }

        fseek(fichier, 0, SEEK_SET); // On se replace au début du fichier
        for(i=1; i<numero2; i++) // On se place au début de la ligne du deuxième vecteur cherché
        {
            while(fgetc(fichier)!='\n')
                {}
        }
        while(fgetc(fichier)!='(')
            {}
        for(i=0; i<tailleVecteur; i++) // on lit ses composantes
        {
            fscanf(fichier, "%f,", &vecteur2[i]);
        }
        fseek(fichier, 0, SEEK_END);
        fprintf(fichier, "Vecteur %d + Vecteur %d = (", numero1, numero2);
        for(i=0; i<tailleVecteur; i++) // On effectue la somme des vecteurs que l'on enregistre dans le fichier
        {
            fprintf(fichier, "%f,", vecteur1[i]+vecteur2[i]);
        }
        fseek(fichier, -1, SEEK_CUR);
        fputs(")\n", fichier);
        fclose(fichier);
        free(vecteur1);
        free(vecteur2);
    }
}
 // Fonction qui retourne la création d'un vecteur de taille N
float* creationVecteur(int tailleVecteur)
{
    float* vecteur=NULL; // On déclare un pointeur qui servira à contenir l'adresse de notre futur tableau.
    vecteur = (float*)malloc(tailleVecteur*sizeof(float)); // On alloue de la mémoire pour le tableau grâce à la fonction malloc. Celle-ci retourne un pointeur pointant sur notre tableau. (plus précisément le premier élément du tableau, il est a noté que le tableau se comporte comme un pointeur donc on retourne tout simplement un tableau)
    if(vecteur == NULL) // On vérifie si l'allocation a fonctionné ou non
    {
        printf("L'allocation de la fonction malloc a echouee : memoire vive insuffisante !");
        exit(EXIT_FAILURE); // On arrête tout
    }
    else
    {
        return vecteur;
    }
}
