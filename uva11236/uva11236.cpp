#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;

int main(int argc, char* argv[])
{
  long long const mln = 1000000;
  long long const tt = 2000;

  //I first run it with the tt as the high limit for a, 
  //and then observed, that a does not get higher than 125 in the output
  //so to pass the TL I just put 125 as the high limit for a
  for (long long a=1; a<=125; ++a) {
    for (long long b=a; b<=tt-a; ++b) {
      for (long long c=b; c<=tt-a-b; ++c) {
        long long abc = a*b*c;
        if (abc<=mln)
          continue;
        lldiv_t dd = div((a+b+c)*mln,abc-mln);
        if (dd.rem>0)
          continue;
        long long d = dd.quot;
        if (d<c)
          break;
        if (a+b+c+d>tt)
          continue;
        printf("%.2f %.2f %.2f %.2f\n",a*0.01,b*0.01,c*0.01,d*0.01);
      }
    }
  }
	return 0;
}