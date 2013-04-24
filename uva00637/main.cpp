#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

const int BLANK = 0;
const int MAX_SHEETS = 25;

struct page {
	int left;
	int right;
	void output_half(int half) {
		if (half==BLANK) {
			cout<<"Blank";
		} else {
			cout<<half;
		}
	}

	void output_halfs() {
		output_half(left);
		cout<<", ";
		output_half(right);
	}

	void output(int sheet_n,bool is_front) {
		if (!is_blank()) {
			cout<<"Sheet "<<sheet_n+1<<(is_front ? ", front: " : ", back : ");
			output_halfs();
			cout<<endl;
		}
	}

	bool is_blank() {
		return left==BLANK && right==BLANK;
	}
};

const page BLANK_PAGE = {BLANK,BLANK};

struct sheet {
	page front;
	page back;
};

int main(int argc, char* argv[])
{
	int n;

	sheet sheets[MAX_SHEETS];

	while (cin>>n && n) {
		int n_sheets = n / 4 + ( n % 4 ? 1 : 0);
		int count = 1;

		//init:
		for (int i=0;i<MAX_SHEETS;i++) {
			sheets[i].front = BLANK_PAGE;
			sheets[i].back = BLANK_PAGE;
		}

		//forward:
		for (int i=0;i<n_sheets;i++) {
			if (count<=n) {
				sheets[i].front.right=count++;
			}
			if (count<=n) {
				sheets[i].back.left=count++;
			}
		}

		//backward:
		for (int i=n_sheets-1;i>=0;i--) {
			if (count<=n) {
				sheets[i].back.right=count++;
			}
			if (count<=n) {
				sheets[i].front.left=count++;
			}
		}

		//output:
		cout<<"Printing order for "<<n<<" pages:"<<endl;
		for (int i=0;i<n_sheets;i++) {
			sheets[i].front.output(i,true);
			sheets[i].back.output(i,false);
		}
	}
	return 0;
}