#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    //��ɫ����
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        ////����һ������
        //QuickSort(0, n - 1, nums);

        //����������ָ��˼��
        for (int i = 0, left = -1, right = n; i < right;)
        {
            if (nums[i] == 0) swap(nums[++left], nums[i++]);
            else if (nums[i] == 1) i++;
            else if (nums[i] == 2) swap(nums[--right], nums[i]);
        }
    }

    vector<int> tmp;

    //��������
    vector<int> sortArray(vector<int>& nums) {
        /*srand(time(NULL));
        QuickSort(0, nums.size() - 1, nums);*/

        tmp.resize(nums.size());
        MergeSort(0, nums.size() - 1, nums);

        return nums;
    }

    //����+����˼��
    void QuickSort(int left, int right, vector<int>& v)
    {
        if (left >= right) return;
        int start = left-1, end = right+1,i = left;
        int tmp = v[(rand() % (right - left + 1)) + left];//���������ȡ��׼ֵ
        while (i<end)
        {
            if (v[i] < tmp) swap(v[++start], v[i++]);
            else if (v[i] == tmp) i++;
            else if (v[i] > tmp) swap(v[--end], v[i]);
        }

        QuickSort(left, start, v);
        QuickSort(end, right, v);
    }

    //�����е�k�����Ԫ��
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

        //1.��ȡ��׼ֵ
        int left = l - 1, right = r + 1, i = l, key = GetRandom(l, r, v);
        //2.����
        while (i < right)
        {
            if (v[i] < key) swap(v[++left], v[i++]);
            else if (v[i] == key) i++;
            else if (v[i] > key) swap(v[--right], v[i]);
        }

        //��������жϵ�k���ֵ���ڵ������ȡ��k���ֵ

        int c = r - right + 1, b = right - left - 1, ans;
        if (c >= k) ans = qsort(right, r, v, k);
        else if (b + c >= k) return key;
        else ans = qsort(l, left, v, k - b - c);
        return ans;

    }
    //���ԭ��
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(NULL));
        if (cnt == 0) return {};
        Qsort(0, stock.size() - 1, stock, cnt);
        return { stock.begin(),stock.begin() + cnt };

    }

    void Qsort(int l, int r, vector<int>& v, int k)
    {

        if (l >= r) return;
        //1.��ȡ��׼ֵ
        int left = l - 1, right = r + 1, i = l, key = GetRandom(l, r, v);
        //2.����
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

    

    //�鲢����
    void MergeSort(int left, int right, vector<int>& nums)
    {
        if (left >= right) return;

        //��һ���м�λ�ý��з���
        int mid = (left + right) >> 1;

        //����
        MergeSort(left, mid, nums);
        MergeSort(mid + 1, right, nums);

        //�ϲ�������������
        int cur1 = left, cur2 = mid + 1,i = 0;
        while (cur1 <= mid && cur2 <= right)
            tmp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];

        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];

        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        //�ٽ����������ź����Ԫ�ؿ�����ȥ
        for (int j = left; j <= right; j++)
            nums[j] = tmp[j-left];
           
    }


    vector<int> temp;
    // ��������Ե�����

    int reversePairs(vector<int>& nums) {
        int n = nums.size() - 1;
        temp.resize(50010);
        return mergeSort(0, n, nums);
    }

    int mergeSort(int left, int right, vector<int>& nums)
    {
        if (left >= right) return 0;
        
        //ѡ���м�㣬��֧����
        int mid = (left + right) >> 1;
        
        int ret = 0; //��¼����������Ե�����
        
        //����  ����������������Բ����򣬼����Ұ�����������Բ�����
        ret += mergeSort(left, mid, nums);
        ret += mergeSort(mid + 1, right, nums);

        //����һ��һ�ҵ������
        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
            {
                tmp[i++] = nums[cur1++];
            }
            else
            {
                ret += mid - cur1 + 1;
                tmp[i++] = nums[cur2++];
            }
        }
        
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        //��tmp�����е�Ԫ�ؿ�����ԭ����
        for (int j = left; j <= right; j++)
            nums[j] = tmp[j - left];

        return ret;
    }

    vector<int> index;
    vector<int> ret;
    int tmpNums[100010];
    int tmpIndex[100010];

    //�����Ҳ�С�ڵ�ǰԪ�صĸ���
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        index.resize(n);
        ret.resize(n);
        for (int i = 0; i < n; i++)
            index[i] = i;
        _mergeSort(0, n - 1, nums);
        return ret;
    }

    void _mergeSort(int left, int right, vector<int>& nums)
    {
        if (left >= right) return;

        //��һ���м��������仮��
        int mid = (left + right) >> 1;

        //����
        _mergeSort(left, mid, nums);
        _mergeSort(mid + 1, right, nums);

        //һ��һ�ҵ����
        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
            {
                tmpNums[i] = nums[cur2];
                tmpIndex[i++] = index[cur2++];
            }
            else
            {
                ret[index[cur1]] += right - cur2 + 1;
                tmpNums[i] = nums[cur1];
                tmpIndex[i++] = index[cur1++];

            }
        }

        while (cur1 <= mid)
        {
            tmpNums[i] = nums[cur1];
            tmpIndex[i++] = index[cur1++];
        }

        while (cur2 <= right)
        {
            tmpNums[i] = nums[cur2];
            tmpIndex[i++] = index[cur2++];
        }

        for (int j = left; j <= right; j++)
        {
            nums[j] = tmpNums[j - left];
            index[j] = tmpIndex[j - left];
        }
    }

    //��ת��
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return _MergeSort(0, n - 1, nums);
    }

    int _MergeSort(int left, int right, vector<int>& nums)
    {
        if (left >= right) return 0;

        //ѡһ���м��������仮��
        int mid = (left + right) >> 1;

        int res = 0;

        //������ߵ����䷭ת�Եĸ���
        res += _MergeSort(left, mid, nums);
        //������ߵ����䷭ת�Եĸ���
        res += _MergeSort(mid + 1, right, nums);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid)
        {
            while (cur2 <= right && nums[cur1] / 2.0 <= nums[cur2])cur2++;

            if (cur2 > right) break;
            res += right - cur2 + 1;
            cur1++;
        }
        //һ��һ�ҵ����
        cur1 = left, cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
            tmpNums[i++] = nums[cur1] <= nums[cur2] ? nums[cur2++] : nums[cur1++];

        while (cur1 <= mid) tmpNums[i++] = nums[cur1++];

        while (cur2 <= right) tmpNums[i++] = nums[cur2++];

        for (int j = left; j <= right; j++)  nums[j] = tmpNums[j - left];
        return res;
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