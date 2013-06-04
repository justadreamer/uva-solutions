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
	TestCase(int _N);
private:
	void input();
	void output();
	void calc();
private:
	int N;
	int swaps_count;
	vector<int> numbers;
	void do_swap(int i,int j);
};

int main(int argc, char* argv[])
{
	int N;
	while (cin>>N) {
		TestCase t(N);
	}
	return 0;
}

TestCase::TestCase(int _N) : N(_N),swaps_count(0) {
	input();
	calc();
	output();
}

void TestCase::do_swap(int i,int j) {
	swap(numbers[i],numbers[j]);
	++swaps_count;
}

void TestCase::input() {
	for (int i=0;i<N;++i) {
		int n;
		cin >> n;
		numbers.push_back(n);
	}
}

void TestCase::calc() {
	for (int i=0;i<N;++i) {
		bool did_swap = false;
		for (int j=i+1;numbers[j]<numbers[j-1] && j<N;++j) {
			do_swap(j,j-1);
			did_swap = true;
		}
		if (did_swap)
			--i;
	}
}

void TestCase::output() {
	cout<<swaps_count<<endl;
}