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

	int N;
  while (cin>>N && N>0) {
    int sum = 0;
    int ans = 0;
  	while (N--) {
      int n; cin>>n;
      sum+=n;
      ans = max(sum,ans);
      if (sum<0) sum = 0;
  	}
    if (ans==0) {
      cout<<"Losing streak."<<endl;
    } else {
      cout<<"The maximum winning streak is "<<ans<<"."<<endl;
    }
  }
	return 0;
}