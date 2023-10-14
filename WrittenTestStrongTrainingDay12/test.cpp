#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        return n |= (m << j);
    }
};


//查找组成一个偶数最接近的两个素数

bool IsPrime(int m)
{
    bool flag = true;

    for(int i = 2;i<=sqrt(m);i++)
        if (m % i == 0)
        {
            flag = false;
            break;
        }

    return flag;
}

void solve()
{
    int n = 0;
    cin >> n;
    int m = n / 2;
    int left = m, right = m;
    while (left > 1 && (!IsPrime(left) || !IsPrime(right)))
        right++, left--;

    cout << left << "\n" << right << endl;
}

int main()
{
    /*BinInsert bi;
    cout<<bi.binInsert(1024, 19, 2, 6) << endl;*/
    solve();
    return 0;
}