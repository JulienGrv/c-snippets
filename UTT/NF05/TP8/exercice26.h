#ifndef EXERCICE26_H_INCLUDED
#define EXERCICE26_H_INCLUDED

#include <stdbool.h>
#include <string.h>

typedef struct Contact Contact;
struct Contact
{
    char *nom, *prenom;
    int tel, ID;
    Contact *suivant;
};

int exercice26(void);
void question261(void);
Contact *initialisationListeContacts(char *nomSaisie, char *prenomSaisie, int telephone);
void nettoyeur(char *chaine);
void vidageMemoireTampon(void);
void affichageContacts(Contact liste);
Contact *ajouterContactDebut(Contact *liste, int identifiant, char *nomSaisie, char *prenomSaisie, int telephone);
void trieAlphabetique(Contact **listeContacts);
Contact *supprimerContact(int identifiant, Contact *liste);
void modifierContact(int identifiant, Contact *liste);
void sauvegardeListe(Contact *liste, int nbContacts);
void liberationMemoireContact(Contact *liste);

#endif // EXERCICE26_H_INCLUDED
