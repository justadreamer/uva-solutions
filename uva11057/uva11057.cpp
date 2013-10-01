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
		vi prices;
    while (N--) {
      int price; cin>>price;
      prices.push_back(price);
    }

    sort(prices.begin(),prices.end());
    int M; cin>>M;

    int ii,jj;
    for (int i=0;i<prices.size() && prices[i]<=M/2;++i) {
      for (int j=i+1;j<prices.size();++j) {
        if (prices[i]+prices[j]==M) {
          ii=i;jj=j;
        }
      }
    }

    cout<<"Peter should buy books whose prices are "<<prices[ii]<<" and "<<prices[jj]<<"."<<endl<<endl;
	}
	return 0;
}