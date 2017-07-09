#include "exercice20.h"

void exercice20(void)
{
    system("cls"); // On efface ce qui était auparavant écrit sur la fenêtre DOS
    int choixMenu=0;
    printf("---- Menu exercice 20 ----\n\n1: Forme cartesienne vers polaire\n2: Forme polaire vers cartesienne\n3: Somme et soustraction de deux nombres complexes\n4: Produit et division de deux nombres complexes\n5: Resolution de trinome a coefficients complexes\n");
    scanf("%d",&choixMenu);
    switch(choixMenu)
    {
    case 1:
        question1();
        break;
    case 2:
        question2();
        break;
    case 3:
        question3();
        break;
    case 4:
        question4();
        break;
    case 5:
        question5();
        break;
    default:
        printf("Veuillez recommencer.");
        break;
    }
    system("PAUSE");
    return exercice20();
}

// Cette procédure permet de convertir des coordonnées cartesiennes en polaires
void question1(void)
{
    Cplx Z = {{0,0},{0,0}}; // Z sera de type Cplx (structure permettant de stocker les coordonées cartesiennes et polaire d'un nombre complexe
    printf("\nSaisir la partie reelle et imaginaire du nombre complexe Z :\n");
    printf("Re(Z) = ");
    scanf("%lf",&Z.formeCartesienne.reelle);
    printf("Im(Z) = ");
    scanf("%lf",&Z.formeCartesienne.imaginaire);
    cartesienneVersPolaire(&Z); // On appel la procédure de conversion des coords cartésiennes en polaire et on lui envoi l'adresse de Z
    printf("\n|Z| = %f\narg(Z) = %f\n",Z.formePolaire.module,Z.formePolaire.argument);
}

// Il s'agit de la procédure de conversion des coords carté vers polaire. Z-> est équivalent à (*Z). , l'avantage c'est que c'est plus court !
void cartesienneVersPolaire(Cplx *Z)
{
    Z->formePolaire.module=sqrt(Z->formeCartesienne.reelle*Z->formeCartesienne.reelle+Z->formeCartesienne.imaginaire*Z->formeCartesienne.imaginaire); // On calcul le module
    if(Z->formeCartesienne.reelle<0&&Z->formeCartesienne.imaginaire==0) // Si Z est un réel strictement inférieur à zéro alors on dit que son argument est PI
    {
        Z->formePolaire.argument=PI;
    }
    else if(Z->formeCartesienne.reelle==0&&Z->formeCartesienne.imaginaire==0) // Si Z est l'origine alors son argument est nul (ainsi que son module)
    {
        Z->formePolaire.argument=0;
    }
    else // Sinon on emploi la formule mathématiques générale qui dit que arg(Z)=2*arctan(Im(Z)/(Re(Z)+|Z|)) avec arg(Z) compris entre ]-PI;PI[
    {
        Z->formePolaire.argument=(double)2*atan(Z->formeCartesienne.imaginaire/(Z->formeCartesienne.reelle+Z->formePolaire.module));
    }

}

// Procédure permettant d'aller des coords polaire vers carté
void question2(void)
{
    Cplx Z = {{0,0},{0,0}};
    printf("\nSaisir le module et l'argument du nombre complexe Z :\n");
    printf("|Z| = ");
    scanf("%lf",&Z.formePolaire.module);
    printf("arg(Z) = ");
    scanf("%lf",&Z.formePolaire.argument);
    polaireVersCartesienne(&Z);
    printf("\nRe(Z) = %f\nIm(Z) = %f\n",Z.formeCartesienne.reelle,Z.formeCartesienne.imaginaire);
}

// Cette procédure calcul les coord carté en fonction des polaires
void polaireVersCartesienne(Cplx *Z)
{
    Z->formeCartesienne.reelle=Z->formePolaire.module*cos(Z->formePolaire.argument); // x = r*cos(teta)
    Z->formeCartesienne.imaginaire=Z->formePolaire.module*sin(Z->formePolaire.argument); // y = r*sin(teta)
}

// Afin de rendre mon programme plus polvalent, on donnela possibilité à l'utilisateur de rentrer ses nombres complexes sous forme carté ou polaire. On se chargera de les convertir ensuite grâce aux procédure créée juste avant !
void saisieCplx(Cplx *Z1, Cplx *Z2)
{
    int choixForme=0;
    printf("\nQu'elle est la forme des 2 complexes Z1 et Z2 ? (1=cartesienne/2=polaire)");
    scanf("%d",&choixForme);
    if(choixForme==1) // L'utilisateur saisie ses coordonnées cartésiennes
    {
        printf("Re(Z1) = ");
        scanf("%lf",&(Z1->formeCartesienne.reelle));
        printf("Im(Z1) = ");
        scanf("%lf",&(Z1->formeCartesienne.imaginaire));
        printf("Re(Z2) = ");
        scanf("%lf",&(Z2->formeCartesienne.reelle));
        printf("Im(Z2) = ");
        scanf("%lf",&(Z2->formeCartesienne.imaginaire));
        cartesienneVersPolaire(Z1);
        cartesienneVersPolaire(Z2);
        /* On utilise la procédure de conversion des coords carté en polaire afin que nos complexes Z1 et Z2 soient facilement utilisable
        que ce soit pour effectuer une somme ou soustraction avec les coords carté
        ou alors pour la multiplication et division en coords polaire */
    }
    else if(choixForme==2)
    {
        printf("|Z1| = ");
        scanf("%lf",&(Z1->formePolaire.module));
        printf("arg(Z1) = ");
        scanf("%lf",&(Z1->formePolaire.argument));
        printf("|Z2| = ");
        scanf("%lf",&(Z2->formePolaire.module));
        printf("arg(Z2) = ");
        scanf("%lf",&(Z2->formePolaire.argument));
        polaireVersCartesienne(Z1); // Ici on fait l'inverse avec la conversion de polaire vers carté
        polaireVersCartesienne(Z2);
    }
    else
    {
        printf("Veuillez recommencer.\n");
        return exercice20();
    }
}

// Ici c'est la procédure qui permet d'effectuer une somme et soustraction de 2 complexes
void question3(void)
{
    Cplx Z1 = {{0,0},{0,0}}, Z2 = {{0,0},{0,0}};
    saisieCplx(&Z1, &Z2);
    Cplx somme = sommeCplx(Z1, Z2);
    printf("\nZ1+Z2 = %f + %fi = %f exp(%fi)\n",somme.formeCartesienne.reelle,somme.formeCartesienne.imaginaire,somme.formePolaire.module,somme.formePolaire.argument);
    Cplx soustraction = sousCplx(Z1,Z2);
    printf("Z1-Z2 = %f + %fi = %f exp(%fi)\n",soustraction.formeCartesienne.reelle,soustraction.formeCartesienne.imaginaire,soustraction.formePolaire.module,soustraction.formePolaire.argument);
}

/* Ici la fonction qui retourne la somme de deux complexes.
La somme est faite au niveau des coordonnées cartésiennes,
On recalculera à nouveau les coordonnées polaire en appelant la procédure de conversion créée auparavant. */
Cplx sommeCplx(Cplx Z1, Cplx Z2)
{
    Cplx somme = {{Z1.formeCartesienne.reelle+Z2.formeCartesienne.reelle,Z1.formeCartesienne.imaginaire+Z2.formeCartesienne.imaginaire},{0,0}};
    cartesienneVersPolaire(&somme);
    return somme;
}

// Même principe pour la fonction de soustraction.
Cplx sousCplx(Cplx Z1, Cplx Z2)
{
    Cplx soustraction = {{Z1.formeCartesienne.reelle-Z2.formeCartesienne.reelle,Z1.formeCartesienne.imaginaire-Z2.formeCartesienne.imaginaire},{0,0}};
    cartesienneVersPolaire(&soustraction);
    return soustraction;
}

// La procédure ci-après permet d'effectuer la multiplication et division d'un nombre complexe
void question4(void)
{
    Cplx Z1 = {{0,0},{0,0}}, Z2 = {{0,0},{0,0}};
    saisieCplx(&Z1, &Z2);
    Cplx produit = mulCplx(Z1,Z2);
    printf("\nZ1*Z2 = %f + %fi = %f exp(%fi)\n",produit.formeCartesienne.reelle,produit.formeCartesienne.imaginaire,produit.formePolaire.module,produit.formePolaire.argument);
    Cplx division = divCplx(Z1,Z2);
    printf("Z1/Z2 = %f + %fi = %f exp(%fi)\n",division.formeCartesienne.reelle,division.formeCartesienne.imaginaire,division.formePolaire.module,division.formePolaire.argument);
}

// La fonction suivante effectue le produit de deux nombres complexes au niveau des coordonnées polaire. On effectuera la conversion en cartésiennes ensuite.
Cplx mulCplx(Cplx Z1, Cplx Z2)
{
    Cplx produit = {{0,0},{Z1.formePolaire.module*Z2.formePolaire.module,Z1.formePolaire.argument+Z2.formePolaire.argument}};
    polaireVersCartesienne(&produit);
    return produit;
}

// Même principe pour la division
Cplx divCplx(Cplx Z1, Cplx Z2)
{
    Cplx division = {{0,0},{Z1.formePolaire.module/Z2.formePolaire.module,Z1.formePolaire.argument-Z2.formePolaire.argument}};
    polaireVersCartesienne(&division);
    return division;
}

/* Dans cette procédure de calcul des racines d'un trinôme à coefficients complexes,
On réutilisera le principe de saisie des question 3 et 4 mais avec une variable supplémentaire. */
void question5(void)
{
    printf("Soit P(X)=Z1*X^2+Z2*X+Z3\n");
    Cplx Z1 = {{0,0},{0,0}}, Z2 = {{0,0},{0,0}}, Z3 = {{0,0},{0,0}};
    int choixForme=0;
    printf("Qu'elle est la forme des 3 complexes Z1, Z2 et Z3 ? (1=cartesienne/2=polaire)");
    scanf("%d",&choixForme);
    if(choixForme==1)
    {
        printf("Re(Z1) = ");
        scanf("%lf",&(Z1.formeCartesienne.reelle));
        printf("Im(Z1) = ");
        scanf("%lf",&(Z1.formeCartesienne.imaginaire));
        printf("Re(Z2) = ");
        scanf("%lf",&(Z2.formeCartesienne.reelle));
        printf("Im(Z2) = ");
        scanf("%lf",&(Z2.formeCartesienne.imaginaire));
        printf("Re(Z3) = ");
        scanf("%lf",&(Z3.formeCartesienne.reelle));
        printf("Im(Z3) = ");
        scanf("%lf",&(Z3.formeCartesienne.imaginaire));
        cartesienneVersPolaire(&Z1);
        cartesienneVersPolaire(&Z2);
        cartesienneVersPolaire(&Z3);
    }
    else if(choixForme==2)
    {
        printf("|Z1| = ");
        scanf("%lf",&(Z1.formePolaire.module));
        printf("arg(Z1) = ");
        scanf("%lf",&(Z1.formePolaire.argument));
        printf("|Z2| = ");
        scanf("%lf",&(Z2.formePolaire.module));
        printf("arg(Z2) = ");
        scanf("%lf",&(Z2.formePolaire.argument));
        printf("|Z3| = ");
        scanf("%lf",&(Z3.formePolaire.module));
        printf("arg(Z3) = ");
        scanf("%lf",&(Z3.formePolaire.argument));
        polaireVersCartesienne(&Z1);
        polaireVersCartesienne(&Z2);
        polaireVersCartesienne(&Z3);
    }
    else
    {
        printf("Veuillez recommencer.\n");
        return exercice20();
    }
    // Le calcul de delta=Z2²-4*Z1*Z3 se fait en plusieurs parties
    Cplx carreZ2 = mulCplx(Z2,Z2); // On détermine tout d'abord le carré de Z2
    Cplx Z1xZ3 = mulCplx(Z1,Z3); // On effectue la multiplication de Z1 par Z3
    // Ensuite on multiplie par 4 le produit de Z1 et Z3
    Z1xZ3.formeCartesienne.reelle = (double)4*Z1xZ3.formeCartesienne.reelle;
    Z1xZ3.formeCartesienne.imaginaire = (double)4*Z1xZ3.formeCartesienne.imaginaire;
    cartesienneVersPolaire(&Z1xZ3); // Puis on recalcul les coordonnées polaires
    Cplx delta = sousCplx(carreZ2,Z1xZ3); // Enfin on effectue la soustraction du carré de Z2 et de 4*Z1*Z3
    // Quelques soient delta, on aura besoin de -Z2 et de 2*Z1 donc on calcul cela juste avant de tester delta
    Z2.formeCartesienne.reelle = (double)-1*Z2.formeCartesienne.reelle;
    Z2.formeCartesienne.imaginaire = (double)-1*Z2.formeCartesienne.imaginaire;
    cartesienneVersPolaire(&Z2);
    Z1.formeCartesienne.reelle = (double)2*Z1.formeCartesienne.reelle;
    Z1.formeCartesienne.imaginaire = (double)2*Z1.formeCartesienne.imaginaire;
    cartesienneVersPolaire(&Z1);
    // si delta==0 alors une seule racine sinon 2
    if(delta.formeCartesienne.reelle==0&&delta.formeCartesienne.imaginaire==0)
    {
        Cplx Z0 = divCplx(Z2,Z1); // Si delta==0 alors la racine est -Z2/2*Z1
        printf("\nIl existe une solution:\nZ0 = %f + %fi = %f * exp(%fi)\n",Z0.formeCartesienne.reelle,Z0.formeCartesienne.imaginaire,Z0.formePolaire.module,Z0.formePolaire.argument);
    }
    else // Sinon les racines sont -Z2+sqrt(delta)/2*Z1 et -Z2-sqrt(delta)/2*Z1
    {
        Cplx racineDelta = {{sqrt((delta.formeCartesienne.reelle+delta.formePolaire.module)/(double)2),(double)-1*sqrt((delta.formePolaire.module-delta.formeCartesienne.reelle)/(double)2)},{0,0}};
        cartesienneVersPolaire(&racineDelta);
        Cplx solution1 = sommeCplx(Z2,racineDelta);
        solution1 = divCplx(solution1,Z1);
        Cplx solution2 = sousCplx(Z2,racineDelta);
        solution2 = divCplx(solution2,Z1);
        printf("\nIl existe deux solutions:\nSolution 1 = %f + %fi = %f * exp(%fi)\nSolution 2 = %f + %fi = %f * exp(%fi)\n",solution1.formeCartesienne.reelle,solution1.formeCartesienne.imaginaire,solution1.formePolaire.module,solution1.formePolaire.argument,solution2.formeCartesienne.reelle,solution2.formeCartesienne.imaginaire,solution2.formePolaire.module,solution2.formePolaire.argument);
    }
}
