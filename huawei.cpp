/*20180908 笔试题*/


//第二题，安排会议室，[s,f),s开始时间，f结束时间















//第三题，走迷宫，dfs搜索
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;
bool DFS(int row, int col,vector<string>map)
{
 if (map[row][col] == '1'|| map[row][col] == 'A') return false;
 map[row][col] = '1';
 if (row + 1 >= 10 || row < 0 || col >= 10 || col < 0) return true;
 return DFS(row + 1, col, map) || DFS(row - 1, col, map) || DFS(row, col + 1, map) || DFS(row, col - 1, map)
}
int main()
{
    vector<string> map;
    for (int i = 0; i < 10; ++i)
    {
        string s;
        cin >> s;
        map.push_back(s);
    }
    int row, col;
    cin >> col >> row;
    cout << DFS(row, col, map);
    system("pause");
    return 0;
}
