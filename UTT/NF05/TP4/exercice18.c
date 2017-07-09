#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* On inclus la librairie stdbool.h qui permet de d�finir des types bool.
C'est une nouvelle �volution du langage C (le C99) qui est normalis�e par l'ISO en 1999.*/
#include <time.h> // Cette librairie propose une fonction permettant de conna�tre la date de l'ordinateur.
#include "exercice18.h"

void exercice18(void)
{
    system("cls");
    int  choixMenu=0;
    printf("---- Menu exercice 18 ----\n1: Determiner si une annee est bissextile.\n2: Calculer le nombre de jours ecoule jusqu'a aujourd'hui.\n");
    scanf("%d",&choixMenu);
    system("cls");
    switch(choixMenu)
    {
    case 1:
        question1();
        break;
    case 2:
        question2();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }

}

void question1(void)
{
    int annee=0;
    printf("Saisir une annee :\n");
    scanf("%d",&annee);
    bool bissextile=anneeBissextile(annee);
    /* Gr�ce � la biblioth�que stdbool.h on peut directement utiliser des variables bool�enne.
    Ceci est une �volution du langage C normalis� par l'ISO en 1999.
    On aurait autrement pu utiliser une variable de type int avec seulement deux valeurs possibles (1 et 0)
    et l'on aurait tester cette valeur mais cette m�thode est moins pratique.
    */
    if(bissextile)
    {
        printf("%d est une annee bissextile.\n",annee);
    }
    else
    {
        printf("%d n'est pas une annee bissextile.\n",annee);
    }
    system("PAUSE");
    return exercice18();
}

// Cette fonction permet de connaitre si une ann�e est bissextile.
bool anneeBissextile(int annee)
{
    bool bissextile=0;
    if((annee%4==0&&annee%100!=0)||(annee%400==0)) // Une ann�e est bissextile si elle est divisible par 4 et pas par 100 OU si elle est simplement divisible par 400. (Source: Wikip�dia)
    {
        bissextile=1;
    }
    return bissextile;
}

void question2(void)
{
    int anneeDeReference=0;
    printf("Qu'elle est l'annee de reference ?\n");
    scanf("%d",&anneeDeReference);
    int nombreDeJours=calculJours(anneeDeReference); // On appelle la fonction calculsJours qui nous retourne le nombres de jours �coul�s depuis l'ann�e de r�f�rence jusqu'� aujourd'hui.
    printf("%d jours se sont ecoules depuis le 1er janvier %d.\n",nombreDeJours,anneeDeReference);
    system("PAUSE");
    return exercice18();
}


// Cette fonction permet de conna�tre le nombre de jours �coul�es depuis l'ann�e de r�f�rence � aujourd'hui
int calculJours(int anneeDeReference)
{
    time_t secondes; // secondes est de type time_t. Ce type permet de stocker un nombre de secondes
    struct tm instant; // instant sera une structure tm, cette structure fait partie int�grante de la biblioth�qe time.h;
    time(&secondes); // time() retourne le nombre de secondes �coul�es depuis 1900 jusqu'� aujourd'hui et le stocke dans secondes. (�quivalent �: secondes = time(NULL))
    instant=*localtime(&secondes); // Afin de transformer le nombre de secondes stocker � la variable secondes, on emploi la fonction localtime() qui retourne l'adresse d'une structure tm que l'on va enregistr� dans la structure instant.
    /* Tout ce qui pr�c�de nous permet de ne pas avoir � demander � l'utilisateur de pr�ciser la date du jour */

    int i=0, nombreDeJours=instant.tm_yday;

    for(i=anneeDeReference; i<instant.tm_year+1900; i++)
    {
        if(anneeBissextile(i))
        {
            nombreDeJours+=366;
        }
        else
        {
            nombreDeJours+=365;
        }
    }
    return nombreDeJours;
}
