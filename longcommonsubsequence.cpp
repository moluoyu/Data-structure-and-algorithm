/**
 * @brief https://www.youtube.com/watch?v=Qf5R-uYQRPk
 * 
 * @file longcommonsubsequence.cpp
 * @author Luo Yu
 * @date 2018-08-11
 */
//solution1  Recursive
#include <string>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * 
 * @param P 
 * @param Q 
 * @param n  the length of string P
 * @param m  the length of string Q
 * @return int      the number of  Longest Common Subsequence
 */
int LCS_Recu(string P, string Q, int n, int m)
{
	int result, temp1, temp2;
	if (n == 0 || m == 0)
	{
		result = 0;
	}
	else if (P[n - 1] == Q[m - 1]) //最后一个字符相等
	{
		
		result = 1 + LCS_Recu(P, Q, n - 1, m - 1);
	}
	else // (P[n-1]!=Q[m-1]) 这一句可以不写
	{
		temp1 = LCS_Recu(P, Q, n, m - 1);
		temp2 = LCS_Recu(P, Q, n - 1, m);
		result = max(temp1, temp2);
	}
	return result;
}
/**
 * @brief memorize intermediate Results(Dynamic Programming)
 *  这种方法必须在函数定义前面初始化一个全局二维数组，
 *  如果在lcs中直接传入二维数组的话， 递归调用那里不好处理
 * @param P 
 * @param Q 
 * @param n 
 * @param m 
 * @return int 
 */

int arr[][6] = {-1,-1,-1,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,
};
int LCS(string P, string Q, int n, int m)
{
	int result, temp1, temp2;
	if (arr[n][m] != -1)
	{
		return arr[n][m];
	}
	if (n == 0 || m == 0)
	{
		result = 0;
	}
	else if (P[n - 1] == Q[m - 1]) //最后一个字符相等
	{

		result = 1 + LCS(P, Q, n - 1, m - 1);
	}
	else // (P[n-1]!=Q[m-1]) 这一句可以不写
	{
		temp1 = LCS(P, Q, n, m - 1);
		temp2 = LCS(P, Q, n - 1, m);
		result = max(temp1, temp2);
	}
		arr[n][m] = result;
	
	return result;
}
/**
 * @(Dynamic Programming    bottom-up
 *  在vs2015中 L[n+1][m+1] 会报错，猜测可能是vs2015会未完全支持c++11
 * @param P 
 * @param Q 
 * @param n 
 * @param m 
 * @return int 
 */

int LCS(char* X, char *Y, int n, int m)
{

    int L[n + 1][m + 1];
    int i, j;
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[n][m];
}