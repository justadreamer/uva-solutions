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

int const MAX_D = 20;
int const MAX_M = 10;

int N; vi n; //n contains N numbers

vector<vector<vector<vi> > > memo;

int value (int id, int M, int D, long long sum) {
  if (id==N || M==0) return 0;
  int ind_sum = sum<0 ? MAX_D-sum : sum;
  if (memo[id][M][D][ind_sum]>-1) return memo[id][M][D][ind_sum];
  long long newsum = sum + (long long) n[id]; newsum%=D;
  if (M==1 && (newsum == 0)) return memo[id][M][D][ind_sum] = 1 + value(id+1,M,D,sum);
  memo[id][M][D][ind_sum] = value(id+1,M,D,sum) + value(id+1,M-1,D,newsum);
  return memo[id][M][D][ind_sum];
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif
  vi a(2*MAX_D,-1);
  vector<vi> b(MAX_D+1,a);
  vector<vector<vi> > c(MAX_M+1,b);

  int Q;
  int n_set=1;

	while (cin>>N && cin>>Q && N && Q) {
    n = vi(N,0); memo = vector<vector<vector<vi> > > (N,c);
		for (int i=0;i<N;++i) cin>>n[i];

    cout<<"SET "<<n_set++<<":"<<endl;
    for (int q=1;q<=Q;++q) {
      int M,D; cin>>D>>M;
      cout<<"QUERY "<<q<<": "<<value(0,M,D,0)<<endl;
    }
	}
	return 0;
}