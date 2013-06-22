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
typedef map<int,int> mii;

class TestCase {
public:
	TestCase(int _r,int _c) :r(_r),c(_c) { 
		input();
		output();
	}
private:
	void input() {
		mtr.assign(c,mii());
		for (int i=0;i<r;++i) {
			int n = 0;
			cin>>n;

			set<int> row;
			for (int j=0;j<n;++j) {
				int col;
				cin>>col;
				row.insert(col-1);
			}
			for (set<int>::iterator j=row.begin();j!=row.end();++j) {
				int val;
				cin>>val;
				mtr[*j][i]=val;
			}
		}
	}
	void output() {
		cout<<c<<" "<<r<<endl;
		for (vector<mii>::iterator row=mtr.begin();row!=mtr.end();++row) {
			cout<<row->size();
			for (mii::iterator col=row->begin();col!=row->end();++col) {
				cout<<" "<<col->first+1;
			}
			cout<<endl;
			for (mii::iterator col=row->begin();col!=row->end();++col) {
				if (col!=row->begin())
					cout<<" ";
				cout<<col->second;
			}
			cout<<endl;
		}

	}
private:
	int r,c;
	vector<mii > mtr;
};

int main(int argc, char* argv[])
{
	int r,c;
	while (cin>>r>>c && r && c) {
		TestCase t(r,c);
	}
	return 0;
}