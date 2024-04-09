#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashs, hasht;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {      
            if (hashs.count(s[i]) == 0)hashs.insert(std::make_pair(s[i], t[i]));
            else if ((hashs.count(s[i]) != 0 && hashs[s[i]] != t[i])) return false;

            if (hasht.count(t[i]) == 0)hasht.insert(std::make_pair(t[i], s[i]));
            else if((hasht.count(t[i]) != 0 && hasht[t[i]] != s[i])){ return false; }
        }
        return true;

    }
};


int main()
{
    Solution sol;
    cout<<sol.isIsomorphic("badc", "baba");
	return 0;
}