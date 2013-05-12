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

using namespace std;
 
class TestCase {
public:
	TestCase();
private:
	void do_work();
private:
	int K;
	static const int N_CHARS = 256;
	int char_values[N_CHARS];

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
	do_work();
}

void TestCase::do_work() {

	for (int i=0;i<N_CHARS;i++) {
		char_values[i]=0;
	}
	int K = 0;
	cin >> K;
	cin.ignore();
	for (int i=0;i<K;i++) {
		char c;
		int value;
		scanf("%c %d",&c,&value); //to account for space character
		cin.ignore(); //to go to the next line
		char_values[(int)c]=value;
	}
	cin >> K;
	cin.ignore(); //to go to the next line

	unsigned long long cost = 0 ;
	for (int i=0;i<K;i++) {
		unsigned char c;
		while ((c = cin.get()) != '\n' && cin) {
			cost += char_values[(int) c];
		}
	}

	//output:
	printf("%.2lf$\n",cost/100.0);
}