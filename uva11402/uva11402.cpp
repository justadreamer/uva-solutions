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

struct range {
  int i;
  int j;
  OP op;
  bool apply;

  bool operator<(const range& r) const {
    return i<r.i;
  };

  range(int _i, int _j, OP _op, bool _apply):i(_i),j(_j),op(_op),apply(_apply) {};
  void print() const {
    cout<<"["<<i<<","<<j<<"] op="<<op<<endl;
  };
};

class SegmentSumTree {
private: 
  vi A;
  vi st;
  set<range> ranges;
  int n;

  int left (int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
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

  inline void apply (int L, OP op) {
    switch (op) {
      case op_F: {
        A[L]=1;
      } break;
      case op_E: {
        A[L]=0;
      } break;
      case op_I: {
        A[L]=!A[L];
      } break;
    }
  }

  OP mult(OP op1, OP op2) {
    static OP table[][4] = {
      {op_0, op_F, op_E, op_I},  //op1 = op_0
      {op_F, op_F, op_0, op_E},  //op1 = op_F
      {op_E, op_0, op_E, op_F},  //op1 = op_E
      {op_I, op_F, op_E, op_0}  //op1 = op_I
    };
    return table[op1][op2];
  }

  int rsq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return 0;

    if (i <= L && R <= j)
      return st[p];

    int p1 = rsq(left(p) , L            , (L+R) / 2, i, j);
    int p2 = rsq(right(p), (L+R) / 2 + 1, R        , i, j);

    return p1+p2;
  }

  int update_range(int p, int L, int R, int i, int j, OP op) {
    if (i > R || j < L)
      return st[p];
    
    if (L==R) {
      apply(L,op);
      return st[p]=A[L];
    }

    int s1 = update_range(left(p) , L              , (L + R) / 2, i, j, op);
    int s2 = update_range(right(p), (L + R) / 2 + 1, R           , i, j, op);

    st[p]=s1+s2;
    return st[p];
  }

public:
  SegmentSumTree(const vi &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rsq(int i, int j) {
    add_range(i,j,op_S);
    for (set<range>::iterator r=ranges.begin();r!=ranges.end();++r) {
      if (r->apply) {
        update_range(1, 0, n-1, r->i, r->j, r->op);
      }
    }
    return rsq(1, 0, n - 1, i, j);
  }

  void add_range(int i, int j, OP op) {
    set<range> new_ranges;
    for (set<range>::iterator r=ranges.begin();r!=ranges.end();++r) {
      if (i>j || i>r->j || j<r->i) {
        new_ranges.insert(*r);
        continue;
      }

      if (i <= r->i - 1 && op!=op_S) {
        new_ranges.insert(range(i,r->i-1,op,false));
        i=r->i;
      }

      int int_i = max(i,r->i);
      int int_j = min(j,r->j);
      OP new_op = op!=op_S ? mult(r->op,op) : r->op;
      if (new_op!=op_0 && int_i <= int_j) {
        new_ranges.insert(range(int_i,int_j,new_op,true));
        i=int_j+1;
      }
      if (i>j && i<=r->j) {
        new_ranges.insert(range(i,r->j,r->op,false));
      }
    }
    if (i<=j) {
      new_ranges.insert(range(i,j,op,false));
    }
    ranges = new_ranges;
  }

  void print() {
    for (int i=0;i<A.size();++i) {
      cout<<A[i];
    }
    cout<<endl;
    /*for (int i=0;i<st.size();++i) {
      cout<<st[i]<<" ";
    }*/
    cout<<endl;
  }
};


class TestCase {
public:
	TestCase(int t);
private:
	void calc();
private:
  int t;
};


TestCase::TestCase(int _t):t(_t) {
	calc();
}

void TestCase::calc() {
//input:
  int M;
  cin>>M;
  vi A;
  while (M--) {
    int T;
    cin>>T;
    string Pirates;
    cin.ignore();
    cin>>Pirates;
    while (T--) {
      for (string::iterator i = Pirates.begin();i!=Pirates.end();++i) {
        A.push_back((int)(*i-'0'));
      }
    }
  }

//create SegmentTree:
  SegmentSumTree st(A);
//output test case number
  cout<<"Case "<<t<<":"<<endl;

//queries:
  int Q;
  cin>>Q;
  int s_count = 1;
  OP idx[255];
  idx[(int)'F']=op_F;
  idx[(int)'E']=op_E;
  idx[(int)'I']=op_I;

  while (Q--) {
    char q;
    int i,j;
    cin>>q>>i>>j;
    if (q=='F' || q=='E' || q=='I') {      
      st.add_range(i,j,idx[(int)q]);
    } else if (q=='S') {
      int answer = st.rsq(i,j);
      cout<<"Q"<<s_count++<<": "<<answer<<endl;
    }
  }
}

int main() {
  int T;
  cin>>T;
  for (int i=1;i<=T;++i) {
    TestCase t(i);
  }
  return 0;
}