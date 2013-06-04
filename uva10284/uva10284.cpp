#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

const int SIZE  = 8;
const int FREE  = 0;
const int ATTACKED = 1;

class TestCase;
typedef void (TestCase::*func)(int,int,char);

class TestCase {
public:
	TestCase(const string& s);
	~TestCase();
private:
	void fill (const string& s);
	void output();
	void output_board();
	void calc();
	void calc_attack(int row, int col, char c);
	void calc_sum(int row, int col, char c);
	bool mark_attack(int row, int col);
	void cross_attack(int row, int col);
	void line_attack(int row, int col, int row_inc, int col_inc);
	void diag_cross_attack(int row, int col);
	bool is_within(int row, int col);
	void loop_thru(func f);
private:
	int** board;
	int result;
};

int main(int argc, char* argv[])
{
	string s;
	while (cin>>s) {
		TestCase t(s);

	}
	return 0;
}

TestCase::TestCase(const string& s) {
	board = new int* [SIZE];
	for (int i=0;i<SIZE;i++) {
		board[i] = new int [SIZE];
	}

	fill(s);
	calc();
	output();
}

TestCase::~TestCase() {
	for (int i=0;i<SIZE;i++) {
		delete [] board[i];
	}
	delete [] board;
}

void TestCase::fill(const string& s) {

	int row = SIZE-1;
	int col = 0;
	for (int i=0;i<s.length();i++) {
		char c = s[i];
		if (c=='/') {
			row--;
			col = 0;
			continue;
		} else if (isdigit(c)) {
			int k = c - '0';
			for (int j=0;j<k;j++) {
				board[row][col++]=FREE;
			}

		} else {
			board[row][col++]=c;
		}

	}
}

void TestCase::output_board() {
	for (int i=SIZE-1;i>=0;i--) {
		for (int j=0;j<SIZE;j++) {
			int c = board[i][j];
			if (isalpha(c)) {
				cout<<(char)c;
			} else {
				cout<<c;
			}
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void TestCase::output() {
	cout<<result<<endl;
}

void TestCase::loop_thru(func f) {
	for (int i=SIZE-1;i>=0;i--) {
		for (int j=0;j<SIZE;j++) {
			(this->*f)(i,j,board[i][j]);
		}
	}
}

void TestCase::calc_sum(int row, int col, char c) {
	if (c==FREE)
		result++;
}

void TestCase::calc() {
	loop_thru(&TestCase::calc_attack);
	result = 0;
	loop_thru(&TestCase::calc_sum);
}

void TestCase::calc_attack(int row, int col, char c) {
	if (!isalpha(c))
		return;

	if (c=='p') {
		mark_attack(row-1,col-1);
		mark_attack(row-1,col+1);
	} else if (c=='P') {
		mark_attack(row+1,col-1);
		mark_attack(row+1,col+1);
	} else if (toupper(c)=='R') {
		cross_attack(row,col);
	} else if (toupper(c)=='B') {
		diag_cross_attack(row,col);
	} else if (toupper(c)=='N') {
		mark_attack(row+1,col+2);
		mark_attack(row+1,col-2);
		mark_attack(row+2,col+1);
		mark_attack(row+2,col-1);
		mark_attack(row-2,col+1);
		mark_attack(row-2,col-1);
		mark_attack(row-1,col+2);
		mark_attack(row-1,col-2);
	} else if (toupper(c)=='Q') {
		cross_attack(row,col);
		diag_cross_attack(row,col);
	} else if (toupper(c)=='K') {
		for (int i=row-1;i<row+2;i++) {
			for (int j=col-1;j<col+2;j++) {
				mark_attack(i,j);
			}
		}
	}
}

bool TestCase::is_within(int row, int col) {
	return row>=0 && row < SIZE && col>=0 && col < SIZE;
}

bool TestCase::mark_attack(int row, int col) {
	if (is_within(row,col) && board[row][col]==FREE) {
		board[row][col]=ATTACKED;
		return true;
	}
	return false;
}

void TestCase::cross_attack(int row, int col) {
	line_attack(row,col,1,0);
	line_attack(row,col,-1,0);
	line_attack(row,col,0,1);
	line_attack(row,col,0,-1);
}

void TestCase::line_attack(int row, int col, int row_inc, int col_inc) {
	do  {
		row+=row_inc;
		col+=col_inc;
		mark_attack(row,col);
	} while (is_within(row,col) && !isalpha(board[row][col]));
}

void TestCase::diag_cross_attack(int row, int col) {
	line_attack(row,col,1,1);
	line_attack(row,col,-1,1);
	line_attack(row,col,-1,-1);
	line_attack(row,col,1,-1);
}