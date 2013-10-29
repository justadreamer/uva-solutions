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
	int T;
	cin>>T;
	while (T--) {
		int n; cin>>n;
    vi C;
    for (int i=0;i<n;++i) {
      int c; cin>>c; C.push_back(c);
    }

    int count = 0;
    int sum = 0;
    for (int i=0;i<n;++i) {
      if (i==n-1 || sum+C[i]<C[i+1]) {
        sum+=C[i]; count++;
      }
    }

    cout<<count<<endl;
	}
	return 0;
}