class Solution {
public:
    //动态规划，dp[i][j]表示nums中前i个元素，组成和为j的方案数，dp[i][j]=dp[i-1][j-nums[i]]+dp[i-1][j+nums[i]]
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum<target || (sum+target)%2==1) return 0;
        int t=(sum+target)/2;
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=t;j++){
                if(j>=nums[i-1]) dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][t];
    }
};