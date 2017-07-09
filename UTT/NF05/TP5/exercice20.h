#ifndef EXERCICE20_H_INCLUDED
#define EXERCICE20_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Utilisé pour fabs() et sqrt()
#define PI 3.14159265

typedef struct CplxCartesien CplxCartesien;
struct CplxCartesien
{
    double reelle, imaginaire;
};

typedef struct CplxPolaire CplxPolaire;
struct CplxPolaire
{
    double module, argument;
};

typedef struct Cplx Cplx;
struct Cplx
{
    CplxCartesien formeCartesienne;
    CplxPolaire formePolaire;
};

void exercice20(void);
void question1(void);
void cartesienneVersPolaire(Cplx  *Z);
void question2(void);
void polaireVersCartesienne(Cplx *Z);
void saisieCplx(Cplx *Z1, Cplx *Z2);
void question3(void);
Cplx sommeCplx(Cplx Z1, Cplx Z2);
Cplx sousCplx(Cplx Z1, Cplx Z2);
void question4(void);
Cplx mulCplx(Cplx Z1, Cplx Z2);
Cplx divCplx(Cplx Z1, Cplx Z2);
void question5(void);

#endif // EXERCICE20_H_INCLUDED
