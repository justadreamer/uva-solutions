#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class TestCase {
public:
	bool is_terminal();
	TestCase(int _k);
	void doWork();
private:
	void input();
	void output();
	void calc();

private:
	int k;
	int m,n;
	char** field;
};

int main(int argc, char* argv[])
{
	int k = 0;
	for (;;) {
		TestCase t(++k);
		if (t.is_terminal()) {
			break;
		}
		if (k>1)
			cout<<endl;
		t.doWork();
	}
	return 0;
}

TestCase::TestCase(int _k):k(_k) {
	input();
}

void TestCase::doWork() {
	if (!is_terminal()) {
		calc();
		output();
	}
}

void TestCase::input() {
	cin>>n>>m;
	field = new char*[n];
	for (int i=0;i<n;i++) {
		field[i] = new char [m];
		for (int j=0;j<m;j++) {
			cin>>field[i][j];
		}
	}
}

void TestCase::output() {
	cout<<"Field #"<<k<<":"<<endl;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cout<<field[i][j];
		}
		cout<<endl;
	}
}

void TestCase::calc() {
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (field[i][j]=='.') {
				int mine_count=0;
				for (int ii=i-1;ii<=i+1;ii++) {
					if (ii<0 || ii>n-1)
						continue;
					for (int jj=j-1;jj<=j+1;jj++) {
						if (jj<0 || jj>m-1)
							continue;
						if (field[ii][jj]=='*') 
							mine_count++;
					}
				}
				field[i][j]='0'+mine_count;
			}
		}
	}
}

bool TestCase::is_terminal() {
	return m==0 && n==0;
}