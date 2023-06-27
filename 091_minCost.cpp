class Solution {
public:
    //粉刷房子，房子排成一排，每个房子可以粉刷成红色、蓝色或者绿色，相邻的房子不能粉刷成相同的颜色，求最小的粉刷成本
    //思路：动态规划，dp[i][j]表示粉刷到第i个房子时，第i个房子粉刷成j颜色的最小成本
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0) return 0;
        int n=costs.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        //初始化
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        //状态转移方程
        for(int i=1;i<n;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+costs[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2])+costs[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1])+costs[i][2];
        }
        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};