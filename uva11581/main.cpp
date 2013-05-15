#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <set>
#include <iomanip>
#include <list>

using namespace std;
const int S = 3;

struct Grid {
	int g[S][S];

	Grid f(int n) {
		Grid g1;
		if (n==0) {
			g1 = *this;
		} else {
			g1 = f(n-1);
			g1.f();
		}
		return g1;
	}

	Grid f() {
		Grid g1;
		for (int i=0;i<S;i++) {
			for (int j=0;j<S;j++) {
				g1.g[i][j]=sum_adj(i,j);
			}
		}
		*this = g1;
	}

	/*int k(const Grid& h) {
		Grid g1 = *this;
		int count = 0;
		for (int i=0;i<50;i++) {
			if (g1.f(i)==h)
				count++;
		}
		return count;
	}*/

	bool is_finite() {
		return f(1)!=*this;
	}

	void input() {
		for (int i=0;i<S;i++) {
			for (int j=0;j<S;j++) {
				int d;
				scanf("%1d",&d);
				g[i][j]=d;
			}
		}
	}

	void output() {
		for (int i=0;i<S;i++) {
			for (int j=0;j<S;j++) {
				int d;
				cout<<g[i][j];
			}
			cout<<endl;
		}	
	}

	bool operator==(const Grid& right) const {
		bool equal = true;
		for (int i=0;i<S;i++) {
			for (int j=0;j<S;j++) {
				if (g[i][j]!=right.g[i][j]) {
					equal = false;
					break;
				}
			}
		}
		return equal;
	}

	bool operator!=(const Grid& right) const {
		return !operator==(right);
	}

private:
	int sum_adj(int i, int j) {
		int sum=0;
		if (i>0) {
			sum+=g[i-1][j];
		}
		if (i<S-1) {
			sum+=g[i+1][j];
		}
		if (j>0) {
			sum+=g[i][j-1];
		}
		if (j<S-1) {
			sum+=g[i][j+1];
		}
		return sum % 2;
	}
};

int main(int argc, char* argv[])
{
	int T = 0;
	cin>>T;
	for (int i=0;i<T;i++) {
		cin.ignore();
		Grid g;
		g.input();
		int j=0;
		while (g.f(j).is_finite()) {
			j++;
		}
		cout<<j-1<<endl;
	}
	return 0;
}