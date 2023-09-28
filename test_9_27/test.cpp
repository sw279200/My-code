#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//˫ָ���㷨

class Solution {
public:
	//�ƶ���
    void moveZeroes(vector<int>& nums) {
		for (int dest = -1, cur = 0; cur < nums.size(); cur++)
		{
			if (nums[cur] != 0)
			{
				swap(nums[++dest], nums[cur]);
			}
		}
    }

	//��д��
	void duplicateZeros(vector<int>&  arr) {

		//1.���ҵ��ܹ���д�������һ������λ��
		int cur = 0;
		int dest = -1;
		while (cur<arr.size())
		{
			if (arr[cur] != 0)
			{			
				dest++;
			}
			else
			{
				dest += 2;
			}

			if (dest>=arr.size()-1)
			{
				break;
			}

			cur++;
		}

		//����Խ���������
		if (dest == arr.size())
		{
			arr[arr.size() - 1] = 0;
			cur--;
			dest -= 2;
		}


		//�Ӻ���ǰ��д
		while (cur >= 0)
		{
			if (arr[cur] != 0)
			{
				arr[dest] = arr[cur];
				dest--;
			}
			else
			{
				arr[dest--] = 0;
				arr[dest--] = 0;		
			}
			cur--;
		}
	}

	//��һ������ƽ����
	int quadSum(int n)
	{
		int sum = 0;
		while (n)
		{
			int num = n % 10;
			sum += num * num;
			n /= 10;
		}
		return sum;
	}

	//������
	bool isHappy(int n) {
		////����һ :�볲ԭ��
		//vector<int> v(811, 0);
		//if (n == 1)
		//	return n == 1;
		//stack<int> st;
		//int x = n;
		//int sum = 0;

		//while (sum != n && sum != 1)
		//{
		//	sum = 0;
		//	while (x != 0)
		//	{
		//		st.push(x % 10);
		//		x /= 10;
		//	}

		//	while (!st.empty())
		//	{
		//		sum += st.top() * st.top();
		//		cout << st.top() << " ";
		//		st.pop();
		//	}
		//	x = sum;
		//	v[x]++;
		//	if (v[x] >= 2)
		//	{
		//		break;
		//	}
		//}

		//if (sum == 1)
		//{
		//	return true;
		//}
		//return false;

		//������������ָ�뷨
		int slow = n;
		int fast = quadSum(n);
		while (slow != fast)
		{
			slow = quadSum(slow);
			fast = quadSum(quadSum(fast));
		}

		return slow == 1;
	}


	//ʢ���ˮ������
	int maxArea(vector<int>& height) {
		int left = 0,right = height.size()-1;
		int max = 0;
		while (left < right)
		{
			if (height[left] <= height[right])
			{
				max = max > (right - left) * height[left]?max: (right - left) * height[left];
				left++;
			}
			else
			{
				max = max > (right - left) * height[right]? max: (right - left) * height[right];
				right--;
			}

		}
		return max;

	}

	//��Ч�����εĸ���
	int triangleNumber(vector<int>& nums) {
		int count = 0;
		sort(nums.begin(), nums.end());
		int size = nums.size()-1;
		int MaxNum;
		while (size > 0)
		{
			MaxNum = nums[size];   //�̶������
			int left = 0;
			int right = size - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] > MaxNum)
				{
					count += right - left;
					right--;

				}
				else
				{
					left++;
				}
			}
			size--;
		}
		return count;

	}

	//�����ܼ۸�ΪĿ��ֵ��������Ʒ
	vector<int> twoSum(vector<int>& price, int target) {
		vector<int> v;
		int left = 0;
		int right = price.size() - 1;
		while (left < right)
		{
			if (price[left] + price[right] > target)
			{
				right--;
			}
			else if (price[left] + price[right] < target)
			{
				left++;
			}
			else
			{
				break;
			}
		}

		v.push_back(price[left]);
		v.push_back(price[right]);
		return v;
	}

	//����֮��
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> vv;
		int x = 0;
		int size = nums.size();
		while (x < size)
		{
			if (nums[x] > 0)	break;
			int left = x + 1, right = size - 1;;
			while (left < right)
			{
				int sum = nums[left] + nums[right];
				if (sum + nums[x] > 0) right--;
				else if (sum + nums[x] < 0)	left++;
				else
				{
					vv.push_back({ nums[x],nums[left],nums[right] });
					left++, right--;
					while (right > left && nums[right] == nums[right + 1]) right--;
					while (left < right && nums[left - 1] == nums[left]) left++;
				}
			}
			x++;
			while (x < size - 1 && nums[x] == nums[x - 1])x++;
		}
		return vv;
	}


	//����֮��
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> vv;
		int n = nums.size();
		if (n < 4)
		{
			return {};
		}
		for (int fixNum = 0; fixNum < n;)
		{
			int x = fixNum + 1;
			int size = n;
			while (x < size)
			{

				int left = x + 1, right = size - 1;;
				while (left < right)
				{
					long long sum = (long long)nums[left] + (long long)nums[right] + (long long)nums[fixNum];
					if (sum + nums[x] > target) right--;
					else if (sum + nums[x] < target)	left++;
					else
					{
						vv.push_back({ nums[fixNum],nums[x],nums[left],nums[right] });
						left++, right--;
						while (right > left && nums[right] == nums[right + 1]) right--;
						while (left < right && nums[left - 1] == nums[left]) left++;
					}
				}
				x++;
				while (x < size - 1 && nums[x] == nums[x - 1])x++;
			}

			fixNum++;
			while (fixNum < n && nums[fixNum - 1] == nums[fixNum])fixNum++;
		}
		return vv;
	}
};

int main() {
	
	Solution sol;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	v.push_back(12);
	//sol.moveZeroes(v);
	
	sol.threeSum(v);
	//sol.duplicateZeros(v);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	sol.isHappy(21);
	return 0;
}