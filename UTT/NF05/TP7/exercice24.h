#ifndef EXERCICE24_H_INCLUDED
#define EXERCICE24_H_INCLUDED

#include <string.h>

typedef struct
{
    int jour, mois, annee;
} date;

typedef struct
{
    char auteur[20], titre[100], cote[9], editeur[20], enPret[6];
    int annee;
    date dateDePret;
} BibLivres;

void exercice24(void);
BibLivres saisirLivre(void);
void nettoyeur(char *chaine);
void vidageMemoireTampon(void);
void creerBibliotheque(void);
int rechercheLivre(char nomDuFichier[100]);
void question244(void);
void question243(void);
void lireBibliotheque(char nomDuFichier[100], BibLivres **bibliotheque);
void modification(void);

#endif // EXERCICE24_H_INCLUDED
