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
	int r;
	cin >> r;
	vector<int> streets(r,0);

	for (size_t i=0;i<r;i++) {
		int s;
		cin >> s;
		streets[i]=s;
	}
	sort(streets.begin(),streets.end());
	size_t med = r / 2;
	int mindist = r > 0 ? INT_MAX : 0;
	for (size_t k=med;k<=med+1 && k<streets.size();++k) {
		int dist = 0;
		int base = streets[k];
		for (int i=0;i<r;++i) {
			dist+=abs(base-streets[i]);
		}
		if (dist<mindist)
			mindist = dist;
	}
	cout<<mindist<<endl;
}

void TestCase::output() {
}

void TestCase::calc() {
	
}
