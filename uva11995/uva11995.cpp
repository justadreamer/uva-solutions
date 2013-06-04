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

class TestCase {
public:
	TestCase();
	bool dotest();
private:

};

int main(int argc, char* argv[])
{
	int T;
	while (true) {
		TestCase t;
		if (!t.dotest())
			break;
	}
	return 0;
}

TestCase::TestCase() {

}

bool TestCase::dotest() {
	int n;
	if (!(cin>>n))
		return false;
	stack<int> s;
	queue<int> q;
	priority_queue<int> pq;
	bool is[] = {true,true,true};
	bool& is_s = is[0];
	bool& is_q = is[1];
	bool& is_pq = is[2];
	for (int i=0;i<n;++i) {
		int op;
		int x;
		cin>>op>>x;
		if (op==1) {
			if (is_s) {
				s.push(x);
			}
			if (is_q) {
				q.push(x);
			}
			if (is_pq) {
				pq.push(x);
			}
		} else if (op==2) {
			if (is_s) {
				if (is_s = s.size() && s.top()==x)
					s.pop();
			}
			if (is_q) {
				if (is_q=q.size() && q.front()==x)
					q.pop();
			}
			if (is_pq) {
				if (is_pq=pq.size() && pq.top()==x)
					pq.pop();
			}
		}
	}
	int count = 0;
	for (int i=0;i<3;++i) {
		if (is[i])
			++count;
	}
	if (count>1)
		cout<<"not sure";
	else if (count==0)
		cout<<"impossible";
	else if (is_s)
		cout<<"stack";
	else if (is_q)
		cout<<"queue";
	else if (is_pq)
		cout<<"priority queue";
		
	cout<<endl;
	return true;
}