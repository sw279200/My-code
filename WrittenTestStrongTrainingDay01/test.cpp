#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include<iostream>
#include<string>
using namespace std;



//É¾³ý¹«¹²×Ö·û´®
string erasePublicString(string& str1, string& str2)
{
	string s("");
	for (size_t i = 0; i < str1.size(); i++)
	{	
		bool flag = false;
		for (size_t j = 0; j < str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			s += str1[i];
		}
	}
	return s;
}


int main()
{
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin, s2);

	cout << erasePublicString(s1, s2) << endl;
	return 0;
}
#endif 

#if 0
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


//×é¶Ó¾ºÈü
long long MaxLevelValue()
{
	int n = 0;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n * 3; i++)
	{	
		int input = 0;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	long long sum = 0;
	vector<int>::iterator it = v.begin()+n;
	while (it != v.end() - 1&&it != v.end())
	{
		sum += *it;
		it += 2;
	}

	return sum;
}

int main()
{
	cout << MaxLevelValue() << endl;
	return 0;
}
#endif




#if 0

//µ¼ÖÂ×Ö·û´®
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void solve()
{
	string str;
	getline(cin, str);
	vector<string> vs;
	string s("");
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			s += str[i];
		}
		else
		{
			vs.push_back(s);
			s = "";
		}

	}
	vs.push_back(s);
	
	reverse(vs.begin(),vs.end());
	auto it = vs.begin();
	while (it != vs.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

int main()
{
	solve();
	return 0;
}
#endif



#include<iostream>
#include<algorithm>
#include<vector>
#define int long long 
using namespace std;


signed main()
{
	int n; cin >> n;
	vector<int>a;

	int last = -1;

	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		if (x != last)
		{
			last = x;
			a.push_back(last);
		}
	}

	//for(auto t:a)cout<<t<<" ";cout<<endl;



	int t = 0;
	int ans = 1;
	for (int i = 1; i < (int)a.size(); i++)
	{
		int T = a[i] - a[i - 1];
		//  cout<<T<<endl;
		if (T * t < 0) {
			ans++;
			t = 0;
		}
		else t = T;
	}
	cout << ans << endl;
}