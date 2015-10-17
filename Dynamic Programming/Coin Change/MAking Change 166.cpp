#include <stdio.h>
#define inf 10000
#define min(a,b) (a<b)?a:b;
int minimum[1005];
int av[6];
int coins[] ={5, 10, 20, 50, 100,200};
int minimumChange(int n,int first)
{
    if(n<-500||n>500)
        return inf;
    if(n<=0&&first<0)
        return minimum[-n];
    else if(first<0)
        return inf;
    else if(!av[first])
        return minimumChange(n,first-1);
    else
    {
        av[first]--;
        int a = minimumChange(n-coins[first],first);
        av[first]++;
        int b = minimumChange(n,first-1);
        return min(1+a,b);
    }
}
int main()
{
    int i,j,r,q;
    for(i=0;i<1005;i++)minimum[i]=inf;
    minimum[0]=0;
    for(i=0;i<6;i++)
        for(j=coins[i];j<1005;j++)
            minimum[j]=min(minimum[j],1+minimum[j-coins[i]]);

    scanf("%d %d %d %d %d %d",av,av+1,av+2,av+3,av+4,av+5);
    while(av[0]||av[1]||av[2]||av[3]||av[4]||av[5])
    {
        scanf("%d.%d",&r,&q);
        r = r*100 + q;
        printf("%3d\n",minimumChange(r,5));
        scanf("%d %d %d %d %d %d",av,av+1,av+2,av+3,av+4,av+5);
    }
    return 0;
}
