#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
#define PB push_back
#define pi acos(-1.0)
#define eps 1e-9

struct A
{
    int x,y;
    string s;

    bool operator < (const A &b) const
    {
        if(x==b.x)
        {
            if(y==b.y)  return s<b.s;
            else
                return y<b.y;
        }
        else
            return x>b.x;
    }
};
int main()

{

    int t,x1,y1,i,j;
    string s1;
    vector<A>v;
    vector<string>v1;
    vector<string>v2;
    A a;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        for(j=0; j<10; j++)
        {
            cin>>s1>>x1>>y1;
            a.s=s1;
            a.x=x1;
            a.y=y1;
            v.PB(a);
        }
        sort(v.begin(),v.end());
        for(j=0; j<5; j++)
            v1.PB(v[j].s);
        for(j=5; j<10; j++)
            v2.PB(v[j].s);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        cout<<"Case "<<i<<":"<<endl;
        cout<<"("<<v1[0];
        for(j=1; j<5; j++)
            cout<<", "<<v1[j];
        cout<<")"<<endl;
        cout<<"("<<v2[0];
        for(j=1; j<5; j++)
            cout<<", "<<v2[j];
        cout<<")"<<endl;
        v.clear();
        v1.clear();
        v2.clear();
    }

    return 0;
}
