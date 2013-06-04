#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class TestCase {
public:
	TestCase(int _t);
private:
	void input();
	void output();
	void calc();
	bool read_square_and_compare(bool by_line,bool start_from_lower_right,const string& s_compare);
private:
	vector<vector<char> > square;
	string s;
	int t;
	int dimension;
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	//to go to the next line:
	string newline;
	getline(cin,newline);
	for (int i=0;i<T;i++) {
		TestCase(i+1);
	}
	return 0;
}

TestCase::TestCase(int _t):t(_t),dimension(0) {
	input();
	calc();
	output();
}

void TestCase::input() {
	getline(cin,s);
}

void TestCase::output() {
	cout<<"Case #"<<t<<":"<<endl;
	if (dimension) {
		cout<<dimension<<endl;
	} else {
		cout<<"No magic :("<<endl;
	}
}

void TestCase::calc() {
	//sanitize from punctuation etc.
	stringstream ssanitized;
	for (int i=0;i<s.size();++i) {
		if (isalpha(s[i])) {
			ssanitized<<s[i];
		}
	}
	string sanitized;
	ssanitized>>sanitized;

	//check if it is a square:
	double sq = sqrt(sanitized.size());
	if (sq!=round(sq)) 
		return;
	dimension = (int)sq;
	//form a square
	for (int i=0;i<dimension;++i) {
		vector<char> row;
		for (int j=0;j<dimension;++j) {
			row.push_back(sanitized[i*dimension+j]);
		}
		square.push_back(row);
	}


	if (!(read_square_and_compare(false,false,sanitized)  &&
		read_square_and_compare(true,true,sanitized) &&
		read_square_and_compare(false,true,sanitized))) {
		dimension = 0;
	}
}

bool TestCase::read_square_and_compare(bool by_line,bool start_from_lower_right,const string& s_compare) {
	stringstream from_square;
	int start = 0;
	int end = dimension;
	int inc = 1;
	if (start_from_lower_right) {
		start = dimension-1;
		end = -1;
		inc = -1;
	}

	for (int i=start;i!=end;i=i+inc) {
		for (int j=start;j!=end;j=j+inc) {
			from_square<<(by_line ? square[i][j] : square[j][i]);
		}
	}

	string s_from_square;
	from_square>>s_from_square;
	return s_from_square==s_compare;
}
