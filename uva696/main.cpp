#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class TestCase {
public:
	TestCase();
	bool is_done();
private:
	void input();
	void output();
	int calc_knights();

private:
	int m,n;
};

int main(int argc, char* argv[])
{
	while(true ){
		TestCase t;
		if (t.is_done())
			break;
	}
	return 0;
}

TestCase::TestCase() {
	input();
	output();
}

void TestCase::input() {
	cin>>m>>n;
}

void TestCase::output() {
	if (!is_done()) {
		cout<<calc_knights()<<" knights may be placed on a "<<m<<" row "<<n<<" column board."<<endl;
	}
}

int TestCase::calc_knights() {
	int result = 0;
	//if there is even number of cols:
	if (m==2 || n==2) {
		int mn = m*n;
		result = mn/8 * 4 + min(4, mn % 8);
	} else if (m==1 || n==1) {
		result = m*n;
	} else if (n%2==0) {
		result = m*n/2;
	} else if (m%2==0) { 	//for even number of rows:
		result = m/2*n;
	} else {
		result = floor((double)m/2)*floor((double)n/2)+ceil((double)m/2)*ceil((double)n/2);
	}
	return result;
}

bool TestCase::is_done() {
	return m==0 && n==0;
}