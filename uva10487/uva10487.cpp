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
#include <bitset>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;

int find_closest(const vi& numbers, int q) {
  int s = numbers[0]+numbers[1];
  for (int i=0;i<numbers.size();++i) {
    for (int j=0;j<i;++j) {
      int temp = numbers[i]+numbers[j];
      if (abs(temp-q) < abs(s-q)) s=temp;
    }
  }
  return s;
}

int main(int argc, char* argv[])
{
	int n;
  int n_case = 0;
	while (cin>>n && n>0) {
    vi numbers;
		while (n--) {
      int num; cin>>num; numbers.push_back(num);
    }
    int m; cin>>m;
    cout<<"Case "<<++n_case<<":"<<endl;
    while (m--) {
      int q; cin>>q; 
      int s = find_closest(numbers,q);
      cout<<"Closest sum to "<<q<<" is "<<s<<"."<<endl;
    }
	}
	return 0;
}