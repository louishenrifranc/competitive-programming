#include <cstdio>
using namespace std;
/**
In the first years following the French Revolution, intellectuals were set to outroot the society from
the traditions and superstitions the dark ages of the royalty. Some of these contributions have had a
worldwide success, such as the metric system. Others have falled into (almost) complete oblivion, such
as the decimal clock system, invented by the mathematician Gilbert Romme. The decimal clock system
divides the day in 10 decimal hours, themselves divided in 100 decimal minutes, themselves divided
into 100 decimal seconds.
You are commissioned by the international watch maker “Splatch” to include yet another useless
feature in their next line of product: decimal time display. Your first task will be to implement a
program that converts a traditional time into a decimal time at the precision of one-hundredth of
second.


**/
int main(){
	char str[10];
	while( scanf("%s", str) != EOF ){
		int sec  = ( (str[0] - '0') * 10 + (str[1] - '0') ) * 60 * 60 * 100;
			sec += ( (str[2] - '0') * 10 + (str[3] - '0') ) * 60 * 100;
			sec += ( (str[4] - '0') * 10 + (str[5] - '0') ) * 100;
			sec += ( (str[6] - '0') * 10 + (str[7] - '0') );

			printf("%07d\n", (sec * 125) / 108);
	}
	return 0;
}
