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
	while (cin>>n && n>0) {
		multiset<int> numbers;
		for (int i=0;i<n;i++) {
			int k;
			cin>>k;
			numbers.insert(k);
		}
		for (set<int>::iterator i=numbers.begin();i!=numbers.end();++i) {
			if (i!=numbers.begin()) {
				cout<<" ";
			}
			cout<<*i;
		}
		cout<<endl;
	}
	return 0;
}