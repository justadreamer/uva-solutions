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
struct F {
	int f;
	int n;
};

typedef vector<int> vi;

class SegmentTree {
private: vi st, A;
  int n;
  int left (int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = L;
    else {
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = compare(p1,p2,0) ? p1 : p2;
  } }

  bool compare(int idx1, int idx2, int i) {
  	return adjusted_val(idx1,i) >= adjusted_val(idx2,i);
  }

  inline bool is_true_val(int idx,int i) {
  	return A[idx]<=idx-i+1;
  }

  int rmq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return -1;
    if (L==R) return st[p];
    if (L >= i && R <= j && is_true_val(st[p],i)) return st[p];

    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return compare(p1,p2,i) ? p1 : p2; 
  }

public:
  inline int adjusted_val(int idx, int i) {
  	int adj = min(idx-i+1, A[idx]);
  	return adj;
  }

  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

class TestCase {
public:
	TestCase (int n) {
		process(n);
	}
private:
	void process(int n) {
		int q;
		cin>>q;
		vi A(n,0);
		int prev;
		int count=1;
		for (int i=0;i<n;++i) {
			int cur;
			cin>>cur;
			if (cur!=prev) {
				count=1;
			}
			prev = cur;
			A[i] = count++;
		}
		SegmentTree st(A);
		for (int k=0;k<q;++k) {
			int i,j;
			cin>>i>>j;
			--i;--j;
			int rmq = st.rmq(i,j);
			int adj = st.adjusted_val(rmq,i);
			cout<<adj<<endl;
		}
	}
};


int main(int argc, char* argv[])
{
	int n;
	while (cin>>n && n) {
		TestCase t(n);
	}
	return 0;
}