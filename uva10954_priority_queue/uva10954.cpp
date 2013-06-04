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
	bool input();
	void output();
	void calc();
private:
	priority_queue<int,vector<int>,greater<int> > numbers;
	int cost;
};

int main(int argc, char* argv[])
{
	int T;
	while(true) {
		TestCase t;
		if (!t.dotest())
			break;
	}
	return 0;
}

TestCase::TestCase() {
	
}

bool TestCase::dotest() {
	if (!input()) {
		return false;
	}
	calc();
	output();
	return true;
}

bool TestCase::input() {
	int n;
	cin>>n;

	if (!n)
		return false;
	for (int i=0;i<n;++i) {
		int number;
		cin>>number;
		numbers.push(number);
	}
	return true;
}

void TestCase::calc() {
	cost = 0;
	int sum = 0;
	while (numbers.size()>1) {
		int sum = numbers.top();
		numbers.pop();
		sum+=numbers.top();
		numbers.pop();
		cost+=sum;
		numbers.push(sum);
	}
}

void TestCase::output() {
	cout<<cost<<endl;
}