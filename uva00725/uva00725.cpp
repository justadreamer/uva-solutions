#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>

using namespace std;

typedef vector<int> vi;

class TestCase {
public:
	TestCase(int N) {
		process(N);
	}
private:
	void process(int N) {
		bool did_output = false;
		for (int fghij=1234;fghij<=98765/N;++fghij) {
			int abcde = fghij*N;
			int used = (fghij<10000);
			int tmp = fghij; while (tmp) {used |= 1<<(tmp%10); tmp/=10;}
			tmp = abcde; while (tmp) {used |= 1<<(tmp%10); tmp/=10;}
			if (used==(1<<10)-1) {
				did_output = true;
				printf("%05d / %05d = %d\n",abcde,fghij,N);
			}
		}
		if (!did_output) {
			cout<<"There are no solutions for "<<N<<"."<<endl;
		}
	}
};


int main(int argc, char* argv[])
{
	int N;
	bool is_first = true;
	while (cin>>N && N>0) {
		if (!is_first) {
			cout<<endl;
		} else {
			is_first = false;
		}
		TestCase t(N);
	}
	return 0;
}