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
typedef set<int> si;

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
  int const FERTILE = 1;
  int const INFERTILE = 2;
	for (int t=1;t<=T;++t) {
		int N; cin>>N;
    vi field;
    int fertile = 0;
    for (int i=0;i<N;++i) {
      char c; cin>>c; 
      if (c=='.') {
        field.push_back(FERTILE);
        ++fertile;
      } else {
        field.push_back(INFERTILE);
      }
    }

    int crows = 0;
    int idx =0;
    while (fertile>0 && idx<field.size()) {
      if (field[idx]==FERTILE) {
        ++crows;
        idx+=2;
        for (int i = idx-2;i<idx+1;++i) {
          if (field[i]==FERTILE) {
            --fertile;
          }
        }
      }
      ++idx;
    }
    cout<<"Case "<<t<<": "<<crows<<endl;
	}
	return 0;
}