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
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;

bool check(vii& dominoes, ii& left, ii& right, int n, int used) {
  for (int i=0;i<dominoes.size();++i) {
    int mask = 1<<i;
    if (0 == (used & mask)) {
      ii next_left;
      if (dominoes[i].first==left.second) {
        next_left = dominoes[i];
      } else if (dominoes[i].second==left.second) {
        next_left = make_pair(dominoes[i].second,dominoes[i].first);
      } else {
        continue;
      }

      int bits = __builtin_popcount(used);
      if (bits<n-1) {
        used |= mask;
        if (check(dominoes,next_left,right,n,used))
          return true;
        used ^= mask;
      } else if (bits==n-1 && next_left.second==right.first) {
        return true;
      } else {
        return false;
      }
    }
  }
  return false;
}

int main(int argc, char* argv[])
{
	int n,m;
	while (cin>>n>>m && n && m) {
		vii dominoes;
    ii left,right;
    for (int i=0;i<m+2;++i) {
      int p,q; cin>>p>>q;
      ii d = make_pair(p,q);
      if (i==0)
        left = d;
      else if(i==1)
        right = d;
      else
        dominoes.push_back(d);
    }

    cout << (check(dominoes,left,right,n,0) ? "YES" : "NO")<<endl;
	}
	return 0;
}