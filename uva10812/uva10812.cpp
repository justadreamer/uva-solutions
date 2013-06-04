#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	int s;
	int d;
	int a;
	int b;
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
	cin>>s>>d;
}

void TestCase::output() {
	if (a<0 || b<0) {
		cout<<"impossible";
	} else {
		cout<<a<<" "<<b;
	}
	cout<<endl;
}

void TestCase::calc() {
	int sd = s+d;
	if (sd % 2 !=0) {
		a = -1;
		b = -1;
		return;
	}
	a = sd/2;
	b = s - a;
	if (b>a) {
		swap(a,b);
	}
}