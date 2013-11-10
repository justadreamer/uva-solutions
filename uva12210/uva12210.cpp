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
	int B,S;
  int t=1;
	while (cin>>B>>S && B && S) {
    //input and sort right away:
    multiset<int,greater<int> > bachelors;
    multiset<int> spinsters;
    for (int i=0;i<B;++i) {
      int age; cin>>age; bachelors.insert(age);
    }
    for (int i=0;i<S;++i) {
      int age; cin>>age; spinsters.insert(age);
    }
    //cout<<"bachelors.size()="<<bachelors.size()<<endl;
    //either bachelors or spinsters will exhaust
    while (bachelors.size() && spinsters.size()) {
      int age = *(bachelors.begin());
      si::iterator s_it = spinsters.lower_bound(age);
      if (s_it==spinsters.end()) {
        --s_it;
      } else if (s_it!=spinsters.begin()) {
        //let's check with the previous
        si::iterator prev = s_it; --prev;
        if (abs(age-*prev)<abs(age-*s_it)) {
          s_it = prev;
        }
      }
      //cout<<"erasing: b="<<*(bachelors.begin())<<" s="<<*s_it<<endl;
      bachelors.erase(bachelors.begin());
      spinsters.erase(s_it);
    }

    //prepare result:
    int bachelors_left = bachelors.size();
    int yongest_age = 0;
    if (bachelors_left) {
      si::iterator last = bachelors.end();
      --last;
      yongest_age = *last;
    }
		//output result:
    cout<<"Case "<<t++<<": "<<bachelors_left;
    if (bachelors_left>0) {
      cout<<" "<<yongest_age;
    }
    cout<<endl;
	}
	return 0;
}