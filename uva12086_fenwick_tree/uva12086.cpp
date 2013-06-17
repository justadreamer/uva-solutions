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

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;
typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { 
  	ft.assign(n + 1, 0); 
  }

  int rsq(int b) {                                     // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }

  void set(int k, int v) {
  	int diff = v - rsq(k,k);
  	adjust(k,diff);
  }
public:
  void print() {
  	for (int i=0;i<ft.size();++i) {
  		cout<<ft[i]<<" ";
  	}
  	cout<<endl;
  }
};

int main(int argc, char* argv[])
{
	int N = 0;
	int tc = 1;
	while (cin>>N && N>0) {
		FenwickTree ft(N);
		for (int i=1;i<=N;++i) {
			int R;
			scanf("%d\n",&R);
			ft.adjust(i,R);
		}
		if (tc>1)
			cout<<endl;
		cout<<"Case "<<tc++<<":"<<endl;
		//queries:
		char buf [4];
		while (true) {
			scanf("%s",buf);
			if (0==strncmp(buf,"END",3)) {
				break;
			}
				
			int a,b;
			scanf("%d %d\n",&a,&b);
			if (buf[0]=='M') {
				cout<<ft.rsq(a,b)<<endl;
			} else if (buf[0]=='S') {
				ft.set(a,b);
			}
		}
	}
	return 0;
}