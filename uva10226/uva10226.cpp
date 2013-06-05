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
private:
	void input();
	void output();
	void calc();
private:
	int count;
	map<string,int> mapping;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	cin.ignore();
	cin.ignore();
	for (int i=0;i<T;i++) {
		if (i!=0) {
			cout<<endl;
		}
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
	string in;
	count = 0;
	while (getline(cin,in) && in.length()>0) {
		++count;
		if (mapping.find(in)==mapping.end()) {
			mapping[in]=1;
		} else {
			++mapping[in];
		}
	}
}

void TestCase::calc() {
}

void TestCase::output() {
	for (map<string,int>::iterator i = mapping.begin();i!=mapping.end();++i) {
		float part = ((double)(i->second))/(double)count*100.0;
		cout<<i->first<<fixed<<setprecision(4)<<" "<<part<<endl;
	}
}