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

double eps = 10e-8;

double f(int p, int q, int r, int s, int t, int u, double x) {
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2.0) + u;
}

int main(int argc, char* argv[])
{
	int p,q,r,s,t,u;
	while (cin && cin>>p>>q>>r>>s>>t>>u) {
    double lo = 0;
    double hi = 1.0;

    double flo = f(p,q,r,s,t,u,lo);
    double fhi = f(p,q,r,s,t,u,hi);
    if ((flo>0 && fhi>0) || (flo<0 && fhi<0) || (flo==0 && fhi==0)) {
      cout<<"No solution"<<endl;
    } else if (flo==0 && fhi!=0) {
      cout<<"0.0000"<<endl;
    } else if (fhi==0 && flo!=0) {
      cout<<"1.0000"<<endl;
    } else {
      while (true) {
        double med = (lo+hi)/2.0;
        double fmed = f(p,q,r,s,t,u,med);
        if (abs(fmed)<=eps) {
          cout<<fixed<<setprecision(4)<<med<<endl;
          break;
        } else {
          if (fmed*flo<0) {
            hi = med;
            fhi = fmed;
          } else {
            lo = med;
            flo = fmed;
          }
        }
      }
    }
	}
	return 0;
}