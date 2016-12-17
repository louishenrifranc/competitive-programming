#include<stdio.h>
#include<string.h>
using namespace std;

int max(int a,int b){ return( (a<b)? b:a) ;}

int c, n, t, m, tmp;

int d[800][100][100];
int s[800];
int main(void) {
    scanf("%d",&c);
    while (c--) {
        scanf("%d %d %d",&n,&t,&m);
        int p=0;
        scanf("%d", s+p++);
        for (int i=1; i<n; i++) {
            scanf(", %d", s+p++);
        }
        memset(d, 0, sizeof(d));
        for (int i=0; i<n; i++) {
            for (int j=0; j<=m; j++) {
                for (int k=0; k<=t; k++) {
                    if (k<s[i]) {
                        d[i+1][j][k]=d[i][j][k];
                    } else {
                        d[i+1][j][k]=max(d[i][j][k], d[i][j][k-s[i]]+1);
                    }
                    if (j>0) {
                        d[i+1][j][k]=max(d[i+1][j][k], d[i][j-1][t-s[i]]+1);
                    }
                }
            }
        }
        int r=0;
        for (int i=0; i<=n; i++) {
            r=max(r, d[i][m][0]);
        }
            printf("%d\n",r);
            if (c) {
            putchar('\n');
        }
    }
    return 0;
}
