#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;

//void Parameter_analysis()
//{
//	string str;
//	getline(cin, str);
//	int count = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '"')
//		{
//			i++;
//			while (i < str.size() && str[i] != '"')
//				i++;
//
//			if (i == str.size() - 1) break;
//			count++;
//		}
//
//		if (i > 0 && str[i - 1] != ' ' && str[i] == ' ')
//		{
//			count++;
//		}
//	}
//	count++;
//	cout <<count<< endl;
//
//	for (int i = 0; i < str.size();i++)
//	{
//		if (str[i] == '"')
//		{
//			i++;
//			while (i < str.size()&&str[i] != '"')
//				cout << str[i++];
//
//			if (i == str.size() - 1) break;
//			i++;
//		}
//
//		if(str[i] != ' ')
//		{
//			cout << str[i];
//		}			
//	}
//}




//int main()
//{
//	//Parameter_analysis();
//
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;

int dp[N];


int main()
{
    int n, m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    dp[n] = 0;
    for (int i = n; i <= m; i++) {

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
                dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
            }
        }
    }
    //for(int i= 1;i<=m;i++)cout<<dp[i]<<" "<<i<<endl;
    if (dp[m] == 0x3f3f3f3f)dp[m] = -1;
    cout << dp[m] << endl;
}

