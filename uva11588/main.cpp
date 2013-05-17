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

using namespace std;
typedef pair<char,int> pci;
class TestCase {
public:
	TestCase(int _n_case);
private:
	void input();
	void output();
	void calc();
private:
	int M,N;
	static int const MAX_LETTERS = 26;
	int letter_counts[MAX_LETTERS];
	int file_size;
	int n_case;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		TestCase t(i);
	}
	return 0;
}

TestCase::TestCase(int _n_case) : n_case(_n_case) {
	input();
	calc();
	output();
}

void TestCase::input() {
	int R,C;
	cin>>R>>C>>M>>N;
	for (int i=0;i<MAX_LETTERS;i++) {
		letter_counts[i]=0;
	}
	for (int i=0;i<R;++i) {
		for (int j=0;j<C;++j) {
			char c;
			cin>>c;
			++letter_counts[c -'A'];
		}
		cin.ignore();
	}
}

void TestCase::calc() {
	sort(letter_counts,letter_counts+MAX_LETTERS);
	int max = letter_counts[MAX_LETTERS-1];
	file_size = 0;
	for (int i=0;i<MAX_LETTERS;++i) {
		int coef = letter_counts[i]==max ? M : N;
		file_size+=coef*letter_counts[i];
	}
}

void TestCase::output() {
	cout<<"Case "<<n_case+1<<": "<<file_size<<endl;
}