#include <stdio.h>
#include <stdlib.h>
#include <math.h> //me permet d'utiliser la fonction powf

void binaireVersDecimal(void)
{
    unsigned int nombreBinaire=0, n=0, nombreDecimal=0; //nombreBinaire, n et nombreDecimal sont des entiers non-sign�s. n indique la position du bit o� l'on se situe.
    printf("Saisir le nombre binaire :\n");
    scanf("%u",&nombreBinaire); //%u est employ� dans le cadre d'une variable de type unsigned int
    while(nombreBinaire!=0)
    {
        nombreDecimal=nombreDecimal+(nombreBinaire%10)*(unsigned int)powf((float)2,(float)n);
        /*
        Afin d'�viter des erreurs de calculs, j'ai cast� certaines variables.
        En effet, powf est une fonction qui fonctionne avec des variables de type float en entr�e et qui retourne une valeur de type float en sortie.
        C'est pourquoi en entr�e j'ai cast� 2 et n en type float puis en sortie j'ai cast� la valeur en unsigned int.
        cela permet d'�viter bien des erreurs.
        */
        nombreBinaire/=10; //i.e. nombreBinaire=nombreBinaire/10, l'avantage de ma m�thode c'est qu'elle est l�g�rement plus rapide � �crire pour moi et aussi � ex�cuter par l'ordinateur.
        n++;
    }
    printf("Resultat de la conversion en decimal :\n%u\n",nombreDecimal);
}

/*
Les programme de conversion decimal vers binaire ou octal ont un principe de fonctionnant tout � fait �quivalent,
je ne m'amuserai donc pas � les d�tailler davatange.
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
    char nombreHexa[100]= {0}, temp[100]= {0}; //Je cr�� 2 tableaux de caract�res. temp est le tableau qui contient le r�sultat de la conversion mais dans le "sens inverse" de lecture.
    printf("Saisir le nombre decimal :\n");
    scanf("%u",&nombreDecimal);
    while ((nombreDecimal!=0)&&(n!=100)) //La conversion se fera tant que le nombreDecimal ne sera pas nul et que n ne vaudra pas 100 (limite des tableaux)
    {
        if ((nombreDecimal%16)<10)
        {
            switch (nombreDecimal%16) //l'emploi du switch est justifi� dans ce cas-ci puisqu'il y a de nombreuses possibilit�es
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
    for (i=0; i<n; i++) //cette boucle for me permet de replacer dans le bon sens de lecture le r�sultat de la conversion que je stocke dans le tableau nombreHexa avant de l'afficher.
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
    Cette op�ration �quivaut � faire A=((unsigned short)C)+A;
    Le passage en type int pour A et B ne changerait rien au r�sultat mis � part.
    */
    A=~A;
    /*
    Il s'agit de la n�gation binaire : exemple la n�gation de 0101 est 1010.
    Le passage en type int de la variable A aura une influence sur le r�sultat.
    Ceci s'explique par le fait que la taille d'un unsigned short et d'un int ne sont pas tout � fait aussi grande.
    De plus, un int est un entier sign� donc si le nombre pr�c�dent �tait positif, il deviendra n�gatif.
    */
    B=A^(A+2);
    /*
    Il s'agit d'un OU exclusif bit-�-bit. Exemple : 1010^1101=0111
    Le changement en type int de A et B pourrait avoir une influence sur les r�sultats m�me si dans le cas donn� �tudi� non.
    */
    C=(float)(A<<B);
    /*
    C est de type float tandis que A et B sont de types unsigned short donc on doit faire un cast.
    L'op�ration << est un d�calage des bits vers la gauche de B fois. Exemple (5<<2)=10100
    Le changement en type int a une influence sur le r�sultat dans la mesure o� la n�gation binaire aura d�j� un r�sultat diff�rent.
    */
    A=A&(unsigned short)C;
    /*
    Toujours le m�me principe pour le cast.
    Il s'agit d'un ET bit-�-bit. Exemple : 9&12=8 car 1001&1100=1000.
    Le changement en type int aura une influence sur le r�sultat puisque A n'a pas la m�me valeur.
    */
}
