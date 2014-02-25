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

int value(int id, int amount, vi& coins, vector<vi>& memo) {
  if (id==coins.size() || amount==0) return 0;
  if (memo[id][amount]!=-1)  return memo[id][amount];
  if (coins[id]>amount) return memo[id][amount]=value(id+1,amount,coins,memo);

  return memo[id][amount]=max(value(id+1,amount,coins,memo),coins[id]+value(id+1,amount-coins[id],coins,memo));
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

	int n; cin>>n;
	while (n--) {
		int m; cin>>m;
    int sum = 0;
    vi coins(m,0);
    for (int i=0;i<m;++i) {
      cin>>coins[i]; sum+=coins[i];
    }
    vi amounts(sum/2+1,-1);
    vector<vi> memo(m,amounts);
    int val = value(0,sum/2,coins,memo);
    cout<<sum-2*val<<endl;
	}
	return 0;
}