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
#include <numeric>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;

bool is_prime(int n) {
  if (n<4)
    return true;
  for (int i=2;i<=n/2;++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void print(int circle[], int n) {
  for (int i = 0;i<n;++i) {
    if (i>0) cout<<" ";
    cout<<circle[i];
  }
  cout<<endl;
}

void create (int circle[], int n, int cur, int used) {
  if (n==cur) {
    if (is_prime(circle[n-1] + circle[0])) print(circle,n);
    return;
  }

  for (int i=1;i<n;++i) {
    int mask = 1<<i;
    if (0 == (used & mask)) {
      int temp = i+1;
      if (is_prime(circle[cur-1]+temp)) {
        used |= mask;
        circle[cur]=temp;
        create(circle,n,cur+1,used);
        used ^= mask;
      }
    }
  }
}

int main(int argc, char* argv[])
{
	int n;
  int n_case = 0;
	while (cin>>n) {
    if (n_case>0) cout<<endl;
		int circle[n];
    circle[0]=1;
    cout<<"Case "<<++n_case<<":"<<endl;
    create(circle,n,1,1);
	}
	return 0;
}