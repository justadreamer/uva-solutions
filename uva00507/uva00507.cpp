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

	int R; cin>>R;
	for (int r=1;r<=R;++r) {
		int s; cin>>s;
    int ans = 0; int ans_start = 1; int ans_end = 1;
    int sum = 0; int start = 1; int end = 1;

    for (int i=1;i<s;++i) {
      int n; cin>>n;
      sum+=n;
      if (sum<0) {
        sum=0;
        start = i+1;
        end = start;
      }

      if (sum>=ans) {
        end = i+1;
      }

      if (sum>ans || (sum==ans && ans_start!=start && end-start > ans_end-ans_start)) {
        ans = sum;
        ans_start = start;
      }

      if (ans_start==start) {
        ans_end = end;
      }
    }

    //output:
    if (ans>0) {
      cout<<"The nicest part of route "<<r<<" is between stops "<<ans_start<<" and "<<ans_end<<endl;
    } else {
      cout<<"Route "<<r<<" has no nice parts"<<endl;
    }
	}
	return 0;
}