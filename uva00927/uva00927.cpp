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

using namespace std;

typedef vector<int> vi;

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	while (T--) {
		int i;
		cin>>i; ++i;
		vi c;
		while (i--) {
			int cj;
			cin>>cj;
			c.push_back(cj);
		}
		int d,k;
		cin>>d;
		cin>>k;
		long long sum = 0;
		for (int n=1;n<=k;++n) {
			sum+=n*d;
			if (sum>=k) {
				long long an = 0;
				for (int j=0;j<c.size();++j) {
					an += ((long long)c[j])*((long long)pow((float)n,(float)j));
				}
				cout<<an<<endl;
				break;
			}
		}
	}
	return 0;
}