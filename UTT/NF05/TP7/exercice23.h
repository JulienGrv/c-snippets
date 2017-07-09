#ifndef EXERCICE23_H_INCLUDED
#define EXERCICE23_H_INCLUDED

#include <string.h>

void exercice23(void);
void question231(void);
float** saisieVecteurs(int nombreDeVecteurs, int tailleVecteur);
void clean(char *chaine);
void purger(void);
void sauvegardeFichier(int nombreDeVecteurs, int tailleVecteur, float **listeDeVecteurs, char *nomDuFichier);
void question232(void);
void affichageFichier(char nomDuFichier[100]);
void question233(char nomDuFichier[100], int tailleVecteur);
float* creationVecteur(int tailleVecteur);

#endif // EXERCICE23_H_INCLUDED
