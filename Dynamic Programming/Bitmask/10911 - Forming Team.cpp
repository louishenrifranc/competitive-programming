#include <stdio.h>
#include <math.h>
#include<string.h>
#define min(a,b) (a<b)?a:b

/**
You have been given the job of forming the quiz teams for the next `MCA CPCI Quiz Championship'.
There are 2 N students interested to participate and you have to form N teams, each team consisting
of two members. Since the members have to practice together, all the students want their members
house as near as possible. Let be the distance between the houses of group 1,be the distance
between the houses of group 2 and so on. You have to make sure the summation is minimized.

Dinamic Programming + bitmask
On enregistre dans un tableau , quel est la minimum distance si l'on a déja pris des etudiant
Par exemple si on a déja pris la paire 12 et 34 alors quand on calculera la paire 34 et 12
on aura deja notre resultat, ici la valeur sera enregistre dans t[1<<1|1<<2|1<<3|1<<4]
**/
using namespace std;
int maxi;
int n;
int x[20];
int y[20];
double dist[20][20],dp[1<<16];
char name[20];
double minD(int state)
{
    if(state==maxi)     // Si on a pris tous les élèves, alors plus besoin d'ajouter des distances
        return 0;
    else if(dp[state]!=-1)  // Si on a déja calculé la valeur
        return dp[state];
    else
    {
        int i,j;
        double m=1<<30;         // Un max aléatoire
        for(i = 0;i<2*n;i++)
            if(!(state&(1<<i)))     // Si l'étudiant a deja ete pris alors on ne continue pas, on passe a i+1
                for(j=i+1;j<2*n;j++)
                    if(!(state&(1<<j))) // Si l'etudiant a deja ete pris, on passe a j+1

                        m = min(m,dist[i][j]+minD(state|(1<<i)|(1<<j))); /**   // Si par exemple on a 6 eleves, et on
                                                                // on arrive ici apres avoir appele minD pour la paire 12
                                                                // Alors m retournera pour la paire 1-2 le min entre toute les paires
                                                                // 34-56 puis
                                                                    // 35-46
                                                                        // puis 36-45
                                                                            // puis 43 -56 mais c'est deja calcule avec 34-56
                                                                            // donc on retourne la valeur **/
        return dp[state]=m;
    }
}
int main()
{
    int i,j,cc=1;
    scanf("%d",&n);
    while(n)
    {
        maxi = (1<<(2*n))-1; // On prend n=2
                            // 2*n = 4, -1 car le tableau commence a 0
        printf("%d",maxi);
        for(i=0;i<2*n;i++)
            scanf("%s %d %d",name,x+i,y+i);
        for(i=0;i<2*n;i++)
            for(j=i+1;j<2*n;j++)
                dist[i][j]=dist[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %.2lf\n",cc++,minD(0));    // Afficher avec 2 chiffres apres la virgule
        scanf("%d",&n);
    }
    return 0;
}
