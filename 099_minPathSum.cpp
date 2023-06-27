class Solution {
public:
    //最小路径和，给定一个m*n的网格，每个位置都有一个非负整数，找到一条从左上角到右下角的路径，使得路径上的数字和最小
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        //初始化
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }
        //状态转移方程为：dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j]
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        //返回结果
        return dp[m-1][n-1];
    }
};