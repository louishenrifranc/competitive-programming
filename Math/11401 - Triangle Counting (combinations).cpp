#include <stdio.h>
/**

Triangle de cote de longueur de 1 a n

Pour longueur = 3: 0
     longueur = 4:   +1 =1
     longueur = 5:    +2 =3
     ...                +4= 7
                          +6= 13
                          ....
**/
long long  t[1000001];
int main()
{
    long long j=0;
    long long i=0,incrementeur(1),k;
    t[3]=0;

    i=4;
    k=0;
    while(i<1000001)
    {
        if(j==2)
        {
            incrementeur++;
            j=0;
        }
        k+=incrementeur;
        t[i]=t[i-1]+k;
        j++;
        i++;
    }
    while(scanf("%d",&i)==1 && i>=3) printf("%lld\n",t[i]);
}

