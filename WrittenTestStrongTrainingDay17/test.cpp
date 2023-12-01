#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//超时，未过所有案例
void Pascal_triangle() {
    int n = 0;
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    int m = n * 2 + 1;
    vector<int> v1(m), v2(m);
    v1[n] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i < m - 1; i++)
        {
            int a = v1[i - 1], b = v1[i], c = v1[i + 1];
            v2[i] = a + b + c;
            if (j==n&&v1[i] != 0 && v1[i] % 2 == 0)
            {
                cout << i << endl;
                return;
            }
        }

        swap(v1, v2);
    }
    cout << -1 << endl;

}



#if 0
void solve()
{
    string str;
    getline(cin, str);
    char ch;
    ch=getchar();
    int count = 0;
    if (ch >= 'a' && ch <= 'z')
        ch -= 32;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (ch==str[i])
            count++;
    }
    cout << count << endl;
}

#endif
int main() {
    Pascal_triangle();

    //solve();
    return 0;
}