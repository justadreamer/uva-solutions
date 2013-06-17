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

using namespace std;

typedef vector<int> vi;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
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
}

void TestCase::calc() {
}

void TestCase::output() {
}