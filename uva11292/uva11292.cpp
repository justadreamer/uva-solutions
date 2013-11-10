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
typedef set<int> si;

int main(int argc, char* argv[])
{
	int n,m;
	while (cin>>n>>m && n>0 && m>0) {
    vi heads;
  	for (int i=0;i<n;++i) {
      int head; cin>>head; heads.push_back(head);
    }

    vi knights;
    for (int i=0;i<m;++i) {
      int knight; cin>>knight; knights.push_back(knight);
    }

    sort(heads.begin(),heads.end());
    sort(knights.begin(),knights.end());
    bool is_doomed = false;
    int money = 0;

    if (m<n) {
      is_doomed = true;
    } else {
      int j = 0;
      for (int i=0;i<n;++i) {
        while (j<m && knights[j]<heads[i]) {
          ++j;
        }
        if (j<m && knights[j]>=heads[i]) {
          money+=knights[j];
        } else {
          is_doomed = true;
          break;
        }
        ++j;
      }
    }

    //output result:
    if (is_doomed) {
      cout<<"Loowater is doomed!"<<endl;
    } else {
      cout<<money<<endl;
    }
	}
	return 0;
}