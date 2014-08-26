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
    int ncars; cin>>ncars;
    vi cars;
    for (int i=0;i<ncars;++i) {
      int w; cin>>w; cars.push_back(w);
    }

    vi LIS (ncars,0);
    vi LDS (ncars,0);

    int max_sum = 0;
    for (int i=ncars-1;i>=0;--i) {
      int max_LIS = 0;
      int max_LDS = 0;

      for (int j=i+1;j<ncars;++j) {
        if (cars[j]>cars[i] && LIS[j]>max_LIS) {
          max_LIS = LIS[j];
        }
        if (cars[j]<cars[i] && LDS[j]>max_LDS) {
          max_LDS = LDS[j];
        }
      }

      LIS[i]=max_LIS+1;
      LDS[i]=max_LDS+1;
      int sum = LIS[i]+LDS[i]-1;
      if (max_sum<sum) {
        max_sum = sum;
      }
    }

    cout<<max_sum<<endl;
	}
	return 0;
}