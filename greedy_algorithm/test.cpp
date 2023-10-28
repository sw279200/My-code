#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    //柠檬水找零
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0, five = 0;
        for (auto x : bills)
        {
            if (x == 5)five++;
            else if (x == 10)
            {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else if (x == 20)
            {
                if (ten >= 1 && five >= 1)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
    //将数组和减半的最少操作次数
    int halveArray(vector<int>& nums) {
        priority_queue<double>heap;
        double sum = 0.0;
        for (auto x : nums)
        {
            sum += x;
            heap.push(x);
        }
        sum /= 2.0;
        int count = 0;
        while (sum > 0)
        {
            double t = heap.top();
            heap.pop();
            t /= 2.0;
            sum -= t;
            count++;
            heap.push(t);
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v.push_back(5);
    v.push_back(5);
    v.push_back(10);
    v.push_back(10);
    v.push_back(20);
    cout << sol.lemonadeChange(v) << endl;

    return 0;
}