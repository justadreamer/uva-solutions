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
	int T;
	cin>>T;
	while (T--) {
		vi a;
    int na; cin>>na;
    while (na--) {
      int ai; cin>>ai; a.push_back(ai);
    }

    int s = 0;
    for (int i=1; i<a.size(); ++i) {
      for (int j=0; j<i; ++j) {
        if (a[j]<=a[i])
          ++s;
      }
    }
    cout<<s<<endl;
	}
	return 0;
}