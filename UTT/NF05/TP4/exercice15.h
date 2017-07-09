#ifndef EXERCICE15_H_INCLUDED
#define EXERCICE15_H_INCLUDED

void exercice15(void);
void affichage(int nbDElements, float* tabAffiche);
float* saisieElements(int* nbDElements);
float calculMoyenne(int nbDElements, float* tableauMoyenne);
float calculVariance(int nbDElements, float* tableauVariance, float moyenne);
int positionMinimum(int nbDElements, float* tableauMinimum);

#endif // EXERCICE15_H_INCLUDED
