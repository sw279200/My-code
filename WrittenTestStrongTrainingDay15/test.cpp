#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int minimum = 0x3f3f3f3f, Count1 = 0x3f3f3f3f,Count2= 0x3f3f3f3f,leftSum = 0,rightSum = 0;
		int zeroCount = 0;

		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 || right[i] == 0)
				zeroCount += left[i] + right[i];
			else
			{
				leftSum += left[i];
				rightSum += right[i];
				Count1 = min(Count1, left[i]);
				Count2 = min(Count2, right[i]);
			}

		}
		minimum = min(leftSum-Count1+1,rightSum- Count2+1);
		return zeroCount+minimum+1;
 	}
};


void countOfOneInBinary()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 0; i < 32; i++)
			if (((n >> i) & 1) == 1) count++;

		cout << count << endl;
	}
}
int main()
{
	Gloves gs;
	int n = 4;
	vector<int> left, right;
	left.push_back(0);
	left.push_back(7);
	left.push_back(1);
	left.push_back(6);
	right.push_back(1);
	right.push_back(5);
	right.push_back(0);
	right.push_back(6);

	cout << gs.findMinimum(n, left, right) << endl;
	//countOfOneInBinary();
	return 0;
}