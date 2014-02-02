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

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

	int T; cin>>T;
	for (int t=1;t<=T;++t) {
	  int N; cin>>N;
    vi H(N,0);
    vi L(N,0);
    for (int i=0;i<N;++i) cin>>H[i];
    for (int i=0;i<N;++i) cin>>L[i];
    int lis = 0; vi LI(N,0); 
    int lds = 0; vi LD(N,0);
    for (int i=0;i<N;++i) {
      int max_lis = 0; int max_lds = 0;
      for (int j=0;j<i;++j) {
        if (H[j]<H[i] && LI[j]>max_lis) max_lis = LI[j];
        else if (H[j]>H[i] && LD[j]>max_lds) max_lds = LD[j];
      }
      LI[i] = max_lis + L[i];
      LD[i] = max_lds + L[i];
      if (LI[i]>lis) lis = LI[i];
      if (LD[i]>lds) lds = LD[i];
    }
    cout<<"Case "<<t<<". ";
    if (lis>=lds) {
      cout<<"Increasing ("<<lis<<"). Decreasing ("<<lds<<")."<<endl;
    } else {
      cout<<"Decreasing ("<<lds<<"). Increasing ("<<lis<<")."<<endl;
    }
	}
	return 0;
}