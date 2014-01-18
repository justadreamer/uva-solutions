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

	int T;
	cin>>T;
	while (T--) {
		int N; cin>>N;
    int N2 = N*2;
    int m[N2][N2];
    int s[N2][N2];
    for (int i=0;i<N;++i) for (int j=0;j<N;++j) {
      int n; cin>>n;
      m[i][j]=m[N+i][j]=m[i][N+j]=m[N+i][N+j]=n;
    }
    for (int i=0;i<N2;++i) for (int j=0;j<N2;++j) {
        int sum = m[i][j];
        if (i>0) sum+=s[i-1][j];
        if (j>0) sum+=s[i][j-1];
        if (i>0 && j>0) sum-=s[i-1][j-1];
        s[i][j]=sum;
    }

    int max_sum = s[0][0];
    for (int i1=0;i1<N2;++i1) for (int j1=0;j1<N2;++j1)
    for (int i2=i1;i2<N2 && i2-i1<N;++i2) for (int j2=j1;j2<N2 && j2-j1<N;++j2) {
      int sum = s[i2][j2];
      if (i1>0) sum-=s[i1-1][j2];
      if (j1>0) sum-=s[i2][j1-1];
      if (i1>0 && j1>0) sum+=s[i1-1][j1-1];
      if (sum>max_sum) {
        max_sum = sum;
      }
    }
    cout<<max_sum<<endl;
	}
	return 0;
}