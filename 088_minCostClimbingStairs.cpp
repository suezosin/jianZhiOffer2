class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //思路：动态规划，dp[i]表示到达第i个台阶的最小花费，dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
        //dp[0]=dp[1]=0
        int n=cost.size();
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};