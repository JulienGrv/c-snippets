#include "exercice19.h"

struct Coordonnees // structure de coordonnées cartesiennes
{
    double x, y;
};

void exercice19(void)
{
    int n=0, precision=0;
    printf("Combien de lances doivent etre effectues ?");
    scanf("%d",&n);
    double approximationPi=calculApproximationPi(&n, &precision); // On appel la fonction de calcul d'approximation de PI et on lui envoi l'adresse de n et precision
    printf("Approximation de pi pour n = %d :\n%f\n",n,approximationPi); // On affiche l'approximation de PI
    if(precision!=0) // Si la variable précision est non-nul, cela signifie que l'on a atteint une précision inférieur ou égal à 10^-3 avant la dernière approximation de PI, dans ce cas on l'affiche
    {
        printf("Precision a 10^-3 pres atteinte pour n = %d\n",precision);
    }
    else // dans le cas où aucune des approximation de PI n'a atteint une précision inférieur ou égal à 10^-3, on le dit également
    {
        printf("Pas de precision a 10^-3 pres pour n = %d\n",n);
    }
}

bool testEssai(double x, double y)
{
    return x*x+y*y<=1; // la fléchette est dans le quart de cercle, d'après pythagore, si x^2+y^2<=1
}

// La fonction ci-après permet de calculer une approximation de PI en utilisant la méthode de Monte Carlo
double calculApproximationPi(int *n, int *precision)
{
    struct Coordonnees pointM; // On initialise la variable pointM de type structure de coordonnées
    srand(time(NULL)); // On initialise la fonction random avec la fonction time(). Utile si l'on ne veut pas tomber tout le temps sur la même série de chiffre retourné par rand() !
    int i=0, p=0;
    for(i=0; i<*n; i++) // On va effectuer n lancés
    {
        pointM.x=rand()/(double)RAND_MAX; // à chaque lancé, la fléchette tombe sur une position que l'on définie aléatoirement et qui doit se trouver entre 0 et 1 pour x et y (d'où la division par RAND_MAX)
        pointM.y=rand()/(double)RAND_MAX;
        if(testEssai(pointM.x,pointM.y)) // On vérifie si la fléchette est tombée ou non dans le quart de cercle, si oui on incrémente p
        {
            p++;
        }
        if((fabs((double)PI-(double)p/(double)i*(double)4)<=0.001)&&(*precision==0)) // à chaque lancé on regarde si l'approximation de pi a une précision de 10^-3 par rapport à la valeur connu de PI
        {
            *precision=i; // dès que l'on tombe sur une precision inférieur ou égal à 10^-3 on l'enregistre.
        }
    }
    return (double)p/(double)(*n)*(double)4; // Une fois tous les essais effectués on retourne la dernière approximation de PI
}
