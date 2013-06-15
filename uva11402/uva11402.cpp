#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <set>
#include <iomanip>
#include <list>
#include <climits>
#include <stack>
#include <queue>

using namespace std;
typedef enum {
  op_0,
  op_F,
  op_E,
  op_I,
  op_S
} OP;

typedef vector<int> vi;
typedef vector<OP> vOP;

class SegmentSumTree {
private: 
  int* A;
  vi st;
  vOP opt;

  int n;

  inline int left (int p) { return p << 1; }
  inline int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    opt[p]=op_0;
    if (L==R) {
      st[p] = A[L];
    } else {
      int lp = left(p);
      int rp = right(p);
      build(lp , L              , (L + R) / 2);
      build(rp, (L + R) / 2 + 1, R           );
      int p1 = st[lp], p2 = st[rp];
      st[p] = p1+p2;
    }
  }

  inline int apply (int p, int L, int R) {
    switch (opt[p]) {
      case op_F: {
        return (R-L+1);
      }
      case op_E: {
        return 0;
      }
      case op_I: {
        return (R-L+1)-st[p];
      }
      default:
        return st[p];
    }
  }

  inline OP mult(OP op1, OP op2) {
    static OP table[][4] = {
      {op_0, op_F, op_E, op_I},  //op1 = op_0
      {op_F, op_F, op_E, op_E},  //op1 = op_F
      {op_E, op_F, op_E, op_F},  //op1 = op_E
      {op_I, op_F, op_E, op_0}   //op1 = op_I
    };
    return table[op1][op2];
  }

  inline void propagate(int p, int L, int R) {
    if (opt[p]!=op_0) {
      int lp = left(p);
      int rp = right(p);

      opt[lp]=mult(opt[lp],opt[p]);
      opt[rp]=mult(opt[rp],opt[p]);

      int p1 = apply(lp, L          , (L+R) / 2);
      int p2 = apply(rp, (L+R) / 2+1, R);
      st[p] = p1+p2;
      opt[p] = op_0;
    }
  }

  int rsq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return 0;

    if (i <= L && R <= j)
      return apply(p,L,R);

    propagate(p,L,R);

    int p1 = rsq(left(p) , L            , (L+R) / 2, i, j);
    int p2 = rsq(right(p), (L+R) / 2 + 1, R        , i, j);

    return p1+p2;
  }

  int update_range(int p, int L, int R, int i, int j, OP op) {
    if (i > R || j < L)
      return apply(p,L,R);

    if (i <= L && R <= j) {
      opt[p]=mult(opt[p],op);
      return apply(p,L,R);
    }

    propagate(p,L,R);

    int s1 = update_range(left(p) , L              , (L + R) / 2, i, j, op);
    int s2 = update_range(right(p), (L + R) / 2 + 1, R          , i, j, op);

    return st[p]=s1+s2;
  }

public:

  SegmentSumTree(int* _A, int _n) : A(_A),n(_n) {
    int tree_size = 4*n;
    st.assign(tree_size, 0);
    opt.assign(tree_size, op_0);

    build(1, 0, n - 1);
  }

  int rsq(int i, int j) {
    return rsq(1, 0, n - 1, i, j);
  }

  void update_range(int i, int j, OP op) {
    update_range(1,0,n-1,i,j,op);
  }
};

int main() {
  OP idx[255];
  idx[(int)'F']=op_F;
  idx[(int)'E']=op_E;
  idx[(int)'I']=op_I;

  int TC;
  cin>>TC;
  for (int t=1;t<=TC;++t) {
    //input:
    int M;
    scanf("%d\n",&M);
    int A[1500000];
    int count = 0;
    while (M--) {
      int T;
      scanf("%d\n",&T);
      char buf [51];
      scanf("%s\n",buf);
      while (T--) {
        int i=0;
        while (buf[i]!='\0') {
          A[count++] = (int)(buf[i++]-'0');
        }
      }
    }

    //create SegmentTree:
    SegmentSumTree st(A,count);

    //output test case number
    cout<<"Case "<<t<<":"<<endl;

    //queries:
    int Q;
    cin>>Q;
    int s_count=1;
    while (Q--) {
      char q;
      int i,j;
      cin>>q>>i>>j;
      if (q=='F' || q=='E' || q=='I') {
        st.update_range(i,j,idx[(int)q]);
      } else if (q=='S') {
        int answer = st.rsq(i,j);
        cout<<"Q"<<s_count++<<": "<<answer<<endl;
      }
    }
  }
  return 0;
}