#include <stdio.h>
#include <stdlib.h>
#include "exercice24.h"

void exercice24(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
    int choixQuestion=0;
    printf("---- Menu Exercice 24 ----\n\n1: Saisir les infos d'un livre\n2: Creer une bibliotheque\n3: Lire une bibliotheque\n4: Rechercher livre\n5: Modifier informations d'un livre\n");
    scanf("%d",&choixQuestion);
    vidageMemoireTampon();
    system("cls");
    switch(choixQuestion)
    {
    case 1:
        saisirLivre();
        break;
    case 2:
        creerBibliotheque();
        break;
    case 3:
        question243();
        break;
    case 4:
        question244();
        break;
    case 5:
        modification();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return exercice24();
}

// Fonction qui retourne la saisie d'un livre de type BibLivres
BibLivres saisirLivre(void)
{
    BibLivres livre = {"","","","","",0,{0,0,0}};
    printf("Auteur: ");
    fgets(livre.auteur, 20, stdin);
    nettoyeur(livre.auteur);
    printf("Titre: ");
    fgets(livre.titre, 100, stdin);
    nettoyeur(livre.titre);
    printf("Cote: ");
    fgets(livre.cote, 9, stdin);
    nettoyeur(livre.cote);
    printf("Annee de publication: ");
    scanf("%d",&livre.annee);
    vidageMemoireTampon();
    printf("Editeur: ");
    fgets(livre.editeur, 20, stdin);
    nettoyeur(livre.editeur);
    printf("Le livre est-il en pret ou en rayon ? (pret/rayon)\n");
    fgets(livre.enPret, 6, stdin);
    nettoyeur(livre.enPret);
    if(!strcmp("pret",livre.enPret)) // inutile de saisire la date de pret si celui-ci est en rayon
    {
        printf("Date de pret (jj/mm/aaaa): ");
        scanf("%d/%d/%d",&livre.dateDePret.jour,&livre.dateDePret.mois,&livre.dateDePret.annee);
        vidageMemoireTampon();
    }
    return livre;
}

// Procédure qui permet de retirer le retour à la ligne lors de la saisie de fgets
void nettoyeur(char *chaine)
{
    char *positionEntree = strchr(chaine, '\n'); // On recherche la position du retour à la ligne
    if (positionEntree!=NULL) // Si on a trouvé le retour à la ligne
    {
        *positionEntree = '\0'; // On le remplace par \0
    }
    else // Sinon on vide la mémoire tampon car la chaine saisie a dépasser le nombre de caractère maximum qu'elle peut avoir
    {
        vidageMemoireTampon();
    }
}

// Procédure permettant de vider la mémoire tampon du flux stdin
void vidageMemoireTampon(void)
{
    int caractere = 0;
    while ((caractere=getchar())!='\n'&&caractere!=EOF) // On "avale" un à un les caractères du flux stdin tant qu'on a pas rencontré le dernier caractère \n ou que stdin n'est pas vide.
        {}
}

// Procédure qui permet de créer une bibliotheque de livres
void creerBibliotheque(void)
{
    int nbLivres = 0, i = 0;
    char nomDuFichier[100] = "";
    BibLivres livre = {"","","","","",0,{0,0,0}};
    printf("Combien de livres doivent etre enregistres ?\n");
    scanf("%d",&nbLivres);
    vidageMemoireTampon();
    printf("Quel est le nom du fichier d'enregistrement ?\n");
    fgets(nomDuFichier, 100, stdin);
    nettoyeur(nomDuFichier);
    FILE *fichier = NULL;
    fichier = fopen(nomDuFichier, "w");
    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s : fichier introuvable !\n",nomDuFichier);
        exit(EXIT_FAILURE);
    }
    fprintf(fichier, "%d livres stockés.\n", nbLivres);
    for(i=0; i<nbLivres; i++)
    {
        printf("Livre %d :\n",i+1);
        livre = saisirLivre();
        fprintf(fichier, "%s\n%s\n%s\n%d\n%s\n%s\n%d/%d/%d\n",livre.auteur,livre.titre,livre.cote,livre.annee,livre.editeur,livre.enPret,livre.dateDePret.jour,livre.dateDePret.mois,livre.dateDePret.annee);
    }
    fclose(fichier);
}

// Procédure qui permet de lire une bibliotheque
void question243(void)
{
    char nomDuFichier[100] = "";
    BibLivres *bibliotheque = NULL;
    printf("Quel est le nom du fichier bibliotheque ?\n");
    fgets(nomDuFichier, 100, stdin);
    nettoyeur(nomDuFichier);
    lireBibliotheque(nomDuFichier, &bibliotheque);
    free(bibliotheque);
}
 // Procédure qui lit une bibliotheque
void lireBibliotheque(char nomDuFichier[100], BibLivres **bibliotheque)
{
    FILE *fichier = NULL;
    int nbLivres = 0, i = 0;
    fichier = fopen(nomDuFichier, "r");
    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s : fichier introuvable !\n", nomDuFichier);
        exit(EXIT_FAILURE);
    }
    fscanf(fichier, "%d", &nbLivres);
    if(nbLivres<=0)
    {
        printf("Veuillez entrer un nombre d'elements strictement superieur a zero.");
        exit(EXIT_FAILURE);
    }
    fseek(fichier, 17, SEEK_CUR);
    *bibliotheque = (BibLivres*)malloc(nbLivres*sizeof(BibLivres));
    if(*bibliotheque==NULL)
    {
        printf("L'allocation dynamique a echouee : memoire vive insuffisante !\n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<nbLivres; i++)
    {
        fscanf(fichier, "%s\n", &(((*bibliotheque)[i]).auteur));
        fscanf(fichier, "%s\n", &(((*bibliotheque)[i]).titre));
        fscanf(fichier, "%s\n", &(((*bibliotheque)[i]).cote));
        fscanf(fichier, "%d\n", &(((*bibliotheque)[i]).annee));
        fscanf(fichier, "%s\n", &(((*bibliotheque)[i]).editeur));
        fscanf(fichier, "%s\n", &(((*bibliotheque)[i]).enPret));
        fscanf(fichier, "%d/%d/%d\n", &(((*bibliotheque)[i]).dateDePret.jour), &(((*bibliotheque)[i]).dateDePret.mois), &(((*bibliotheque)[i]).dateDePret.annee));
    }
    fclose(fichier);
}

// Procédure de recherche d'un livre dans la bibliotheque grace à son titre
void question244(void)
{
    char nomDuFichier[100] = "";
    printf("Quel est le nom du fichier bibliotheque ?\n");
    fgets(nomDuFichier, 100, stdin);
    nettoyeur(nomDuFichier);
    rechercheLivre(nomDuFichier);
}

// Fonction qui retourne la position du livre recherché et qui affiche son contenu
int rechercheLivre(char nomDuFichier[100])
{
    char titreLivre[100] = "";
    BibLivres *bibliotheque = NULL;
    int nbLivres = 0, i = 0;
    FILE *fichier = NULL;
    fichier = fopen(nomDuFichier, "r");
    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s : fichier introuvable !\n", nomDuFichier);
        exit(EXIT_FAILURE);
    }
    fscanf(fichier, "%d", &nbLivres);
    printf("Quel est le titre du livre recherche ?\n");
    fgets(titreLivre, 100, stdin);
    nettoyeur(titreLivre);
    lireBibliotheque(nomDuFichier, &bibliotheque);
    while(strcmp(bibliotheque[i].titre, titreLivre)&&i<nbLivres)
    {
        i++;
    }
    if(!strcmp(bibliotheque[i].titre, titreLivre)&&!strcmp(bibliotheque[i].enPret,"pret"))
    {
        printf("Livre trouvee !\nAuteur : %s\nTitre : %s\nCote : %s\nAnnee de publication : %d\nEditeur : %s\nStatut : en %s\nDate de pret : %d/%d/%d\n",bibliotheque[i].auteur,bibliotheque[i].titre,bibliotheque[i].cote,bibliotheque[i].annee,bibliotheque[i].editeur,bibliotheque[i].enPret,bibliotheque[i].dateDePret.jour,bibliotheque[i].dateDePret.mois,bibliotheque[i].dateDePret.annee);
    }
    else if(!strcmp(bibliotheque[i].titre, titreLivre)&&strcmp(bibliotheque[i].enPret,"pret"))
    {
        printf("Livre trouvee !\nAuteur : %s\nTitre : %s\nCote : %s\nAnnee de publication : %d\nEditeur : %s\nStatut : en %s\n",bibliotheque[i].auteur,bibliotheque[i].titre,bibliotheque[i].cote,bibliotheque[i].annee,bibliotheque[i].editeur,bibliotheque[i].enPret);
    }
    else
    {
        printf("Livre introuvable !\n");
    }
    free(bibliotheque);
    fclose(fichier);
    return i;
}

// Procédure de modification d'un livre en saisissant son titre
void modification(void)
{
    char nomDuFichier[100] = "";
    BibLivres *bibliotheque = NULL;
    int nbLivres = 0, i = 0;
    FILE *fichier = NULL;
    printf("Quel est le nom du fichier bibliotheque ?\n");
    fgets(nomDuFichier, 100, stdin);
    nettoyeur(nomDuFichier);
    int IDLivreModifie = rechercheLivre(nomDuFichier);
    lireBibliotheque(nomDuFichier, &bibliotheque);
    printf("Veuillez saisir les nouvelles informations du livre :\n");
    bibliotheque[IDLivreModifie] = saisirLivre();
    fichier = fopen(nomDuFichier, "r+");
    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s : fichier introuvable !\n", nomDuFichier);
        exit(EXIT_FAILURE);
    }
    fscanf(fichier, "%d", &nbLivres);
    fseek(fichier, 0, SEEK_SET);
    // On réenregistre le fichier
    fprintf(fichier, "%d livres stockés.\n", nbLivres);
    for(i=0; i<nbLivres; i++)
    {
        fprintf(fichier, "%s\n%s\n%s\n%d\n%s\n%s\n%d/%d/%d\n",bibliotheque[i].auteur,bibliotheque[i].titre,bibliotheque[i].cote,bibliotheque[i].annee,bibliotheque[i].editeur,bibliotheque[i].enPret,bibliotheque[i].dateDePret.jour,bibliotheque[i].dateDePret.mois,bibliotheque[i].dateDePret.annee);
    }
    free(bibliotheque);
    fclose(fichier);
}
