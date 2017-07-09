#include <stdio.h>
#include <stdlib.h>
#include "exercice26.h"

int exercice26(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
    int choixQuestion=0;
    printf("---- Menu Exercice 26 ----\n\n1: Creer une liste de contacts\n");
    scanf("%d",&choixQuestion);
    system("cls");
    vidageMemoireTampon();
    switch(choixQuestion)
    {
    case 1:
        question261();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    return EXIT_SUCCESS;
}

void question261(void)
{
    int IDContact = 1, finSaisie = 0, telephone = 0, choix =0;
    char nomSaisie[100] = "", prenomSaisie[100] = "";
    printf("Contact 1 :\nNom = ");
    fgets(nomSaisie, 100, stdin);
    nettoyeur(nomSaisie);
    printf("Prenom = ");
    fgets(prenomSaisie, 100, stdin);
    nettoyeur(prenomSaisie);
    printf("Telephone = ");
    scanf("%d",&telephone);
    vidageMemoireTampon();
    Contact *listeContacts = initialisationListeContacts(nomSaisie, prenomSaisie, telephone);
    printf("Voulez-vous ajouter un autre contact ? (0=Non/1=Oui)\n");
    scanf("%d",&finSaisie);
    vidageMemoireTampon();
    while(finSaisie==1)
    {
        IDContact++;
        printf("Contact %d :\nNom = ", IDContact);
        fgets(nomSaisie, 100, stdin);
        nettoyeur(nomSaisie);
        printf("Prenom = ");
        fgets(prenomSaisie, 100, stdin);
        nettoyeur(prenomSaisie);
        printf("Telephone = ");
        scanf("%d",&telephone);
        vidageMemoireTampon();
        listeContacts = ajouterContactDebut(listeContacts, IDContact, nomSaisie, prenomSaisie, telephone);
        printf("Voulez-vous ajouter un autre contact ? (0=Non/1=Oui)\n");
        scanf("%d",&finSaisie);
        vidageMemoireTampon();
    }
    printf("Voulez-vous trier la liste de contacts par ordre alphabetique ? (0=Non/1=Oui)");
    scanf("%d",&choix);
    vidageMemoireTampon();
    if(choix==1)
    {
        trieAlphabetique(&listeContacts);
    }
    system("cls");
    affichageContacts(*listeContacts);
    printf("\nSouhaitez-vous modifier les informations d'un contact ? (0=Non/1=Oui)\n");
    scanf("%d",&choix);
    vidageMemoireTampon();
    if(choix==1)
    {
        printf("Quel est l'ID du contact a modifier ?\n");
        scanf("%d",&IDContact);
        vidageMemoireTampon();
        system("cls");
        modifierContact(IDContact, listeContacts);
        printf("\nVoulez-vous a nouveau trier la liste de contacts par ordre alphabetique ? (0=Non/1=Oui)");
        scanf("%d",&choix);
        vidageMemoireTampon();
        system("cls");
        printf("Nouvelle liste de contacts :\n");
        affichageContacts(*listeContacts);
    }
    sauvegardeListe(listeContacts, IDContact);
    liberationMemoireContact(listeContacts);
}

// Fonction qui retourne une liste chaînée avec le premier contact
Contact *initialisationListeContacts(char *nomSaisie, char *prenomSaisie, int telephone)
{
    Contact *liste = (Contact*)malloc(sizeof(Contact)); // On alloue dynamiquement le premier contact de notre liste
    if(liste==NULL)
    {
        printf("Impossible d'initialiser la liste chainee : memoire vive insuffisante !\n");
        exit(EXIT_FAILURE);
    }
    liste->nom = malloc(strlen(nomSaisie)+1);// On alloue dynamiquement le nom du contact idem pour le prénom
    strcpy(liste->nom, nomSaisie); // On copie le nom saisie dans la variable nom allouée dynamiquement à la longueur suffisante (idem pour le prénom)
    liste->prenom = malloc(strlen(prenomSaisie)+1);
    strcpy(liste->prenom, prenomSaisie);
    liste->tel = telephone;
    liste->ID = 1;
    liste->suivant = NULL;
    return liste;
}

// Procédure qui permet de retirer le retour à la ligne lors de la saisie de fgets
void nettoyeur(char *chaine)
{
    char *positionEntree = strchr(chaine, '\n'); // On recherche la position du retour à la ligne
    if (positionEntree!=NULL) // Si on a trouvé le retour à la ligne
    {
        *positionEntree = '\0'; // On le remplace par \0
    }
    else // Sinon on vide la mémoire tampon
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

// Fonction qui ajoute un contact au début de la liste et qui retourne la nouvelle liste
Contact *ajouterContactDebut(Contact *liste, int identifiant, char *nomSaisie, char *prenomSaisie, int telephone)
{
    Contact *aux = (Contact*)malloc(sizeof(Contact)); // On alloue dynamiquement le nouveau contact
    aux->nom = malloc(strlen(nomSaisie)+1); // On alloue dynamiquement le nom du contact idem pour le prénom
    strcpy(aux->nom, nomSaisie); // On copie le nom saisie dans la variable nom allouée dynamiquement à la longueur suffisante (idem pour le prénom)
    aux->prenom = malloc(strlen(prenomSaisie)+1);
    strcpy(aux->prenom, prenomSaisie);
    aux->tel = telephone;
    aux->ID = identifiant;
    aux->suivant = liste;
    return aux; // On retourne la nouvelle liste
}

// Procédure qui permet d'afficher la liste de contacts
void affichageContacts(Contact liste)
{
    Contact *aux = &liste;
    while(aux!=NULL)
    {
        printf("ID = %d\n",aux->ID);
        printf("Nom = %s\n",aux->nom);
        printf("Prenom = %s\n",aux->prenom);
        printf("Telephone = %d\n",aux->tel);
        aux = aux->suivant;
    }
}

// Procédure qui permet de trier alphabétiquement la liste de contacts, méthode de trie : par sélection
void trieAlphabetique(Contact **listeContacts)
{
    Contact *fixe = *listeContacts;
    Contact *dynamique = fixe->suivant;
    Contact *plusPetit = fixe;
    int lettre = 0;
    while(fixe->suivant!=NULL)
    {
        while(dynamique!=NULL)
        {
            lettre = 0;
            if(strcmp(dynamique->nom,plusPetit->nom))
            {
                while(dynamique->nom[lettre]==plusPetit->nom[lettre])
                {
                    lettre++;
                }
                if(dynamique->nom[lettre]>plusPetit->nom[lettre])
                {
                    plusPetit = dynamique;
                }
            }
            else
            {
                while(dynamique->prenom[lettre]==plusPetit->prenom[lettre])
                {
                    lettre++;
                }
                if(dynamique->prenom[lettre]>plusPetit->prenom[lettre])
                {
                    plusPetit = dynamique;
                }
            }
            dynamique = dynamique->suivant;
        }
        *listeContacts = supprimerContact(plusPetit->ID, *listeContacts);
        fixe = supprimerContact(plusPetit->ID, fixe);
        *listeContacts = ajouterContactDebut(*listeContacts, plusPetit->ID, plusPetit->nom, plusPetit->prenom, plusPetit->tel);
        dynamique = fixe->suivant;
        plusPetit = fixe;
    }
    *listeContacts = supprimerContact(fixe->ID, *listeContacts);
    *listeContacts = ajouterContactDebut(*listeContacts, fixe->ID, fixe->nom, fixe->prenom, fixe->tel);
}

// Fonction qui permet de supprimer un contact de la liste puis de retourner l'adresse de la nouvelle liste
Contact *supprimerContact(int identifiant, Contact *liste)
{
    if(liste==NULL)
    {
        return liste;
    }
    else if(liste->ID==identifiant)
    {
        return liste->suivant;
    }
    else
    {
        return ajouterContactDebut(supprimerContact(identifiant, liste->suivant), liste->ID, liste->nom, liste->prenom, liste->tel);
    }
}

// Procédure de modification des infos d'un contact
void modifierContact(int identifiant, Contact *liste)
{
    Contact *aux = liste;
    char nomSaisie[100] = "", prenomSaisie[100] = "";
    int telephone = 0;
    while(aux->ID!=identifiant&&aux!=NULL)
    {
        aux=aux->suivant;
    }
    if(aux!=NULL)
    {
        printf("Contact trouve :\n");
        printf("ID = %d\n",aux->ID);
        printf("Nom = %s\n",aux->nom);
        printf("Prenom = %s\n",aux->prenom);
        printf("Telephone = %d\n",aux->tel);
        printf("\nSaisir les nouvelles informations du contact %d :\nNom = ", identifiant);
        fgets(nomSaisie, 100, stdin);
        nettoyeur(nomSaisie);
        aux->nom = malloc(strlen(nomSaisie)+1);
        strcpy(aux->nom, nomSaisie);
        printf("Prenom = ");
        fgets(prenomSaisie, 100, stdin);
        nettoyeur(prenomSaisie);
        aux->prenom = malloc(strlen(prenomSaisie)+1);
        strcpy(aux->prenom, prenomSaisie);
        printf("Telephone = ");
        scanf("%d",&telephone);
        vidageMemoireTampon();
        aux->tel = telephone;
    }
}

// Procédure de sauvegarde de la liste de contacts
void sauvegardeListe(Contact *liste, int nbContacts)
{
    char nomDuFichier[100] = "";
    Contact *aux = liste;
    printf("\nQuel est le nom du fichier de sauvegarde ?\n");
    fgets(nomDuFichier, 100, stdin);
    nettoyeur(nomDuFichier);
    FILE *fichier = NULL;
    fichier = fopen(nomDuFichier, "w");
    fprintf(fichier, "%d contacts.\n", nbContacts);
    while(aux!=NULL)
    {
        fprintf(fichier, "ID : %d\n", aux->ID);
        fprintf(fichier, "Nom : %s\n", aux->nom);
        fprintf(fichier, "Prénom : %s\n", aux->prenom);
        aux=aux->suivant;
    }
    fclose(fichier);
}

// Procédure qui libère chacun des cellules allouées dynamiquement
void liberationMemoireContact(Contact *liste)
{
    Contact *aux = liste;
    while(liste->suivant!=NULL)
    {
        liste = liste->suivant;
        free(aux);
        aux = liste;
    }
    free(liste);
}
