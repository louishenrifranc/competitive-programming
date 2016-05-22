#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;

int main(){
int listdesdistances[200001];
set<int> t,d;
register int d1,m,j,resultat;

while(scanf("%d",&d1)==1){
memset(listdesdistances,-1,sizeof(listdesdistances));
t.clear();
d.clear();
resultat=0;
for(int i(0);i<d1;i++){
    scanf("%d",&m);
    listdesdistances[m]=1;
    t.insert(m);
}
scanf("%d",&m);
for(int i(0);i<m;i++){
    scanf("%d",&j);
    if(listdesdistances[j] != -1) resultat++;
    d.insert(j);
}

for(set<int>::iterator it1=t.begin();it1!=t.end();it1++){
        for(set<int>::iterator it2=it1;it2!=t.end();it2++)
if(d.find(*it1+*it2) != d.end()){
    resultat++;
}
    }
printf("%d\n",resultat);

}
return 0;
}

