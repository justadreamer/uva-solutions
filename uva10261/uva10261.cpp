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
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int L; 
vi cars;
unordered_map<int,int> memo;

inline int _idx(int port, int star) {
  int idx = port*(L+1)+star; 
  return idx;
}

int backtrack(int port, int star, int id) {
  if ((port<=0 && star<=0) || id==cars.size()) return 0;

  int idx = _idx(port,star);

  if (memo.find(idx)!=memo.end()) {
    return memo[idx];
  }

  int new_port = port - cars[id];
  int new_star = star - cars[id];

  if (new_port>=0 && new_star>=0 && port==star) 
    return memo[idx] = 1 + backtrack(new_port,star,id+1);

  if (new_port>=0 && new_star>=0)
    return memo[idx] = 1 + max(backtrack(new_port,star,id+1), backtrack(port,new_star,id+1));

  if (new_port>=0) 
    return memo[idx] = 1 + backtrack(new_port,star,id+1);

  if (new_star>=0) 
    return memo[idx] = 1 + backtrack(port,new_star,id+1);

  return 0;
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

	int T; cin>>T;
	while (T--) {
    cars.clear();

    cin>>L; L*=100;
    int car_len;

    while (cin>>car_len && car_len) {
      cars.push_back(car_len);
    }

    memo.clear();
    int n_cars = backtrack(L, L, 0);

    cout<<n_cars<<endl;

    int port = L;
    int star = L;
    int id = 0;

    for (int id=0;id<n_cars;++id) {
      int new_port = port-cars[id];
      int new_star = star-cars[id];
      int port_idx = _idx(new_port,star);
      int star_idx = _idx(port,new_star);
      if (new_port>=0 && new_star>=0) {
        if (port==star 
          || 
          (memo.find(port_idx)!=memo.end() && memo.find(star_idx)!=memo.end() 
            && memo[port_idx]>=memo[star_idx])
          || 
          (memo.find(port_idx)!=memo.end() && memo.find(star_idx)==memo.end()))  {
          cout<<"port";
          port = new_port;
        } else {
          cout<<"starboard";
          star = new_star;
        }
      } else if (new_port>=0) {
        cout<<"port";
        port = new_port;
      } else if (new_star>=0) {
        cout<<"starboard";
        star = new_star;
      }
      cout<<endl;
    }
    if (T>0) cout<<endl;
	}
	return 0;
}