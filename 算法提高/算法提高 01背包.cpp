算法提高 01背包
问题描述
　　给定N个物品,每个物品有一个重量W和一个价值V.你有一个能装M重量的背包.问怎么装使得所装价值最大.每个物品只有一个.
输入格式
　　输入的第一行包含两个整数n, m，分别表示物品的个数和背包能装重量。
　　以后N行每行两个数Wi和Vi,表示物品的重量和价值
输出格式
　　输出1行，包含一个整数，表示最大价值。
样例输入
3 5
2 3
3 5
4 7
样例输出
8
数据规模和约定
　　1<=N<=200,M<=5000.

分析：dp[i][j]表示前i件物品选择部分装入体积为j的背包后，背包当前的最大价值，
一共有n件物品，那么dp[n][m]就是前n件物品选择部分装入容量为m的背包后，背包内物品的最大价值
1.当当前输入的物品体积大于背包容量，则不装入背包，dp[i][j] = dp[i-1][j];
2.当当前输入的物品体积小于等于背包容量，考虑装或者不装两种状态，取体积最大的那个：dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);

#include <iostream>
using namespace std;
#define max(a, b) (a) > (b) ? (a) : (b)
int dp[201][5001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        for(int j = 1; j <= m; j++) {
            if (j >= w)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][m];
    return 0;
}