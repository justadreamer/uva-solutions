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

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>

using namespace std;

typedef vector<int> vi;
const int SIZE = 8;


int fixed_row,fixed_col;//fixed queen position
int n;
int cols[SIZE+1];

void check_and_output(int cols[],int col);

void output() {
	cout<<setw(2)<<++n<<"      ";
	for (int i=1;i<=SIZE;++i) {
		if (i>1) cout<<" ";
		cout<<cols[i];
	}
	cout<<endl;
}

bool has_conflicts(int row,int col) {
	//check row and diag:
	for (int i=1;i<col;++i) {
		if (cols[i]==row || abs(cols[i]-row)==abs(col-i)) {
			return true;
		}
	}
	return false;
}


void backtrack(int col) {
	if (col>SIZE) {
		output();
		return;
	}
	if (col==fixed_col) {
		if (!has_conflicts(fixed_row,fixed_col)) {
			cols[fixed_col]=fixed_row;
			backtrack(col+1);	
		}
	} else {
		for (int row=1;row<=SIZE;++row) {
			if (!has_conflicts(row,col)) {
				cols[col] = row;
				backtrack(col+1);	
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	while (T--) {
		cout<<"SOLN       COLUMN"<<endl;
 		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
		cin>>fixed_row>>fixed_col;
		n = 0;
		fill_n(cols,0,SIZE+1);
		backtrack(1);
		if (T) cout<<endl;
	}
	return 0;
}