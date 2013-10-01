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

int to_idx(char c) {
  if (c>='a') {
    return 26+c-'a';
  }
  return c-'A';
}

struct compare {
  inline bool operator()(const int left, const int right) const {
    return left<=right;
  };
};

int main(int argc, char* argv[])
{
  string S; cin>>S;
  vi pos[52];
  for (int i=0;i<S.size();++i) {
    pos[to_idx(S[i])].push_back(i);
  }

  compare c;
	int Q; cin>>Q;
	while (Q--) {
    string SS; cin>>SS;
    bool matches = true;
    int first=0,last=-1;
    int cur_pos=0;

    for (int i=0;i<SS.size();++i) {
      int idx = to_idx(SS[i]);
      vi::iterator it = lower_bound(pos[idx].begin(),pos[idx].end(),last,c);
      if (it==pos[idx].end()) {
        matches = false;
        break;
      } else {
        last = *it;
        if (i==0) {
          first = last;
        }
      }
    }

    if (matches) {
      cout<<"Matched "<<first<<" "<<last<<endl;
    } else {
      cout<<"Not matched"<<endl;
    }
	}

	return 0;
}