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
	string input;
	while (cin>>input && input!="#") {
		if (next_permutation(input.begin(),input.end())) {
			cout<<input;
		} else {
			cout<<"No Successor";
		}
		cout<<endl;
	}
	return 0;
}