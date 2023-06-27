class Solution {
public:
    //交错字符串，给定三个字符串s1、s2、s3，判断s3是否由s1和s2交错组成
    //思路：动态规划，dp[i][j]表示s1[0...i]和s2[0...j]是否能交错组成s3[0...i+j]
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size(),l=s3.size();
        if(m+n!=l) return false;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        //初始化
        dp[0][0] = true;
        for(int i=1;i<=m;i++){
            dp[i][0] = dp[i-1][0] && s1[i-1]==s3[i-1];
        }
        for(int j=1;j<=n;j++){
            dp[0][j] = dp[0][j-1] && s2[j-1]==s3[j-1];
        }
        //状态转移方程为：dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i+j-1] || dp[i][j-1] && s2[j-1]==s3[i+j-1]
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i+j-1] || dp[i][j-1] && s2[j-1]==s3[i+j-1];
            }
        }
        return dp[m][n];
    }
};