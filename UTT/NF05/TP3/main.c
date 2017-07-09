#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("cls");
    getcharEtPutchar();
    return main();
}

/*
Exo 9:
Il s'agit d'un programme de calcul des solutions d'une équation du second degré.
On demande à l'utilisateur de simplement saisir les coefficients du trinome.
*/
void equationSecondDegre()
{
    double a, b, c, discriminant, reelle, imaginaire; //
    printf("Saisisser un a un les coefficients a, b et c du trinome :\n");
    printf("a = ");
    scanf("%lf",&a);
    fflush(stdin); //On doit vider l'entrée du clavier entre chaque saisi sinon la fonction scanf ira toujours lire la précédente saisi
    printf("b = ");
    scanf("%lf",&b);
    fflush(stdin);
    printf("c = ");
    scanf("%lf",&c);
    fflush(stdin);
    discriminant=b*b-4*a*c; //Calul du discriminant dont le signe va nous indiquer les solutions
    if (discriminant>0)
    {
        printf("Les solutions sont :\n");
        printf("X1 = %lf\n",(-b+sqrt(discriminant))/(2*a));
        printf("X2 = %lf\n",(-b-sqrt(discriminant))/(2*a));
    }
    else if (discriminant==0)
    {
        printf("La solution est :\n");
        printf("X0 = %lf\n",(-b)/(2*a));
    }
    else
    {
        reelle=(-b)/(2*a);
        imaginaire=(sqrt(-discriminant))/(2*a);
        printf("Les solutions sont :\n");
        printf("X1 = %lf+i%lf\n",reelle,imaginaire);
        printf("X2 = %lf-i%lf\n",reelle,imaginaire);
    }
    system("PAUSE");
}

/*
Exo 10
*/
int premier(int n)
{
    if(n==2) return 1; //Si la variable d'entrée i vaut 2 alors on asit déjà que le nombre est premier donc on retourne 1 au programme principal
    else
    {
        int k=2, z=1;
        while (k<n) //on va tester pour tous les nombres entiers k inférieur à n (qui correspond à la variable d'entrée i) s'il est divisible afin de savoir si n est premier ou non
        {
            while ((premier(k)==0)&&(k<n-1)) //tant que k n'est pas premier et qu'il est inférieur à n-1 on l'augmente. le fait d'mployer à nouveau la fonction premier(k) va énormément soliciter l'emploi de la récursivité, au final, le programme s'en retrouvera considérablement ralenti voir quasiment incapable d'aller au delà de 50 entiers testés en moins d'une demi heure
            {
                k++;
            }
            if (n%k==0) //puis si le reste de la division euclidienne de n par le nombre premier k est 0 alors le nombre n n'est pas premier puisqu'il est divisible par un nombre premier qui lui est inférieur
            {
                z=0;
                k++;
            }
            else k++; //dans le cas contraire n n'est pas divisible par k donc on va recommencer pour le prochain nombre premier k si k est bien sûr toujours inférieur à n après son incrémentation
        }
        return z; //si à la fin z vaut 0 alors n n'est pas premier sinon si z=1 il l'est
    }
    system("PAUSE");
}

void testNombrePremier()
{
    int i;
    for (i=2; i<50; i++) printf("premier(%d)=%d\n",i,premier(i));
    /*
    premier(i) va être appellé à chaque tour de boucle pour renvoyer à l'affichage si le nombre i est premier ou non
    L'opération se fera sur les entiers inférieurs à 50.
    */
}

/*
Exo 11
*/
#define pi 3.14159265 //on défini la constante pi
void sommeSerie()
{
    int n=0;
    float sommeSerie=0;
    while((((pi*pi)/6.0)-sommeSerie)>=0.001)//le calcul de la somme de la série s'arrête lorsque celle-ci est proche de la somme infinie à 10 puissance -3 près
    {
        n++;
        sommeSerie=sommeSerie+(1.0/(float)(n*n)); //on calcul la somme de la série
    }
    printf("La condition d'arret est n = %d\n",n); //on affiche à quelle valeur de n la boucle à dû s'arrêter, c'est la condition d'arrêt
    system("PAUSE");
}

/*
Exo 12
*/
#include <math.h> //on a besoin de la librairie math.h pour la fonction exponentielle
void integralDuneFonction()
{
    double x=0, integral=0;
    for(x=0.1;x<=10;x=x+0.01)//on calcul l'intégral avec un pas de 0.01
    {
        integral=integral+0.01*(exp(-x))/(x*x*x); //on prend une longueur des rectangles de 0.01
    }
    printf("Resultat : %.2lf\n",integral); //on écri %.2lf => l'intégral aura donc un résultat à 10 puissance -2 près
    system("PAUSE");
}

/*
Exo 13
*/
void moyenneEtVariance()
{
    int N=0, i=0;
    double reel=0, sommeReels=0, sommeVariance=0, moyenne=0, variance=0;
    printf("Combien y a t-il de reel a saisir ?\n");
    scanf("%d",&N);
    for(i=1;i<=N;i++) //on demande la saisi des N valeurs
    {
        printf("Reel %d = ",i);
        scanf("%lf",&reel);
        sommeReels=sommeReels+reel; //la somme des réels nous permettra de cacluler la moyenne
        sommeVariance=sommeVariance+reel*reel; //la somme des réels au carré nous permettra de calculer la variance
    }
    moyenne=sommeReels/((double)N); //calcule de la moyenne qui est de type double donc on cast N en double
    printf("Moyenne : %lf\n",moyenne);
    variance=((double)1/(double)N)*sommeVariance-moyenne*moyenne; //calcul de la variance qui est de type double
    printf("Variance : %lf\n",variance);
    system("PAUSE");
}

/*
Exo 14
*/
#define taillemax 10 //la taillemax du tableau est déclaré sous forme d'une constante
void getsEtPuts()
{
    char chaine[taillemax]={0};
    fflush(stdin);
    printf("Saisir la chaine (taille maximale=%d):\n",taillemax);
    gets(chaine); //gets permet d'enregistrer la saisi d'une chaine de caractere dans la variable chaine, gets ne gère pas les débordements, sinon il faut utiliser une fonction fgets(chaine,taillemax,stdin)
    printf("Vous avez saisi:\n");
    puts(chaine); //puts affiche à l'écran une chaine de caractère
    system("PAUSE");
}

void getcharEtPutchar()
{
    printf("Saisir un seul caractere\n");
    fflush(stdin);
    char caractere=getchar(); //getchar va récupérer un caractère saisi au clavier et le mettre dans le caractère caractere. Getchar a l'avantage de gérer les débordements.
    printf("Vous avez saisi:\n");
    putchar(caractere); //putchar va afficher un seul et unique caractère à l'écran.
    system("PAUSE");
}
