#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<sstream>
#include<stdlib.h>

/**
a = 1
z = 26
ab = 27
... jusqu'a vwxyz
Precomputing puis Stockage dans une map
*/
using namespace std;
map<string,int> t;
int res(0);

void remplissage()
{
    string j;
    char s[6];

    for( s[0] ='a' ; s[0] <= 'z' ; s[0]++)
    {
        s[1]='\0';
        t[string(s)]=++res;
    }

    for(s[0] ='a' ; s[0] <= 'z'-1 ; s[0]++)
    {
        for(s[1]=s[0]+1; s[1] <='z'; s[1]++)
        {
            s[2]='\0';
            t[string(s)]=++res;
        }
    }

    for(s[0] ='a' ; s[0] <= 'z'-2 ; s[0]++)
    {
        for(s[1]=s[0]+1; s[1] <='z'-1; s[1]++)
        {
            for(s[2]=s[1]+1; s[2] <='z'; s[2]++)
            {
                s[3]='\0';
                t[string(s)]=++res;
            }

        }

    }
    for (s[0] = 'a'; s[0] <= 'z' - 3; s[0]++)
		for (s[1] = s[0] + 1; s[1] <= 'z' - 2; s[1]++)
			for (s[2] = s[1] + 1; s[2] <= 'z' - 1; s[2]++)
				for (s[3] = s[2] + 1; s[3] <= 'z'; s[3]++) {
					s[4] = '\0';
					t[string(s)] = ++res;
				}

	for (s[0] = 'a'; s[0] <= 'z' - 4; s[0]++)
		for (s[1] = s[0] + 1; s[1] <= 'z' - 3; s[1]++)
			for (s[2] = s[1] + 1; s[2] <= 'z' - 2; s[2]++)
				for (s[3] = s[2] + 1; s[3] <= 'z' - 1; s[3]++)
					for (s[4] = s[3] + 1; s[4] <= 'z'; s[4]++) {
						s[5] = '\0';
						t[string(s)] = ++res;
					}

}

int main()
{
    remplissage();
    string buffer;
    while(getline(cin,buffer)){
            if(t.count(buffer)) printf("%d\n",t[buffer]);
            else printf("0\n");
    }
    return 0;
}
