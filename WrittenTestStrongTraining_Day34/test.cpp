#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

////ISBN号码
//void solve() {
//    string str;
//    cin >> str;
//    int n = str.size(), count = 1, sum = 0;
//    for (int i = 0; i < n - 1; i++) {
//        if (str[i] >= '0' && str[i] <= '9') {
//            sum += (str[i] - '0') * count;
//            count++;
//        }
//    }
//    int ret = sum % 11;
//    if ((ret >= 0 && ret <= 9 && ret == (str[n - 1] - '0')) || (ret == 10 && 'X' == str[n - 1]))
//        cout << "Right" << endl;
//    else {
//        if (ret == 10)
//            str[n - 1] = 'X';
//        else str[n - 1] = ret + '0';
//        cout << str << endl;
//    }
//}

//代码实现有问题
//void dfs(int x, int y, vector<vector<char>>& vv, int len,int & count,int & minLen)
//{
//    if (vv[x][y] == 'k' && vv[x + 1][y] != '.' && vv[x][y + 1] != '.' && vv[x - 1][y] != '.' && vv[x][y - 1] != '.')return;
//    if (vv[x + 1][y] == 'e'|| vv[x - 1][y] == 'e' || vv[x][y+1] == 'e' || vv[x][y-1] == 'e')
//    {
//        count++;
//        len++;
//        minLen = min(len, minLen);
//    }
//
//    //上
//    else if (vv[x + 1][y] == '.')
//    {
//        vv[x + 1][y] = '#';
//        dfs(x + 1, y, vv, len + 1, count,minLen);
//    }
//    //右
//    else if (vv[x][y+1] == '.')
//    {
//        vv[x][y+1] = '#';
//        dfs(x, y+1, vv, len + 1, count, minLen);
//    }
//    //下
//    else if (vv[x-1][y] == '.')
//    {
//        vv[x-1][y] = '#';
//        dfs(x-1, y, vv, len + 1, count, minLen);
//    }
//    //左
//    else if (vv[x][y - 1] == '.')
//    {
//        vv[x][y - 1] = '#';
//        dfs(x, y - 1, vv, len + 1, count, minLen);
//    }
//
//
//    else if (vv[x + 1][y] == '#')dfs(x + 1, y,vv, len - 1, count, minLen);
//
//    else if (vv[x][y+1] == '#')dfs(x, y+1, vv, len - 1, count, minLen);
//
//    else if (vv[x - 1][y] == '#')dfs(x-1, y, vv, len - 1, count, minLen);
//
//    else if (vv[x][y-1] == '#')dfs(x, y-1, vv, len - 1, count, minLen);
//
//}
//
//void solution()
//{
//    int n, m,x=1,y=1;
//    cin >> n >> m;
//    vector<vector<char>> vv(n+2,vector<char>(m+2,'*'));
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> vv[i][j];
//            if (vv[i][j] == 'k')
//            {
//                x = i;
//                y = j;
//            }
//        }
//    }  
//    int minLen = 0x3f3f3f3f,count = 0;
//    dfs(x, y, vv,0,count,minLen);
//    if (count == 0) cout << -1 << endl;
//    else cout << count <<" "<< minLen << endl;
//}

//kotori和迷宫

const int N = 35;
int x, y;
int n, m;
char arr[N][N];
int dist[N][N];
queue<pair<int, int>> q;
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0 };

void bfs()
{
    memset(dist, -1, sizeof dist);
    dist[x][y] = 0;
    q.push({ x , y });

    while (q.size())
    {
        auto pairElement = q.front();

        int x2 = pairElement.first;

        int y2 = pairElement.second;
        q.pop();
        for (int i = 0; i < 4;i++)
        {
            int a = x2 + dx[i], b = y2 + dy[i];
            if (a >= 1 && a <= n && b >= 1 && b <= m && dist[a][b] == -1&&arr[a][b]!='*')
            {
                dist[a][b] = dist[x2][y2] + 1;
                if (arr[a][b] != 'e')q.push({ a,b });
            }
        }

    }
}

void solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'k')
            {
                x = i;
                y = j;
            }
        }
    }

    bfs();

    int count = 0, ret = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 'e' && dist[i][j] != -1)
            {
                count++;
                ret = min(ret, dist[i][j]);
            }
        }
    }
    if (count == 0) cout << -1 << endl;
    else cout << count << " " << ret << endl;

}

//矩阵最长递增路径
class Solution {
public:
    int m, n;
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int memo[1010][1010];
    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != -1) return memo[i][j];
        int len = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = dx[k] + i, y = dy[k] + j;
            if (x >= 0 && x < m && y >= 0 && y<n && matrix[x][y]>matrix[i][j])
            {
                len = max(len, 1 + dfs(matrix, x, y));
            }
        }
        memo[i][j] = len;
        return len;
    }
    int solve(vector<vector<int> >& matrix) {
        // write code here
        m = matrix.size(), n = matrix[0].size();
        memset(memo, -1, sizeof memo);
        int ret = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, dfs(matrix, i, j));
            }
        }
        return ret;
    }
};

int main()
{
	//solve();
    solution();
	return 0;
}