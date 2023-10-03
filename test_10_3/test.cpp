#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    //颜色分类
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        ////方法一：快排
        //QuickSort(0, n - 1, nums);

        //方法二，三指针思想
        for (int i = 0, left = -1, right = n; i < right;)
        {
            if (nums[i] == 0) swap(nums[++left], nums[i++]);
            else if (nums[i] == 1) i++;
            else if (nums[i] == 2) swap(nums[--right], nums[i]);
        }
    }

    vector<int> tmp;

    //排序数组
    vector<int> sortArray(vector<int>& nums) {
        /*srand(time(NULL));
        QuickSort(0, nums.size() - 1, nums);*/

        tmp.resize(nums.size());
        MergeSort(0, nums.size() - 1, nums);

        return nums;
    }

    //快排+分治思想
    void QuickSort(int left, int right, vector<int>& v)
    {
        if (left >= right) return;
        int start = left-1, end = right+1,i = left;
        int tmp = v[(rand() % (right - left + 1)) + left];//利用随机数取基准值
        while (i<end)
        {
            if (v[i] < tmp) swap(v[++start], v[i++]);
            else if (v[i] == tmp) i++;
            else if (v[i] > tmp) swap(v[--end], v[i]);
        }

        QuickSort(left, start, v);
        QuickSort(end, right, v);
    }

    //数组中第k个最大元素
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return qsort(0, nums.size() - 1, nums, k);
    }

    int GetRandom(int left, int right, vector<int>& nums)
    {
        return nums[(rand() % (right - left + 1)) + left];
    }

    int qsort(int l, int r, vector<int>& v, int k)
    {

        //1.获取基准值
        int left = l - 1, right = r + 1, i = l, key = GetRandom(l, r, v);
        //2.排序
        while (i < right)
        {
            if (v[i] < key) swap(v[++left], v[i++]);
            else if (v[i] == key) i++;
            else if (v[i] > key) swap(v[--right], v[i]);
        }

        //根据情况判断第k大的值所在的区间获取第k大的值

        int c = r - right + 1, b = right - left - 1, ans;
        if (c >= k) ans = qsort(right, r, v, k);
        else if (b + c >= k) return key;
        else ans = qsort(l, left, v, k - b - c);
        return ans;

    }
    //库存原理
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(NULL));
        if (cnt == 0) return {};
        Qsort(0, stock.size() - 1, stock, cnt);
        return { stock.begin(),stock.begin() + cnt };

    }

    void Qsort(int l, int r, vector<int>& v, int k)
    {

        if (l >= r) return;
        //1.获取基准值
        int left = l - 1, right = r + 1, i = l, key = GetRandom(l, r, v);
        //2.排序
        while (i < right)
        {
            if (v[i] < key) swap(v[++left], v[i++]);
            else if (v[i] == key) i++;
            else if (v[i] > key) swap(v[--right], v[i]);
        }

        int a = left - l + 1, b = right - left - 1;
        if (a > k) Qsort(l, left, v, k);
        else if (a + b >= k)return;
        else  Qsort(right, r, v, k - a - b);

    }

    

    //归并排序
    void MergeSort(int left, int right, vector<int>& nums)
    {
        if (left >= right) return;

        //找一个中间位置进行分治
        int mid = (left + right) >> 1;

        //排序
        MergeSort(left, mid, nums);
        MergeSort(mid + 1, right, nums);

        //合并两个有序数组
        int cur1 = left, cur2 = mid + 1,i = 0;
        while (cur1 <= mid && cur2 <= right)
            tmp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];

        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];

        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        //再将该数组中排好序的元素拷贝回去
        for (int j = left; j <= right; j++)
            nums[j] = tmp[j-left];
           
    }
};

int main()
{

    Solution sol;
    vector<int> v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    sol.sortColors(v);
    for (auto e : v)
        cout << e << " ";
    cout << endl;
	return 0;
}