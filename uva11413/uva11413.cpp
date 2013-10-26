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
typedef set<int> si;
bool can (vi& v, int m, int maxv) {
  int s = 0;
  for (int i = 0; i<v.size(); ++i) {
    if (s+v[i]<=maxv) {
      s+=v[i];
    } else {
      --m;
      s = v[i];
    }
  }

  return s<=maxv && m>0;
}

int main(int argc, char* argv[])
{
	int n,m;
	while (cin && cin>>n>>m) {
    vi vessels;
    int lo = 0; //this is the max size(volume) of the vessel
    int hi = 0; //this is the sum of all vessels
		for (int i=0;i<n;++i) {
      int v; cin>>v; vessels.push_back(v);
      if (v>lo) {
        lo = v;
      }
      hi+=v;
    }

    //now we have lo and hi let's binary search and simulate:
    int ans = hi;
    while (hi>lo) {
      int mid = (lo+hi)/2;
      if (can(vessels,m,mid)) {
        ans = mid;
        hi = mid;
      } else {
        lo = mid+1;
      }
    }

    cout<<ans<<endl;
	}
	return 0;
}