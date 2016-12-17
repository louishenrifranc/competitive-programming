#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include<math.h>
using namespace std;
int main()
{   int a,b,i,j(0);
    for(;;){
     scanf("%d",&a);
     if( a < 0 ) break;
     b=1;i=1;
     if(a<2) i=0;
     else while((b=b<<1) < a) i++;
    j++;
    printf("Case %d: %d\n",j,i);

}
}
