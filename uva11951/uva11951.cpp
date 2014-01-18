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

	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int N,M; long long K; cin>>N>>M>>K;
    long long P[N][M];
    for (int i=0;i<N;++i) for (int j=0;j<M;++j) {
      long long p; cin>>p;
      P[i][j]=p;
      if (i>0) P[i][j]+=P[i-1][j];
      if (j>0) P[i][j]+=P[i][j-1];
      if (i>0 && j>0) P[i][j]-=P[i-1][j-1];
    }

    long long min_p=0; int max_s=0;

    for (int i1=0;i1<N;++i1) {
      int max_height = N-i1;
      if (max_height*M<max_s) break;

      for (int j1=0;j1<M;++j1) {
        int max_width = M-j1;
        if (max_height*max_width<max_s) break;

        for (int i2=i1;i2<N;++i2) {
          int height = (i2-i1+1);
          if (height*max_width<max_s) continue;

          for (int j2=j1;j2<M;++j2) {
            int width = (j2-j1+1);
            int s = height*width;
            if (s<max_s) continue;

            long long p = P[i2][j2];
            if (i1>0) p-=P[i1-1][j2];
            if (j1>0) p-=P[i2][j1-1];
            if (i1>0 && j1>0) p+=P[i1-1][j1-1];

            if (p>K) break;

            if (s>max_s) {
              max_s = s;
              min_p = p;
            } else if (s==max_s && p<min_p) {
              min_p = p;
            }          
          }
        }
      }
    }

    cout<<"Case #"<<t<<": "<<max_s<<" "<<min_p<<endl;
	}
	return 0;
}