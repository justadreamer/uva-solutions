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

int t, w, n;
vi d, v; 
vector<vi> memo;

int value (int id,int t) {
  if (id==n) return 0;
  if (memo[id][t]>-1) return memo[id][t];
  int cur_t = 3*w*d[id];
  if (t<cur_t) memo[id][t]=value(id+1,t);
  else memo[id][t] = max(value(id+1,t),v[id]+value(id+1,t-cur_t));
  return memo[id][t];
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif
  bool first = true;
	while (cin && cin>>t>>w) {
    if (!first) cout<<endl; else first = false;
		cin>>n;
    d = vi(n,0);
    v = vi(n,0);
    for (int i=0;i<n;++i) cin>>d[i]>>v[i];
    vi row(t+1,-1);
    memo = vector<vi>(n,row);
    int val = value(0,t); //the final value is stored at memo[0][t]

    //reconstructing solution to print:
    vi sol;
    for (int i=0;i<n;++i) {
      if (i<n-1 && memo[i][t]==memo[i+1][t]) continue;
      if (memo[i][t]>0) {
        sol.push_back(i); t-=3*w*d[i];
      }
    }
    
    //printing solution:
    cout<<val<<endl<<sol.size()<<endl;
    for (int i=0;i<sol.size();++i) cout<<d[sol[i]]<<" "<<v[sol[i]]<<endl;
	}
	return 0;
}