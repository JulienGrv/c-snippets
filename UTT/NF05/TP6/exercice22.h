#ifndef EXERCICE22_H_INCLUDED
#define EXERCICE22_H_INCLUDED

#include <string.h>

typedef struct
{
    char nom[100];
    char prenom[100];
    int dateDeNaissance[3];
    float noteMedian;
    float noteFinal;
    float moyenne;

} etudiant;

void exercice22(void);
void question221(void);
void saisiePhrase(char *phrase);
void clean(char *chaine);
void purger(void);
void question222(void);
etudiant* allocationDynamique(int nombreDEtudiants);
void saisieEtudiant(int IDEtudiant, etudiant *listeEtudiants);
void triageListeEtudiants(int  nombreDEtudiants, etudiant *listeEtudiants);
void triageParMoyenne(int nombreDEtudiants, etudiant *listeEtudiants);

#endif // EXERCICE22_H_INCLUDED
