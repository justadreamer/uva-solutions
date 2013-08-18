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
	int T;
	cin>>T;
	while (T--) {
		int A,B,C;
		cin>>A>>B>>C;
		int x,y,z;
		bool sol = false;
		for (x = -100; x <= 100 && !sol; ++x) {
			for (y = -100; y <= 100 && !sol; ++y) {
				for (z = -100; z <= 100 && !sol; ++z) {
					if (x!=y && y!=z && x!=z && x+y+z==A && x*y*z==B && x*x+y*y+z*z==C) {
						cout<<x<<" "<<y<<" "<<z<<endl;
						sol = true;
					}
				}
			}
		}
		if (!sol) {
			cout<<"No solution."<<endl;
		}
	}
	return 0;
}