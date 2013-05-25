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

using namespace std;

class TestCase {
public:
	TestCase(const string& _s);
private:
	void do_test();
private:
	void success();
	void failure();
	void out(const string& s);

private:
	string s;
	stack<int> matrioshkas;
};

int main(int argc, char* argv[])
{
	string in;
	while (getline(cin,in) && in.length()>0) {
		TestCase t(in);
	}
	return 0;
}

TestCase::TestCase(const string& _s) : s(_s){
	do_test();
}

void TestCase::do_test() {
	stringstream ss(s);
	bool succeeded = true;
	int n;
	while (ss>>n) {
		if (n<0) {
			matrioshkas.push(n);
		} else if (n>0) {
			int inner = 0;
			int top = 0;
			while (matrioshkas.size()>0 && (top = matrioshkas.top())>0) {
				inner+=top;
				matrioshkas.pop();
			}

			if (abs(top)!=n) {
				succeeded = false;
				break;
			} else {
				matrioshkas.pop();
				if (inner<n) {
					matrioshkas.push(n);
				} else {
					succeeded = false;
					break;
				}
			}

		}
	}
	if (succeeded && matrioshkas.size()==1)
		success();
	else
		failure();
}

void TestCase::success() {
	out(":-) Matrioshka!");
}

void TestCase::failure() {
	out(":-( Try again.");
}

void TestCase::out(const string& s) {
	cout<<s<<endl;
}