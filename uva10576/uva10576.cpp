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

//0 considered a deficit
bool post(int posts[], int s, int d, int month) {  
  if (month>4) {
    int last_5 = accumulate(posts+month-5,posts+month,0);
    if (last_5>0) {
      return false;
    }
  }

  if (month==12) {
    int year = accumulate(posts,posts+12,0);
    if (year<=0)
      cout<<"Deficit"<<endl;
    else
      cout<<year<<endl;
    return true;
  }

  posts[month]=s;
  if (!post(posts,s,d,month+1)) {
    posts[month]=-d;
    return post(posts,s,d,month+1);
  }
  return true;
}

int main(int argc, char* argv[])
{
  int s,d; 
	while (cin && cin>>s>>d) {
		int posts[12];
    post(posts,s,d,0);
	}
	return 0;
}