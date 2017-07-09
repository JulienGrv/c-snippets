#include "exercice19.h"

struct Coordonnees // structure de coordonn�es cartesiennes
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
    if(precision!=0) // Si la variable pr�cision est non-nul, cela signifie que l'on a atteint une pr�cision inf�rieur ou �gal � 10^-3 avant la derni�re approximation de PI, dans ce cas on l'affiche
    {
        printf("Precision a 10^-3 pres atteinte pour n = %d\n",precision);
    }
    else // dans le cas o� aucune des approximation de PI n'a atteint une pr�cision inf�rieur ou �gal � 10^-3, on le dit �galement
    {
        printf("Pas de precision a 10^-3 pres pour n = %d\n",n);
    }
}

bool testEssai(double x, double y)
{
    return x*x+y*y<=1; // la fl�chette est dans le quart de cercle, d'apr�s pythagore, si x^2+y^2<=1
}

// La fonction ci-apr�s permet de calculer une approximation de PI en utilisant la m�thode de Monte Carlo
double calculApproximationPi(int *n, int *precision)
{
    struct Coordonnees pointM; // On initialise la variable pointM de type structure de coordonn�es
    srand(time(NULL)); // On initialise la fonction random avec la fonction time(). Utile si l'on ne veut pas tomber tout le temps sur la m�me s�rie de chiffre retourn� par rand() !
    int i=0, p=0;
    for(i=0; i<*n; i++) // On va effectuer n lanc�s
    {
        pointM.x=rand()/(double)RAND_MAX; // � chaque lanc�, la fl�chette tombe sur une position que l'on d�finie al�atoirement et qui doit se trouver entre 0 et 1 pour x et y (d'o� la division par RAND_MAX)
        pointM.y=rand()/(double)RAND_MAX;
        if(testEssai(pointM.x,pointM.y)) // On v�rifie si la fl�chette est tomb�e ou non dans le quart de cercle, si oui on incr�mente p
        {
            p++;
        }
        if((fabs((double)PI-(double)p/(double)i*(double)4)<=0.001)&&(*precision==0)) // � chaque lanc� on regarde si l'approximation de pi a une pr�cision de 10^-3 par rapport � la valeur connu de PI
        {
            *precision=i; // d�s que l'on tombe sur une precision inf�rieur ou �gal � 10^-3 on l'enregistre.
        }
    }
    return (double)p/(double)(*n)*(double)4; // Une fois tous les essais effectu�s on retourne la derni�re approximation de PI
}
