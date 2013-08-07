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
void check_and_output(int cols[],int col);

void output(int cols[]) {
	cout<<setw(2)<<++n<<"      ";
	for (int i=1;i<=SIZE;++i) {
		if (i>1) cout<<" ";
		cout<<cols[i];
	}
	cout<<endl;
}

void place_queen(int cols[], int col) {
	if (col==fixed_col) {
		cols[col]=fixed_row;
		check_and_output(cols,col);
	} else {
		for (int row=1;row<=SIZE;++row) {
			cols[col]=row;
			check_and_output(cols,col);
		}
	}
}

bool has_conflicts(int cols[],int col) {
	//check row and diag:
	for (int i=1;i<col;++i) {
		if (cols[i]==cols[col] || abs(cols[i]-cols[col])==abs(col-i)) {
			return true;
		}
	}
	return false;
}

void check_and_output(int cols[], int col) {
	if (!has_conflicts(cols,col)) {
		if (col==SIZE) {
			output(cols);
		} else {
			place_queen(cols,++col);
		}
	}
}


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	for (int i=0;i<T;++i) {
		if (i>0) cout<<endl;
		cout<<"SOLN       COLUMN"<<endl;
 		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;

		cin>>fixed_row>>fixed_col;
		n = 0;
		int cols[SIZE+1];
		fill_n(cols,0,SIZE+1);
		place_queen(cols,1);
	}
	return 0;
}