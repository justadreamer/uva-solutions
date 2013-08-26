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

const int M = 5;
const int MM = M*M;

int md(int x,int y) {
  div_t xx = div(x,M);
  div_t yy = div(y,M);
  return abs(xx.quot-yy.quot)+abs(xx.rem-yy.rem);
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	while (T--) {
		int n; cin>>n;
    int area[MM];
    int min_dist_sum=0;
    for (int i=0;i<MM;++i) {
      area[i]=0;
      min_dist_sum+=2*M*10000;
    }
    while (n--) {
      int r,c,population; cin>>r>>c>>population; area[r*M+c]=population;
    }

    int sol[5];
    for (int a=0;a<MM-4;++a) {
      for (int b=a+1;b<MM-3;++b) {
        for (int c=b+1;c<MM-2;++c) {
          for (int d=c+1;d<MM-1;++d) {
            for (int e=d+1;e<MM;++e) {
              int office[5]={a,b,c,d,e};
              
              //distance sum to offices from all areas
              int dist_sum = 0;
              for (int i=0;i<MM;++i) {
                if (area[i]>0) {
                  int dist = md(i,office[0]);
                  for (int j=1;j<5;++j) {
                    int tmp = md(i,office[j]);
                    if (tmp<dist) {
                      dist=tmp;
                    }
                  }
                  dist*=area[i];
                  dist_sum+=dist;
                }
              }

              if (dist_sum<min_dist_sum) {
                min_dist_sum=dist_sum;
                memcpy(sol,office,sizeof(int)*5);
              }
            }
          }
        }
      }
    }

    for (int i=0;i<5;++i) {
      if (i>0)
        cout<<" ";
      cout<<sol[i];
    }
    cout<<endl;
	}
	return 0;
}