#include<stdio.h>
int t[101][101];

int main()
{
    int n,m,cas(0);
    char buffer;
    void ajouter(int a,int b)
    {
        for(int i(-1); i<2; i++)
        {
            for(int j(-1); j<2; j++)
            {
                if(a+i >=0 && b+i >=0 && a+i < n && b+i <m && (i || j))
                }
        }

    }

    while(scanf("%d %d",&n,&m) == 2 && ( n || m))
    {
        memset(t,0,sizeof(0));
        for(int a(0); a<n; a++)
        {
            for(int b(0); b<m; b++)
            {
                scanf("%c",&buffer);
                if(buffer == '*')
                {
                    for(int i(-1); i<2; i++)
                    {
                        for(int j(-1); j<2; j++)
                        {
                            if(a+i >=0 && b+i >=0 && a+i < n && b+i <m && (i || j))
                                t[a+i][b+j]++;
                            }

                    }
                }

            }
        }
        printf("Field #%d",++cas);
        for(int i(0);i<n;i++){
            for(int j(0);j<m;j++){
                printf("%d",t[i][j]);
            }
            printf("\n");
        }

    }
}
