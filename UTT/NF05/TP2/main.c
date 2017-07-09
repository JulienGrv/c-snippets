#include <stdio.h>
#include <stdlib.h>
#include <math.h> //me permet d'utiliser la fonction powf

void binaireVersDecimal(void)
{
    unsigned int nombreBinaire=0, n=0, nombreDecimal=0; //nombreBinaire, n et nombreDecimal sont des entiers non-signés. n indique la position du bit où l'on se situe.
    printf("Saisir le nombre binaire :\n");
    scanf("%u",&nombreBinaire); //%u est employé dans le cadre d'une variable de type unsigned int
    while(nombreBinaire!=0)
    {
        nombreDecimal=nombreDecimal+(nombreBinaire%10)*(unsigned int)powf((float)2,(float)n);
        /*
        Afin d'éviter des erreurs de calculs, j'ai casté certaines variables.
        En effet, powf est une fonction qui fonctionne avec des variables de type float en entrée et qui retourne une valeur de type float en sortie.
        C'est pourquoi en entrée j'ai casté 2 et n en type float puis en sortie j'ai casté la valeur en unsigned int.
        cela permet d'éviter bien des erreurs.
        */
        nombreBinaire/=10; //i.e. nombreBinaire=nombreBinaire/10, l'avantage de ma méthode c'est qu'elle est légèrement plus rapide à écrire pour moi et aussi à exécuter par l'ordinateur.
        n++;
    }
    printf("Resultat de la conversion en decimal :\n%u\n",nombreDecimal);
}

/*
Les programme de conversion decimal vers binaire ou octal ont un principe de fonctionnant tout à fait équivalent,
je ne m'amuserai donc pas à les détailler davatange.
*/

void decimalVersBinaire(void)
{
    unsigned int nombreDecimal=0, n=0, nombreBinaire=0;
    printf("Saisir le nombre decimal :\n");
    scanf("%u",&nombreDecimal);
    while(nombreDecimal!=0)
    {
        nombreBinaire=nombreBinaire+(nombreDecimal%2)*(unsigned int)pow((double)10,(double)n);
        nombreDecimal/=2;
        n++;
    }
    printf("Resultat de la conversion en binaire :\n%u\n",nombreBinaire);
}

void decimalVersOctal(void)
{
    unsigned int nombreDecimal=0, n=0, nombreOctal=0;
    printf("Saisir le nombre decimal :\n");
    scanf("%u",&nombreDecimal);
    while(nombreDecimal!=0)
    {
        nombreOctal=nombreOctal+(nombreDecimal%8)*(unsigned int)powf((float)10,(float)n);
        nombreDecimal/=8;
        n++;
    }
    printf("Resultat de la conversion en octal :\n%u\n",nombreOctal);
}

void decimalVersHexadecimal(void)
{
    unsigned int nombreDecimal=0, n=0, i=0;
    char nombreHexa[100]= {0}, temp[100]= {0}; //Je créé 2 tableaux de caractères. temp est le tableau qui contient le résultat de la conversion mais dans le "sens inverse" de lecture.
    printf("Saisir le nombre decimal :\n");
    scanf("%u",&nombreDecimal);
    while ((nombreDecimal!=0)&&(n!=100)) //La conversion se fera tant que le nombreDecimal ne sera pas nul et que n ne vaudra pas 100 (limite des tableaux)
    {
        if ((nombreDecimal%16)<10)
        {
            switch (nombreDecimal%16) //l'emploi du switch est justifié dans ce cas-ci puisqu'il y a de nombreuses possibilitées
            {
            case 0:
                temp[n]='0';
                break;
            case 1:
                temp[n]='1';
                break;
            case 2:
                temp[n]='2';
                break;
            case 3:
                temp[n]='3';
                break;
            case 4:
                temp[n]='4';
                break;
            case 5:
                temp[n]='5';
                break;
            case 6:
                temp[n]='6';
                break;
            case 7:
                temp[n]='7';
                break;
            case 8:
                temp[n]='8';
                break;
            case 9:
                temp[n]='9';
                break;
            }
        }
        else
        {
            switch (nombreDecimal%16)
            {
            case 10:
                temp[n]='A';
                break;
            case 11:
                temp[n]='B';
                break;
            case 12:
                temp[n]='C';
                break;
            case 13:
                temp[n]='D';
                break;
            case 14:
                temp[n]='E';
                break;
            case 15:
                temp[n]='F';
                break;
            }
        }
        nombreDecimal/=16;
        n++;
    }
    for (i=0; i<n; i++) //cette boucle for me permet de replacer dans le bon sens de lecture le résultat de la conversion que je stocke dans le tableau nombreHexa avant de l'afficher.
    {
        nombreHexa[i]=temp[n-1-i];
    }
    printf("Resultat de la conversion en hexadecimal :\n%s\n",nombreHexa);
}

void exercice8(void)
{
    unsigned short A=104, B;
    float C=6.5;
    A+=(unsigned short)C;
    /*
    A est de type unsigned short tandis que C est de type float donc on doit cast C en unsigned short.
    Cette opération équivaut à faire A=((unsigned short)C)+A;
    Le passage en type int pour A et B ne changerait rien au résultat mis à part.
    */
    A=~A;
    /*
    Il s'agit de la négation binaire : exemple la négation de 0101 est 1010.
    Le passage en type int de la variable A aura une influence sur le résultat.
    Ceci s'explique par le fait que la taille d'un unsigned short et d'un int ne sont pas tout à fait aussi grande.
    De plus, un int est un entier signé donc si le nombre précédent était positif, il deviendra négatif.
    */
    B=A^(A+2);
    /*
    Il s'agit d'un OU exclusif bit-à-bit. Exemple : 1010^1101=0111
    Le changement en type int de A et B pourrait avoir une influence sur les résultats même si dans le cas donné étudié non.
    */
    C=(float)(A<<B);
    /*
    C est de type float tandis que A et B sont de types unsigned short donc on doit faire un cast.
    L'opération << est un décalage des bits vers la gauche de B fois. Exemple (5<<2)=10100
    Le changement en type int a une influence sur le résultat dans la mesure où la négation binaire aura déjà un résultat différent.
    */
    A=A&(unsigned short)C;
    /*
    Toujours le même principe pour le cast.
    Il s'agit d'un ET bit-à-bit. Exemple : 9&12=8 car 1001&1100=1000.
    Le changement en type int aura une influence sur le résultat puisque A n'a pas la même valeur.
    */
}
