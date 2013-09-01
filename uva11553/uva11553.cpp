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

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	while (T--) {
		int n; cin>>n;
    int mat[n][n];
    for (int i=0;i<n;++i) {
      for (int j=0;j<n;++j) {
        int m; cin>>m;
        mat[i][j]=m;
      }
    }

    int permutation[n];
    for (int i=0;i<n;++i) {
      permutation[i]=i;
    }

    int min = INT_MAX;
    do {
      int temp = 0;
      for (int i=0;i<n;++i) {
        temp+=mat[i][permutation[i]];
      }
      if (temp<min)
        min = temp;
    } while (next_permutation(permutation,permutation+n));
    cout<<min<<endl;
	}
	return 0;
}
