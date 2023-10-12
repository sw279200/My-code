#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Board {
public:
    //¾®×ÖÆå
    bool checkWon(vector<vector<int> > board) {
        // write code here
          // write code here
        int x = 0, y = 0;
        for (int i = 0; i < 3; i++)
        {
            int sum = 0, count = 0;
            for (int j = 0; j < 3; j++)
            {
                sum += board[i][j];
                count += board[j][i];
            }
            if (sum == 3 || count == 3) return true;
            x += board[i][i];
            y += board[2 - i][i];
        }

        if (x == 3 || y == 3) return true;
        return false;
    }
};

int lengthScore(const string& s) {
    int n = s.size(), ret = 0;

    if (n <= 4) ret = 5;
    else if (n >= 5 && n <= 7) ret = 10;
    else ret = 25;

    return ret;
}

int ScoreAlphabet(const string& s) {
    int Acount = 0, acount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            acount++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            Acount++;
    }

    if (acount != 0 && Acount != 0) return 20;
    else if (acount != 0 || Acount != 0) return 10;

    return 0;

}

int ScoreDigit(const string& s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            count++;

    if (count == 0) return 0;
    else if (count == 1) return 10;

    return 20;

}

int ScoreMark(const string& s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!((s[i] >= 0x21 && s[i] <= 0x2F) || (s[i] >= 0x3A && s[i] <= 0x40) 
            || (s[i] >= 0x5B && s[i] <= 0x60)||(s[i] >= 0x7B && s[i] <= 0x7E)))
            count++;
    }
    if (count == 0) return 0;
    else if (count == 1) return 10;

    return 25;
}

int EncourageScore(const string& s) {
    if (ScoreAlphabet(s) != 0 && ScoreDigit(s) != 0 && ScoreMark(s) == 20)
        return 5;

    if (ScoreAlphabet(s) != 0 && ScoreDigit(s) != 0 && ScoreMark(s) != 0)
        return 3;

    if (ScoreAlphabet(s) != 0 && ScoreDigit(s) != 0)
        return 2;


    return 0;
}


void solve() {
    int sum = 0;
    string str;
    cin >> str;
    sum += ScoreAlphabet(str) + ScoreDigit(str) + ScoreMark(str) + lengthScore(
        str) + EncourageScore(str);
    cout << ScoreAlphabet(str) << " " << ScoreDigit(str) << " " << ScoreMark(str) << " " << lengthScore(
        str) << " " << EncourageScore(str) << endl;
    if (sum >= 90) cout << "VERY_SECURE" << endl;
    else if (sum >= 80 && sum < 90) cout << "SECURE" << endl;
    else if (sum >= 70 && sum < 80) cout << "VERY_STRONG" << endl;
    else if (sum >= 60 && sum < 70) cout << "STRONG" << endl;
    else if (sum >= 50 && sum < 60) cout << "AVERAGE" << endl;
    else if (sum >= 25 && sum < 50) cout << "WEAK" << endl;
    if (sum >= 0 && sum < 25) cout << "VERY_WEAK" << endl;
}
int main() {
    solve();
    return 0;
}