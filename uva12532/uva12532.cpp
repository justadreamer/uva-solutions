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
#include <cctype>

using namespace std;

typedef vector<int> vi;

class SegmentProdTree {
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
      st[p] = op(p1,p2);
    }
  }

  int rsq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return 1;
    if (L >= i && R <= j) return st[p];

    int p1 = rsq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rsq(right(p), (L+R) / 2 + 1, R          , i, j);

    return op(p1,p2);
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
    return st[p] = op(s1,s2);
  }

  inline int op(int p1,int p2) {
    return p1*p2;
  }

public:
  SegmentProdTree(const vi &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }   // overloading

  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};
  

class TestCase {
public:
	TestCase(int N) {
		process(N);
	}
private:
	inline int normalized(int n) {
		return n > 0 ? 1 : (n < 0 ? -1 : 0);
	}

	void process(int N) {
		int K;
		cin>>K;
		vi A(N,0);
		for (int i=0;i<N;++i) {
			int tmp;
			cin>>tmp;
			A[i] = normalized(tmp);
		}

		SegmentProdTree st(A);

		while (K--) {
			char c;
			int i,j;
			cin>>c>>i>>j;
			if (c=='C') {
				st.update_point(i-1,normalized(j));
			} else if (c=='P') {
				int prod = st.rsq(i-1,j-1);
				if (prod>0) {
					cout<<'+';
				} else if (prod<0) {
					cout<<'-';
				} else {
					cout<<0;
				}
			}
		}
		cout<<endl;
	}
};


int main(int argc, char* argv[])
{
	int N;
	while (cin>>N) {
		TestCase t(N);
	}
	return 0;
}