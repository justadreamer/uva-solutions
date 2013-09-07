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

int sum(int num[], int n, int used) {
  int _sum = 0;
  for (int i=0;i<n;++i) {
    if (used & (1<<i)) {
      _sum += num[i];
    }
  }
  return _sum;
}

void print(vi sol) {
  for (int i=0;i<sol.size();++i) {
    if (i>0) 
      cout<<"+";
    cout<<sol[i];
  }
  cout<<endl;
}

typedef set<vi,greater<vi> > gset;
gset sols;

void add(int num[], int n, int used) {
  vi sol;
  for (int i=0;i<n;++i) {
    if (used & (1<<i)) {
      sol.push_back(num[i]);
    }
  }
  sols.insert(sol);
}

void backtrack(int num[], int n, int t, int l, int used) {
  int s = sum(num,n,used);

  if (s==t) {
    add(num,n,used);
    return;
  } else if (s<t) {
    for (int i=l;i<n;++i) {
      int mask = 1<<i;
      if (0 == (used & mask)) {
        used |= mask;
        backtrack(num,n,t,l+1,used);
        used ^= mask;
      }
    }
  }
}



int main(int argc, char* argv[])
{
	int t,n;
	while (cin>>t>>n && t && n) {
    sols.clear();
		int num [n];
    //input
    for (int i=0;i<n;++i) cin>>num[i];
    //building solutions
    backtrack(num,n,t,0,0);
    //output
    cout<<"Sums of "<<t<<":"<<endl;
    if (sols.size()==0) {
      cout<<"NONE"<<endl;
    } else {
      for (gset::iterator i=sols.begin();i!=sols.end();++i) {
        print(*i);
      }
    }  
	}
	return 0;
}