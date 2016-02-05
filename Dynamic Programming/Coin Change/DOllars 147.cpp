#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include<math.h>
using namespace std;
double valeur[]= {0.05,0.10,0.20,0.5,1,2,5,10,20,50,100}; // Toute la monnaie possible
double table[6001]; // On multiplie toutes les valeurs par 20 pour les mettre dans un tableau
                    // On sait que 300 en change est la valeur maximale demande

void countt();

int main()
{
    countt();
    register int r;

    double nombre;

    for(;;)
    {
        scanf("%lf",&nombre);
        if(nombre==0) break;
        r= nombre*20;
        printf("%6.2lf%17.lf\n",nombre,table[r]); // __200.__ 17 espaces contenant le chiffres suivant.
    }

}

void countt()
{

    int buffer;
        // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    table[0] = 1;


    n=6000;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<11; i++)
    {
        intermediaire1=valeur[i]*20;
        for(int j=intermediaire1; j<=n; j++)

            table[j] += table[j-intermediaire1];
    }

}
