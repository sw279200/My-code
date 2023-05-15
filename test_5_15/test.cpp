
//文文上体育课
//#include<iostream>
//#include<algorithm>
//
//#include<cmath>
//
//
//using namespace std;
//

//int main()
//{
//	int n; cin >> n;
//	n = log2(n);
//	cout << (int)pow(2, n);
//}

#if 0
//文文学mex
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<int>arr;
    arr.resize(n+10, 0);
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        arr[x]++;
        int count = min;
        while (count<n&&arr[count] != 0)
        {
            count++;
        }
        min = count;
        cout << count << endl;
    }
    return 0;
}
#endif



#include<iostream>
#include<vector>
using namespace std;

void solve()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<int>dyg[1010];

    for (int i = 0; i < 1010; i++)
    {
        dyg[i].resize(m+10, 0);
    }
    
    
    while (Q--)
    {
        int x, y, op;
        cin >> x >> y >> op;
        if (x >= 1 && x <= n && y >= 1 && y <= m)
        {
            switch (op)
            {
            case 1:
            {
                int x_ = 0;
                int y_ = 0;
                while (((x - x_ >= 1) && (x - x_ <= x)) && ((y - y_ >= 1) && (y - y_ <= y)))
                {
                    dyg[x - x_][y - y_] = 1;
                    x_++;
                    y_++;
                }
                break;
            }
            case 2:
            {
                int x_ = 0;
                while (((x - x_ >= 1) && (x - x_ <= x)))
                {
                    dyg[x - x_][y] = 2;
                    x_++;
                }
                break;
            }
            case 3:
            {
                int x_ = 0;
                int y_ = 0;
                while (((x - x_ >= 1) && (x - x_ <= x)) && ((y + y_ >= y) && (y + y_ <= m)))
                {
                    dyg[x - x_][y + y_] = 3;
                    x_++;
                    y_++;
                }
                break;
            }
            case 4:
            {
                int y_ = 0;
                while ((y + y_ >= y) && (y + y_ <= m))
                {
                    dyg[x][y + y_] = 4;
                    y_++;
                }
                break;
            }
            case 5:
            {
                int x_ = 0;
                int y_ = 0;
                while (((x + x_ >= x) && (x + x_ <= n)) && ((y + y_ >= y) && (y + y_ <= m)))
                {
                    dyg[x + x_][y + y_] = 5;
                    x_++;
                    y_++;
                }
                break;
            }
            case 6:
            {
                int x_ = 0;
                while ((x + x_ >= x) && (x + x_ <= n))
                {
                    dyg[x + x_][y] = 6;
                    x_++;
                }
                break;
            }
            case 7:
            {
                int x_ = 0;
                int y_ = 0;
                while (((x + x_ >= x) && (x + x_ <= n)) && ((y - y_ >= 1) && (y - y_ <= y)))
                {
                    dyg[x + x_][y - y_] = 7;
                    x_++;
                    y_++;
                }
                break;
            }
            case 8:
            {
                int y_ = 0;
                while ((y - y_ >= 1) && (y - y_ <= y))
                {
                    dyg[x][y - y_] = 8;
                    y_++;
                }
                break;
            }
            case 9:
            {
                if (dyg[x][y] != 0)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
                break;
            }
            default:
                break;

            }
        }
       
    }

}
int main()
{
    solve();
    return 0;
}
