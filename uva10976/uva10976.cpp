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

typedef vector<pair<int,int> > vii;

int main(int argc, char* argv[])
{
	int k;
	while (cin>>k) {
    vii sol;
    int y = k+1;
    int x = 0;
    do {
      div_t r = div(k*y,y-k);
      x = r.quot;
      if (r.rem==0) {
        sol.push_back(make_pair<int,int>(x,y));
      }
    } while (x>k && x!=y++);
    cout<<sol.size()<<endl;
    for (int i=0;i<sol.size();++i) {
      cout<<"1/"<<k<<" = "<<"1/"<<sol[i].first<<" + "<<"1/"<<sol[i].second<<endl;
    }
	}
	return 0;
}