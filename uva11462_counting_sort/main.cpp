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

int main(int argc, char* argv[])
{
	int n;
	const int MAX = 100;
	int counts[MAX];
	while (cin>>n && n>0) {
		for (int i=0;i<MAX;i++) {
			counts[i]=0;
		}
		for (int i=0;i<n;i++) {
			int k;
			cin>>k;
			++counts[k];
		}
		bool did_output = false;
		for (int i=0;i<MAX;i++) {
			for (int j=0;j<counts[i];j++) {
				if (did_output) {
					cout<<" ";
				} else {
					did_output = true;
				}
				cout<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}