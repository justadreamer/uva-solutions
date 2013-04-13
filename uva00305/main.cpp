#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class TestCase {
public:
	TestCase(int k);
	~TestCase();
private:
	void init();
	void output();
	void calc();
private:
	int k;
	int* circle;
	static const int FREE = 0;
	static const int OCCUPIED = 1;
	int result;
};

/* precalc:

int main(int argc, char* argv[])
{
	int k;
	int answers [] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
	while (cin>>k && k>0) {
		cout<<answers[k]<<endl;
	}
	return 0;
}
*/

int main(int argc, char* argv[])
{
	int k;
	while (cin>>k && k>0) {
		TestCase t(k);
	}
	return 0;
}


TestCase::TestCase(int _k):k(_k) {
	result = 0;
	circle = new int [2*k+1];
	calc();
	output();
}

void TestCase::init() {
	for (int i =0;i<=2*k;i++) {
		circle[i]=FREE;
	}
}

void TestCase::calc() {
	int m = k;
	while (true) {
		++m;
		init();
		int executed = 0;
		int cur = 1;
		bool is_k_executed = true;

		while (executed<k) {
			int free_counter = 0;
			while (free_counter<m) {
				if (circle[cur]==FREE) {
					free_counter++;
				}
				if (free_counter<m) {
					cur=(cur+1)%(2*k+1); if (cur==0) cur = 1;
				}
			}
			
			if (cur<=k && executed<k) {
				is_k_executed=false;
				break;
			}
			circle[cur]=OCCUPIED;
			++executed;
		}
		if (is_k_executed) {
			result = m;
			break;
		}
		if ((m/k)%2==0) {
			m = (m/k+1)*k;
		}
	}
}

void TestCase::output() {
	cout<<result<<endl;
}

TestCase::~TestCase () {
	delete [] circle;
}