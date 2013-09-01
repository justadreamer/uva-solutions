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

int main(int argc, char* argv[])
{
  int N;
  while (cin && cin>>N) {
    int n_tracks; cin>>n_tracks;
    int durations[n_tracks];
    for (int i=0;i<n_tracks;++i) {
      cin>>durations[i];
    }

    int max_sum = 0;
    int max_n = 0;
    for (int c=0;c<(1<<n_tracks);++c) {
      int sum = 0;
      for (int k=0;k<n_tracks;++k) {
        if (c & (1<<k)) {
          sum+=durations[k];
        }
      }
      if (sum<=N && sum>max_sum) {
        max_sum = sum;
        max_n = c;
      }
    }
    
    for (int k=0;k<n_tracks;++k) {
      if (max_n & (1<<k)) {
        cout<<durations[k]<<" ";
      }
    }
    cout<<"sum:"<<max_sum<<endl;
  }
	return 0;
}