#ifndef EXERCICE25_H_INCLUDED
#define EXERCICE25_H_INCLUDED

typedef struct Cellule Cellule;
struct Cellule // Structure d'une cellule
{
    Cellule *precedent;
    int info;
    Cellule *suivant;
};

int exercice25(void);
Cellule *initialisationListe(int info);
Cellule *add_first(int info, Cellule *liste);
void affichage(Cellule liste);
int main(int argc, char *argv[]);
void liberationMemoire(Cellule *liste);

#endif // EXERCICE25_H_INCLUDED
