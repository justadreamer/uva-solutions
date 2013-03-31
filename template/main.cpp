#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

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

void TestCase::output() {
}

void TestCase::calc() {
	
}