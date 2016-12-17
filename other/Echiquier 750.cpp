#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<math.h>
#include<string.h>
/**
Positionner des dames sur un echiquier
**/
using namespace std;
int x[9],a,b,nombredesolutions(0); // Ne pas s'embrouiller avec les indices allouer un indice de plus et l'intiilialiser avec memset


bool positionnner(int colomn,int row)
{
    for(int j(1); j< colomn; j++)
        if(x[j]==row || fabs(j-colomn) == fabs(x[j]-row)) return false;


    return true;
}

void Possibilite(int colomn)
{
    for(int i(1); i<9; i++)
    {
        if(positionnner(colomn,i))
        {
            x[colomn]=i;
            if(colomn==8 && x[a]==b)
            {
                nombredesolutions++;
                printf("%2d      %d",nombredesolutions,x[1]);
                for(int u(2); u<9; u++)
                {
                    printf(" %d",x[u]);

                }
                printf("\n");

            }

            else
            {
                Possibilite(colomn+1);
            }
        }

    }

}



int main()
{
    int times;
    scanf("%d",&times);

    while(times--)
    {
        scanf("%d %d",&b,&a);
        memset(x,0,sizeof(x));
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8");
        printf("\n\n");
        Possibilite(1);
        nombredesolutions=0;
            if(times) printf("\n");
    }
    return 0;
}

