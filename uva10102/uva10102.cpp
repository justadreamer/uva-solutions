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
	int M;
	while (cin>>M && M>0) {
		vector<vi> field;
    for (int i=0;i<M;++i) {
      vi row;
      for (int j=0;j<M;++j) {
        int c; scanf("%1d",&c); row.push_back(c);
      }
      field.push_back(row);
    }

    int max_d=0;
    for (int i=0;i<M;++i) {
      for (int j=0;j<M;++j) {
        int min_d=2*M;
        if (field[i][j]!=1) continue;
        for (int ii=0;ii<M;++ii) {
          for (int jj=0;jj<M;++jj) {
            if (field[ii][jj]==3) {
              int d = abs(ii-i)+abs(jj-j);
              if (d<min_d) min_d = d;
            }
          }
        }

        if (min_d>max_d) max_d = min_d;
      }
    }

    cout<<max_d<<endl;
	}
	return 0;
}