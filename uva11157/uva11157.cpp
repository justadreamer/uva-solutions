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

typedef struct {
  bool is_small;
  int d;
  bool is_drowned;
} stone;

int main(int argc, char* argv[])
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int N, D;
    cin>>N>>D;
    vector<stone> stones;
    for (int i=0;i<N;++i) {
      char c; int d;
      cin>>c; cin.ignore(); cin>>d;
      stone s; s.is_small = c=='S'; s.d = d; s.is_drowned = false;
      stones.push_back(s);
    }
    stone s; s.is_small = false; s.d = D; s.is_drowned = false;
    stones.push_back(s);

    int small_stone_counter = 0;
    int cur_dist = 0;
    int max_leap = 0;
    //first pass: some stones must drown
    for (int i=0;i<stones.size();++i) {
      stone& s = stones[i];
      int leap = s.d-cur_dist;
      bool increase_dist = true;
      if (!s.is_small) {
        small_stone_counter = 0;
      } else if (small_stone_counter++ % 2 == 0) { //this stone drowns on the first pass
        s.is_drowned = true;
      } else { //this stone is saved for the second pass, so do not count the leaps from it
        leap = 0;
        increase_dist = false;
      }
      if (leap>max_leap) max_leap = leap;
      if (increase_dist) cur_dist = s.d;
    }

    //second pass: detect leaps only from the stones that are not drowned
    cur_dist = 0;
    for (int i=0;i<stones.size();++i) {
      stone& s = stones[i];
      if (!s.is_drowned) {
        int leap = s.d - cur_dist;
        if (leap>max_leap) max_leap = leap;
        cur_dist = s.d;
      }
    }
    cout<<"Case "<<t<<": "<<max_leap<<endl;
	}
	return 0;
}