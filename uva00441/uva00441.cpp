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
	int k;
  bool is_first=true;
	while (cin>>k && k) {
    if (!is_first) 
      printf("\n");
    else 
      is_first = false;
		vi S;
    while (k--) {
      int n; cin>>n; S.push_back(n);
    }

    k = S.size();

    for (int a=0;a<=k-6;++a) {
      for (int b=a+1;b<=1+k-6;++b) {
        for (int c=b+1;c<=2+k-6;++c) {
          for (int d=c+1;d<=3+k-6;++d) {
            for (int e=d+1;e<=4+k-6;++e) {
              for (int f=e+1;f<=5+k-6;++f) {
                printf("%d %d %d %d %d %d\n",S[a],S[b],S[c],S[d],S[e],S[f]);
              }
            }
          }
        }
      }
    }
	}
	return 0;
}