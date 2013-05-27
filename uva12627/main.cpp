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

#define p(n,k) (int)pow((double)n,(double)k)

using namespace std;
long long S[31];

class TestCase {
public:
	TestCase(int _t);
private:
	void input();
	void output();
	void calc();
private:
	int K,A,B;
	int t;
	long long N;
	long long C(int a, int b, int k);
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	S[0]=1;
	for (int i=1;i<=30;i++) {
		S[i]=3*S[i-1];
	}
	for (int i=0;i<T;++i) {
		TestCase t(i+1);
	}
	return 0;
}

TestCase::TestCase(int _t) : t(_t) {
	input();
	calc();
	output();
}

void TestCase::input() {
	cin>>K>>A>>B;
}

void TestCase::calc() {
	N=C(A,B,K);
}

void TestCase::output() {
	cout<<"Case "<<t<<": "<<N<<endl;
}

long long TestCase::C(int a, int b, int k) {
	if (a==1 && b==p(2,k)) {
		return S[k];
	}

	long long p2k1 = p(2,k-1);
	if (a<=p2k1 && b>p2k1) {
		return 2*C(a,p2k1,k-1) + C(1,b-p2k1,k-1);
	}

	if (a<=p2k1) {
		return 2*C(a,b,k-1);
	}

	return C(a-p2k1,b-p2k1,k-1);
}