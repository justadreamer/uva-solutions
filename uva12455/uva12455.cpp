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

class TestCase {
public:
	TestCase() {
		input();
		calc();
	}
private:
	void input() {
		cin>>n;
		cin>>p;
		for (int i=0;i<p;++i) {
			int bar;
			cin>>bar;
			bars.push_back(bar);
		}
	}

	void calc() {
		for (int N=0;N<(1<<p);++N) {
			int sum=0;
			for (int i=0;i<p;++i) {
				if (N & (1<<i)) {
					sum+=bars[i];
				}
			}
			if (sum==n) {
				cout<<"YES"<<endl;
				return;
			}
		}
		cout<<"NO"<<endl;
	}

private:
	int n;
	int p;
	vector<int> bars;
};


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		TestCase();
	}
	return 0;
}