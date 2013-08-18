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

int min(int a,int b,int c) {
	return a<=b ? (a<=c ? a : c) : (b<=c ? b : c);
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	while (T--) {
		int A,B,C;
		cin>>A>>B>>C;
		int x,y,z;
		bool sol = false;
		for (x = -22; x <= 22 && !sol; ++x) { if (x<=A && x<=B && x*x<=C)
			for (y = x+1; y <= 100 && !sol; ++y) {
				if (x!=y && x+y<=A && x*y<=B && x*x+y*y<=C) {
					z = A-x-y;
					if (y!=z && x!=z && x+y+z==A && x*y*z==B && x*x+y*y+z*z==C) {
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