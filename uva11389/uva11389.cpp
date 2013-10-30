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
	int n,d,r;
	while (cin>>n>>d>>r && n && d && r) {
    vi morning;
    vi evening;
    for (int i=0;i<n;++i) {
      int m; cin>>m; morning.push_back(m);
    }
    for (int i=0;i<n;++i) {
      int e; cin>>e; evening.push_back(e);
    }

    sort(morning.begin(),morning.end());
    sort(evening.begin(),evening.end(),greater<int>());

    int overtime = 0;
    for (int i=0;i<n;++i) {
      int s = morning[i]+evening[i];
      if (s>d) {
        overtime+=s-d;
      }
    }

    cout<<overtime*r<<endl;

	}
	return 0;
}