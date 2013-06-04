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
#include <climits>
#include <stack>
#include <queue>

using namespace std;

const int FULL = 1;
const int EMPTY = 0;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	int N,S,Q;
	vector<queue<int> > B;
	stack<int> s;
	int cargos;
	int delivered;
	int time;
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

TestCase::TestCase() {
	input();
	calc();
	output();
}

void TestCase::input() {
	cin>>N>>S>>Q;
	delivered = 0;
	cargos=0;
	time = 0;
	for (int i=0;i<N;++i) {
		queue<int> b;
		int n;
		cin>>n;
		cargos+=n;
		for (int j=0;j<n;++j) {
			int cargo;
			cin>>cargo;
			b.push(cargo);
		}
		B.push_back(b);
	}
}

void TestCase::calc() {
	int current = 0;
	int count=0;
	bool has_done_first_move = false;
	while (delivered<cargos) {
		if (!has_done_first_move) {
			has_done_first_move = true;
		} else {
			time+=2;
		}

		while(s.size()) {
			if (s.top()==current+1) {
				++delivered;
			} else if (B[current].size()<Q) {
				B[current].push(s.top());
			} else {
				break;
			}
			s.pop();
			++time;
		}
		while (B[current].size() && s.size() < S) {
			s.push(B[current].front());
			B[current].pop();
			++time;
		}
		current=(current+1) % N;
	}
}

void TestCase::output() {
	cout<<time<<endl;
}