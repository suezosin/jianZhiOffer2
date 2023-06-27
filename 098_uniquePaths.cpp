class Solution {
public:
    //不同的路径，一个机器人位于一个m*n的网格的左上角，机器人每次只能向下或者向右移动一步，机器人试图到达网格的右下角，问有多少条不同的路径
    //思路：动态规划，dp[i][j]表示到达(i,j)位置的不同路径数
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        //初始化
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        //状态转移方程为：dp[i][j] = dp[i-1][j]+dp[i][j-1]
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        //返回结果
        return dp[m-1][n-1];
    }
};