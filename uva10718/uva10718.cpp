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
#include <numeric>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int main(int argc, char* argv[])
{
	unsigned int N,L,U;
	while (cin && cin>>N>>L>>U) {
    unsigned int M=~N;
    for (int i=31;i>=0;--i) {
      unsigned int MM = M>>i;
      unsigned int LL = L>>i;
      unsigned int UU = U>>i;
      unsigned int mask = 1<<i;
      if (MM<LL) {
        M |= mask;
      } else if (MM>UU) {
        M &= ~mask;
      }
    }
    cout<<M<<endl;
	}
	return 0;
}