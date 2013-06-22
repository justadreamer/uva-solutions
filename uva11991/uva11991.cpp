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

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>

using namespace std;

typedef vector<int> vi;

int main(int argc, char* argv[])
{
	int n,m;
	map<int,vector<int> > rows;
	while (cin>>n>>m) {
		for (int pos=1;pos<=n;++pos) {
			int num;
			cin>>num;
			rows[num].push_back(pos);
		}
		while (m--) {
			int k,v;
			cin>>k>>v;
			if (k<=rows[v].size()) {
				cout<<rows[v][k-1]<<endl;
			} else {
				cout<<0<<endl;
			}
		}
	}
	return 0;
}