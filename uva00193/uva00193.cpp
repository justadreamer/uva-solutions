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

void build(int n, vector<set<int> >& adjacent_nodes, vector<vi>& solutions, vi& solution) {
  int start = solution.size() ? solution.back()+1 : 0;
  bool add_solution = true;
  for (int i=start;i<n;++i) {
    bool has_adjacent = false;
    for (int j=0;j<solution.size();++j) {
      if (adjacent_nodes[i].find(solution[j])!=adjacent_nodes[i].end()) {
        has_adjacent = true;
        break;
      }
    }
    if (!has_adjacent) {
      add_solution = false;
      solution.push_back(i);
      build(n,adjacent_nodes,solutions,solution);
      solution.pop_back();
    }
  }

  if (add_solution) {
    solutions.push_back(solution);
  }
}

int main(int argc, char* argv[])
{
	int m;
	cin>>m;
	while (m--) {
		int n,k; cin>>n>>k;
    vector<set<int> > adjacent_nodes(n);
    while (k--) {
      int n1,n2; cin>>n1>>n2; n1--; n2--;
      adjacent_nodes[n1].insert(n2);
      adjacent_nodes[n2].insert(n1);
    }

    vector<vi> solutions;
    vi solution;
    build(n,adjacent_nodes,solutions,solution);

    int max_size = solutions[0].size();
    int max_size_idx = 0;
    for (int i=0;i<solutions.size();++i) {
      if (solutions[i].size()>max_size) {
        max_size = solutions[i].size();
        max_size_idx = i;
      }
    }

    cout<<max_size<<endl;
    vi& sol = solutions[max_size_idx];
    for (int i=0;i<sol.size();++i) {
      if (i>0) cout<<" ";
      cout<<sol[i]+1;
    }
    cout<<endl;
	}
	return 0;
}