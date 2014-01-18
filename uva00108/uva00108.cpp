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

	int N; cin>>N;
  int s[N][N];
	for (int i=0;i<N;++i) for (int j=0;j<N;++j) {
    int n; cin>>n;
    s[i][j]=n;
    if (i>0) s[i][j]+=s[i-1][j];
    if (j>0) s[i][j]+=s[i][j-1];
    if (i>0 && j>0) s[i][j]-=s[i-1][j-1];
  }

  int max_sum = s[0][0];
  for (int i=0;i<N;++i) for (int j=0;j<N;++j) 
  for (int i2=i;i2<N;++i2) for (int j2=j;j2<N;++j2) {
    int sum = s[i2][j2];
    if (i>0) sum-=s[i-1][j2];
    if (j>0) sum-=s[i2][j-1];
    if (i>0 && j>0) sum+=s[i-1][j-1];
    if (sum>max_sum)
      max_sum = sum;
  }

  cout<<max_sum<<endl;
	return 0;
}