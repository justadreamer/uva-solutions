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

int main(int argc, char* argv[])
{
	int M,N;
	while (cin>>M>>N && M && N) {
		vector<vi> H;
    for (int i=0;i<M;++i) {
      vi row;
      for (int j=0;j<N;++j) {
        int h; cin>>h; row.push_back(h);
      }
      H.push_back(row);
    }

    int Q; cin>>Q;
    while (Q--) {
      int lo,hi; cin>>lo>>hi;
      int s = 0;
      for (int row=0;row<M;++row) {
        vi& row_data = H[row];
        vi::iterator lo_it = lower_bound(row_data.begin(),row_data.end(),lo);
        int col = distance(row_data.begin(),lo_it);

        for (int new_s = s+1; ((row + new_s - 1) < M) && ((col + new_s - 1) < N);++new_s) {
          int diag_row = row + new_s - 1;
          int diag_col = col + new_s - 1;

          if (H[diag_row][diag_col] <= hi) {
            s = new_s;
          } else {
            break;
          }
        }
      }
      cout<<s<<endl;
    }
    cout<<"-"<<endl;
	}
	return 0;
}