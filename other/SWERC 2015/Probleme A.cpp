#include<bits/stdc++.h>
#define MAX 100

int level[MAX];
std::vector<std::vector<int> > listeAdacente;

int affichage(int a,int n)
{

    while(level[a] == level[a+1] && a > 0 && a != n-1) a--;
    printf("%d\n",a+1);
    return ++a;
}

void dfs(int x,int niveau)
{
    for(int u : listeAdacente[x])
    {
        if( level[u] < niveau)
            dfs(u,niveau+1);
    }
}

int main()
{
    int n,q,m,c;
    scanf("%d %d %d",&n,&m,&q);
    int a,b;
    bool estRacine [n + 1];                         // Pour trouver les racines
    memset(estRacine, false, n+1 * sizeof(bool));   // intialisation
    std::vector<int> racine;
    memset(level,0,n+1 * sizeof(int));
    for(int i = 0; i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        listeAdacente[a].push_back(b);
        listeAdacente[b].push_back(a);
        estRacine[b] =false;
    }
    for(int i(0); i< n; i++)
    {
        if (estRacine[i]) racine.push_back(i);
    }
    for(int x : racine)
    {
        dfs(x,1);
    }

    std::sort(level,level+n);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        a--;
        b--;
        affichage(a,n);
        (b == n) ? (c=affichage(n-1,n)) :(c = affichage(b,n));
        printf("%d",n-c);
    }
}
