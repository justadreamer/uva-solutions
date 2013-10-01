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
  int N;
	while (cin>>N) {
		set<int> prices;
    while (N--) {
      int price; cin>>price;
      prices.insert(price);
    }

    int M; cin>>M;

    int pi,pj;
    for (set<int>::iterator i=prices.begin();i!=prices.end() && *i<=M/2;++i) {
      int p = M-*i;
      set<int>::iterator j = prices.find(p);
      if (j!=prices.end()) {
        pi = *i;
        pj = *j;
      }
    }

    cout<<"Peter should buy books whose prices are "<<pi<<" and "<<pj<<"."<<endl<<endl;
	}
	return 0;
}