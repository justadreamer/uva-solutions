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

int main(int argc, char* argv[])
{
	int T;
	cin>>T;

	for (int t=1;t<=T;++t) {
    vi rangs;
    int n; cin>>n;
    int max_diff = 0;
    while (n--) {
      int cur; cin>>cur;
      int diff = rangs.size()>0 ? cur - rangs.back(): cur;
      if (diff>max_diff) {
        max_diff = diff;
      }
      rangs.push_back(cur);
    }

    //simulate with k==max_diff, if it does not work, then ans=k+1
    int ans = max_diff;
    int k = max_diff;
    for (int i=0;i<rangs.size();++i) {
      int diff = i>0 ? rangs[i]-rangs[i-1] : rangs[i];
      if (diff==k) {
        --k;
      } else if (diff>k) {
        ans=max_diff+1;
        break;
      }
    }

    cout<<"Case "<<t<<": "<<ans<<endl;
  }

	return 0;
}