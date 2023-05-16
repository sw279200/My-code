#define _CRT_SECURE_NO_WARNINGS 1

//快速排序
#if 0
#include <iostream>
using namespace std;
#include<string>
void quick_sort(int arr[], int left, int right)
{
	//static int count = 0; //计算交换次数

	if (left >= right)
	{
		return;
	}
	int i = left-1;
	int j = right+1;
	int temp = arr[left];

	while (i < j)
	{
		do
		{
			i++;
		} while (arr[i] < temp);

		do
		{
			j--;
		} while (arr[j] > temp);

		if (i < j)
		{
			swap(arr[i], arr[j]);
			//cout << "count = " << count << endl;
			//count++;
		}
	}

	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}

int main()
{

	int arr[] = { 1,0,8,2,5,5,6,7,4,3,6,7,9};
	int sz = sizeof(arr) / sizeof(int);
	quick_sort(arr, 0, sz-1);
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

#endif

#if 0
//归并排序
#include <iostream>
using namespace std;
int n;
int arr[1000010];
int temp[1000010];

void merge_sort(int arr[],int left,int right)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);

	int k = 0;
	int i = left;
	int j = mid+1;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left,j = 0; i <= right; i++,j++)
	{
		arr[i] = temp[j];
	}
}

int main()
{
	cout << "请输入需要排序的个数： ";
	cin >> n;
	cout << "排序前：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1);
	cout << "排序后：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

#endif


#if 0
//超长整数相加
#include <iostream>
#include <vector>
using namespace std;

vector<int> Add(vector<int>& A, vector<int>& B)
{
	vector<int>C;
	int t = 0;
	
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size())t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;

	}
	if (t)
		C.push_back(1);
	return C;
}

int main()
{
	string a;
	string b;
	vector<int>A;
	vector<int>B;
	vector<int>C;

	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	for (int i = b.size() - 1; i >= 0; i--)
	{
		B.push_back(b[i] - '0');
	}

	C = Add(A, B);

	for (int i = C.size()-1; i >=0 ; i--)
	{
		cout << C[i];
	}
	cout << endl;
	return 0;
}



#endif

#if 1
//超长整数相减
#include <iostream>
#include <vector>
using namespace std;


bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size())
		return A.size() > B.size();

	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] != B[i])
		{
			return A[i] > B[i];
		}
	}
	return true;
}

vector<int> Sub(vector<int>& A, vector<int>& B)
{
	vector<int>C;
	int t = 0;

	for (int i = 0; i < A.size(); i++)
	{
		t = A[i]-t;
		if (i < B.size()) t -= B[i];
		C.push_back((t+10) % 10);
		if (t < 0)
			t = 1;
		else
			t = 0;

	}
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C; 
}

int main()
{
	string a;
	string b;
	vector<int>A;
	vector<int>B;
	vector<int>C;

	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	for (int i = b.size() - 1; i >= 0; i--)
	{
		B.push_back(b[i] - '0');
	}

	if (cmp(A, B))
	{
		C = Sub(A, B);
		for (int i = C.size() - 1; i >= 0; i--)
		{
			cout << C[i];
		}
		cout << endl;
	}
	else
	{
		C = Sub(B, A);
		cout << "-";
		for (int i = C.size() - 1; i >= 0; i--)
		{
			cout << C[i];
		}
		cout << endl;
	}
	

	
	return 0;
}
#endif