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
#include <iterator>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

void reconstruct_print(int end, vi const & s, vi const & p) {
  stack<int> st;
  for (int x = end; x>=0; x=p[x]) st.push(s[x]);
  for (;!st.empty();st.pop()) cout<<st.top()<<endl;
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

  vi A;
  int n;
	while (cin>>n) A.push_back(n);

  vi L(A.size(),0);
  vi L_id(A.size(),0);
  vi P(A.size(),0);
  int lis = 0; int lis_end = 0;
  for (int i=0;i<A.size();++i) {
    vi::iterator Lend = L.begin(); advance(Lend,lis);
    int pos = distance(L.begin(),lower_bound(L.begin(),Lend,A[i]));
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos-1] : -1;
    if (pos+1>lis) {
      lis = pos+1;
      lis_end = i;
    }
  }

  cout<<lis<<endl;
  cout<<"-"<<endl;
  reconstruct_print(lis_end,A,P);
	return 0;
}