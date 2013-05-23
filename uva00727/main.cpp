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

using namespace std;
struct OpType {
	char op;
	int priority() {
		int priority = op=='+' || op=='-' ? 1 : 2;
		return priority;
	};
	OpType(char _op) : op(_op) {

	};
};

class TestCase {
public:
	TestCase();
private:
	void do_test();
	string process();
	void combine_terms(stack<string>& terms, stack<OpType>& op);
	void combine_terms_1_op(stack<string>& terms, const OpType& op);
private:
};

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	cin.ignore();
	cin.ignore();
	for (int i=0;i<T;i++) {
		if (i>0)
			cout<<endl;
		TestCase();
	}
	return 0;
}

TestCase::TestCase() {
	do_test();
}

void TestCase::do_test() {
	string term = process();
	cout<<term<<endl;
}

string TestCase::process() {
	stack<string> terms;
	stack<OpType> op;
	string in;
	while (getline(cin,in) && in.length()>0) {
		char c = in[0];
		if (isdigit(c)) {
			terms.push(in);
			if (op.size()>1)
				combine_terms(terms,op);
		} else if (ispunct(c)) {
			if (c=='(') {
				string term = process();
				terms.push(term);
				if (op.size()>1)
					combine_terms(terms,op);
			} else if (c==')') {
				break;
			} else if (c=='+' || c=='-' || c=='*' || c=='/') {
				op.push(OpType(c));
			}
		}
	}
	combine_terms(terms,op);
	return terms.top();
}

void TestCase::combine_terms(stack<string>& terms, stack<OpType>& op) {
	if (op.size()>1 && terms.size()>2) {
		OpType op2 = op.top();
		op.pop();
		OpType op1 = op.top();
		op.pop();
		if (op2.priority()>op1.priority()) {
			combine_terms_1_op(terms,op2);
			op.push(op1);
		} else {
			string term3 = terms.top();
			terms.pop();
			combine_terms_1_op(terms,op1);
			terms.push(term3);
			op.push(op2);
		}
	} else if (op.size()>0 && terms.size()>1) {
		OpType op1 = op.top();
		op.pop();
		combine_terms_1_op(terms,op1);
	}
}

void TestCase::combine_terms_1_op(stack<string>& terms, const OpType& op) {
	string term2 = terms.top();
	terms.pop();
	string term1 = terms.top();
	terms.pop();
	term1+=term2;
	term1+=op.op;
	terms.push(term1);
}


// 1+2+3*4*(2-8*(3+4))
// 12+34*2834+*-*+