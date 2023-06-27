class Solution {
public:
    //翻转字符串，使得字符串中0的个数最少，返回最少的0的个数
    //思路：动态规划，dp[i][0]表示前i个字符中，以0结尾的最少的0的个数，dp[i][1]表示前i个字符中，以1结尾的最少的0的个数
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        //初始化
        dp[0][0] = s[0] == '0' ? 0:1;
        dp[0][1] = s[0] == '0' ? 1:0;
        //状态转移方程
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0] + (s[i] ==  '0' ? 0:1);
            dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + (s[i] == '0' ? 1:0);
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};