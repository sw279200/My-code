#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

#if 0
//一维数组前缀和
void solve()
{
	int n, q;
	cin >> n >> q;
	vector<long long> v(n + 2, 0);
	vector<long long> sumV(n + 2, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i + 1];
		sumV[i + 1] = sumV[i] + v[i + 1];
	}
	for (int j = 0; j < q; j++)
	{
		int l, r;
		cin >> l >> r;
		cout << sumV[r] - sumV[l - 1] << endl;
	}

}

#endif

const int N = 1001;
const int M = 1001;
int arr[N][M] = { 0 };
long long dpSum[N][M] = { 0 };
//二维数组前缀和
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dpSum[i][j] = dpSum[i][j - 1] + dpSum[i - 1][j] - dpSum[i - 1][j - 1] + arr[i][j];
        }

    }

    int x1, x2, y1, y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        long long sum = dpSum[x2][y2] + dpSum[x1 - 1][y1 - 1]
            - dpSum[x2][y1 - 1] - dpSum[x1 - 1][y2];
        cout << sum << endl;
    }


}

class Solution {
public:
    //寻找数组的中心下标
    int pivotIndex(vector<int>& nums) {
        ////自己的方法
        //int n = nums.size();
        //vector<int> v(n + 1, 0);
        //v[0] = nums[0];
        //for (int i = 1; i < n; i++)
        //    v[i] = v[i - 1] + nums[i];
        //if (v[n - 1] - v[0] == 0) return 0;
        //for (int j = 1; j < n - 1; j++)
        //{
        //    if (v[j - 1] == v[n - 1] - v[j])
        //        return j;
        //}
        //if (n - 2 >= 0 && v[n - 2] == 0) return n - 1;
        //return -1;

        //方法二：前缀和思想
        // lsum[i] 表⽰：[0, i - 1] 区间所有元素的和
        // rsum[i] 表⽰：[i + 1, n - 1] 区间所有元素的和
        int n = nums.size();
        vector<int> lsum(n), rsum(n);
        // 预处理前缀和后缀和数组
        for (int i = 1; i < n; i++)
            lsum[i] = lsum[i - 1] + nums[i - 1];
        for (int i = n - 2; i >= 0; i--)
            rsum[i] = rsum[i + 1] + nums[i + 1];
        // 判断
        for (int i = 0; i < n; i++)
            if (lsum[i] == rsum[i])
                return i;
        return -1;
    }

    //除自身以外数组的乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> PrevFixProduct(n,1), NextFixProduct(n,1);
        vector<int> res(n);
        //前缀乘积[0,i-1]
        for (int i = 1; i < n; i++)
            PrevFixProduct[i] = nums[i-1] * PrevFixProduct[i - 1];
        //后缀乘积 [i+1,n-1]
        for (int j = n - 2; j >= 0; j--)
            NextFixProduct[j] = nums[j + 1] * NextFixProduct[j + 1];
        
        for (int k = 0; k < n; k++)
            res[k] = PrevFixProduct[k] * NextFixProduct[k];

        return res;
    }

    //和为K的子数组
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (auto ch : nums)
        {
            sum += ch; //记录前缀和
            if (hash.count(sum - k))count += hash[sum - k];
            hash[sum]++;
        }

        return count;

    }

    //和可被 K 整除的子数组   同余定理
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (auto ch : nums)
        {
            sum += ch; //记录前缀和
            if (hash.count((sum % k + k) % k))count += hash[(sum % k + k) % k];
            hash[(sum % k + k) % k]++;
        }

        return count;
    }

    //连续数组
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size(), ret = 0,sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i]==0? -1:1;
            if (hash.count(sum)) ret = max(ret, i - hash[sum]);
            else hash[sum] = i;
        }
        return ret;
    }

    //矩阵区域和
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 1.预处理前缀和矩阵
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                mat[i - 1][j - 1];
        // 2.使⽤
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;
                int x2 = min(m - 1, i + k) + 1, y2 = min(n - 1, j + k) + 1;
                ret[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] +
                    dp[x1 - 1][y1 - 1];
            }
        return ret;
    }
};


int main() {
    
    
    //solve();
    return 0;
}

