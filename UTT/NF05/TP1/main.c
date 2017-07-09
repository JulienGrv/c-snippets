#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system ("cls"); //Efface tout ce qui est affich� � l'�cran
    int choixMenu;  //D�claration de la variable de choix de l'utilisateur pour le menu
    printf("---Menu---\n\n"); //Affichage du menu
    printf("1. Liste des tailles des types en octets\n");
    printf("2. Exemple du pointeur\n");
    printf("3. Calculs basiques\n");
    printf("4. Permutation de 2 variables\n");
    printf("5. Permutation de 2 caracteres\n");
    printf("6. Somme et difference de 2 caracteres\n");
    printf("7. Calcul du maximum et minimum\n");
    printf("8. Calcul de l'aire d'un triangle\n");
    printf("9. Calcul du volume d'un cone\n\n");
    printf("Votre choix ?\n");
    scanf("%d", &choixMenu);

    switch (choixMenu) //Condition � choix multiples pour envoyer l'utilisateur vers le programme d�sir�
    {
    case 1:
        system ("cls"); //efface tout ce qui est affich� � l'�cran
        tailleTypes(); //lance la fonction tailleTypes
        break;
    case 2:
        system ("cls");
        pointeur();
        break;
    case 3:
        system ("cls");
        calculsBasiques();
        break;
    case 4:
        system ("cls");
        permuterDeuxVariables();
        break;
    case 5:
        system ("cls");
        permuterDeuxCaracteres();
        break;
    case 6:
        system ("cls");
        sommeEtDifferenceCaracteres();
        break;
    case 7:
        system ("cls");
        maxMin();
        break;
    case 8:
        system ("cls");
        aireTriangle();
        break;
    case 9:
        system ("cls");
        volumeCone();
        break;
    default:
        printf("\nChoisissez un chiffre entre 1 et 9 !\n");
        system("PAUSE");
        break;
    }
    return main();
}

/*Exercice 1 :
On affiche une liste de la taille en octets de diff�rents types � l'aide de la fonction printf.
L'autre fonctionn consiste � afficher des informations sur un exemple de pointeur.*/

int tailleTypes(void)
{
    printf("Liste de la taille en octets des types int, short, char, float et double :\n\n");
    printf("Taille int = %d octets\n", sizeof(int));
    printf("Taille short = %d octets\n", sizeof(short));
    printf("Taille char = %d octets\n", sizeof(char));
    printf("Taille float = %d octets\n", sizeof(float));
    printf("Taille double = %d octets\n\n", sizeof(double));
    system("PAUSE"); //La console marque une pause. Lorsque l'utilisateur appui � nouveau sur une touche, la fonction continue.
    return main(); //retour au menu
}

int pointeur(void)
{
    float *ptr; //D�claration du pointeur ptr qui sera �videmment de m�me type que la variable point�e
    float a; //D�claration de la variable a
    a=3.4; //La variable a vaut maintenant 3.4
    ptr=&a; //Le pointeur ptr pointe vers la variable a
    printf("la valeur contenue dans l'adresse est %1.2f \n",*ptr); //On affiche � l'�cran la valeur contenue � l'adresse de a � l'aide du pointeur ptr
    printf("l'adresse est %d \n",ptr); //On affiche la valeur du pointeur ptr (i.e. l'adresse de a)
    printf("l'adresse de a est %d \n",&a); //On affiche l'adresse de a
    *ptr=a+1; //on incr�mente 1 � la valeur contenue � l'adresse de a
    printf("la valeur contenue dans l'adresse est %1.2f \n",*ptr); //On affiche la nouvelle valeur contenue � l'adresse de a
    printf("l'adresse est %d \n",ptr); //l'adresse de a n'a pas chang� et on l'affiche de nouveau � l'aide d ptr
    printf("l'adresse de a est %d \n",&a); //l'adresse de a est affich�e
    printf("la valeur de a est %1.2f \n",a); //On affiche la nouvelle valeur de a qui a �t� incr�ment� de 1
    system("PAUSE");
    return main();
}

//Exercice 2.1 : programme assez simple effectuant des calculs �l�mentaires entre deux variables demand�es � l'utilisateur

int calculsBasiques(void)
{
    int nombre1=0, nombre2=0; //d�claration des 2 variables servant aux op�rations
    printf("Entrer successivement 2 entiers non-nuls :\n");
    while((nombre1==0)||(nombre2==0)) //�tant donn� que ces entiers doivent �tre non-nuls, on utilise une boucle pour v�rifier que l'utilisateur n'entre pas la valeur 0
    {
        printf("Nombre 1 : ");
        scanf("%d",&nombre1);
        printf("Nombre 2: ");
        scanf("%d",&nombre2);
    }
    printf("\nLa somme : Nombre1 + Nombre2 = %d\n",nombre1+nombre2);
    printf("La difference : Nombre1 - Nombre2 = %d\n",nombre1-nombre2);
    printf("Le produit : Nombre1 * Nombre2 = %d\n",nombre1*nombre2);
    printf("Le quotient : Nombre1 / Nombre2 = %d\n",nombre1/nombre2);
    printf("Le reste de la division euclidienne : Nombre1 %% Nombre2 = %d\n",nombre1%nombre2);
    system("PAUSE");
    return main();
}

//Exercice 2.2 : Deux programmes permettant la permutation entre deux variables ou deux caract�res.

int permuterDeuxVariables(void)
{
    float var1, var2, temp; //D�claration des deux variables devant �tre permut� plus une variable temporaire servant � enregistrer premi�re variable modifi�e
    printf("Saisir deux variables reelles :\n");
    printf("Variable 1 : \n");
    scanf("%f",&var1);
    printf("Variable 2: \n");
    scanf("%f",&var2);
    temp=var1; //sauvegarde de la valeur de var1
    var1=var2; //var1 vaut maintenant var2
    var2=temp; //var2 vaut maintenant var1 gr�ce � la sauvegarde temporaire
    printf("Apres permutation :\nVariable 1 = %f\nVariable 2 = %f\n",var1,var2);
    system("PAUSE");
    return main();
}

int permuterDeuxCaracteres(void) //m�me principe pour la permutation des caract�res
{
    char char1, char2, temp;
    printf("Saisir deux caracteres :\n");
    printf("Caractere 1 : ");
    scanf("%c",&char1);
    fflush(stdin); //on vide la m�moire tampon avant de resaisir un autre caract�re, c'est comme �a.
    printf("Caractere 2 : ");
    scanf("%c",&char2);
    temp=char1;
    char1=char2;
    char2=temp;
    printf("Apres permutation :\nCaractere 1 = %c\nCaractere 2 = %c\n",char1,char2);
    system("PAUSE");
    return main();
}

//Exercice 2.3 : On fait la somme entre 2 caract�res ainsi que leur diff�rence

int sommeEtDifferenceCaracteres(void)
{
    char char1, char2;
    printf("Saisir deux caracteres :\n");
    printf("Caractere 1 : ");
    scanf("%c",&char1);
    fflush(stdin);
    printf("Caractere 2 : ");
    scanf("%c",&char2);
    printf("Le caractere : %c est obtenu par la somme des codes ascii : %d + %d = %d\n",char1+char2,char1,char2,char1+char2);
    printf("Le caractere : %c est obtenu par la difference des codes ascii : %d - %d = %d\n",char1-char2,char1,char2,char1-char2);
    system("PAUSE");
    return main();
}

//Exercice 2.4 : on d�termine le minimum et le maximum entre 2 variables

int maxMin(void)
{
    float val1, val2, min, max; //d�claration des variables val1 et val2 saisis par l'utilisateur et des variables min et max contenant le r�sultat
    printf("Saisir deux valeurs :\n");
    printf("Valeur 1 = ");
    scanf("%f",&val1);
    printf("Valeur 2 = ");
    scanf("%f",&val2);
    if(val1>val2) //on test si val1 est bien le maximum, si la condition est vraie alors max prend la valeur val1 et min la valeur val2
    {
        max=val1;
        min=val2;
    }
    else if(val2>val1) //sinon si c'est val2 qui est plus grand alors on fait l'inverse
    {
        max=val2;
        min=val1;
    }
    else //Si les deux variables ont la m�me valeurs alors il n'existe pas de maximum ni de minimum donc on le pr�cise
    {
        printf("Vous avez saisi deux valeurs identiques.\n");
        return maxMin(); //on relance le programme maximum et minimum
    }
    printf("Le maximum est %f et le minimun est %f.\n",max,min);
    system("PAUSE");
    return main();
}

//Exercice 3 : programme permettant de calculer l'aire d'un triangle � partir de la base et de la hauteur

int aireTriangle(void)
{
    int B, H; //d�claration des variables de la base et de la hauteur qui seront de type entier
    float A; //d�clariation de la variable contenant le r�sultat du calcul de l'aire de type r�el
    printf("Saisir la longueur B de la base du triangle :\n");
    scanf("%d",&B);
    printf("Saisir la longueur H de la hauteur du triangle :\n");
    scanf("%d",&H);
    A=(B*H)/2; //La division �tant effectu� sur des variables de type entier, le r�sultat sera forc�ment un entier (exemple avec B=7 et H=9, on obtient 31 au lieu de 31.5).
    printf("L'aire du triangle est A = (B*H)/2 = %f\n",A);
    system("PAUSE");
    return main();
}

//Exercice 4 : programme permettant de calculer le volume d'un c�ne � partir du rayon de la base et de sa hauteur

#define PI 3.1416 //d�claration de la variable constante PI qui pourra servir dans n'importe quel programme et ne sera pas modifiable

int volumeCone(void)
{
    int R, H; //d�claration des variables du rayon et de la hauteur qui seront de type entier
    float B, V; //d�claration des variables de l'air de la base et du volume de type r�el
    printf("Valeur de la constante PI : %f\n",PI);
    printf("Saisir la longueur R du rayon de la base :\n");
    scanf("%d",&R);
    printf("Saisir la longueur H de la hauteur du cone :\n");
    scanf("%d",&H);
    B=PI*R*R; //en effectuant le calcul entre un type entier et r�el, l'ordinateur comprend que le r�sultat doit �tre un r�el et ne commet donc pas d'erreur
    V=B*H/3; //pareil pour ce calcul, �tant donn� que B est de type r�el, l'ordi sait que le r�sultat doit �tre de type r�el et il ne tronquera donc pas le r�sultat comme pour le programme d'aire
    printf("Le volume du cone est V = %.2f\n",V);
    system("PAUSE");
    return main();
}
