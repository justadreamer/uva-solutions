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
	int f;
	while (cin>>f && f) {
    int r; cin>>r;
    vi f_spr,r_spr;
    while (f--) {
      int spr; cin>>spr; f_spr.push_back(spr);
    }
    while (r--) {
      int spr; cin>>spr; r_spr.push_back(spr);
    }
    vector<float> d;
    for (int i=0;i<f_spr.size();++i) {
      for (int j=0;j<r_spr.size();++j) {
        d.push_back((float)r_spr[j]/f_spr[i]);
      }
    }

    sort(d.begin(),d.end());

    float max_s = d[1]/d[0];
    for (int i=1;i<d.size();++i) {
      float temp = d[i]/d[i-1];
      if (temp>max_s) {
        max_s = temp;
      }
    }
    printf("%.2f\n",max_s);
	}
	return 0;
}