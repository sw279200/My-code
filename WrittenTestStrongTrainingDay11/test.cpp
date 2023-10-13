#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        if (a == 1 || b == 1) return 1;

        if (a == b) return a;

        int parentA = (a - 2) / 2+1,parentB = (b-2)/2+1;

        if (a <= parentB) return getLCA(a, parentB);

        else if (b <= parentA) return getLCA(parentA, b);

        return getLCA(parentA, parentB);
    }
};

//求最大连续bit数
void solve()
{
    int n = 0;
    cin >> n;

    int left = 0, right = 0, maxLength = 0;
    for (; right < 32; right++) {
        if (((n >> right) & 1) == 0) {
            maxLength = max(maxLength, right - left);
            left = right;
            left++;
        }
    }

    cout << maxLength << endl;
}

int main()
{
    LCA lca;
    cout << lca.getLCA(5, 6)<< endl;
	return 0;
}