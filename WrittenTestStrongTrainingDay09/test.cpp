#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class UnusualAdd {
public:
    //¡Ì¿‡º”∑®
    int addAB(int A, int B) {
        // write code here
       
        while (B != 0)
        {
            int carry = (A & B) << 1;
            A ^= B;
            B = carry;
        }
        return A;
    }
};

void solve()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n+2, vector<int>(m+2,0));
    dp[0][1] = 1;
    for (int i = 1; i <= n+1; i++)
        for (int j = 1; j <= m+1; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    cout << dp[n+1][m+1] << endl;
}


int main()
{
    /*UnusualAdd ua;
    cout<<ua.addAB(1, 2)<<endl;*/
    solve();
	return 0;
}
