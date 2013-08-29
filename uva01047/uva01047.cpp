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

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int n; //n - overall number of towers 
int a; //a - number of towers to be actually build
vi towers;
vector<pair<vi, int> > common;
vector<si> combos;

void input() {
  towers.clear();

  for (int i=0;i<n;++i) {
    int n_cust; cin>>n_cust; towers.push_back(n_cust);
  }

  int m; cin>>m;
  
  common.clear();
  for (int i=0;i<m;++i) {
    int t; cin>>t;
    vi tower_idxs;
    for (int j=0;j<t;++j) {
      int tower; cin>>tower; tower_idxs.push_back(tower-1);  
    }

    int common_cust; cin>>common_cust;
    pair<vi,int> common_p = make_pair(tower_idxs,common_cust);
    common.push_back(common_p);
  }
}

void make_combos(si& combo,int start) {
  if (combo.size()==a) {
    combos.push_back(combo);
    return;
  }
  for (int i=start;i<n;++i) {
    combo.insert(i);
    make_combos(combo,i+1);
    combo.erase(i);
  }
}

int eval_combo(const si& combo) {
  int sum = 0;
  for (si::iterator i=combo.begin();i!=combo.end();++i) {
    sum+=towers[*i];
  }

  for (int i=0;i<common.size();++i) {
    int common_count = 0;
    vi& tower_idxs = common[i].first;
    for (int j=0;j<tower_idxs.size();++j) {
      if (combo.find(tower_idxs[j])!=combo.end()) {
        common_count++;
      }
    }
    if (common_count>1)
      sum -= (common_count-1) * common[i].second;
  }

  return sum;
}

void output_combo(const si& combo) {
  for (si::iterator i=combo.begin();i!=combo.end();++i) {
    cout<<" "<<*i+1;
  }
}

int main(int argc, char* argv[])
{
  int n_case = 0;
	while (cin>>n>>a && n && a) {
    input();
    combos.clear(); si combo; make_combos(combo,0);
    int max = 0;
    int max_ind = 0;
    for (int i=0;i<combos.size();++i) {
      int val = eval_combo(combos[i]);
      if (val>max) {
        max = val;
        max_ind = i;
      }
    }

    cout<<"Case Number  "<<++n_case<<endl;
    cout<<"Number of Customers: "<<max<<endl;
    cout<<"Locations recommended:";
    si& max_combo = combos[max_ind];
    output_combo(max_combo);
    cout<<endl<<endl;
	}
	return 0;
}