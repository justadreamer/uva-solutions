#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
	int calc_knights();
private:
	int m,n;
	char piece;
	int result;
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
	cin>>piece;
	cin>>m;
	cin>>n;
}

void TestCase::output() {
	cout<<result<<endl;
}

void TestCase::calc() {
	if (piece=='r') {
		result = min(m,n);
	} else if (piece=='K') {
		result = ceil((double)m/2)*ceil((double)n/2);
	} else if (piece=='Q') {
		result = min(m,n);
	} else if (piece=='k') {
		result = calc_knights();
	}
}

int TestCase::calc_knights() {
	//if there is even number of cols:
	if (n%2==0) {
		return m*n/2;
	}

	
	//for even number of rows:
	if (m%2==0) {
		return m/2*n;
	}
	
	//if number of cols & rows is odd:	
	return floor(m/2)*floor(n/2)+ceil(m/2)*ceil(n/2);
	
}