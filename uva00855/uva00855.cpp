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
class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	int F;
	vector<int> streets;
	vector<int> avenues;
	size_t med;
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
	int S,A;
	cin>>S>>A>>F;
	for (int i=0;i<F;i++) {
		cin>>S>>A;
		streets.push_back(S);
		avenues.push_back(A);
	}
}


void TestCase::calc() {
	sort (streets.begin(),streets.end());
	sort (avenues.begin(),avenues.end());
	med = (F - 1) / 2;
}


void TestCase::output() {
	cout<<"(Street: "<< streets[med] << ", Avenue: "<< avenues[med] <<")"<<endl;
}