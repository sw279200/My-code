#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

void solve()
{
	int n = 0;
	int count = 0;
	cin >> n;

	/*if (n == 1) cout<<count<<endl;*/
	int a = 0, b = 1, c = 1;
	for (int i = 0; i < 35; i++)
	{
		c = b + a;
		a = b;
		b = c;
		if (n >= a && n <= b)
		{
			count = min(n - a, b - n);
			break;
		}
	}
	cout << count << endl;

}

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here

		stack<char> st;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(') st.push(A[i]);
			else if (!st.empty() && A[i] == ')') st.pop();
			else if ((A[i] != '(' && A[i] != ')') || (st.empty() && A[i] == ')')) return false;
		}

		return true;

	}
};

int main()
{
	//solve();
	Parenthesis p;
	cout<<p.chkParenthesis("(()a())", 6)<<endl;
	return 0;
}