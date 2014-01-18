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

#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

	int T; cin>>T;
	while (T--) {
		int A,B,C; cin>>A>>B>>C;
    long long m[A][B][C];
    for (int i=0;i<A;++i) for (int j=0;j<B;++j) for (int k=0;k<C;++k) {
      long long g; cin>>g;
      if (i>0) g+=m[i-1][j][k];
      if (j>0) g+=m[i][j-1][k];
      if (k>0) g+=m[i][j][k-1];
      if (i>0 && j>0) g-=m[i-1][j-1][k];
      if (j>0 && k>0) g-=m[i][j-1][k-1];
      if (i>0 && k>0) g-=m[i-1][j][k-1];
      if (i>0 && j>0 && k>0) g+=m[i-1][j-1][k-1];
      m[i][j][k]=g;
    }

    long long max_sum = INT_MIN;
    for (int i=0;i<A;++i) for (int j=0;j<B;++j) for (int k=0;k<C;++k) 
    for (int i1=i;i1<A;++i1) for (int j1=j;j1<B;++j1) for (int k1=k;k1<C;++k1)  {
      long long s = m[i1][j1][k1];
      if (i>0) s-=m[i-1][j1][k1];
      if (j>0) s-=m[i1][j-1][k1];
      if (k>0) s-=m[i1][j1][k-1];
      if (i>0 && j>0) s+=m[i-1][j-1][k1];
      if (j>0 && k>0) s+=m[i1][j-1][k-1];
      if (i>0 && k>0) s+=m[i-1][j1][k-1];
      if (i>0 && j>0 && k>0) s-=m[i-1][j-1][k-1];
      if (s>max_sum) max_sum = s;
    }

    cout<<max_sum<<endl;
    if (T) cout<<endl;
	}
	return 0;
}