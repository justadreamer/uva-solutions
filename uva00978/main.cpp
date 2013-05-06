#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <set>

using namespace std;

struct more {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

typedef multiset<int,more> mset;

class TestCase {
public:
	TestCase();
private:
	void input();
	void output();
	void calc();
	void fill_multiset(mset& m, int N);
	void fight();
	void output_multiset(const mset& m);
private:
	int B;
	int SB;
	int SG;
	mset blue;
	mset green;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		if (i>0) {
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

void TestCase::fill_multiset(mset& m, int N) {
	for (int i=0;i<N;i++) {
		int p;
		cin>>p;
		m.insert(p);
	}
}

void TestCase::input() {
	cin>>B>>SG>>SB;
	fill_multiset(green,SG);
	fill_multiset(blue,SB);
}

void TestCase::output_multiset(const mset& m) {
	for (mset::iterator it=m.begin();it!=m.end();it++) {
		cout<<*it<<endl;
	}
}

void TestCase::output() {
	if (green.size()) {
		cout<<"green wins"<<endl;
		output_multiset(green);
	} else if (blue.size()) {
		cout<<"blue wins"<<endl;
		output_multiset(blue);
	} else {
		cout<<"green and blue died"<<endl;
	}
}

void TestCase::fight() {
	int battlefields = min(green.size(),blue.size());
	battlefields = min(battlefields,B);
	int i;
	vector<mset::iterator> green_vec,blue_vec;
	mset::iterator green_it=green.begin(),blue_it=blue.begin();
	for (i=0;i<battlefields;i++,green_it++,blue_it++) {
		green_vec.push_back(green_it);
		blue_vec.push_back(blue_it);
	}

	for (i=0;i<green_vec.size();i++) {
		green_it = green_vec[i];
		blue_it = blue_vec[i];
		int diff = *green_it - *blue_it;
		green.erase(green_it);
		blue.erase(blue_it);
		if (diff<0) {
			blue.insert(-diff);
		} else if (diff>0) {
			green.insert(diff);
		}
	}
}

void TestCase::calc() {
	while (blue.size() && green.size()) {
		fight();
	}
}