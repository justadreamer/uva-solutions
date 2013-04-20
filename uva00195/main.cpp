#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
private:
	string s;
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

struct Compare {
	bool operator()(const char& first,const char& second) {
		if (tolower(first)==tolower(second)) {
			return first < second;
		}
		return tolower(first)<tolower(second);
	}
} compare;

TestCase::TestCase() {
	input();
	calc();
	output();
}

void TestCase::input() {
	cin>>s;
}

void TestCase::output() {
	sort(s.begin(),s.end(),compare);
	cout<<s<<endl;
	while (next_permutation(s.begin(),s.end(),compare)) {
		cout<<s<<endl;
	}
}

void TestCase::calc() {
	
}
