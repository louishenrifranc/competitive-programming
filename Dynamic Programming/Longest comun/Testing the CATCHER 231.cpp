#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
using namespace std;
/**
A military contractor for the Department of Defense has just completed a series of preliminary tests
for a new defensive missile called the CATCHER which is capable of intercepting multiple incoming
offensive missiles.  The CATCHER is supposed to be a remarkable defensive missile.  It can move
forward, laterally, and downward at very fast speeds, and it can intercept an offensive missile without
being damaged. But it does have one major
aw. Although it can be red to reach any initial elevation,
it has no power to move higher than the last missile that it has intercepted.
The tests which the contractor completed were computer simulations of battleeld and hostile
attack conditions.  Since they were only preliminary, the simulations tested only the CATCHER's
vertical movement capability. In each simulation, the CATCHER was red at a sequence of offensive
missiles which were incoming at xed time intervals. The only information available to the CATCHER
for each incoming missile was its height at the point it could be intercepted and where it appeared in
the sequence of missiles. Each incoming missile for a test run is represented in the sequence only once.
The result of each test is reported as the sequence of incoming missiles and the total number of
those missiles that are intercepted by the CATCHER in that test.
The General Accounting Office wants to be sure that the simulation test results submitted by the
military contractor are attainable, given the constraints of the CATCHER. You must write a program
that takes input data representing the pattern of incoming missiles for several different tests and outputs
the maximum numbers of missiles that the CATCHER can intercept for those tests. For any incoming
missile in a test, the CATCHER is able to intercept it if and only if it satises one of these two
conditions

Plus longue sous chaine decroissante
**/


int tableau[10000000]; // Nombre de missiles max

int main()
{
    int temp,n(0);
    long long x(1);
    scanf("%d",&temp);
    while(1){
        if(temp!=-1){
                tableau[n+1]=temp;
                n++;
                scanf("%d",&temp);
        }
        else{
            int tt[n+1];

                tt[0]=0;
                tt[1]=1;
                int maxi(1);
                /** Algorithme de plus longue sous chaine decroissante **/
                for(int i(2);i<=n;i++){
                    int ans=1;
                    for(int j(1);j<i;j++){
                        if(tableau[i] => tableau[j])
                            ans=max(ans,1+tt[j]);

                    }

                    tt[i]=ans;
                    if(maxi<ans) maxi=ans;
                }
            if(x>1) printf("\n"); // <- Pas valider a cause de ca !!!!!!!!
            printf("Test #%d:\n",x);
            printf("  maximum possible interceptions: %d\n",maxi);
            x++;
                n=0;
            scanf("%d",&temp);
            if(temp==-1) break;
        }
    }

}


