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
class SegmentSumTree {
private: vi st, A;
  int n;
  int left (int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L];
    else {
      int lp = left(p);
      int rp = right(p);
      build(lp , L              , (L + R) / 2);
      build(rp, (L + R) / 2 + 1, R          );
      int p1 = st[lp], p2 = st[rp];
      st[p] = p1+p2;
    }
  }

  int rsq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return -1;
    if (L >= i && R <= j) return st[p];

    int p1 = rsq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rsq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1 + p2;
  }

  int update_point(int p, int L, int R, int idx, int new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = A[L]; // this index
    }

    // compute the minimum pition in the 
    // left and right part of the interval
    int s1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    int s2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the pition where the overall minimum is
    return st[p] = s1 + s2;
  }

public:
  SegmentSumTree(const vi &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }   // overloading

  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};

int main(int argc, char* argv[])
{
	int N = 0;
	int tc = 1;
	while (cin>>N && N>0) {
		vi potmeters(N,0);
		for (int i=0;i<N;++i) {
			int R;
			scanf("%d\n",&R);
			potmeters[i]=R;
		}

		SegmentSumTree st(potmeters);
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
				cout<<st.rsq(a-1,b-1)<<endl;
			} else if (buf[0]=='S') {
				st.update_point(a-1,b);
			}
		}
	}
	return 0;
}