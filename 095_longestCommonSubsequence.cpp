class Solution {
public:
    //最长公共子序列
    //思路：动态规划，dp[i][j]表示text1[0...i]和text2[0...j]的最长公共子序列的长度
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        //初始化
        dp[0][0] = text1[0] == text2[0] ? 1:0;
        for(int i=1;i<m;i++){
            dp[i][0] = max(dp[i-1][0],text1[i] == text2[0] ? 1:0);
        }
        for(int j=1;j<n;j++){
            dp[0][j] = max(dp[0][j-1],text1[0] == text2[j] ? 1:0);
        }
        //状态转移方程为：dp[i][j] = max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(text1[i]==text2[j]?1:0))
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+(text1[i]==text2[j]?1:0));
            }
        }
        return dp[m-1][n-1];
    }
};